#include "ObjA.h"

using namespace cocos2d;
using namespace cocos2d::yhge;

void ObjA::wait(yhge::Event* event)
{
    ++m_nWait;
}

