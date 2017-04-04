#pragma once
#include "head.h"
#include "factory.h"

//agent所用的类型
typedef pair<agent*,property>relationship;
typedef bool(*AC)(event*,agent*); //是否关注事件
typedef property(*RE)(event*,agent*); //事件对自身状态影响
extern vector<behavior> globalBehaviorList; //全局事件触发表

class agent
{
public:
    agent(string ID,AC ACfun,RE REfun,vector<behavior> behaviorList)
        :ID(ID),ACfun(ACfun),REfun(REfun),behaviorList(behaviorList){}
    string ID;
    property field;
    vector<relationship> relationshipList; //与其它agent的关系列表
    //响应通知池
    int poolsub=0; //已经响应过的事件在通知池中的下标
    bool getAttention(event* e); //计算是否关注事件
    void responseEvent(event *e); //事件响应函数
    void responsePool(); //通知池响应函数
    vector<event*>memory; //对关注事件的记忆
    //自决策
    void decide(); //根据当前状态进行决策的函数，即遍历独有和全局事件触发表
    vector<behavior> behaviorList; //独有事件触发表
    void produceEffects(property fie); //产生作用

private:
    AC ACfun;
    RE REfun;
};


struct event
{
public:
    agent* sender;
    vector<agent*> receiver;
    property senderFie;
    vector<property> receiverFie;
};

static void resetPool()
{
    for(event* i:notificationPool)
    {delete i;}
    notificationPool.clear();

    for(agent* i:allAgent)
    {i->poolsub=0;}
}
