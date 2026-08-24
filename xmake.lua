set_project("LowHealthOverlay")
set_version("0.1.0")

add_rules("mode.debug", "mode.release")

-- Preloader / LeviLauncher SDK
package("preloader")
    set_kind("library")
    set_homepage("https://github.com/LiteLDev/preloader-android")
    set_description("Preloader Android SDK")

    add_urls("https://github.com/LiteLDev/preloader-android.git")
    add_versions("main", "main")

    add_deps("cmake")

    on_install("android", function (package)
        import("package.tools.cmake").install(package)
    end)
package_end()

-- Dependencies
add_requires("preloader")
add_requires("nlohmann_json v3.11.3")
add_requires("fmt")

-- Our native library
target("LowHealthOverlay")
    set_kind("shared")
    set_languages("c++20")

    set_targetdir("build/$(plat)/$(arch)/$(mode)")
    set_basename("LowHealthOverlay")

    add_files(
        "src/main.cpp",
        "src/core/*.cpp",
        "src/launcher/*.cpp",
        "src/modules/*.cpp"
    )

    add_includedirs("src")

    add_packages(
        "preloader",
        "nlohmann_json",
        "fmt"
    )

    if is_plat("android") then
        add_cxflags("-fPIC")
        add_links("android", "log")
    end

    if is_mode("release") then
        set_optimize("smallest")
        set_strip("all")
end
