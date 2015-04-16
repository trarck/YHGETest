/*
 *  Datas.h
 *  Message
 *
 *  Created by trarck trarck on 11-12-16.
 *  Copyright 2011 yitengku.com. All rights reserved.
 *
 */
#include "cocos2d.h"
#include <yhge/yhge.h>

typedef struct Register_Data{
	int type;
	cocos2d::Ref* sender;
	cocos2d::Ref* receiver;
    cocos2d::yhge::SEL_MessageHandler handle;
	
} RegisterData;

typedef struct Dispatch_Data{
	int type;
	cocos2d::Ref* sender;
	cocos2d::Ref* receiver;
	cocos2d::Ref* data;
} DispatchData;

typedef struct DataItem{
	RegisterData regiester;
	DispatchData dispatch;
    int result;
    std::string description;
} DataItem;

enum  {
	MsgAll=0,
	CarStop,
	CarMove,
	DirverCar
};