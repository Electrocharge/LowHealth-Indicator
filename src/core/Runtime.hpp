#pragma once

#include <pl/Mod.hpp>

namespace lowhealth {

class Runtime {
public:
    static Runtime& get();

    bool load(pl::mod::ModContext& context);
    bool enable(pl::mod::ModContext& context);
    bool disable(pl::mod::ModContext& context);
    bool unload(pl::mod::ModContext& context);

private:
    bool installed = false;
};

}
