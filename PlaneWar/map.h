#ifndef MAP_H
#define MAP_H
#include <QPixmap>

class Map
{
public:
    Map();
    //背景图片移动
    void mapposition();
    //背景成员
    QPixmap map1;
    QPixmap map2;
    QPixmap gameOverScene;
    //背景Y坐标
    int map1_posY;
    int map2_posY;
    //背景滚动速度
    int rollspeed;
};

#endif // MAP_H
