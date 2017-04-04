#include "world.h"

void agent::produceEffects(property fie)
{
    //fie短field长，所以它被放在内层遍历
    for (property::iterator i=this->field.begin();i!=this->field.end();i++)
    {
        for (property::iterator j=fie.begin();j!=fie.end();)
        {
            if (j->first == i->first)
            {
                i->second+=j->second;
                j=test.erase(i); //已经作用，就不会再次作用了
            }
            else
                j++;
        }
    }
}

void agent::decide()
{
    for(behavior i:globalBehaviorList)
    {i(this);}

    for(behavior i:behaviorList)
    {i(this);}
}

bool agent::getAttention(event *e)
{return ACfun(e,this);}

void agent::responseEvent(event *e)
{
    property effect=REfun(e,this);
    this->produceEffects(effect); //响应事件只涉及到自身状态改变，不做任何决策
}

void agent::responsePool()
{
    for(int i=poolsub;i<notificationPool.size();i++)
    {
        event *e=notificationPool.at(i);
        if(getAttention(e))
            responseEvent(e);
    }
    poolsub=notificationPool.size()-1;
}
