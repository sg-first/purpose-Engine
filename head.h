#pragma once
#include <map>
#include <string>
#include <vector>
#include <list>
#include <tuple>
#include <functional>
#include <utility>
using namespace std;

//#define EventMemory //是否开启agent事件记忆

typedef map<string,float> property;
class Agent;
typedef map<Agent*,property> relationship;

class help
{
public:
    static void mergemap(property &p,const property &pdelta) //将部分元素的变更量更新到p
    {
        property::iterator it1=p.begin();
        while(it1!=p.end())
        {
            for(auto it2 : pdelta)
            {
                if(it2.first==it1->first)
                {it1->second+=it2.second;}
            }
            it1++;
        }
    }
};
