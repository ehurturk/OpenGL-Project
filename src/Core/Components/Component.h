#pragma once

enum class ComponentType {
    Mesh,
    Transform
};

class Component
{
public:
  
    virtual void update() = 0;
    virtual ComponentType& getComponentType() = 0;
    virtual const char* getID() { return id; } 

protected:
    const char* id;

};
