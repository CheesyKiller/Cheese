import os
import sys
from pathlib import Path
from string import Template

# Define the template for the module interface file
file_template = Template("""module;$required_include

export module $module_name;

#include <glm/$relative_path>""")

glm_template = Template("""export module GLM;

$generatedFiles
""")

generatedFiles = []

def search_in_file(file_path: str, phrase) -> bool:
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            for line in file:
                print(f"Checking line: {line.strip()}")  # Debugging line
                if phrase in line:
                    return True
        return False
    except FileNotFoundError:
        print(f"The file at {file_path} was not found.")
        return False
    except IOError as e:
        print(f"An error occurred while trying to read the file at {file_path}: {e}")
        return False

def make_module_file(hpp_file_path, glm_base_dir, output_dir):
    """
    Generates a .ixx module file for a given .hpp file.
    """
    relative_path = hpp_file_path.relative_to(glm_base_dir).as_posix()

    if hpp_file_path.name.startswith('_'):
        return  # Skip files starting with an underscore

    relative_module_name = relative_path.replace('/', '_').replace('\\', '_').replace('.hpp', '')
    generatedFiles.append(relative_module_name)

    module_name = "GLM-" + relative_module_name
    module_file_path = output_dir / f"{module_name}.ixx"
    module_file_path.parent.mkdir(parents=True, exist_ok=True)

    required_include = ""

    content = file_template.substitute(
        module_name=module_name.replace("GLM-", "GLM:"),
        relative_path=relative_path,
        required_include=required_include
    )

    with open(module_file_path, 'w') as module_file:
        module_file.write(content)

def scan_for_hpp_files(glm_dir, output_dir):
    """
    Scans the GLM directory for .hpp files and generates corresponding .ixx files.
    """
    if not glm_dir.exists():
        print(f"Error: GLM directory '{glm_dir}' does not exist.")
        sys.exit(1)

    fileGenerationCount = 0

    for hpp_file in glm_dir.rglob('*.hpp'):
        make_module_file(hpp_file, glm_dir, output_dir)
        fileGenerationCount += 1

    return fileGenerationCount

def clear_modules_dir(output_dir):
    """
    Clears the modules directory by deleting all existing .ixx files.
    """
    if not output_dir.exists():
        print(f"Modules directory '{output_dir}' does not exist. Creating it.")
        output_dir.mkdir(parents=True, exist_ok=True)
        return

    ix_files = list(output_dir.rglob('*.ixx'))
    if not ix_files:
        print(f"No existing .ixx files found in '{output_dir}'.")
        return

    print(f"Clearing {len(ix_files)} existing .ixx files in '{output_dir}'...")
    for ix_file in ix_files:
        try:
            ix_file.unlink()
        except Exception as e:
            print(f"Failed to delete {ix_file}: {e}")

def main():
    """
    Main function to execute the module generation script.
    """
    glm_base_dir = Path(__file__).parent.resolve()
    output_dir = glm_base_dir / "modules"

    clear_modules_dir(output_dir)

    fileGenerationCount = scan_for_hpp_files(glm_base_dir, output_dir)

    glm_includes = "\n".join([f"export import :{text};" for text in generatedFiles])

    module_file_path = output_dir / "GLM.ixx"

    try:
        module_file_path.parent.mkdir(parents=True, exist_ok=True)

        with open(module_file_path, 'w') as module_file:
            content = glm_template.substitute(generatedFiles=glm_includes)
            module_file.write(content)
            fileGenerationCount += 1
    except Exception as e:
        print(f"Error writing GLM.ixx: {e}")

    print("Files Generated:", fileGenerationCount)

if __name__ == "__main__":
    main()