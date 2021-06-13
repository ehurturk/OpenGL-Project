#version 330 core

layout (location=0) in vec3 position;

out vec3 color;

uniform mat4 model;

void main()
{
    gl_Position = model * vec4(position, 1.0f);
    color = position;
}