#pragma once

#include "object.h"

class Cube : public Object
{
public:
    Cube() : Object()
    {

        mesh = QSharedPointer<Mesh>(new Mesh ({
                                                 -0.5f, -0.5f, -0.5f,
                                                  0.5f, -0.5f, -0.5f,
                                                  0.5f,  0.5f, -0.5f,
                                                  0.5f,  0.5f, -0.5f,
                                                 -0.5f,  0.5f, -0.5f,
                                                 -0.5f, -0.5f, -0.5f,

                                                 -0.5f, -0.5f,  0.5f,
                                                  0.5f, -0.5f,  0.5f,
                                                  0.5f,  0.5f,  0.5f,
                                                  0.5f,  0.5f,  0.5f,
                                                 -0.5f,  0.5f,  0.5f,
                                                 -0.5f, -0.5f,  0.5f,

                                                 -0.5f,  0.5f,  0.5f,
                                                 -0.5f,  0.5f, -0.5f,
                                                 -0.5f, -0.5f, -0.5f,
                                                 -0.5f, -0.5f, -0.5f,
                                                 -0.5f, -0.5f,  0.5f,
                                                 -0.5f,  0.5f,  0.5f,

                                                  0.5f,  0.5f,  0.5f,
                                                  0.5f,  0.5f, -0.5f,
                                                  0.5f, -0.5f, -0.5f,
                                                  0.5f, -0.5f, -0.5f,
                                                  0.5f, -0.5f,  0.5f,
                                                  0.5f,  0.5f,  0.5f,

                                                 -0.5f, -0.5f, -0.5f,
                                                  0.5f, -0.5f, -0.5f,
                                                  0.5f, -0.5f,  0.5f,
                                                  0.5f, -0.5f,  0.5f,
                                                 -0.5f, -0.5f,  0.5f,
                                                 -0.5f, -0.5f, -0.5f,

                                                 -0.5f,  0.5f, -0.5f,
                                                  0.5f,  0.5f, -0.5f,
                                                  0.5f,  0.5f,  0.5f,
                                                  0.5f,  0.5f,  0.5f,
                                                 -0.5f,  0.5f,  0.5f,
                                                 -0.5f,  0.5f, -0.5f
                                             }));
        shader = QSharedPointer<Shader>(new Shader("C:/Users/razer/Documents/Modeller3D/shaders/basic"));

        shader->use();
        mesh->bindVao();
            mesh->bindVbo(0);
            shader->enableAttributeArray(0);
            shader->setAttributeBuffer(0, 3);
        mesh->unBindVao();
        shader->disableAttributeArray(0);
        mesh->unBindVbo(0);
        shader->unbind();

    }
};

