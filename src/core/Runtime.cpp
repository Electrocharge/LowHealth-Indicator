#include "Runtime.hpp"

#include "modules/ModuleRegistry.hpp"
#include "launcher/ModuleMenu.hpp"

namespace lowhealth {

Runtime& Runtime::get() {
    static Runtime runtime;
    return runtime;
}

bool Runtime::load(
    pl::mod::ModContext&
) {
    return true;
}

bool Runtime::enable(
    pl::mod::ModContext&
) {
    if (installed) {
        return true;
    }

    // 1. Create our internal module.
    registerAllModules();

    // 2. Initialise it.
    ModuleRegistry::get().initialize();

    // 3. Tell LeviLauncher about it.
    registerModulesWithLauncher();

    installed = true;

    return true;
}

bool Runtime::disable(
    pl::mod::ModContext&
) {
    return true;
}

bool Runtime::unload(
    pl::mod::ModContext&
) {
    return true;
}

}
