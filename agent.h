#pragma once
#include "head.h"

class Agent;

typedef map<Agent*,property> relationship;

class Agent
{
public:
    string id;
    property p; //拥有的属性
    relationship rs; //与其它agent的关系列表，注意其property的键与p不同
};
