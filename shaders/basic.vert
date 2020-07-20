#version 450 core

layout (location = 0) in vec3 positions;
layout (location = 1) in vec3 normals;

uniform mat4 mvp;
uniform mat4 inverseModel;
uniform mat4 model;

uniform vec3 cameraPos;

out vec3 myNormal;
out vec3 FragPos;
out vec3 CameraPos;

void main()
{
    gl_Position = mvp * vec4(positions, 1.0f);
    FragPos = vec3(model * vec4(positions, 1.0f));
    myNormal = mat3(transpose(inverseModel)) * normals;
    CameraPos = cameraPos;
}
