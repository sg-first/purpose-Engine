#pragma once
#include "head.h"

class initmap //初始化需要的工具函数
{
public:
    static vector<string> pkey; //本环境中property（人物固有属性）所有的key
    static vector<string> rskey; //本环境中relationship中的property（agent间关系类型）所有的key
    static void setpKey(property &p); //用已设定的键初始化property所有的key
    static void setrs2Key(relationship &rs); //重新初始化一个relationship中所有的property（此时应有的键应该已经添加完毕）
    static void setrsKey(relationship &rs,list<Agent*> &allAgent); //向relationship内添加现存的所有agent并初始化property
};
