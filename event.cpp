#include "event.h"

void Event::exec(Agent* a)
{
    if(this->conditionDetermination(a))
    {
        vector<LazyChunk> chunk=this->performCalu(a); //fix:这里有一些问题，一个chunk只能作用于一个agent，多了怎么办？
        if(this->callback!=nullptr)
        {this->callback(chunk);}
        else
        {
            for(LazyChunk i: chunk)
            {i.role();}
        }
    }
}
