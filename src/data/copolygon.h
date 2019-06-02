#ifndef COPOLYGON_H
#define COPOLYGON_H

#include <QObject>

class CoPolygon : public QObject
{
    Q_OBJECT
public:
    explicit CoPolygon(QObject *parent = nullptr);
    ~CoPolygon();
};

#endif // COPOLYGON_H
