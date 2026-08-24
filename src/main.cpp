#include "core/Runtime.hpp"
#include <pl/Mod.hpp>

class LowHealthOverlayMod {
public:
    static LowHealthOverlayMod& instance() {
        static LowHealthOverlayMod mod;
        return mod;
    }

    bool load(pl::mod::ModContext& context) {
        return lowhealth::Runtime::get().load(context);
    }

    bool enable(pl::mod::ModContext& context) {
        return lowhealth::Runtime::get().enable(context);
    }

    bool disable(pl::mod::ModContext& context) {
        return lowhealth::Runtime::get().disable(context);
    }

    bool unload(pl::mod::ModContext& context) {
        return lowhealth::Runtime::get().unload(context);
    }
};

PL_REGISTER_MOD(
    LowHealthOverlayMod,
    LowHealthOverlayMod::instance()
)
