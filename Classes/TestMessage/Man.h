#ifndef CCLIBSTEST_MAN_H_
#define CCLIBSTEST_MAN_H_

#include "cocos2d.h"
#include <yhge/yhge.h>

class Man : public cocos2d::Ref
{
public:

    void wait(cocos2d::yhge::Message* message);

    int m_nWait;
};

#endif  // CCLIBSTEST_MAN_H_