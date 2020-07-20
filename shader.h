#pragma once

#include <QOpenGLShader>
#include <QOpenGLShaderProgram>

class Shader
{
private:
    QOpenGLShaderProgram program;
public:
    Shader(const QString &fileName);
    ~Shader() {};

    void use();
    void unbind();
    void enableAttributeArray(int location);
    void setAttributeBuffer(int location, int count);
    void disableAttributeArray(int location);
    void setMat4x4(const char* name, QMatrix4x4 &value);
};

