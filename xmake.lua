set_project("LowHealthOverlay")
set_version("0.1.0")

add_rules("mode.release", "mode.debug")

target("LowHealthOverlay")
    set_kind("shared")
    add_files("src/*.cpp")
    add_includedirs("include")
    set_targetdir("build/$(plat)/$(arch)/$(mode)")

    -- Android/arm64-v8a toolchain configuration is supplied by the build environment.
    -- Add confirmed LeviLauncher/Preloader SDK include paths and libraries here.
