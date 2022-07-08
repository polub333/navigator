#include "scene.h"

Scene::Scene()
{
    addRect(10, 10, 100, 100, QPen(Qt::NoPen), QBrush(Qt::red));
    addRect(0, 0, 10, 10, QPen(Qt::NoPen), QBrush(Qt::blue));
    addLine(0, 500, 1000, 500, QPen(Qt::black));
    addLine(500, 0, 500, 1000, QPen(Qt::black));
    sceneCenterPosition = QPointF(0, 0);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    qDebug()<<event->scenePos().x()<<" "<<event->scenePos().y();

    if(event->buttons() == Qt::LeftButton){
        qDebug()<<"LEFT BUTTON DROP";

        QPointF offset = event->scenePos() - previousMousePosition;
        QVector2D offsetVector(offset);
        if(offsetVector.lengthSquared() < 100){
            return;
        }
        //QPointF offset = event->scenePos();
        emit changeSceneViewCenter(offset);
        sceneCenterPosition += offset;
    }

    previousMousePosition = event->scenePos();
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    qDebug()<<"Press"<<event->scenePos().x()<<" "<<event->scenePos().y();
}
