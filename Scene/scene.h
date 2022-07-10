#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QWheelEvent>
#include <QDebug>
#include <QVector2D>
#include <QGraphicsTextItem>


#include <QSize>

#include <Engine/node.h>
#include <Engine/pathtype.h>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene();
    void drawNode(std::shared_ptr<Node> node);
    void drawPath(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2, PathType type);

private:

private slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
signals:
};



#endif // SCENE_H
