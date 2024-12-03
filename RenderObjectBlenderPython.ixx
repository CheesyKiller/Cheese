export module RenderObjectBlenderPython;

export namespace RenderObject {
    const char* embedded_python_read_blender_data_script = R"(
def read_blender_data(filepath):
    try:
        import bpy
    except ImportError as e:
        print(f"Error: bpy module not found. Ensure Blender's Python environment is set up correctly.\n\t{e}")
        return {}

    try:
        bpy.ops.wm.open_mainfile(filepath=filepath)

        result = {
            "name": "",
            "position": [],
            "rotation": [],
            "scale": [],
            "vertices": [],
            "colors": [],
            "indices": [],
            "materials": [],
            "face_material_indices": []
        }

        for scene in bpy.data.scenes:
            for obj in scene.objects:
                if obj.type == 'MESH':
                    result["name"] = obj.name

                    # Read position, rotation, and scale
                    result["position"] = [obj.location.x, obj.location.y, obj.location.z]
                    result["rotation"] = [obj.rotation_euler.x, obj.rotation_euler.y, obj.rotation_euler.z]
                    result["scale"] = [obj.scale.x, obj.scale.y, obj.scale.z]

                    mesh = obj.data

                    # Read vertices
                    for vertex in mesh.vertices:
                        result["vertices"].extend([vertex.co.x, vertex.co.y, vertex.co.z])

                    # Triangulate the mesh
                    bpy.context.view_layer.objects.active = obj
                    bpy.ops.object.mode_set(mode='EDIT')
                    bpy.ops.mesh.select_all(action='SELECT')
                    bpy.ops.mesh.quads_convert_to_tris(quad_method='BEAUTY', ngon_method='BEAUTY')
                    bpy.ops.object.mode_set(mode='OBJECT')

                    # Initialize materials list and mapping
                    material_data_list = []
                    material_indices_map = {}

                    # Read materials and create a mapping
                    for idx, material in enumerate(obj.data.materials):
                        material_info = {}
                        material_info['name'] = material.name

                        # Get the base color, including alpha
                        if material.use_nodes:
                            # Assume Principled BSDF node
                            principled_node = next((node for node in material.node_tree.nodes if node.type == 'BSDF_PRINCIPLED'), None)
                            if principled_node:
                                base_color = principled_node.inputs['Base Color'].default_value  # RGBA
                                material_info['baseColor'] = [base_color[0], base_color[1], base_color[2], base_color[3]]
                            else:
                                material_info['baseColor'] = [1.0, 1.0, 1.0, 1.0]
                        else:
                            # If not using nodes, get base color from diffuse_color
                            base_color = material.diffuse_color  # RGBA
                            material_info['baseColor'] = [base_color[0], base_color[1], base_color[2], base_color[3]]

                        material_data_list.append(material_info)
                        material_indices_map[material.name] = idx

                    result["materials"] = material_data_list

                    # Read indices and material indices per face
                    face_material_indices = []

                    for poly in mesh.polygons:
                        # Get material index for the face
                        mat_index = poly.material_index
                        face_material_indices.append(mat_index)

                        # Process indices
                        if len(poly.vertices) == 3:
                            indices = list(poly.vertices)
                            result["indices"].extend(indices)
                        else:
                            print(f"Non-triangle face detected: {poly.vertices}")

                    result["face_material_indices"] = face_material_indices

                    # Read vertex colors if available
                    if mesh.vertex_colors:
                        color_layer = mesh.vertex_colors.active
                        for loop in mesh.loops:
                            color = color_layer.data[loop.index].color
                            result["colors"].extend([color.r, color.g, color.b, color.a])
                    else:
                        # If no vertex colors, add default color (white)
                        for _ in mesh.vertices:
                            result["colors"].extend([1.0, 1.0, 1.0, 1.0])

            return result

    except AttributeError as e:
        print(f"AttributeError: {e}")
        print("Ensure that Blender is installed and the bpy module is properly initialized.")
        return {}

    except Exception as e:
        print(f"An error occurred: {e}")
        return {}
)";
}