#version 330 core

layout (location = 0) in vec3 aPos;

uniform mat4 u_projection;
uniform mat4 u_model;

out vec3 color;

void main()
{
	gl_Position = u_projection * u_model * vec4(aPos.x, aPos.y, aPos.z, 1.0);
	color = vec3(0.2f, 0.2f, 0.8f);
}