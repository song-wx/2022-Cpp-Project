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
    airplane.cpp \
    bomb.cpp \
    bullet.cpp \
    enemyplane.cpp \
    enemyplane2.cpp \
    enemyplane3.cpp \
    main.cpp \
    mainscene.cpp \
    map.cpp \
    mybutton.cpp

HEADERS += \
    airplane.h \
    bomb.h \
    bullet.h \
    config.h \
    enemyplane.h \
    enemyplane2.h \
    enemyplane3.h \
    mainscene.h \
    map.h \
    mybutton.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    pic_res/素材/微信打飞机图片素材-英雄爆破 n3(hero_blowup__爱给网_aigei_com.png \
    pic_res/素材/微信打飞机图片素材-退出 sel(quit_sel)_爱给网_aigei_com.png \
    pic_res/素材/微信打飞机图片素材-重新启动 sel(restart_sel_爱给网_aigei_com.png
