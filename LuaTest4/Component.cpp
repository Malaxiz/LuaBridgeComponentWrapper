//
//  Component.cpp
//  LuaTest4
//
//  Created by Didrik Munther on 16/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#include "Component.h"


Component::Component(Entity* parent, LuaScript* script)
    : _parent(parent)
    , _object(script)
{
    
}


void Component::onLoop() {
    _object.beginCall("onLoop");
    luabridge::Stack<Entity*>::push(_object.getScript()->getState(), _parent);
    _object.endCall(1, 0);
}