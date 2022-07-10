#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <memory>

#include <Scene/scene.h>
#include <Engine/node.h>
#include <Engine/path.h>
#include <Engine/pathtype.h>

class Engine
{
public:
    Engine();
    void setScene(Scene* _scene);

    void createNode(QString name, qreal x, qreal y);
    void createPath(int id1, int id2, PathType type);

    void draw();

private:
    Scene* scene;
    std::vector<std::shared_ptr<Node>> nodes;
    std::vector<std::shared_ptr<Path>> paths;
    int idCounter;

    std::shared_ptr<Node> findNodeById(int id);
};

#endif // ENGINE_H
