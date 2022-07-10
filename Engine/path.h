#ifndef PATH_H
#define PATH_H

#include <memory>

#include <Engine/node.h>
#include <Engine/pathtype.h>

class Path
{
public:
    Path();

    void setNode1(std::shared_ptr<Node> node);
    void setNode2(std::shared_ptr<Node> node);
    void setPathType(PathType _type);

    std::shared_ptr<Node> getNode1() const;
    std::shared_ptr<Node> getNode2() const;
    PathType getPathType() const;

    qreal getLength();
    qreal computeTime();

private:
    std::shared_ptr<Node> node1;
    std::shared_ptr<Node> node2;
    PathType type;
};

#endif // PATH_H
