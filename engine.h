#pragma once
#include "lazyChunk.h"
#include "agent.h"
#include "event.h"

class epool //通知池
{
public:
    static vector<LazyChunk> elist;
    static void addChunk(vector<LazyChunk> chunk);
    static void clearPool();
    static void askEventResponse(Agent *a); //使一个agent响应事件
};

class data //数据池
{
public:
    static property globalp;
    static list<Agent*> allAgent;
    static list<Event*> allEvent;
    static void askEvent(Agent* a); //使一个agent自检状态产生事件
};
