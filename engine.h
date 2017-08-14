#pragma once
#include "head.h"
#include "lazychunk.h"
#include "agent.h"
#include "event.h"

class epool //通知池
{
public:
    static vector<LazyChunk> elist;
    static void addChunk(vector<LazyChunk> chunk);
    static void clearPool();
};

class data
{
public:
    static property globalp;
    static list<Agent*> allAgent;
    static list<Event*> allEvent;
    static void askEvent(Agent* a); //终极
};
