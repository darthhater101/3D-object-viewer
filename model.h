#ifndef MODEL_H
#define MODEL_H

#include "object.h"

#include <QString>

class Model : public Object
{
public:
    Model(const QString& meshPath, const QString& shaderPath);
};

#endif // MODEL_H
