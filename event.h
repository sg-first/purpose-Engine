#pragma once
#include "head.h"
#include "agent.h"
#include "lazyChunk.h"

typedef bool(*CD)(Agent* a); //判定是否满足触发条件
typedef vector<LazyChunk>(*PC)(Agent *a); //满足条件后执行计算操作
typedef function<void(vector<LazyChunk> chunk)>CB; //可选的延迟PC使用的回调函数

class Event
{
public:
    Event(CD conditionDetermination,PC performCalu,CB callback=nullptr)
        :conditionDetermination(conditionDetermination),performCalu(performCalu),callback(callback){}
    CD conditionDetermination;
    PC performCalu;
    CB callback;
    void exec(Agent *a);
};
