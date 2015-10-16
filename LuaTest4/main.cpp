//
//  main.cpp
//  LuaTest4
//
//  Created by Didrik Munther on 16/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#include <iostream>

#include "LuaScript.h"


class Body {
    
public:
    Body() {velX = velY = 10.0f;}
    
    float velX, velY;
    
};

class Entity {
    
public:
    Entity() { body = new Body; }
    ~Entity() { delete body; }
    
    Body* body;
    
};

int main(int argc, const char * argv[]) {
    
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    
    luabridge::getGlobalNamespace(L)
        .beginClass<Entity>("Entity")
            .addConstructor<void(*) (void)>()
            .addData("body", &Entity::body)
        .endClass()
        .beginClass<Body>("Body")
            .addConstructor<void(*) (void)>()
            .addData("velX", &Body::velX)
            .addData("velY", &Body::velY)
        .endClass();
    
    luaL_dofile(L, "resources/class.lua");
    
    // ==
    
    luaL_dofile(L, "resources/Movable.lua");
    auto createFunction = luabridge::getGlobal(L, "create");
    
    // -
    
    Entity entity;
    auto human2 = createFunction(); //luabridge::getGlobal(L, "component");
    
    human2.beginCall();
    ((luabridge::LuaRef)human2["onLoop"]).beginCall();
    lua_pushvalue(L, -2);
    luabridge::Stack<Entity*>::push(L, &entity);
    lua_pcall(L, 2, 0, 0);
    
    // -
    
    Entity entity2;
    auto human3 = createFunction();
    
    human3.beginCall();
    ((luabridge::LuaRef)human3["onLoop"]).beginCall();
    lua_pushvalue(L, -2);
    luabridge::Stack<Entity*>::push(L, &entity2);
    lua_pcall(L, 2, 0, 0);
    
    // ==
    
    lua_close(L);
}















