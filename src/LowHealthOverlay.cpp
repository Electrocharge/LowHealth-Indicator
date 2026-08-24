#include "LowHealthOverlay.hpp"
#include <algorithm>

void LowHealthOverlay::setEnabled(bool enabled) {
    enabled_ = enabled;
}

void LowHealthOverlay::setHealthThreshold(float threshold) {
    healthThreshold_ = std::max(0.1f, threshold);
}

void LowHealthOverlay::onFrame(float localPlayerHealth) {
    if (!enabled_ || localPlayerHealth > healthThreshold_) {
        return;
    }

    // At the threshold the overlay is faint. At zero health it reaches max alpha.
    float ratio = 1.0f - (localPlayerHealth / healthThreshold_);
    ratio = std::clamp(ratio, 0.0f, 1.0f);

    const float minAlpha = 0.12f;
    const float maxAlpha = 0.65f;
    const float alpha = minAlpha + (maxAlpha - minAlpha) * ratio;

    drawFullscreenRedOverlay(alpha);
}

void LowHealthOverlay::drawFullscreenRedOverlay(float alpha) {
    (void)alpha;

    // LEVILAUNCHER RENDER INTEGRATION POINT:
    // Draw a fullscreen translucent red rectangle here using the exact
    // confirmed LeviLauncher/Preloader/Minecraft render callback/API.
    //
    // Do not replace this with guessed offsets or symbols.
}
