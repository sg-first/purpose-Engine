#include "engine.h"

vector<LazyChunk> epool::elist;
list<Agent*> data::allAgent;
list<Event*> data::allEvent;

void epool::addChunk(vector<LazyChunk> chunk)
{
    for(LazyChunk i:chunk)
    {epool::elist.push_back(i);}
}

void deletehalf(vector<LazyChunk>&elist)
{
    vector<LazyChunk>::iterator it=elist.begin();
    for(int i=1;i<=(int)(elist.size()/2);i++)
        it=elist.erase(it);
}

void epool::clearPool() //如果保证所有agent都已响应完最后一个事件，那么可以clear
{
    epool::elist.clear();
    for(Agent* a:data::allAgent)
    {
        a->poolsub=0;
        #ifdef EventMemory
        deletehalf(a->elist); //删除一半的记忆chunk
        #endif
    }
}

void epool::askEventResponse(Agent *a)
{
    if(a->poolsub==epool::elist.size()-1)
        return;

    for(;a->poolsub==epool::elist.size()-1;a->poolsub++) //响应目前通知池中的事件
    {
        for(EventResponse* er:a->responseList)
        {er->exec(a,epool::elist.at(a->poolsub));}
    }
    a->poolsub++; //每次都直接开始
}

void data::askEvent(Agent *a)
{
    for(Event* e:data::allEvent)
    {e->exec(a);}
}
