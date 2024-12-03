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