#version 330 core

layout (location = 0) in vec3 a_Position;
layout (location = 1) in vec3 a_Normal;

uniform mat4 u_projection;
uniform mat4 u_model;

out vec3 normal;

void main()
{
	gl_Position = u_projection * u_model * vec4(a_Position, 1.0);
	normal = a_Normal;
}