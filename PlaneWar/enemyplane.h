#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include <QPixmap>
#include "config.h"
#include "bomb.h"
#include "bullet.h"

class Enemyplane
{
public:
    Enemyplane();
    //设置信息
    void setInfo();
    //敌机图像
    QPixmap enemy;
    //爆炸成员数组
    Bomb bomb[BOMB_NUM];
    //发射间隔记录
    int recorder;
    //坐标
    int x;
    int y;
    //敌机矩形边框
    QRect Rect;
    //状态
    bool free;
    //速度
    float speed;


};

#endif // ENEMYPLANE_H
