#include "event.h"

void Event::exec(Agent* a)
{
    if(this->conditionDetermination(a))
    {
        vector<LazyChunk> chunk=this->performCalu(a);
        if(this->callback!=nullptr)
        {this->callback(chunk);} //处理chunk的任务交给callback（callback进行的如询问用户等）
        else
        {
            for(LazyChunk i: chunk)
            {
                i.role();
                Event::elist->push_back(i); //添加进通知池
            }
        }
    }
}
