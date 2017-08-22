#include "initmap.h"

vector<string> initmap::pkey;
vector<string> initmap::rskey;

void setKey(property &p,vector<string> &keyvec)
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

void initmap::setrsKey(relationship &rs, list<Agent*> &allAgent)
{
    property p;
    setKey(p,initmap::rskey);

    for(Agent* key1:allAgent)
    {rs[key1]=p;}
}
