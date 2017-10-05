TEMPLATE = app
TARGET = messenger

QT = core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    model/message.cpp \
    model/user.cpp \
    model/client.cpp \
    model/server.cpp \
    view/messengerwindowview.cpp

HEADERS += \
    model/message.h \
    model/user.h \
    model/client.h \
    model/server.h \
    view/messengerwindowview.h \
    view/messengerwindowview.h
