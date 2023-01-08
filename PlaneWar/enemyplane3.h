#ifndef ENEMYPLANE3_H
#define ENEMYPLANE3_H
#include "enemyplane2.h"

class Enemyplane3:public Enemyplane
{
public:
    Enemyplane3();
    void fire();
    //受伤的敌机
    QString enemy_hit;
    //弹夹1向左发射
    Bullet bullet1[BULLET_NUM];
    //弹夹2向右发射
    Bullet bullet2[BULLET_NUM];

    //中弹次数
    int count_hit=0;
};

#endif // ENEMYPLANE3_H
