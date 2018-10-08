#include "initmap.h"

vector<string> initmap::pkey;
vector<string> initmap::rskey;

void setKey(property &p,vector<string> &keyvec) //初始化property所有的key
{
    for(string key:keyvec)
    {p[key]=0;}
}

void initmap::setpKey(property &p)
{
    setKey(p,initmap::pkey);
}

void initmap::setrs2Key(relationship &rs)
{
    relationship::iterator it;
    it = rs.begin();

    while(it != rs.end())
    {
        //second为对应property
        setKey(it->second,initmap::rskey);
        it++;
    }
}

//向relationship内添加现存的所有agent并初始化property（这个存在所有权问题所以不能直接在构造函数中调用）
void initmap::setrsKey(relationship &rs, list<Agent*> &allAgent)
{
    property p;
    setKey(p,initmap::rskey);

    for(Agent* key1:allAgent)
    {rs[key1]=p;}
}
