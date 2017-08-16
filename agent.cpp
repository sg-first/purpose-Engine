#include "agent.h"

void EventResponse::exec(Agent *a, const LazyChunk &c)
{
    if(this->conditionDetermination(c))
    {
        property pDelta=this->performCalu(c);
        help::mergemap(a->p,pDelta);
    }
}

void Agent::ask(vector<LazyChunk> &elist)
{
    if(this->poolsub==elist.size())
        return;

    for(;this->poolsub<elist.size();this->poolsub++)
    {
        for(EventResponse* ep:this->responseList)
        {ep->exec(this,elist.at(this->poolsub));}
    }
    this->poolsub++; //每次都直接开始
}
