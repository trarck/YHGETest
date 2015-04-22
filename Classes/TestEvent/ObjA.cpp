#include "ObjA.h"

using namespace cocos2d;
using namespace cocos2d::yhge;

void ObjA::wait(cocos2d::yhge::Event* e)
{
	printf("do wait");
    ++m_nWait;
}

