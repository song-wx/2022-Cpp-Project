#include "map.h"
#include"config.h"

Map::Map()
{
   //加载背景图片
   map1.load(MAPPATH);
   map2.load(MAPPATH);
   gameOverScene.load(GAMEOVER1);
   //初始化背景图片位置
   map1_posY=-GAME_HEIGHT;
   map2_posY=0;
   //设置背景滚动速度
   rollspeed=MAPROLL_SPEED;
}

void Map::mapposition(){
    //第一张图片的移动
    map1_posY+=rollspeed;
    if(map1_posY>=0)
        map1_posY=-GAME_HEIGHT;
    //第二张图片的移动
    map2_posY+=rollspeed;
    if(map2_posY>=GAME_HEIGHT)
        map2_posY=0;
}
