#ifndef BULLET_H
#define BULLET_H
#include "config.h"
#include<QPixmap>

class Bullet
{
public:
    Bullet();
    //更新子弹坐标
    void setPosition();//发射方式向上
    void setPosition2();//发射方式向下
    void setPosition3_1();//发射方式向左下散射
    void setPosition3_2();//发射方式向右下散射
    //子弹图片
    QPixmap mybullet;
    //子弹坐标
    int x;
    int y;
    //子弹移动速度
    float speed;
    //子弹是否可用
    bool free;
    //检测子弹是否到达左边界
    bool mark1=false;
    //检测子弹是否到达右边界
    bool mark2=false;
    //用于碰撞检验的子弹矩形边框
    QRect Rect;

};

#endif // BULLET_H
