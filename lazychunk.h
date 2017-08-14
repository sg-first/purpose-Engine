#pragma once
#include "head.h"
#include "agent.h"

class LazyChunk
{
private:
    Agent* sen; //发动对象
    Agent* obj; //受动对象，默认仅作用于公共状态（为nullptr）
public:
    LazyChunk(Agent* sen,Agent* obj=nullptr):sen(sen),obj(obj){}
    property pDelta; //对obj p的改变
    relationship rsDelta; //对obj rsDelta的改变
    property pspDelta; //对pState p的改变
    void role();
};
