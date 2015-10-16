//
//  Entity.cpp
//  LuaTest4
//
//  Created by Didrik Munther on 16/10/15.
//  Copyright (c) 2015 Didrik Munther. All rights reserved.
//

#include "Entity.h"


void Entity::onLoop() {
    for(auto& i: components) {
        i.second->onLoop();
    }
}