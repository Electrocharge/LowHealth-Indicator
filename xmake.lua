add_rules("mode.debug", "mode.release")

package("preloader")
    set_homepage(
        "https://github.com/LiteLDev/preloader-android"
    )

    set_description("Preloader Android")

    add_urls(
        "https://github.com/LiteLDev/preloader-android.git"
    )

    add_versions("main", "main")

    add_deps("cmake")

    on_install("android", function (package)
        import("package.tools.cmake")
            .install(package)
    end)
package_end()

add_requires("preloader")
add_requires("nlohmann_json v3.11.3")

target("LowHealthOverlay")
    set_kind("shared")
    set_languages("c++20")
    set_strip("all")

    add_files(
        "src/main.cpp",
        "src/core/*.cpp",
        "src/launcher/*.cpp",
        "src/modules/*.cpp"
    )

    add_includedirs(
        "src"
    )

    add_packages(
        "preloader",
        "nlohmann_json"
    )

    if is_plat("android") then
        add_cxflags("-fPIC")
        add_links("android", "log")
end
