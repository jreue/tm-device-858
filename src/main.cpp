#include <Arduino.h>
#include <Button.h>
#include <shared_hardware_config.h>

#include "EspNowHelper.h"
#include "hardware_config.h"

uint8_t hubAddress[] = HUB_MAC_ADDRESS;
EspNowHelper espNowHelper;

Button* toggleSwitch = nullptr;
bool toggleLastState = false;

void setupButtons();
void onToggleChanged(void* button_handle, void* usr_data);

void setup() {
  Serial.begin(115200);

  setupButtons();

  espNowHelper.begin(DEVICE_ID);
  espNowHelper.addPeer(hubAddress);
}

void loop() {
}

void setupButtons() {
  toggleSwitch = new Button(BUTTON_ORIENTATION_PIN, true);
  toggleLastState = (digitalRead(BUTTON_ORIENTATION_PIN) == HIGH);
  toggleSwitch->attachPressDownEventCb(onToggleChanged, nullptr);
  toggleSwitch->attachPressUpEventCb(onToggleChanged, nullptr);
}

void onToggleChanged(void* button_handle, void* usr_data) {
  Serial.println("Toggle state changed");
  bool currentState = (digitalRead(BUTTON_ORIENTATION_PIN) == HIGH);
  if (currentState == toggleLastState)
    return;
  toggleLastState = currentState;
  Serial.println(currentState ? "Toggle: ON" : "Toggle: OFF");

  espNowHelper.sendModuleOverride(hubAddress, DEVICE_ORIENTATION_ID, currentState);
}