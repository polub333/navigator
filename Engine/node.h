#ifndef NODE_H
#define NODE_H

#include <QString>
#include <QPointF>

class Node
{
public:
    Node();

    void setName(QString _name);
    void setId(int _id);
    void setPosition(QPointF _position);
    void setPosition(qreal x, qreal y);

    QString getName() const;
    int getId() const;
    QPointF getPosition() const;
private:
    QString name;
    int id;

    QPointF position;

};

#endif // NODE_H
