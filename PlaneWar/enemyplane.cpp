#include "enemyplane.h"

Enemyplane::Enemyplane()
{
    //敌机图片加载
     enemy.load(ENEMYPLANEPATH1);
     bomb[0].bomb.load(BOMBPATH1_2);
     //敌机位置
     x=0;
     y=0;
     //敌机状态
     free=true;
     //敌机速度
     speed=ENEMY_SPEED;
     //敌机碰撞矩形
     Rect.setWidth(enemy.width());
     Rect.setHeight(enemy.height());
     Rect.moveTo(x,y);


}

void Enemyplane::setInfo(){

    //更新爆炸信息
    for(int i=0;i<BOMB_NUM;i++){
        bomb[i].setInfo();
        //爆炸图片跟随向下移动
        bomb[i].y+=speed;
    }
    //若空闲则不计算坐标
    if(free)return;
    //敌机向下移动
    y+=speed;
    Rect.moveTo(x,y);
    //越界检测
    if(y>=GAME_HEIGHT+Rect.height())free=true;


}
