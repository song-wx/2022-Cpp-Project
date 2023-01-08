#ifndef AIRPLANE_H
#define AIRPLANE_H
#include<QPixmap>
#include"config.h"
#include"bullet.h"

class Airplane
{
public:
    Airplane();

    void fire();//发射子弹
    void setposition(int ,int );//设置位置
    QPixmap plane;//飞机图片
    int x;
    int y;//飞机坐标
    QRect Rect;//用于碰撞检验的飞机矩形边框
    Bullet mybullet[BULLET_NUM];//飞机弹匣
    int recorder;//发射间隔记录

};

#endif // AIRPLANE_H
