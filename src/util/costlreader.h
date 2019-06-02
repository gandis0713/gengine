#ifndef COSTLREADER_H
#define COSTLREADER_H

#include <QObject>

class CoSTLReader : public QObject
{
    Q_OBJECT
public:
    explicit CoSTLReader(QObject *parent = nullptr);

signals:

public slots:
};

#endif // COSTLREADER_H