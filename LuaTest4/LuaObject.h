//
//  LuaObject.h
//  LuaTest4
//
//  Created by Didrik Munther on 16/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#ifndef __LuaTest4__LuaObject__
#define __LuaTest4__LuaObject__

#include <stdio.h>
#include <iostream>

#include "LuaScript.h"


class LuaObject {
    
public:
    LuaObject(LuaScript* script);
    
    void beginCall(std::string function);
    void endCall(int argc, int results);
    void endCall();
    
    void selectScript();
    void selectReference(std::string reference);
    
    void pushObject();
    
    LuaScript* getScript();
    
private:
    LuaScript* _script;
    luabridge::LuaRef _object;
    
};

#endif /* defined(__LuaTest4__LuaObject__) */
