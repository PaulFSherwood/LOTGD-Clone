#ifndef KEYEVENTFILTER_H
#define KEYEVENTFILTER_H

#include <QObject>
#include <QEvent>
#include <QKeyEvent>

class KeyEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit KeyEventFilter(QObject *parent = nullptr);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:
    void keyPressed(int key);
};

#endif // KEYEVENTFILTER_H
