#pragma once

#include "Module.hpp"
#include <nlohmann/json.hpp>

class LowHealthOverlayModule : public Module {
public:
    LowHealthOverlayModule()
        : Module(
            "LowHealthOverlay",
            "Shows a red overlay when your health is low."
        ) {}

    float healthThreshold = 6.0f;

    void onFrame() override;

    void loadConfig(const nlohmann::json& j);
    void saveConfig(nlohmann::json& j) const;
};
