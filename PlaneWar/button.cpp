#include "button.h"

Button::Button()
{
    //初始化图标素材
    myPause.load(PAUSEPATH);
    myStart.load(STARTPATH);
    myResume.load(RESUMEPATH);
    myQuit.load(QUITPATH);
    //初始化按键位置
    //开始按键位于屏幕正中间
    start_x=1/2*GAME_WIDTH-myStart.width();
    start_y=1/2*GAME_HEIGHT-myStart.height();
    //暂停按键位于屏幕右上角
    pause_x=GAME_WIDTH-myPause.width();
    pause_y=myPause.height();
    //继续游戏按键位于屏幕正中间
    resume_x=1/2*GAME_WIDTH-myStart.width();
    resume_y=1/2*GAME_HEIGHT-myStart.height();
    //退出游戏按键位于继续游戏按键下方
    quit_x=1/2*GAME_WIDTH-myStart.width();
    quit_y=resume_y+2*myResume.height();
    //设置矩形边框大小
    pause_rect.setWidth(myPause.width());
    pause_rect.setHeight(myPause.height());
    start_rect.setWidth(myStart.width());
    start_rect.setHeight(myStart.height());
    resume_rect.setWidth(myResume.width());
    resume_rect.setHeight(myResume.height());
    quit_rect.setWidth(myQuit.width());
    quit_rect.setHeight(myQuit.height());

}
