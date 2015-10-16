-- Movable.lua

Movable = class (
    function(self)
        self.jumpPower = 10.0
        self.accelerationX = 1.5
        self.accelerationY = 100.0
        self.stoppingAccelerationX = 1.5
        self.stoppingAccelerationY = 100.0

        self.hasWalkedX = false
        self.hasWalkedY = false

        self.WALKING_MOVEMENT = 0
        self.SNEAKING_MOVEMENT = 1
        self.RUNNING_MOVEMENT = 2

        self.movementState = self.WALKING_MOVEMENT
        self.movementSpeeds = {}
        self.movementSpeeds[self.WALKING_MOVEMENT] = 10.0
        self.movementSpeeds[self.SNEAKING_MOVEMENT] = self.movementSpeeds[self.WALKING_MOVEMENT] / 2.0
        self.movementSpeeds[self.RUNNING_MOVEMENT] = self.movementSpeeds[self.WALKING_MOVEMENT] * 2.0

    end
)

function Movable:onLoop(parent)
    body = parent.body

    body.velX = body.velX + 1.5
    self.jumpPower = self.jumpPower - 1
    print(body.velX .. " | " .. self.jumpPower)

    --[[

	if(not self.hasWalkedX) then
        if(body.velX < 0) then
            body.velX = body.velX + self.stoppingAccelerationX
            if(body.velX >= 0) then
                body.velX = 0.0
            end
        else
            body.velX = body.velX - self.stoppingAccelerationX
            if(body.velX <= 0) then
                body.velX = 0.0
            end
        end
    end
    
    if(not self.hasWalkedY) then
        if(false) then --if(parent.hasProperty(EntityProperty::FLYING)) then
            if(body.velY < 0) then
                body.velY = body.velY + self.stoppingAccelerationY
                if(body.velY >= 0) then
                    body.velY = 0.0
                end
            else
                body.velY = body.velY - self.stoppingAccelerationY
                if(body.velY <= 0) then
                    body.velY = 0.0
                end
            end
        end
    end
    
    self.hasWalkedX = false
    self.hasWalkedY = false

    --]]
end

function Movable:goRight(parent)
    body = parent.body

	body.velX = body.velX + self.accelerationX;
    
    if(body.velX > self.movementSpeeds[self.movementState]) then
        body.velX = self.movementSpeeds[self.movementState]
    end
    
    self.hasWalkedX = true
end

function Movable:goLeft(parent)
    body = parent.body

	body.velX = body.velX - self.accelerationX
    
    if(body.velX < -self.movementSpeeds[self.movementState]) then
        body.velX = self.movementSpeeds[self.movementState]
    end
    
    self.hasWalkedX = true;
end

function Movable:goUp(parent)
    body = parent.body

	if(false) then --if(parent.hasProperty(EntityProperty::FLYING)) then
        body.velY = body.velY - self.accelerationY
        
        if(body.velY < -self.movementSpeeds[self.movementState]) then
            body.velY = -self.movementSpeeds[self.movementState]
        end
    else
        self.jump(parent)
    end
    
    self.hasWalkedY = true
end

function Movable:goDown(parent)
    body = parent.body

	if(false) then --if(hasProperty(EntityProperty::FLYING)) then
        body.velY = body.velY + self.accelerationY
        
        if(body.velY > self.movementSpeeds[self.movementState]) then
            body.velY = self.movementSpeeds[self.movementState]
        end
    end
    
    self.hasWalkedY = true
end

function Movable:jump(parent)
    body = parent.body

	--if(not parent.collisionSides.bottom)
    --    return
    
    body.velY = body.velY - self.accelerationY
    if(body.velY < -self.jumpPower) then
        body.velY = -self.jumpPower
    end
end

function create()
    return Movable()
end