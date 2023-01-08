#include "bomb.h"

Bomb::Bomb()
{
  //加载爆炸图片
  bomb.load(BOMBPATH1_2);
  //初始化坐标
  x=-100;
  y=-100;
  //初始化空闲状态
  free=true;
  //爆炸间隔记录
  bomb_recorder=0;

}
void Bomb::setInfo(){
    //若空闲状态则返回
    if(free)return;
    //爆炸时间加一
    bomb_recorder++;
    //爆炸持续时间未到则返回
    if(bomb_recorder<BOMB_INTERVAL)return;
    //重置爆炸持续记录
    bomb_recorder=0;
    //爆炸结束
    free=true;
}
