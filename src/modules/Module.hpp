#pragma once

#include <string>

class Module {
public:
    const char* name;
    const char* description;
    std::string moduleId;

    bool masterEnabled = false;
    bool enabled = false;
    bool showInMenu = true;

    Module(
        const char* moduleName,
        const char* moduleDescription
    )
        : name(moduleName),
          description(moduleDescription),
          moduleId(
              std::string("lowhealthoverlay.") + moduleName
          ) {}

    virtual ~Module() = default;

    virtual void onInit() {}
    virtual void onEnable() {}
    virtual void onDisable() {}
    virtual void onFrame() {}

    void setMasterEnabled(bool state) {
        if (masterEnabled == state) return;

        masterEnabled = state;

        if (enabled == masterEnabled) return;

        enabled = masterEnabled;

        if (enabled) {
            onEnable();
        } else {
            onDisable();
        }
    }
};
