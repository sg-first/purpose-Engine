#pragma once
#include <map>
#include <string>
#include <vector>
#include <tuple>
#include <functional>

using namespace std;
typedef std::tie unpack;
typedef tuple pack;

typedef map<string,float> property;

//decisionFactory所用的函数指针
typedef bool(*fp1)(property *field); //传入本单位所有参数，是否满足触发条件
typedef pack<property,vector<agent*>,vector<property>,bool> (*fp23)(property *field); //传入本单位所有参数 返回对本单位的影响和对其它单位的影响以及是否延迟产生
typedef std::function<void()>eff; //产生副作用的函数，在需要延迟事件生效时产生
typedef std::function<eff(agent*)>behavior; //agent可能产生的行为，实质作用是fp1和fp23。如果该行为延迟生效，则返回一个eff实值

static behavior decisionFactory(fp1 condition,fp23 result)
{
    return [](agent* examiner) {
        if(!condition(examiner->field)) //检查是否满足发生条件
            return nullptr;
        //准备自解包
        property thisAgentFie;
        vector<agent*> otherAgent;
        vector<property> otherAgentFie;
        bool islazy;
        unpack(thisAgentFie,otherAgent,otherAgentFie,islazy)=result(examiner->field); //得到事件产生的结果
        //产生副作用的函数
        eff lazyfun=[]() {
            produceEffects(examiner,thisAgentFie);
            for(int i=0;i<otherAgent.size();i++)
            {produceEffects(otherAgent.at(i),otherAgentFie.at(i));}
        };
        //根据是否延迟作用决定是返回函数还是直接执行
        if(islazy)
        {return lazyfun;}
        lazyfun();
        return nullptr;
    };
}

static void produceEffects(agent *receiver,property thisAgentFie)
{

}

class agent
{
public:
    string ID;
    property field;
    property response(event *e); //事件响应函数
    void decide();
};

class event
{
public:
    agent* sender;
    vector<agent*> receiver;

};
