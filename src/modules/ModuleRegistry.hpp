#pragma once

#include "Module.hpp"
#include <memory>
#include <vector>

class ModuleRegistry {
public:
    static ModuleRegistry& get();

    template <class T, class... Args>
    T& emplace(Args&&... args) {
        auto module =
            std::make_unique<T>(
                std::forward<Args>(args)...
            );

        auto* raw = module.get();

        mView.push_back(raw);
        mOwned.push_back(std::move(module));

        return *raw;
    }

    const std::vector<Module*>& modules() const;

    void initialize();
    void onFrame();

private:
    std::vector<std::unique_ptr<Module>> mOwned;
    std::vector<Module*> mView;
    bool initialized = false;
};

void registerAllModules();
