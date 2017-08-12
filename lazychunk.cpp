#include "lazyChunk.h"
#include "publicState.h"

void mergemap(property &p1,property &p2)
{
    property::iterator it1=p1.begin();
    while(it1!=p1.end())
    {
        for(auto it2:p2)
        {
            if(it2.first==it1.first)
            {it1.second+=it2.second;} //fix:合并后最好删除
        }
        it1++;
    }
}

void mergers(relationship &rs1,relationship &rs2)
{
    //找到一样的agent，然后对其second进行mergemap
    relationship::iterator it1=rs1.begin();
    while(it1!=p1.end())
    {
        for(auto it2:rs2)
        {
            if(it2.first==it1.first)
            {mergemap(it1.second,it2.second);}
        }
        it1++;
    }
}

void LazyChunk::role()
{
    if(this->obj!=nullptr)
    {
        mergemap(obj->p,this->pDelta);
        mergers(obj->rs,this->rsDelta);
    }
    mergemap(pstate::p,this->pspDelta);
}
