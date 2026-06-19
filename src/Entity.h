#pragma once
#include <vector>
#include <memory>
#include <string>
#include <typeinfo>
#include "Component.h"
#include "TimeStep.h"

class Entity {
private:
    std::vector<std::unique_ptr<Component>> components;

public:
    std::string name;

    Entity(std::string entityName = "Entity") : name(entityName) {}

    template<typename T, typename... Args>
    T* AddComponent(Args&&... args) {
        T* newComponent = new T(std::forward<Args>(args)...);
        newComponent->owner = this;
        components.emplace_back(newComponent);
        newComponent->Start();
        return newComponent;
    }

    template<typename T>
    T* GetComponent() {
        for (auto& comp : components) {
            T* ptr = dynamic_cast<T*>(comp.get());
            if (ptr != nullptr) {
                return ptr;
            }
        }
        return nullptr;
    }

    void Update(const VeneriX::TimeStep& ts) {
        for (auto& comp : components) {
            comp->Update(ts);
        }
    }
};