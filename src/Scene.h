#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Entity.h"
#include "TimeStep.h"

#include <imgui.h> 
using VeneriX::TimeStep;

class Scene {
private:
    std::vector<std::unique_ptr<Entity>> entities;
public:
    std::string name;
    Scene(std::string sceneName) : name(sceneName) {}
    virtual ~Scene() = default;

    Entity* CreateEntity(const std::string& entityName) {
        auto entity = std::make_unique<Entity>(entityName);
        Entity* ptr = entity.get();
        entities.push_back(std::move(entity));
        return ptr;
    }

    void UpdateEntities(const VeneriX::TimeStep& ts) {
        for (auto& entity : entities) {
            entity->Update(ts);
        }
    }

    virtual void Update(const VeneriX::TimeStep& ts) {}

    virtual void Render() {}
    virtual void RenderUI() {}
};