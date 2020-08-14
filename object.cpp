#include "object.h"

#include<QMatrix4x4>

int Object::nextId = 0;

void Object::draw(Camera* camera) const
{
    shader->use();

    QMatrix4x4 model;
    model.translate(position);
    model.scale(camera->getScaleVec());
    model.scale(scale);

    QMatrix4x4 view = camera->getViewMat();

    QMatrix4x4 projection;
    projection.perspective(45.0f, (float)800 / (float)600, 0.1f, 100.0f);

    QMatrix4x4 mvp = projection * view * model;
    shader->setMat4x4("mvp", mvp);
    shader->setMat4x4("model", model);
    QMatrix4x4 m = model.inverted();
    shader->setMat4x4("inverseModel", m);
    QVector3D cameraPos = camera->getPosition();
    shader->setVec3("cameraPos", cameraPos);

    mesh->draw();
    shader->unbind();
}

QString Object::getName()
{
    return QString(name + "." + QString::number(id));
}

int Object::getId()
{
    return id;
}
