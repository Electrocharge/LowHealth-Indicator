#include "LowHealthOverlay.hpp"

static LowHealthOverlay g_lowHealthOverlay;

// LEVILAUNCHER NATIVE ENTRY INTEGRATION POINT
//
// Connect this file to the exact native-mod registration/initialization API
// confirmed from the LeviLauncher SDK/source for your version.
//
// Conceptual lifecycle:
//
// LeviLauncher loads this .so
//     -> register Low Health Overlay module
//     -> expose enabled + health threshold settings
//     -> wait for Minecraft/local player
//     -> on each confirmed HUD/render callback:
//            health = read local player health
//            g_lowHealthOverlay.onFrame(health)
//
// The concrete entry symbol and callback registration are deliberately not
// guessed here because a wrong native ABI/API can crash the game.
