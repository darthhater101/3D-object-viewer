#pragma once

#include "object.h"

#include <QString>

class Model : public Object
{
public:
    Model(QVector3D pos, float scale, const QString& meshPath, const QString& shaderPath);
};

