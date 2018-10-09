#pragma once
#include "head.h"

class Agent;

class LazyChunk //事件导致的状态变更（可以看作事件），该类用于延迟触发和记录（先前的）事件使其它agent响应
{
private:
    Agent* sen; //发动对象
    Agent* obj; //受动对象，默认作用于公共状态（为nullptr）
public:
    LazyChunk(Agent* sen,Agent* obj=nullptr):sen(sen),obj(obj){}
    property pDelta; //对obj p的改变
    relationship rsDelta; //对obj rsDelta的改变
    property pspDelta; //对全局状态p的改变
    void role();

    static property* globalp; //会被初始化为data中的全局状态p
};
