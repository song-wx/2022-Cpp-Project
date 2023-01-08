#include "mybutton.h"
#include<QDebug>
Mybutton::Mybutton(QString normalImg,QString pressImg)
{
   //设置一般的图像路径
   this->normalImgPath=normalImg;
   //设置按压后的图像路径
   this->pressImgPath=pressImg;
   //初始化图像
   QPixmap pix;
   bool ret=pix.load(normalImgPath);
   if(!ret)
      {
//       qDebug()<<"素材未成功导入";
       return;
   }
   //设置固定大小
   this->setFixedSize(pix.width(),pix.height());
   //设置不规则形状
   this->setStyleSheet("QPushbutton(border:0px)");
   //设置背景为透明
   QString btn_Stylesheet = "background-color:transparent";
   this->setStyleSheet(btn_Stylesheet);
   //设置按钮图像
   this->setIcon(pix);
   //设置图像大小
   this->setIconSize(QSize(pix.width(),pix.height()));

}

void Mybutton::zoom1(){
    //创建动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");
    //设置时间间隔，单位毫秒
    animation->setDuration(200);
    //创建初始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //创建结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation->start();

}

void Mybutton::zoom2(){
    //创建动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");
    //设置时间间隔，单位毫秒
    animation->setDuration(200);
    //创建初始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //创建结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation->start();

}
