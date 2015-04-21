#include "TestEvent.h"
#include "EventDatas.h"
#include "ObjA.h"
#include "ObjB.h"

using namespace cocos2d;
using namespace cocos2d::yhge;

void showTestFail(const char* msg)
{
    CCLOG("=========test fail{============\n%s",msg);
    CCLOG("=========}test fail============");
}

void TestEvent::run()
{
    CCLOG("CTestMessagear::run");
    testRegiestAndSend();
	testRemove();

}

void TestEvent::testRegiestAndSend()
{
    CCLOG("********TestEvent::testRegiestAndSend{***************");
    ObjA *objA=new ObjA();
	ObjB *objB=new ObjB();
	
	
	EventDataItem datas[]={
        //regist objB wait event 
        //  objB trigger wait event
		{kEventWait,objB,objA,YH_EVENT_SELECTOR(ObjA::wait),kEventWait,objB,NULL,1,""},
        {kEventStop,objB,objA,YH_EVENT_SELECTOR(ObjA::wait),kEventWait,objB,NULL,0,""},
	};

	int dataLength=sizeof(datas)/sizeof(EventDataItem);
	EventDataItem it;
	
	struct timeval start;
    struct timeval end;
	gettimeofday(&start,NULL);
	
    for(int j=0;j<100;++j){

	    for(int i=0;i<dataLength;i++){
		    //CCLOG("do test %d",i);
            objA->m_nWait=0;

		    it=datas[i];
		    EventRegisterData rd=it.regiester;
		    EventDispatchData dd=it.dispatch;
		    //regiester
		    EventListenerManager * em=new EventListenerManager();
            em->init();
            em->addEventListener(rd.sender,rd.type,rd.listener,rd.handle);

		    //dispatch
		    yhge::Event *event=new yhge::Event();
            event->initEvent(dd.type,true,ture);       
            em->dispatchEvent(objB,event);
            em->release();
            if(objA->m_nWait!=it.result){
                char buffer[255];
                sprintf(buffer,"index:%d,%s",i,it.description.c_str());
                showTestFail(buffer);
            }
	    }
    }
    gettimeofday(&end,NULL);
    CCLOG("use:%ld,%d",end.tv_sec-start.tv_sec,end.tv_usec-start.tv_usec);
    CCLOG("********}TestEvent::testRegiestAndSend***************");
}


void TestEvent::testRemove()
{
    CCLOG("********TestEvent::testRemove{***************");
    ObjA *objA=new ObjA();
	ObjB *objB=new ObjB();
	
	
	EventDataItem datas[]={
        //regist man CarStop from car 
        //  car send CarStop to man
		{kEventWait,objB,objA,YH_EVENT_SELECTOR(ObjA::wait),kEventWait,objB,NULL,1,""},
        {kEventStop,objB,objA,YH_EVENT_SELECTOR(ObjA::wait),kEventWait,objB,NULL,0,""},
       
	};

	int dataLength=sizeof(datas)/sizeof(EventDataItem);
	EventDataItem it;
	
	struct timeval start;
    struct timeval end;
	gettimeofday(&start,NULL);
	
	for(int i=0;i<dataLength;i++){
		CCLOG("do test %d",i);
        objA->m_nWait=0;

		it=datas[i];
		EventRegisterData rd=it.regiester;
		EventDispatchData dd=it.dispatch;
		//regiester
		EventListenerManager * em=new EventListenerManager();
        em->init();
        em->addEventListener(rd.sender,rd.type,rd.listener,rd.handle);

        //remove register
        em->removeEventListener(rd.sender);

		//dispatch
		yhge::Event *event=new yhge::Event();
        event->initEvent(dd.type,true,ture);            
		em->dispatchEvent(objB,event);
        em->release();
        if(objA->m_nWait!=it.result){
            char buffer[255];
            sprintf(buffer,"index:%d,%s",i,it.description.c_str());
            showTestFail(buffer);
        }
	}
    gettimeofday(&end,NULL);
    CCLOG("use:%ld,%d",end.tv_sec-start.tv_sec,end.tv_usec-start.tv_usec);
    CCLOG("********}TestEvent::testRemove***************");
}
