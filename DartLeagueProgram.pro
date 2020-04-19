QT += core \
    quick \
    gui \
    charts \
    sql


CONFIG += c++11
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RC_ICONS = logo.ico

SOURCES += \
datahandler.cpp \
    editthrowsmenu.cpp \
    gameaddeditmenu.cpp \
    gamereviewmenu.cpp \
    main.cpp \
    managechoicemenu.cpp \
    managegamemenu.cpp \
    manageplayermenu.cpp \
    matchstartdata.cpp \
    mathclass.cpp \
    player.cpp \
    playeraddeditmenu.cpp \
    sqlhandler.cpp \
    startupmenu.cpp \
    audienceview.cpp \
    scorerview.cpp \
    widget.cpp \
    gameselectionmenu.cpp

INSTALLS += target

FORMS += \
    editthrowsmenu.ui \
    gameaddeditmenu.ui \
    gamereviewmenu.ui \
    managechoicemenu.ui \
    managegamemenu.ui \
    manageplayermenu.ui \
    playeraddeditmenu.ui \
    startupmenu.ui \
    audienceview.ui \
    scorerview.ui \
    gameselectionmenu.ui

HEADERS += \
datahandler.h \
    editthrowsmenu.h \
    gameaddeditmenu.h \
    gamereviewmenu.h \
    managechoicemenu.h \
    managegamemenu.h \
    manageplayermenu.h \
    matchstartdata.h \
    mathclass.h \
    player.h \
    playeraddeditmenu.h \
    sqlhandler.h \
    startupmenu.h \
    audienceview.h \
    scorerview.h \
    widget.h \
    gameselectionmenu.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    DartLeague.db
