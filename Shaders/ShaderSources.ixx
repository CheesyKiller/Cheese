export module ShaderSources;

export const char* FragmentShaderSource = R"(
#version 330 core

// Input from vertex shader
in vec3 FragPos; // Position in world space

// Output fragment color
out vec4 FragColor;

// Material properties
struct Material {
    vec4 baseColor;    // Includes alpha
    float metallic;
    float roughness;
    vec3 emission;
    // Add other material properties as needed
};

uniform Material material;

void main()
{
    // Use the base color from the material
    vec4 color = material.baseColor;

    // Apply emission (additive)
    color.rgb += material.emission;

    // Output the final color with alpha
    FragColor = color;
}
)";

export const char* VertexShaderSource = R"(
#version 330 core

// Vertex attributes
layout(location = 0) in vec3 aPos; // Base vertex position

// Shape key positions (assuming up to 2 shape keys)
const int MAX_SHAPE_KEYS = 2; // Adjust as needed
layout(location = 1) in vec3 aShapeKeyPos0; // Shape key 0 position
layout(location = 2) in vec3 aShapeKeyPos1; // Shape key 1 position

// Output to fragment shader
out vec3 FragPos; // Position in world space

// Uniforms
uniform mat4 model;           // Model transformation matrix
uniform mat4 view;            // View transformation matrix
uniform mat4 projection;      // Projection matrix
uniform float shapeKeyWeights[MAX_SHAPE_KEYS]; // Shape key weights

void main()
{
    // Base position
    vec3 blendedPos = aPos;

    // Shape key blending
    blendedPos += shapeKeyWeights[0] * (aShapeKeyPos0 - aPos);
    blendedPos += shapeKeyWeights[1] * (aShapeKeyPos1 - aPos);

    // Apply transformations
    vec4 worldPosition = model * vec4(blendedPos, 1.0);
    gl_Position = projection * view * worldPosition;

    // Pass position to fragment shader
    FragPos = vec3(worldPosition);
}
)";