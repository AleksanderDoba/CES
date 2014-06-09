#pragma once

#include "position_component.hpp"
#include "velocity_component.hpp"

struct MovementSystem : BaseSystem {
    void run(){
        for (std::vector<Entity>::iterator it = entities.begin(); it != entities.end(); ++it){
            Entity &e = *it;
            E_GET(e, PositionComponent, p)
            E_GET(e, VelocityComponent, v)
            // Any idea how to get delta time in here?
            float dt = 1.0f/60.0f;
            p.x += v.x*dt;
            p.y += v.y*dt;
        }
    }
};

extern SYSTEM(MovementSystem);
