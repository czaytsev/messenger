#ifndef MESSENGERWINDOWVIEW_H
#define MESSENGERWINDOWVIEW_H

#include "model/client.h"
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QMainWindow>

/**
 * The MessengerWindowView class is a subclass of QMainWindow
 */
class MessengerWindowView : public QMainWindow
{
    Q_OBJECT

public:
    MessengerWindowView(Client * client);
    virtual ~MessengerWindowView();
private:
    // Copy the value of client * to this attribute
    Client * client_;
    QWidget * messenger_;
    QVBoxLayout *layout_;
    QTextEdit *editor_;
    QPushButton *submit_;

public slots:
    void grabTextAndSend();
};

#endif // MESSENGERWINDOWVIEW_H
