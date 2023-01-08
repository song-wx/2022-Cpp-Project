#ifndef ENEMYPLANE2_H
#define ENEMYPLANE2_H
#include "enemyplane.h"

class Enemyplane2:public Enemyplane
{
public:
    Enemyplane2();
    void fire();
    //受伤的敌机
    QString enemy_hit;
    //弹夹
    Bullet bullet[BULLET_NUM];
    //中弹次数
    int count_hit=0;
};

#endif // ENEMYPLANE2_H
