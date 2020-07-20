#include "model.h"

Model::Model(const QString& meshPath, const QString& shaderPath)
{
    mesh = QSharedPointer<Mesh>(new Mesh(meshPath));
    shader = QSharedPointer<Shader>(new Shader(shaderPath));

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
