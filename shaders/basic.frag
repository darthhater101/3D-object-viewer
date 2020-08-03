#version 330 core

out vec4 color;

in vec3 myNormal;
in vec3 FragPos;
in vec3 CameraPos;

void main()
{
    //color = vec4(0.5f, 0.13f, 0.83f, 1.0f);

    vec3 lightPos = vec3(CameraPos.x, CameraPos.y, CameraPos.z);
    vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);
    vec3 objectColor = vec3(0.5f, 0.13f, 0.83f);

    float ambientStrength = 0.2f;
    vec3 ambient = ambientStrength * lightColor;

    vec3 norm = normalize(myNormal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    vec3 result = (ambient + diffuse) * objectColor;
    color = vec4(result, 1.0f);
}
