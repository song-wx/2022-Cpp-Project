#ifndef BOMB_H
#define BOMB_H
#include"config.h"
#include<QPixmap>


class Bomb
{
public:
    Bomb();
    //设置爆炸信息（爆炸图片，播放间隔）
    void setInfo();
    //爆炸资源
    QPixmap bomb;
    //爆炸位置
    int x;
    int y;
    //爆炸状态
    bool free;
    //爆炸显示时长
    int bomb_recorder;
};

#endif // BOMB_H
