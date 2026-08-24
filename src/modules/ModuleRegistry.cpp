#include "ModuleRegistry.hpp"
#include "LowHealthOverlay.hpp"

ModuleRegistry& ModuleRegistry::get() {
    static ModuleRegistry registry;
    return registry;
}

const std::vector<Module*>&
ModuleRegistry::modules() const {
    return mView;
}

void ModuleRegistry::initialize() {
    if (initialized) return;

    for (auto* module : mView) {
        module->onInit();
    }

    initialized = true;
}

void ModuleRegistry::onFrame() {
    for (auto* module : mView) {
        if (module->enabled) {
            module->onFrame();
        }
    }
}

void registerAllModules() {
    auto& registry = ModuleRegistry::get();

    if (!registry.modules().empty()) {
        return;
    }

    registry.emplace<LowHealthOverlayModule>();
}
