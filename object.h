#pragma once
#include <QSharedPointer>
#include <QOpenGLContext>
#include <QDir>
#include <QCoreApplication>

#include "shader.h"
#include "mesh.h"
#include "camera.h"
#include "listitem.h"

class Object
{
protected:
    Mesh* mesh;
    Shader* shader;

    QVector3D position;
    float scale;

    QString name;
    int id;

    static int nextId;

public:
    Object(QVector3D pos, float scale)
    {
        position = pos;
        this->scale = scale;
        this->id = nextId++;
    }

    virtual ~Object()
    {
        delete mesh;
        delete shader;
    }

    void draw(Camera* camera) const;

    QString getName();
    int getId();
};

