#include "playgamescene.h"

PlayGameScene::PlayGameScene(QWidget *parent) : QWidget(parent)
{
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_LOGO));
}
