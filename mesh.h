#pragma once

#include <QVector>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

class Mesh
{
private:
    QVector<float> mVertices;
    QVector<float> mNormals;
    QVector<float> mTextures;

    QOpenGLBuffer vbo[2];
    QOpenGLVertexArrayObject vao;

public:
    Mesh(QVector<float> vertices);
    Mesh(const QString& path);
    ~Mesh() {}

    void draw();

    void bindVbo(int index);
    void unBindVbo(int index);
    void bindVao();
    void unBindVao();

    void load(const QString& path);
};

