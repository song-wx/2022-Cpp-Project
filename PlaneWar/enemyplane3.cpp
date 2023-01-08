#include "enemyplane3.h"

Enemyplane3::Enemyplane3()
{
    //导入敌机图片
    enemy.load(ENEMYPLANEPATH3);
    //导入两种爆炸图片
    bomb[0].bomb.load(BOMBPATH3_1);
    bomb[1].bomb.load(BOMBPATH3_2);
    bomb[2].bomb.load(BOMBPATH3_3);
    //导入飞机被击中图片
    enemy_hit = ENEMYPLANEPATH3_HIT;
    //重新设置子弹图片
    for(int i=0;i<BULLET_NUM;i++){
        bullet1[i].mybullet.load(BULLET3);
        bullet2[i].mybullet.load(BULLET3);
    }
    //敌机位置
    x=-1000;
    y=-1000;
    //敌机状态
    free=true;
    //敌机速度
    speed=ENEMY3_SPEED;
    //敌机碰撞矩形
    Rect.setWidth(enemy.width());
    Rect.setHeight(enemy.height());
    Rect.moveTo(x,y);
}

void Enemyplane3::fire(){
    //若飞机空闲则不发射子弹
    if(free)return;
    //时间记录器加一
    recorder++;
    //若记录器未满一个发射间隔则直接返回，不发射子弹
    if(recorder<BULLET3_INTERVAL)return;
    recorder=0;
    //搜索空闲子弹发射
    for(int i=0;i<BULLET_NUM;i++)
    {
        //若子弹空闲则发射子弹
        if(bullet1[i].free)
        {
            //将发射的子弹状态置为忙碌
            bullet1[i].free=false;
            //子弹从飞机正下方偏左发射
            bullet1[i].x=x+Rect.width()*0.5-10;
            bullet1[i].y=y+Rect.height()+5;
            break;//发射一枚子弹后即停止空闲子弹的搜索
        }
    }

    for(int i=0;i<BULLET_NUM;i++)
    {
        //若子弹空闲则发射子弹
        if(bullet2[i].free)
        {
            //将发射的子弹状态置为忙碌
            bullet2[i].free=false;
            //子弹从飞机正下方偏右发射
            bullet2[i].x=x+Rect.width()*0.5;
            bullet2[i].y=y+Rect.height()+5;
            break;//发射一枚子弹后即停止空闲子弹的搜索
        }
    }

}
