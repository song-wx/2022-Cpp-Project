#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QWidget>
#include"config.h"
#include"mainscene.h"
#include <QIcon>
#include <QPixmap>
#include<QPushButton>

class StartScene : public QWidget
{
    Q_OBJECT
public:
    explicit StartScene(QWidget *parent = nullptr);
    MainScene mymainscene;
    void paintEvent(QPaintEvent *);
    Map map;//背景成员
    Airplane myplane;//飞机成员

signals:


};

#endif // STARTSCENE_H
