#include "bullet.h"

Bullet::Bullet()
{
   //初始化子弹图片
   mybullet.load(BULLET1);
   //随意初始化子弹初始位置
   x=-100;
   y=-100;
   //初始化子弹状态为闲置
   free=true;
   //设置子弹速度
   speed=BULLET_SPEED;
   //设置子弹矩形框
   Rect.setWidth(mybullet.width());
   Rect.setHeight(mybullet.height());
   //子弹边框跟随子弹移动
   Rect.moveTo(x,y);
}

void Bullet::setPosition()
{
    //若子弹闲置则直接返回，坐标无需处理
    if(free)return;
    //子弹向上移动
    y-=speed;
    //子弹边框跟随移动
    Rect.moveTo(x,y);
    //若子弹越界则将子弹置为闲置
    if(y<-2*mybullet.height())free=true;
}

void Bullet::setPosition2()
{
    //若子弹闲置则直接返回，坐标无需处理
    if(free)return;
    //子弹向下移动
    y+=speed;
    //子弹边框跟随移动
    Rect.moveTo(x,y);
    //若子弹越界则将子弹置为闲置
    if(y>GAME_HEIGHT+2*mybullet.width()||y<-2*mybullet.height())free=true;
}

void Bullet::setPosition3_1()
{
    //若子弹闲置则直接返回，坐标无需处理
    if(free)return;
    //子弹向下移动
    y+=speed;
    //若子弹到达左边界则左标记为真,右标记为假
    if(x<0){
        mark1=true;
        mark2=false;
    }
    //若子弹到达右边界则右标记为真，左标记为假
    if(x>GAME_WIDTH){
        mark2=true;
        mark1=false;
    }

    if(mark1==false&&mark2==false)
    //初始子弹向左移动
        x-=speed;
    else if(mark1==true&&mark2==false)
        x+=speed;
    else if(mark1==false&&mark2==true)
        x-=speed;


    //子弹边框跟随移动
    Rect.moveTo(x,y);
    //若子弹越下界则将子弹置为闲置,左右状态重置
    if(y>GAME_HEIGHT+2*mybullet.width()){
        free=true;
        mark1=false;
        mark2=false;
    }
}

void Bullet::setPosition3_2()
{
    //若子弹闲置则直接返回，坐标无需处理
    if(free)return;
    //子弹向下移动
    y+=speed;
    //若子弹到达左边界则左标记为真,右标记为假
    if(x<0){
        mark1=true;
        mark2=false;
    }
    //若子弹到达右边界则右标记为真，左标记为假
    if(x>GAME_WIDTH){
        mark2=true;
        mark1=false;
    }

    if(mark1==false&&mark2==false)
    //初始子弹向右移动
        x+=speed;
    else if(mark1==false&&mark2==true)
        x-=speed;
    else if(mark1==true&&mark2==false)
        x+=speed;

    //子弹边框跟随移动
    Rect.moveTo(x,y);
    //若子弹越下界则将子弹置为闲置,左右状态重置
    if(y>GAME_HEIGHT+2*mybullet.width()){
        free=true;
        mark1=false;
        mark2=false;
    }
}
