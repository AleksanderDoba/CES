#pragma once

#include <map>
#include <vector>

typedef unsigned int Entity;

inline Entity entity_get(){
    static Entity next_id = 1;
    return next_id++;
}

struct BaseSystem {
    std::vector<Entity> entities;
};

#define SYSTEM(System) System System ## _instance
#define COMPONENTS(Component) std::map<Entity, Component> Component ## s

#define E_ADD(entity, Component, ...) { Component temp = {__VA_ARGS__}; Component ## s[entity] = temp; }
#define E_GET(entity, Component, component) Component &component = Component ## s[entity];
#define E_DEL(entity, Component) Component ## s[entity.erase(Component ## s.find(entity));

#define SYS_ADD(System, entity) System ## _instance.entities.push_back(entity);
#define SYS_RUN(System) System ## _instance.run();
