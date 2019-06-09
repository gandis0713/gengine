#ifndef COPOINT_H
#define COPOINT_H

#include <QObject>

class CoPoint : public QObject
{
    Q_OBJECT
public:
    explicit CoPoint(QObject *parent = nullptr);
    ~CoPoint();
};

#endif // COPOINT_H
