#pragma once
#include "TimeStep.h"
class Entity;

class Component {
public:
    Entity* owner = nullptr;

    virtual ~Component() = default;

    virtual void Start() {}

    virtual void Update(const VeneriX::TimeStep& ts) {}
};