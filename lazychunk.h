#pragma once
#include "head.h"
#include "agent.h"

class LazyChunk
{
private:
    Agent* obj; //作用对象，默认仅作用于公共状态
public:
    LazyChunk(Agent* obj=nullptr):obj(obj){}
    property pDelta; //对obj p的改变
    relationship rsDelta; //对obj rsDelta的改变
    property pspDelta; //对pState p的改变
    void role();
};
