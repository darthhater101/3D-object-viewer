#pragma once
#include <QSharedPointer>
#include <QOpenGLContext>

#include "shader.h"
#include "mesh.h"
#include "camera.h"
#include "listitem.h"

class Object
{
protected:
    QSharedPointer<Mesh> mesh;
    QSharedPointer<Shader> shader;

    QVector3D position;
    float scale;

    QString name;
    int id;

    static int nextId;

public:
    Object(QVector3D pos, float scale) {
        position = pos;
        this->scale = scale;
        this->id = nextId++;
    }

    virtual void draw(Camera camera);

    QString getName();
    int getId();
};

