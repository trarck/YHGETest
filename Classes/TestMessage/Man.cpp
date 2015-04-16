#include "Man.h"

using namespace cocos2d;
using namespace cocos2d::yhge;

void Man::wait(Message* message)
{
    //CCLOG("Man:wait");
    ++m_nWait;
}

