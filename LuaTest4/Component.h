//
//  Component.h
//  LuaTest4
//
//  Created by Didrik Munther on 16/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#ifndef __LuaTest4__Component__
#define __LuaTest4__Component__

#include <stdio.h>

#include "LuaObject.h"


class Entity;

class Component {
    
public:
    Component(Entity* parent, LuaScript* script);
    
    void onLoop();
    
private:
    Entity* _parent;
    LuaObject _object;
    
};

#endif /* defined(__LuaTest4__Component__) */
