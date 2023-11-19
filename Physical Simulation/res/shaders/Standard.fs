#version 330 core

in vec3 normal;
out vec4 FragColor;

vec3 lightDirection = vec3(1.0, 1.0, -1.0);
vec3 color = vec3(0.2, 0.2, 0.8);

void main()
{
	float diffuseComponent = max(dot(lightDirection, normal), 0.0);
	FragColor = vec4(color * (diffuseComponent + 0.3), 1.0);
}