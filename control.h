#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>

class Control : public QObject
{
    Q_OBJECT
public:
    explicit Control(QObject *parent = nullptr);

signals:

private slots:
    void removeBomb();


};

#endif // CONTROL_H
