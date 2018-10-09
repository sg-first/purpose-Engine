#include "agent.h"

void EventResponse::exec(Agent *a, const LazyChunk &c) //让一个agent响应外部lazechunk
{
    if(this->conditionDetermination(c))
    {
        property pDelta=this->performCalu(c);
        help::mergemap(a->p,pDelta); //直接作用，不可延迟
        #ifdef EventMemory
        a->elist.push_back(c); //添加到a的记忆
        #endif
    }
}
