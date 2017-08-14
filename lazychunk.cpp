#include "lazyChunk.h"
#include "engine.h"

void mergers(relationship &rs1,relationship &rs2)
{
    //找到一样的agent，然后对其second进行mergemap
    relationship::iterator it1=rs1.begin();
    while(it1!=rs1.end())
    {
        for(auto it2:rs2)
        {
            if(it2.first==it1->first)
            {help::mergemap(it1->second,it2.second);}
        }
        it1++;
    }
}

void LazyChunk::role()
{
    if(this->obj!=nullptr)
    {
        help::mergemap(obj->p,this->pDelta);
        mergers(obj->rs,this->rsDelta);
    }
    help::mergemap(data::globalp,this->pspDelta);
}
