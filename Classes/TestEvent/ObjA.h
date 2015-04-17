#ifndef CCLIBSTEST_MAN_H_
#define CCLIBSTEST_MAN_H_

#include "cocos2d.h"
#include <yhge/yhge.h>

class ObjA : public cocos2d::Ref
{
public:

    void wait(yhge::Event* event);

    int m_nWait;
};

#endif  // CCLIBSTEST_MAN_H_