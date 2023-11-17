#version 330 core

layout (location = 0) in vec3 aPos;

out vec3 color;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
	color = vec3(0.2f, 0.2f, 0.8f);
}