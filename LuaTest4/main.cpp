//
//  main.cpp
//  LuaTest4
//
//  Created by Didrik Munther on 16/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#include <iostream>

#include "LuaScript.h"
#include "Entity.h"


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
    
    {
    
        LuaScript script(L, "resources/Movable.lua");
        LuaScript script2(L, "resources/Animal.lua");
        
        Entity entity;
        entity.addComponent(&script);
        entity.onLoop();                // Create entity and run default onLoop function
        
        Entity entity2;
        entity2.addComponent(&script2);
        entity2.components["Animal"]->getObject()->beginCall("doThing");
        entity.components["Movable"]->getObject()->pushObject();
        entity2.components["Animal"]->getObject()->endCall(1, 0);
        entity.onLoop();                // Create entity and run costume function with another component as an argument
        
    }
    
    lua_close(L);
}















