#include "stru.h"

void agent::produceEffects(property fie)
{
    //fie短field长，所以它被放在内层遍历
    for(auto &i:this->field)
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
    for(behavior i:behaviorList)
    {i(this);}
}
