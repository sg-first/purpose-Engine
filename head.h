#pragma once
#include <map>
#include <string>
#include <vector>
#include <list>
#include <tuple>
#include <functional>
#include <utility>

using namespace std;

typedef map<string,float> property;

class help
{
public:
    static void mergemap(property &p,const property &pdelta)
    {
        property::iterator it1=p.begin();
        while(it1!=p.end())
        {
            for(auto it2:pdelta)
            {
                if(it2.first==it1->first)
                {it1->second+=it2.second;} //fix:合并后最好删除
            }
            it1++;
        }
    }
};
