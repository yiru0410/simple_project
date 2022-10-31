QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account_create.cpp \
    account_info.cpp \
    bottle.cpp \
    bottlequestion.cpp \
    bottlesender.cpp \
    filesys.cpp \
    floatpan.cpp \
    friends.cpp \
    gv.cpp \
    logindlg.cpp \
    main.cpp \
    mainwindow.cpp \
    myquestion.cpp \
    selflearning.cpp \
    users.cpp

HEADERS += \
    account_create.h \
    account_info.h \
    bottle.h \
    bottlequestion.h \
    bottlesender.h \
    filesys.h \
    floatpan.h \
    friends.h \
    gv.h \
    logindlg.h \
    mainwindow.h \
    myquestion.h \
    selflearning.h \
    users.h

FORMS += \
    account_create.ui \
    account_info.ui \
    bottle.ui \
    bottlequestion.ui \
    bottlesender.ui \
    filesys.ui \
    floatpan.ui \
    friends.ui \
    logindlg.ui \
    mainwindow.ui \
    myquestion.ui \
    selflearning.ui \
    users.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
