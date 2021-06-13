#pragma once

enum class ComponentType {
    Mesh,
    Transform
};

class Component
{
public:
    virtual ~Component() {}
    
    virtual void update() = 0;
    virtual const ComponentType& getComponentType() { return type; }
    virtual const char* getID() { return id; } 

protected:
    const char* id;
    ComponentType type;
};
