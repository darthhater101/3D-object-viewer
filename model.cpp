#include "model.h"

Model::Model(QVector3D pos, float scale, const QString& meshPath, const QString& shaderPath) : Object(pos, scale)
{
    mesh = new Mesh(meshPath);
    shader = new Shader(shaderPath);

    name = "Model";

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
