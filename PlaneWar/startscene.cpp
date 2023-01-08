#include "startscene.h"

StartScene::StartScene(QWidget *parent) : QWidget(parent)
{
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_LOGO));
    //设置初始界面
    Mybutton * btn_start=new Mybutton(STARTPATH);
    Mybutton * btn_quit=new Mybutton(QUITPATH);
    //绑定父类
    btn_start->setParent(this);
    btn_quit->setParent(this);
    //移动位置
    btn_start->move((GAME_WIDTH-btn_start->width())/2,(GAME_HEIGHT-btn_start->height())/2);
    btn_quit->move((GAME_WIDTH-btn_quit->width())/2,(GAME_HEIGHT+4*btn_quit->height())/2);
    //监听退出按钮
    connect(btn_quit,&QPushButton::clicked,[=](){
        btn_quit->zoom1();
        btn_quit->zoom2();
        //延时0.3s后退出游戏
        QTimer::singleShot(300,this,[=](){
            this->close();
        });

    });
    //监听启动按钮
    connect(btn_start,&QPushButton::clicked,[=](){
        btn_start->zoom1();
        btn_start->zoom2();
        //开始游戏
        this->hide();
        //进入到游戏界面
        mymainscene.show();
        mymainscene.playGame();
    });


}
void MainScene::paintEvent(QPaintEvent*){
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,map.map1_posY,map.map1);
    painter.drawPixmap(0,map.map2_posY,map.map2);
    //绘制飞机
    painter.drawPixmap(myplane.x,myplane.y,myplane.plane);

}
