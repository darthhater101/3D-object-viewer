#include "shader.h"

Shader::Shader(const QString &fileName)
{
    QOpenGLShader vertex(QOpenGLShader::Vertex);
    QOpenGLShader fragment(QOpenGLShader::Fragment);

    if(vertex.compileSourceFile(fileName + ".vert"))
    {
        program.addShader(&vertex);
    }
    else
    {
        qDebug() << "Vertex shader error\n" << vertex.log();
    }
    if(fragment.compileSourceFile(fileName + ".frag"))
    {
        program.addShader(&fragment);
    }
    else
    {
        qDebug() << "Fragment shader error\n" << fragment.log();
    }

    if(!program.link())
    {
        qDebug() << "Program linking error\n";
    }
}

void Shader::use()
{
    program.bind();
}

void Shader::unbind()
{
    program.release();
}

void Shader::enableAttributeArray(int location)
{
    program.enableAttributeArray(location);
}

void Shader::setAttributeBuffer(int location, int count)
{
    program.setAttributeBuffer(location, GL_FLOAT, 0, count, 0);
}

void Shader::disableAttributeArray(int location)
{
    program.disableAttributeArray(location);
}

void Shader::setMat4x4(const char *name, QMatrix4x4 &value)
{
    program.setUniformValue(name, value);
}

void Shader::setVec3(const char *name, QVector3D &value)
{
    program.setUniformValue(name, value);
}
