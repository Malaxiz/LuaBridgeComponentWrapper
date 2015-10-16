//
//  Entity.h
//  LuaTest4
//
//  Created by Didrik Munther on 16/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#ifndef __LuaTest4__Entity__
#define __LuaTest4__Entity__

#include <stdio.h>
#include <map>

#include "LuaObject.h"
#include "Component.h"


class Body {
    
public:
    Body() {velX = velY = 10.0f;}
    
    float velX, velY;
    
};

class Entity {
    
public:
    Entity() { body = new Body; }
    ~Entity() { delete body; }
    
    void onLoop();
    
    Body* body;
    
    void addComponent(LuaScript* script) {
        Component* component = new Component(this, script);
        components[script->getName()] = component;
    }
    
    std::map<std::string, Component*> components;
    
};

#endif /* defined(__LuaTest4__Entity__) */
