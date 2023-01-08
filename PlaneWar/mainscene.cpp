#include "mainscene.h"
#include "config.h"
#include<QIcon>
#include<QPushButton>
#include<QTimer>
#include<ctime>//头文件得到当前时间
#include<QDebug>

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    initScene();

}

MainScene::~MainScene()
{
}

void MainScene::initScene(){
    //尚未开始游戏
    gameStart=false;
    //设置界面长宽、图标
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_LOGO));
    //导入所需字体
    int fontId = QFontDatabase::addApplicationFont(TYPEOFTEXT);
    if (fontId == -1) {
        qDebug("load font failed!");
    }
    //获取字体名称
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    if (fontName == nullptr)return;

    //添加随机数种子
    srand((unsigned int)time(NULL));
    //设置初始界面
      btn_start  =new Mybutton(STARTPATH);
      btn_quit   =new Mybutton(QUITPATH);
      btn_pause  =new Mybutton(PAUSEPATH);
      btn_resume =new Mybutton(RESUMEPATH);
      btn_restart=new Mybutton(RESTARTPATH);
      btn_test   =new Mybutton;//新建一个开启无敌版的按钮
    //按键绑定主屏幕父类
    btn_start->setParent(this);
    btn_quit->setParent(this);
    btn_pause->setParent(this);
    btn_resume->setParent(this);
    btn_restart->setParent(this);
    btn_test->setParent(this);
    //记分牌绑定主屏幕父类并设置记分牌的基本属性
    scoreboard.setParent(this);
    scoreboard.setGeometry(GAME_WIDTH-150,20,200,50);//记分牌长宽及位置
    QFont myfont;
    myfont.setFamily(fontName);//设置字体
    myfont.setPointSize(20);//设置字号
    scoreboard.setFont(myfont);
    //设置无敌版按钮的基本属性
    btn_test->setGeometry(GAME_WIDTH-100,GAME_HEIGHT-70,100,100);
    btn_test->setText(QString("开启无敌版"));
    btn_test->setFont(fontName);
    btn_test->setStyleSheet("background-color:transparent;font-size:20px");

    //隐藏开始界面不需要的按钮
    btn_pause->hide();
    btn_resume->hide();
    btn_restart->hide();

    //移动位置
    btn_start->move((GAME_WIDTH-btn_start->width())/2,(GAME_HEIGHT-btn_start->height())/2);
    btn_quit->move((GAME_WIDTH-btn_quit->width())/2,(GAME_HEIGHT+8*btn_quit->height())/2);
    btn_pause->move(btn_pause->width()/2,btn_pause->height()/2);
    btn_resume->move((GAME_WIDTH-btn_resume->width())/2,(GAME_HEIGHT-btn_resume->height())/2);
    btn_restart->move((GAME_WIDTH-btn_restart->width())/2,(GAME_HEIGHT+2.8*btn_restart->height())/2);
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
        gameStart=true;
        //延时0.3s后进入到游戏界面

        QTimer::singleShot(300,this,[=](){
            //开始与退出键消失
            btn_start->hide();
            btn_quit->hide();
            playGame();
            //暂停键出现
            btn_pause->show();
        });


    });
    //监听暂停按钮
    connect(btn_pause,&QPushButton::clicked,[=](){
        //暂停键弹跳
        btn_pause->zoom1();
        btn_pause->zoom2();
        //定时器暂停
        mytimer.stop();
        gameStart=false;
        btn_quit->show();
        btn_resume->show();
        btn_restart->show();
        //延时0.3s后暂停键消失
        QTimer::singleShot(300,this,[=](){
            btn_pause->hide();
        });


    });
    //监听继续按钮
    connect(btn_resume,&QPushButton::clicked,[=](){
        //继续键弹跳
        btn_resume->zoom1();
        btn_resume->zoom2();

       //延时0.3s后继续游戏
        QTimer::singleShot(300,this,[=](){
            //定时器恢复
            mytimer.start();
            //游戏状态恢复
            gameStart=true;
            //退出和继续键消失
            btn_quit->hide();
            btn_resume->hide();
            btn_restart->hide();
            //暂停键显示
            btn_pause->show();
        });


    });

    //监听重开按钮
    connect(btn_restart,&QPushButton::clicked,[=](){
        //继续键弹跳
        btn_restart->zoom1();
        btn_restart->zoom2();

       //延时0.3s后继续游戏
        QTimer::singleShot(300,this,[=](){
            //退出、重开、继续键消失
            btn_quit->hide();
            btn_restart->hide();
            btn_resume->hide();
            //暂停键显示
            btn_pause->show();
            restart();
        });


    });

    //监听无敌按钮
    connect(btn_test,&QPushButton::clicked,[=](){
        //无敌键弹跳
        btn_test->zoom1();
        btn_test->zoom2();
        if(isinvincible==true)
            isinvincible=false;
        else
            isinvincible=true;

    });

}

void MainScene::restart(){
    //飞机坐标初始化
    myplane.x=0.5*GAME_WIDTH-0.5*myplane.plane.width();
    myplane.y=GAME_HEIGHT-myplane.plane.height();
    //飞机子弹置空闲
    for(int i=0;i<BULLET_NUM;i++)
        myplane.mybullet[i].free=true;
    //敌机初始化
    for(int i=0;i<ENEMY_NUM;i++)
    {
        //敌机1坐标初始化
        myenemy[i].x=-100;
        myenemy[i].y=-100;
        //敌机1状态重置
        myenemy[i].free=true;

        //敌机2坐标初始化
        myenemy2[i].x=-100;
        myenemy2[i].y=-100;
        //敌机2状态重置
        myenemy2[i].free=true;
        //敌机2子弹子弹置空闲
        for(int j=0;j<BULLET_NUM;j++)
        myenemy2[i].bullet[j].free=true;
    }
    //敌机3坐标初始化
    myenemy3.x=-1000;
    myenemy3.y=-1000;
    //敌机3状态重置
    myenemy3.free=true;
    //敌机3子弹1,2置空闲
    for(int j=0;j<BULLET_NUM;j++){
     myenemy3.bullet1[j].free=true;
     myenemy3.bullet2[j].free=true;
    }
    //分数清零
    score=0;

    //开始游戏
    gameStart=true;
    isgameover=false;
    mytimer.start();
}

void MainScene::gameover(){
    //游戏结束
    isgameover=true;
    gameStart=false;
}

void MainScene::updatePosition(){
    //更新地图坐标
    map.mapposition();
    //发射子弹
    myplane.fire();
    //更新子弹坐标
    for(int i=0;i<BULLET_NUM;i++)
        myplane.mybullet[i].setPosition();
    //更新敌机信息
    for(int i=0;i<ENEMY_NUM;i++){
        myenemy[i].setInfo();
        myenemy2[i].setInfo();

        //敌机2发射子弹
        myenemy2[i].fire();
        //敌机3发射子弹
        myenemy3.fire();
        //更新敌机子弹移动
        for (int j=0;j<BULLET_NUM;j++) {
            //敌机2子弹向下移动
            myenemy2[i].bullet[j].setPosition2();
        }


    }
    //敌机3更新位置
    if(myenemy3.y<myenemy3.enemy.height())
    myenemy3.setInfo();

    for (int j=0;j<BULLET_NUM;j++) {
        //敌机3子弹向左下右下移动
        myenemy3.bullet1[j].setPosition3_1();
        myenemy3.bullet2[j].setPosition3_2();
    }


}

void MainScene::playGame()
{
    //设置定时器间隔
    mytimer.setInterval(GAME_RATE);
    //启动定时器
    mytimer.start();
    //监听定时器
    connect(&mytimer,&QTimer::timeout,[=](){
    //敌机出现
    enemyToScene();
    //调用updatePosition来定时更新坐标
    updatePosition();
    //触发重绘函数
    update();
    //碰撞检测
    collision_detcion();
    //qDebug()<<i;i++;DEBUG
    });

}

void MainScene::paintEvent(QPaintEvent*){
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,map.map1_posY,map.map1);
    painter.drawPixmap(0,map.map2_posY,map.map2);
    //绘制飞机
    painter.drawPixmap(myplane.x,myplane.y,myplane.plane);
    //绘制子弹
    for(int i=0;i<BULLET_NUM;i++)
        if(myplane.mybullet[i].free==false)
            painter.drawPixmap(myplane.mybullet[i].x,myplane.mybullet[i].y,myplane.mybullet[i].mybullet);
    //绘制敌机2子弹
    for(int i=0;i<ENEMY_NUM;i++){
        for(int j=0;j<BULLET_NUM;j++)
                if(myenemy2[i].bullet[j].free==false)
                    painter.drawPixmap(myenemy2[i].bullet[j].x,myenemy2[i].bullet[j].y,myenemy2[i].bullet[j].mybullet);
    }
    //绘制敌机3子弹
        for(int j=0;j<BULLET_NUM;j++){
                if(myenemy3.bullet1[j].free==false)
                    painter.drawPixmap(myenemy3.bullet1[j].x,myenemy3.bullet1[j].y,myenemy3.bullet1[j].mybullet);
                if(myenemy3.bullet2[j].free==false)
                    painter.drawPixmap(myenemy3.bullet2[j].x,myenemy3.bullet2[j].y,myenemy3.bullet2[j].mybullet);

}
    //绘制敌机1、2
    for(int i=0;i<ENEMY_NUM;i++){
        if(myenemy[i].free==false)
            painter.drawPixmap(myenemy[i].x,myenemy[i].y,myenemy[i].enemy);
        if(myenemy2[i].free==false)
            painter.drawPixmap(myenemy2[i].x,myenemy2[i].y,myenemy2[i].enemy);

    }
    //绘制敌机3
    if(myenemy3.free==false)
        painter.drawPixmap(myenemy3.x,myenemy3.y,myenemy3.enemy);
    //绘制爆炸图片
    for(int i=0;i<ENEMY_NUM;i++){
        //绘制敌机1爆炸图片
            if(myenemy[i].bomb[0].free==false)
                painter.drawPixmap(myenemy[i].bomb[0].x,myenemy[i].bomb[0].y,myenemy[i].bomb[0].bomb);
        //绘制敌机2爆炸图片
         for(int j=0;j<BOMB_NUM;j++)
            if(myenemy2[i].bomb[j].free==false)
                painter.drawPixmap(myenemy2[i].bomb[j].x,myenemy2[i].bomb[j].y,myenemy2[i].bomb[j].bomb);

    }

    //绘制敌机3爆炸图片
    for(int j=0;j<BOMB_NUM;j++)
       if(myenemy3.bomb[j].free==false)
           painter.drawPixmap(myenemy3.bomb[j].x,myenemy3.bomb[j].y,myenemy3.bomb[j].bomb);

    //记分牌分数更新
    QString str=QString("分数：%1").arg(this->score);//设置记分牌内容
    scoreboard.setText(str);
    scoreboard.show();//显示分数

    //绘制游戏结束界面且暂停计时器
    if(isgameover){
    painter.drawPixmap(0,0,map.gameOverScene);
    mytimer.stop();
    //设置游戏结束界面按钮组
          btn_quit->show();
          btn_pause->hide();
          btn_restart->show();
    }

}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    if(gameStart)
    {//防止横坐标越界
    int x = event->x()-myplane.Rect.width()*0.5;
    int y=event->y()-myplane.Rect.height()*0.5;
    //防止纵坐标越界
    if(x<=0)x=0;
    if(x>=GAME_WIDTH-myplane.Rect.width())x=GAME_WIDTH-myplane.Rect.width();
    //重新设置拖拽后的坐标
    if(y<=0)y=0;
    if(y>=GAME_HEIGHT-myplane.Rect.height())y=GAME_HEIGHT-myplane.Rect.height();
    myplane.setposition(x,y);
    }
}


void MainScene::enemyToScene(){
    enemy1_recorder++;
    enemy2_recorder++;

    if(enemy1_recorder==ENEMY1_INTERVAL)
    {
        //若累计满一个间隔，则计数器置零，派出敌机
         enemy1_recorder=0;
        //逐个搜索空闲敌机
        for(int i=0;i<ENEMY_NUM;i++){
           if(myenemy[i].free){
               myenemy[i].free=false;//将敌机状态置为占用
               myenemy[i].x=rand()%(GAME_WIDTH-myenemy[i].Rect.width());//随机出现在屏幕上方
               myenemy[i].y=-myenemy[i].Rect.height();
               break;
           }
        }
    }
    if(enemy2_recorder==ENEMY2_INTERVAL)
    {
        //若累计满一个间隔，则计数器置零，派出敌机
         enemy2_recorder=0;
       //逐个搜索空闲敌机
        for(int i=0;i<ENEMY_NUM;i++){
           if(myenemy2[i].free){
                       myenemy2[i].free=false;//将敌机状态置为占用
                       myenemy2[i].x=rand()%(GAME_WIDTH-myenemy2[i].enemy.width());//随机出现在屏幕上方
                       myenemy2[i].y=-myenemy2[i].enemy.height();
                       break;
           }
        }
    }

  //若屏幕上没有敌机3则开始计数
        if(myenemy3.free){
           enemy3_recorder++;
           if(enemy3_recorder==ENEMY3_INTERVAL){
               //若累计满一个间隔，则计数器置零，派出敌机
                enemy3_recorder=0;
                myenemy3.free=false;//将敌机状态置为占用
                myenemy3.x=rand()%(GAME_WIDTH-myenemy3.enemy.width());//随机出现在屏幕上方
                myenemy3.y=-myenemy3.enemy.height();

           }
        }
}

void MainScene::collision_detcion(){

    for (int i=0;i<ENEMY_NUM;i++) {

        //对敌机1进行碰撞检测
        //遍历所有非空闲的敌机1
        if(myenemy[i].free==false){//若敌机空闲则跳过
        //遍历所有己方子弹
        for (int j=0;j<BULLET_NUM;j++) {
            //若子弹空闲则跳过检测
            if(myplane.mybullet[j].free)continue;
            //检测是否子弹和敌机碰撞矩形相交
            if(myenemy[i].Rect.intersects(myplane.mybullet[j].Rect))
            {
                //将敌机与子弹置空闲
                myenemy[i].free=true;
                myplane.mybullet[j].free=true;
                //设置爆炸坐标
                myenemy[i].bomb[0].x=myenemy[i].x;
                myenemy[i].bomb[0].y=myenemy[i].y;
                //设置爆炸状态
                myenemy[i].bomb[0].free=false;
                //分数加1
                score++;
            }
         }
        //若飞机撞到敌机1，且未开启无敌版，则游戏结束
        if(myplane.Rect.intersects(myenemy[i].Rect)&&isinvincible==false)
            gameover();
      }

        //对敌机2进行碰撞检测
        //遍历所有非空闲的敌机2
        if(myenemy2[i].free==false){//若敌机空闲则跳过
        //遍历所有子弹
        for (int j=0;j<BULLET_NUM;j++) {
            //遍历所有敌机2子弹,若己方敌机中弹且未开启无敌版，则游戏结束
            if(myenemy2[i].bullet[j].Rect.intersects(myplane.Rect)&&isinvincible==false)
            gameover();

            //遍历所有己方子弹
            //若子弹空闲则跳过检测
            if(myplane.mybullet[j].free)continue;
            //检测是否子弹和敌机2碰撞矩形相交
            if(myenemy2[i].Rect.intersects(myplane.mybullet[j].Rect))
            {
                //中弹次数加一
                myenemy2[i].count_hit++;
                //将子弹置空闲
                myplane.mybullet[j].free=true;
                //若中弹达到一定次数，则发生第一次爆炸
                if(myenemy2[i].count_hit==ENEMY2LIFE){
                //设置爆炸图片1的坐标
                myenemy2[i].bomb[0].x=myenemy2[i].x;
                myenemy2[i].bomb[0].y=myenemy2[i].y;
                //设置爆炸图片1的状态
                myenemy2[i].bomb[0].free=false;
                //飞机更新为受损状态
                myenemy2[i].enemy.load(myenemy2[i].enemy_hit);
                //退出此次循环
                continue;
                }
                //若中弹再次达到一定状态，则发生最后一次爆炸
                if(myenemy2[i].count_hit==2*ENEMY2LIFE){
                   //敌机2置空闲
                   myenemy2[i].free=true;
                   //设置爆炸图片2的坐标
                   myenemy2[i].bomb[1].x=myenemy2[i].x;
                   myenemy2[i].bomb[1].y=myenemy2[i].y;
                   //设置爆炸图片2的状态
                   myenemy2[i].bomb[1].free=false;
                   //中弹次数清零
                   myenemy2[i].count_hit=0;
                   //敌机2样式重置
                   myenemy2[i].enemy.load(ENEMYPLANEPATH2);
                   //分数加3
                   score+=3;
                }

            }
         }
      }
   }


    //对敌机3进行碰撞检测
    //遍历所有非空闲的敌机2
    if(myenemy3.free==false){//若敌机空闲则跳过
    //遍历所有子弹
    for (int j=0;j<BULLET_NUM;j++) {
        //遍历所有敌机3子弹,若己方敌机中弹(子弹1或子弹2)且未开启无敌版，则游戏结束
        if((myenemy3.bullet1[j].Rect.intersects(myplane.Rect)||myenemy3.bullet2[j].Rect.intersects(myplane.Rect))&&isinvincible==false)
        gameover();
        //遍历所有己方子弹
        //若子弹空闲则跳过检测
        if(myplane.mybullet[j].free)continue;
        //检测是否子弹和敌机2碰撞矩形相交
        if(myenemy3.Rect.intersects(myplane.mybullet[j].Rect))
        {
            //中弹次数加一
            myenemy3.count_hit++;
            //将子弹置空闲
            myplane.mybullet[j].free=true;
            //若中弹达到一定次数，则发生第一次爆炸
            if(myenemy3.count_hit==ENEMY3LIFE){
            //设置爆炸图片1的坐标
            myenemy3.bomb[0].x=myenemy3.x;
            myenemy3.bomb[0].y=myenemy3.y;
            //设置爆炸图片1的状态
            myenemy3.bomb[0].free=false;
            //飞机更新为受损状态
            myenemy3.enemy.load(myenemy3.enemy_hit);
            //退出此次循环
            continue;
            }
            //若中弹再次达到一定次数，则发生第二次爆炸
            if(myenemy3.count_hit==2*ENEMY3LIFE){
            //设置爆炸图片2的坐标
            myenemy3.bomb[1].x=myenemy3.x;
            myenemy3.bomb[1].y=myenemy3.y;
            //设置爆炸图片2的状态
            myenemy3.bomb[1].free=false;
            //退出此次循环
            continue;
            }
            //若中弹达到临界状态，则发生最后一次爆炸
            if(myenemy3.count_hit==3*ENEMY3LIFE){
               //敌机3置空闲
               myenemy3.free=true;
               //设置爆炸图片3的坐标
               myenemy3.bomb[2].x=myenemy3.x;
               myenemy3.bomb[2].y=myenemy3.y;
               //设置爆炸图片3的状态
               myenemy3.bomb[2].free=false;
               //中弹次数清零
               myenemy3.count_hit=0;
               //敌机3样式重置
               myenemy3.enemy.load(ENEMYPLANEPATH3);
               //分数加10
               score+=10;
            }

        }
     }
  }

}
