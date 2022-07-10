#include "engine.h"

Engine::Engine()
{
    idCounter = 0;
}

void Engine::setScene(Scene* _scene)
{
    scene = _scene;
}

void Engine::createNode(QString name, qreal x, qreal y)
{
    std::shared_ptr<Node> node = std::make_shared<Node>();
    node->setName(name);
    node->setPosition(x, y);
    node->setId(idCounter);
    nodes.push_back(node);
    ++idCounter;

}

void Engine::createPath(int id1, int id2, PathType type)
{
    std::shared_ptr<Node> node1 = findNodeById(id1);
    std::shared_ptr<Node> node2 = findNodeById(id2);
    std::shared_ptr<Path> path = std::make_shared<Path>();
    path->setNode1(node1);
    path->setNode2(node2);
    path->setPathType(type);
    paths.push_back(path);
}

void Engine::draw()
{
    for(auto it = nodes.begin(); it != nodes.end(); ++it){
        scene->drawNode(*it);
    }
    for(auto it = paths.begin(); it != paths.end(); ++it){
        auto node1 = (*it)->getNode1();
        auto node2 = (*it)->getNode2();


        scene->drawPath(node1, node2, (*it)->getPathType());
    }
}

std::shared_ptr<Node> Engine::findNodeById(int id)
{
    for(auto it = nodes.begin(); it != nodes.end(); ++it){
        if((*it)->getId() == id){
            return (*it);
        }
    }
    return nullptr;
}
