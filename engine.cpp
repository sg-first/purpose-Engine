#include "engine.h"

void epool::addChunk(vector<LazyChunk> chunk)
{
    for(LazyChunk i:chunk)
    {epool::elist.push_back(i);}
}

void epool::clearPool()
{
    epool::elist.clear();
    for(Agent* a:data::allAgent)
    {a->poolsub=0;}
}

void data::askEvent(Agent *a)
{
    for(Event* e:data::allEvent)
    {e->exec(a);}
}
