import os

# Get the directory where the script is located
source_directory = os.path.dirname(os.path.abspath(__file__))
output_file = os.path.join(source_directory, "ShaderSources.ixx")

# Start of the output file content
output_header = """export module ShaderSources;"""

# Function to sanitize filenames for variable names
def sanitize_filename(filename):
    filename = filename.replace(".glsl", "")
    return filename.replace(".", "_").replace("-", "_")

# Collect and process files
file_content = [output_header]
for filename in sorted(os.listdir(source_directory)):
    if filename.endswith(".glsl"):
        filepath = os.path.join(source_directory, filename)
        with open(filepath, "r") as file:
            content = file.read()
        variable_name = sanitize_filename(filename) + "Source"
        file_content.append(f'\n\nexport const char* {variable_name} = R"(\n{content}\n)";')

# Write to output file
with open(output_file, "w") as output:
    output.writelines(file_content)

print(f"File '{output_file}' has been created with contents from the .glsl files.")
