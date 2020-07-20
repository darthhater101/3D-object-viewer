#include "object.h"

#include<QMatrix4x4>

void Object::draw(Camera camera)
{
    shader->use();

    QMatrix4x4 model;
    model.translate(position);
    QMatrix4x4 view = camera.getViewMat();
    QMatrix4x4 projection;
    projection.perspective(45.0f, (float)800 / (float)600, 0.1f, 100.0f);
    QMatrix4x4 mvp = projection * view * model;
    shader->setMat4x4("mvp", mvp);
    mesh->draw();
    shader->unbind();
}
