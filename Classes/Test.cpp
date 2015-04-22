#include "Test.h"
#include "TestMessage/TestMessage.h"
#include "TestEvent/TestEvent.h"


Test::Test()
{
}


Test::~Test()
{
}

void Test::start()
{
	TestMessage* tm = new TestMessage();
	tm->run();

	tm->release();

	TestEvent* te = new TestEvent();
	te->run();

	te->release();

}
