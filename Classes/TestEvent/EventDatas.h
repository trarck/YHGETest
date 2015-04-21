#ifndef YHGEGEST_TESTEVENT_EVENTDATA_H_
#define YHGEGEST_TESTEVENT_EVENTDATA_H_

#include "cocos2d.h"
#include <yhge/yhge.h>

typedef struct Event_Register_Data{
	int type;
	cocos2d::Ref* sender;
	cocos2d::Ref* listener;
    cocos2d::yhge::SEL_EventHandle handle;
	
} EventRegisterData;

typedef struct Event_Dispatch_Data{
	int type;
	cocos2d::Ref* sender;
	cocos2d::Ref* data;
} EventDispatchData;

typedef struct Event_Data_Item{
	EventRegisterData regiester;
	EventDispatchData dispatch;
    int result;
    std::string description;
} EventDataItem;

enum  {
	kEventWait=1,
	kEventMove,
	kEventStop,
	kEventDirverCar
};

#endif  // YHGEGEST_TESTEVENT_EVENTDATA_H_