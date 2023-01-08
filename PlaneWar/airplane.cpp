#include "airplane.h"
#include"config.h"
Airplane::Airplane()
{
     //加载飞机图片
     plane.load(PLANEPATH);
     //调整飞机大小
     plane=plane.scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
     //飞机坐标初始化
     x=0.5*GAME_WIDTH-0.5*plane.width();
     y=GAME_HEIGHT-2*plane.height();
     //设置飞机矩形边框
     Rect.setWidth(plane.width());
     Rect.setHeight(plane.height());
}
void Airplane::setposition(int m,int n){
    int x=m;
    int y=n;
    //矩形边框跟随飞机移动
    Rect.moveTo(x,y);
    this->x=x;
    this->y=y;
}
void Airplane::fire(){
    //时间记录器加一
    recorder++;
    //若记录器未满一个发射间隔则直接返回，不发射子弹
    if(recorder<BULLET_INTERVAL)return;
    recorder=0;
    //搜索空闲子弹发射
    for(int i=0;i<BULLET_NUM;i++)
    {
        //若子弹空闲则发射子弹
        if(mybullet[i].free)
        {
            //将发射的子弹状态置为忙碌
            mybullet[i].free=false;
            //子弹从飞机正上方发射
            mybullet[i].x=x+Rect.width()*0.5-5;
            mybullet[i].y=y-Rect.height()*0.5+5;
            break;//发射一枚子弹后即停止空闲子弹的搜索
        }
    }
}
