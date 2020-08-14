#pragma once

#include "object.h"

class Cube : public Object
{
public:
    Cube(QVector3D pos, float scale) : Object(pos, scale)
    {
        mesh = new Mesh ("C:/Users/razer/Documents/Modeller3D/meshes/cube.obj");
        shader = new Shader("C:/Users/razer/Documents/Modeller3D/shaders/basic");

        name = "Cube";

        shader->use();
        mesh->bindVao();
            mesh->bindVbo(0);
            shader->enableAttributeArray(0);
            shader->setAttributeBuffer(0, 3);
        mesh->unBindVao();
        shader->disableAttributeArray(0);
        mesh->unBindVbo(0);
        shader->unbind();

        shader->use();
        mesh->bindVao();
            mesh->bindVbo(1);
            shader->enableAttributeArray(1);
            shader->setAttributeBuffer(1, 3);
        mesh->unBindVao();
        shader->disableAttributeArray(1);
        mesh->unBindVbo(1);
        shader->unbind();
    }
};

