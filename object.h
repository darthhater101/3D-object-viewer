#pragma once
#include <QSharedPointer>

#include "shader.h"
#include "mesh.h"
#include "camera.h"

class Object
{
protected:
    QSharedPointer<Mesh> mesh;
    QSharedPointer<Shader> shader;

    QVector3D position;

public:
    Object() { position = QVector3D(0.0f, 0.0f, 0.0f); }

    virtual void draw(Camera camera);
};

