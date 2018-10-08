#pragma once
#include "head.h"
#include "lazychunk.h"
#include "initmap.h"

class Agent;

typedef bool(*CD2)(const LazyChunk &c); //判定是否满足触发条件
typedef property(*PC2)(const LazyChunk &c); //满足条件后通过lazychunk（事件）计算pDelta（对agent属性影响）

class EventResponse //因外部事件产生自身状态变更
{
public:
    EventResponse(CD2 conditionDetermination,PC2 performCalu):
        conditionDetermination(conditionDetermination),performCalu(performCalu){}
    CD2 conditionDetermination;
    PC2 performCalu;
    void exec(Agent* a,const LazyChunk &c);
};

class Agent
{
public:
    Agent(string id,int nowpoolsub
      #ifdef EventMemory
          ,vector<LazyChunk>elist
      #endif
          ):
        id(id),poolsub(nowpoolsub)
      #ifdef EventMemory
        ,elist(elist)
      #endif
    {
        initmap::setpKey(this->p);
        //rs因为没有allagent的所有权无法在此初始化
    }
    string id;
    property p; //拥有的属性
    relationship rs; //与其它agent的关系列表，注意其property的键与p不同
    int poolsub; //目前处理到的通知池下标
    list<EventResponse*> responseList; //每个agent具有不同的事件响应列表
    #ifdef EventMemory
    vector<LazyChunk> elist; //这个是作为“记忆”存在，但在大部分应用中其实并不需要，所以暂未设为构造函数参数
    #endif
};
