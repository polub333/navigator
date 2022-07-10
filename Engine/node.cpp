#include "node.h"

Node::Node()
{

}

void Node::setName(QString _name)
{
    name = _name;
}

void Node::setId(int _id)
{
    id = _id;
}

void Node::setPosition(QPointF _position)
{
    position = _position;
}
void Node::setPosition(qreal x, qreal y)
{
    position = QPointF(x, y);
}

QString Node::getName() const
{
    return name;
}

int Node::getId() const
{
    return id;
}

QPointF Node::getPosition() const
{
    return position;
}
