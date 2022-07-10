#include "scene.h"

Scene::Scene()
{
    addRect(10, 10, 100, 100, QPen(Qt::NoPen), QBrush(Qt::red));
    addRect(0, 0, 10, 10, QPen(Qt::NoPen), QBrush(Qt::blue));
    addLine(0, 500, 1000, 500, QPen(Qt::black));
    addLine(500, 0, 500, 1000, QPen(Qt::black));
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{

}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{

}

void Scene::drawNode(std::shared_ptr<Node> node)
{
    const int r = 5;
    addEllipse(node->getPosition().x() - r, node->getPosition().y() - r, 2*r, 2*r,
               QPen(Qt::NoPen), QBrush(Qt::red));
    QGraphicsTextItem* text = new QGraphicsTextItem();
    text->setPos(node->getPosition().x(), node->getPosition().y());
    text->setPlainText(node->getName());
    addItem(text);

}

void Scene::drawPath(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2, PathType type)
{
    QPen pen;
    pen.setCapStyle(Qt::RoundCap);
    if(type == highway){
        pen.setColor(Qt::black);
        pen.setWidth(5);
    }
    if(type == road){
        pen.setColor(Qt::black);
        pen.setWidth(2);
    }
    if(type == gravel){
        pen.setColor(Qt::yellow);
        pen.setWidth(2);
    }
    if(type == railway){
        pen.setColor(Qt::gray);
        pen.setWidth(3);
        pen.setStyle(Qt::DashLine);
    }
    addLine(node1->getPosition().x(), node1->getPosition().y(),
            node2->getPosition().x(), node2->getPosition().y(), pen);
}
