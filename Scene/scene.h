#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QVector2D>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene();
private:
    QPointF previousMousePosition;
    QPointF sceneCenterPosition;
private slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
signals:
    void changeSceneViewCenter(QPointF offset);
};

#endif // SCENE_H
