#version 330 core

// Input from vertex shader
in vec3 FragPos; // Position in world space

// Output fragment color
out vec4 FragColor;

// Material properties
struct Material {
    vec4 baseColor;
    float metallic;
    float roughness;
    vec3 emission;
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