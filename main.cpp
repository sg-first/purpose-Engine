#include "engine.h"

property* LazyChunk::globalp;
property data::globalp;

int main()
{
    LazyChunk::globalp=&data::globalp;
    //设定所有的event
    //设定普通property和relationship property的键表，设定全局property的键表
    //设定EventResponse
    //初始化（此时所有的agent属性一样）
    //对每个agent初始化rs（因为外部域才有allagent的所有权，调用setrsKey初始化即可），设定不同agent的p与rs的初值
    //设定不同agent的responseList
}
