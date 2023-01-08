#ifndef BUTTON_H
#define BUTTON_H
#include<QPixmap>
#include<config.h>

class Button
{
public:
    Button();
    QPixmap myStart;//开始游戏
    QPixmap myPause;//暂停游戏
    QPixmap myResume;//继续游戏
    QPixmap myQuit;//退出游戏
    //开始游戏图标坐标
    int start_x;
    int start_y;
    //暂停游戏图标坐标
    int pause_x;
    int pause_y;
    //继续游戏图标坐标
    int resume_y;
    int resume_x;
    //退出游戏图标坐标
    int quit_x;
    int quit_y;
    //图标矩形检测边框
    QRect start_rect;
    QRect pause_rect;
    QRect resume_rect;
    QRect quit_rect;


};

#endif // BUTTON_H
