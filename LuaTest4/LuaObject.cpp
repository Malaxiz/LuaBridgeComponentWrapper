//
//
//  LuaTest4
//
//  Created by Didrik Munther on 16/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#include "LuaObject.h"


LuaObject::LuaObject(LuaScript* script)
    : _script(script)
    , _object(script->getObject())
{
    
}



void LuaObject::call(int argc, int results) {
    lua_call(_script->getState(), argc + 1, results);
}

void LuaObject::call() {
    call(0, 0);
}

void LuaObject::selectScript() {
    _object.push(_script->getState());
}

void LuaObject::selectReference(std::string reference) {
    selectScript();
    ((luabridge::LuaRef)_object[reference.c_str()]).push(_script->getState());
}

void LuaObject::pushObject() {
    selectScript();
    lua_pushvalue(_script->getState(), -1);
    lua_pop(_script->getState(), 1);
}