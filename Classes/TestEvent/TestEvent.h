#ifndef CCLIBSTEST_TestMessage_H_
#define CCLIBSTEST_TestMessage_H_

#include "cocos2d.h"

class TestEvent : public cocos2d::Ref
{
public:
    void run();
    void testRegiestAndSend();
    void testRemove();
};

#endif  // CCLIBSTEST_TestMessage_H_