#include "path.h"

Path::Path()
{

}

void Path::setNode1(std::shared_ptr<Node> node)
{
    node1 = node;
}

void Path::setNode2(std::shared_ptr<Node> node)
{
    node2 = node;
}

void Path::setPathType(PathType _type)
{
    type = _type;
}

std::shared_ptr<Node> Path::getNode1() const
{
    return node1;
}

std::shared_ptr<Node> Path::getNode2() const
{
    return node2;
}

PathType Path::getPathType() const
{
    return type;
}
