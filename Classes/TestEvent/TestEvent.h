#ifndef YHGEGEST_TESTEVENT_TESTEVENT_H_
#define YHGEGEST_TESTEVENT_TESTEVENT_H_

#include "cocos2d.h"

class TestEvent : public cocos2d::Ref
{
public:
    void run();
    void testRegiestAndSend();
    void testRemove();

private:
	void showTestFail(const char* msg);
};

#endif  // YHGEGEST_TESTEVENT_TESTEVENT_H_