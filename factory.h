#pragma once
#include "head.h"

class agent;
class event;
extern vector<agent*> allAgent;
extern vector<event*> notificationPool;

//decisionFactory所用的类型
typedef bool(*fp1)(property *field); //传入本单位所有参数，是否满足触发条件
typedef pack<property,vector<agent*>,vector<property> > (*fp23)(property *field); //传入本单位所有参数 返回对本单位的影响和对其它单位的影响
typedef std::function<void(agent*)> behavior; //决定agent是否执行一个行为，实质作用是fp1和fp23。如果该行为延迟生效，则该类型函数返回一个eff实值

static behavior behaviorFactory(fp1 condition,fp23 result)
{
    return [condition,result](agent* examiner)
    {
        if(!condition(examiner->field)) //检查是否满足发生条件
            return;
        //准备自解包
        property thisAgentFie;
        vector<agent*> otherAgent;
        vector<property> otherAgentFie;
        unpack(thisAgentFie,otherAgent,otherAgentFie)=result(examiner->field); //得到事件产生的结果
        //产生作用
        examiner->produceEffects(thisAgentFie);
        for(int i=0;i<otherAgent.size();i++)
        {otherAgent.at(i)->produceEffects(otherAgentFie.at(i));}
        //发送事件到通知池
        event* e=new event{examiner,otherAgent,thisAgentFie,otherAgentFie};
        notificationPool.push_back(e);
    };
}
