#pragma once
#include "head.h"

//decisionFactory所用的类型
typedef bool(*fp1)(property *field); //传入本单位所有参数，是否满足触发条件
typedef pack<property,vector<agent*>,vector<property> > (*fp23)(property *field); //传入本单位所有参数 返回对本单位的影响和对其它单位的影响以及是否延迟产生
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
        //还有一个发送事件到通知池？
    };
}

//agent所用的类型
typedef pair<agent*,property>relationship;

class agent
{
public:
    string ID;
    property field;
    property response(event *e); //事件响应函数
    void decide(); //根据当前状态进行决策的函数，即遍历behaviorList
    vector<behavior> behaviorList;
    list<relationship> relationshipList; //与其它agent的关系列表
    void produceEffects(property fie); //产生作用
};

class event
{
public:
    agent* sender;
    vector<agent*> receiver;

};
