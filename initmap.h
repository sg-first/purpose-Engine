#pragma once
#include "head.h"

class initmap
{
public:
    static vector<string> pkey;
    static vector<string> rskey;
    static void setpKey(property &p);
    static void setrs2Key(relationship &rs);
    static void setrsKey(relationship &rs,list<Agent*> &allAgent);
};
