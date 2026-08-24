#include "ModuleMenu.hpp"

#include "modules/ModuleRegistry.hpp"

#include <pl/ModMenu.hpp>
#include <string_view>

static void onModuleToggle(
    std::string_view moduleId,
    bool enabled
) {
    for (auto* module :
         ModuleRegistry::get().modules()) {

        if (module->moduleId == moduleId) {
            module->setMasterEnabled(enabled);
            return;
        }
    }
}

void registerModulesWithLauncher() {
    auto& modules =
        ModuleRegistry::get().modules();

    for (auto* mod : modules) {

        if (!mod->showInMenu) {
            continue;
        }

        pl::modmenu::ModuleBuilder builder(
            mod->moduleId,
            mod->name
        );

        builder
            .description(mod->description)
            .defaultEnabled(mod->masterEnabled)
            .onToggle(onModuleToggle);

        // Add the health threshold setting.
        if (mod->moduleId ==
            "lowhealthoverlay.LowHealthOverlay") {

            builder.config(
                "healthThreshold",
                "Health Threshold",
                pl::modmenu::ConfigType::SliderFloat,
                "6.0",
                "1.0",
                "20.0",
                ""
            );
        }

        (void)builder.registerModule();
    }
}
