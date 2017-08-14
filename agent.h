#pragma once
#include "head.h"

class LazyChunk;
class Agent;

typedef bool(*CD2)(const LazyChunk &c); //判定是否满足触发条件
typedef property(*PC2)(const LazyChunk &c); //满足条件后执行计算操作，仅相当于pDelta，直接作用

class EventResponse
{
public:
    EventResponse(CD2 conditionDetermination,PC2 performCalu):
        conditionDetermination(conditionDetermination),performCalu(performCalu){}
    CD2 conditionDetermination;
    PC2 performCalu;
    void exec(Agent* a,const LazyChunk &c);
};

typedef map<Agent*,property> relationship;

class Agent
{
public:
    string id;
    property p; //拥有的属性
    relationship rs; //与其它agent的关系列表，注意其property的键与p不同
    int poolsub; //目前处理到的通知池下标
    list<EventResponse*> responseList; //每个agent具有不同的事件响应列表
    void ask();
};
