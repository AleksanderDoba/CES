#include "movement_system.hpp"

#include <stdio.h>

int main(){
    Entity e;
    E_ADD(e, PositionComponent, 0.0f, 0.0f)
    E_ADD(e, VelocityComponent, 60.0f, -60.0f)

    SYS_ADD(MovementSystem, e)
    SYS_RUN(MovementSystem)

    E_GET(e, PositionComponent, p)

    printf("%f %f\n", p.x, p.y);

    return 0;
}
