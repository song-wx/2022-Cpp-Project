#include "enemyplane2.h"

Enemyplane2::Enemyplane2()
{
    //导入敌机图片
    enemy.load(ENEMYPLANEPATH2);
    //导入两种爆炸图片
    bomb[0].bomb.load(BOMBPATH2_1);
    bomb[1].bomb.load(BOMBPATH2_2);
    //导入飞机被击中图片
    enemy_hit = ENEMYPLANEPATH2_HIT;
    //重新设置子弹图片
    for(int i=0;i<BULLET_NUM;i++)bullet[i].mybullet.load(BULLET2);
    //敌机位置
    x=-100;
    y=-100;
    //敌机状态
    free=true;
    //敌机速度
    speed=ENEMY2_SPEED;
    //敌机碰撞矩形
    Rect.setWidth(enemy.width());
    Rect.setHeight(enemy.height());
    Rect.moveTo(x,y);

}

void Enemyplane2::fire(){
    //若飞机空闲则不发射子弹
    if(free)return;
    //时间记录器加一
    recorder++;
    //若记录器未满一个发射间隔则直接返回，不发射子弹
    if(recorder<BULLET2_INTERVAL)return;
    recorder=0;
    //搜索空闲子弹发射
    for(int i=0;i<BULLET_NUM;i++)
    {
        //若子弹空闲且敌机占用则发射子弹
        if(bullet[i].free&&this->free==false)
        {
            //将发射的子弹状态置为忙碌
            bullet[i].free=false;
            //子弹从飞机正下方发射
            bullet[i].x=x+Rect.width()*0.5-5;
            bullet[i].y=y+Rect.height()*0.5+10;
            break;//发射一枚子弹后即停止空闲子弹的搜索
        }
    }

}
