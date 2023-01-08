#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <QPushButton>
#include <QDebug>
#include<QToolButton>
#include<QPropertyAnimation>
class Mybutton : public QPushButton
{
    Q_OBJECT
public:
    //explicit Mybutton(QWidget *parent = nullptr);
    //按钮构造函数参数1正常显示的图片路径，参数2按下后的图片显示途径
    Mybutton(QString normalImg = "",QString pressImg = "");
    //弹跳动画
    void zoom1();//弹下
    void zoom2();//回弹
    //成员属性
    QString normalImgPath;
    QString pressImgPath;

signals:

};

#endif // MYBUTTON_H
