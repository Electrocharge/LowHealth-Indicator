#pragma once

class LowHealthOverlay {
public:
    void setEnabled(bool enabled);
    void setHealthThreshold(float threshold);
    void onFrame(float localPlayerHealth);

private:
    void drawFullscreenRedOverlay(float alpha);

    bool enabled_ = true;
    float healthThreshold_ = 6.0f;
};
