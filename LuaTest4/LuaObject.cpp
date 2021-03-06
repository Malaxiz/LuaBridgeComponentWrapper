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

void LuaObject::beginCall(std::string function) {
    selectReference(function);
    lua_pushvalue(_script->getState(), -2);
}

void LuaObject::endCall(int argc, int results) {
    lua_pcall(_script->getState(), argc + 1, results, 0);
}

void LuaObject::endCall() {
    endCall(0, 0);
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

LuaScript* LuaObject::getScript() {
    return _script;
}
