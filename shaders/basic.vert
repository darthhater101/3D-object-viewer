#version 330 core

layout (location = 0) in vec3 positions;

uniform mat4 mvp;

void main()
{
    gl_Position = mvp * vec4(positions, 1.0f);
}
