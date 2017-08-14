#include "agent.h"

void EventResponse::exec(Agent *a, const LazyChunk &c)
{
    if(this->conditionDetermination(c))
    {
        property pDelta=this->performCalu(c);
        help::mergemap(a->p,pDelta);
    }
}

void Agent::ask()
{
    if(this->poolsub==epool::elist.size())
        return;

    for(;this->poolsub<epool::elist.size();this->poolsub++)
    {
        for(EventResponse* ep:this->responseList)
        {ep->exec(this,epool::elist.at(this->poolsub));}
    }
    this->poolsub++; //每次都直接开始
}
