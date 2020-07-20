#include "mesh.h"
#include <iostream>
#include <QDebug>
#include <QFile>
#include <QVector3D>
#include <QVector2D>

Mesh::Mesh(QVector<float> vertices) : mVertices(vertices)
{
    vbo[0] = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    vbo[0].create();
    vbo[0].bind();
    vbo[0].setUsagePattern(QOpenGLBuffer::StaticDraw);
    vbo[0].allocate(vertices.data(), vertices.size() * sizeof(vertices[0]));
    vbo[0].release();

    vao.create();
}

Mesh::Mesh(const QString& path)
{
    load(path);

    vbo[0] = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    vbo[0].create();
    vbo[0].bind();
    vbo[0].setUsagePattern(QOpenGLBuffer::StaticDraw);
    vbo[0].allocate(mVertices.data(), mVertices.size() * sizeof(mVertices[0]));
    vbo[0].release();

    vao.create();
}

void Mesh::draw()
{
    vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
    vao.release();
}

void Mesh::bindVao()
{
    vao.bind();
}

void Mesh::unBindVao()
{
    vao.release();
}

void Mesh::bindVbo(int index)
{
    vbo[index].bind();
}

void Mesh::unBindVbo(int index)
{
    vbo[index].release();
}

void Mesh::load(const QString& path)
{
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error opening file\n";
    }

    QTextStream stream(&file);

    QVector<QVector3D> vertices;
    QVector<QVector3D> normals;
    QVector<QVector2D> textures;

    while(!stream.atEnd())
    {
        QString line = stream.readLine();

        if(line.contains("v "))
        {
            QStringList list = line.remove("v ").split(" ");
            vertices.push_back(QVector3D(list[0].toFloat(),
                                         list[1].toFloat(),
                                         list[2].toFloat()));
        }
        if(line.contains("vt "))
        {
            QStringList list = line.remove("vt ").split(" ");
            textures.push_back(QVector2D(list[0].toFloat(),
                                         list[1].toFloat()));
        }
        if(line.contains("vn "))
        {
            QStringList list = line.remove("vn ").split(" ");
            normals.push_back(QVector3D(list[0].toFloat(),
                                        list[1].toFloat(),
                                        list[2].toFloat()));
        }
        if(line.contains("f "))
        {
            QStringList list = line.remove("f ").split(" ");
            if(list.size() == 3)
            {
                for(auto it : list)
                {
                    QStringList point = it.split("/");
                    if(point.size() == 1)
                    {
                        mVertices.push_back(vertices[point[0].toInt() - 1].x());
                        mVertices.push_back(vertices[point[0].toInt() - 1].y());
                        mVertices.push_back(vertices[point[0].toInt() - 1].z());
                    }
                    if(point.size() == 2)
                    {
                        mVertices.push_back(vertices[point[0].toInt() - 1].x());
                        mVertices.push_back(vertices[point[0].toInt() - 1].y());
                        mVertices.push_back(vertices[point[0].toInt() - 1].z());

                        mTextures.push_back(textures[point[1].toInt() - 1].x());
                        mTextures.push_back(textures[point[1].toInt() - 1].y());
                    }
                    if(point.size() == 3)
                    {
                        mVertices.push_back(vertices[point[0].toInt() - 1].x());
                        mVertices.push_back(vertices[point[0].toInt() - 1].y());
                        mVertices.push_back(vertices[point[0].toInt() - 1].z());

                        mTextures.push_back(textures[point[1].toInt() - 1].x());
                        mTextures.push_back(textures[point[1].toInt() - 1].y());

                        mNormals.push_back(normals[point[2].toInt() - 1].x());
                        mNormals.push_back(normals[point[2].toInt() - 1].y());
                        mNormals.push_back(normals[point[2].toInt() - 1].z());
                    }
                }
            }
        }
    }
}
