#pragma once

#include <QListWidgetItem>

class ListItem : public QListWidgetItem
{
private:
    int id;
public:
    ListItem() {}

    int getId()
    {
        return id;
    }

    void setId(const int id)
    {
        this->id = id;
    }
};
