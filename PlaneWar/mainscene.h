#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include <QPaintEvent>
#include <QPainter>
#include <QLabel>
#include <QFontDatabase>
#include "map.h"
#include "airplane.h"
#include "airplane.h"
#include "bullet.h"
#include "enemyplane.h"
#include "enemyplane2.h"
#include "enemyplane3.h"
#include "bomb.h"
#include "playgamescene.h"
#include "mybutton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    void initScene();
    ~MainScene();
    void playGame();//开始游戏，用于启动定时器
    void restart();//重新开始游戏
    void gameover();//游戏结束
    void updatePosition();//更新位置信息
    void paintEvent(QPaintEvent *);//绘图事件
    void mouseMoveEvent(QMouseEvent *);//鼠标控制移动
    void enemyToScene();//敌机出场
    void collision_detcion();//碰撞检测

private:
    bool gameStart;//游戏状态
    bool isgameover=false;//游戏是否结束
    Mybutton * btn_start;//按钮控件
    Mybutton * btn_quit;
    Mybutton * btn_pause;
    Mybutton * btn_resume;
    Mybutton * btn_restart;
    Mybutton * btn_test;//点击开启无敌版
    bool isinvincible;//判断是否开启无敌无敌
    Map map;//背景成员
    QTimer mytimer;//定时器成员
    QLabel scoreboard;//记分牌
    int score=0;//分数
    Ui::MainScene *ui;
    Airplane myplane;//飞机成员
    Enemyplane myenemy[ENEMY_NUM];//敌机成员数组
    Enemyplane2 myenemy2[ENEMY_NUM];//敌机2成员数组
    Enemyplane3 myenemy3;//敌机3
    int enemy1_recorder=0;//记录敌机1出场间隔
    int enemy2_recorder=0;//记录敌机2出场间隔
    int enemy3_recorder=0;//记录敌机3出场间隔
    //int i;timer debug
};
#endif // MAINSCENE_H
