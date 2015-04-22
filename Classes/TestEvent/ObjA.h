#ifndef YHGEGEST_TESTEVENT_OBJA_H_
#define YHGEGEST_TESTEVENT_OBJA_H_

#include "cocos2d.h"
#include <yhge/yhge.h>

class ObjA : public cocos2d::Node
{
public:

	void wait(cocos2d::yhge::Event* e);

    int m_nWait;
};

#endif  // YHGEGEST_TESTEVENT_OBJA_H_