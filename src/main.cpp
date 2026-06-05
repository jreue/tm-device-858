#include <Arduino.h>
#include <Button.h>
#include <shared_hardware_config.h>

#include "EspNowHelper.h"
#include "hardware_config.h"

uint8_t hubAddress[] = HUB_MAC_ADDRESS;
EspNowHelper espNowHelper;

Button* device101Switch = nullptr;
bool device101LastState = false;

Button* device102Switch = nullptr;
bool device102LastState = false;

Button* device103Switch = nullptr;
bool device103LastState = false;

Button* device104Switch = nullptr;
bool device104LastState = false;

Button* device105Switch = nullptr;
bool device105LastState = false;

Button* device106Switch = nullptr;
bool device106LastState = false;

Button* device107Switch = nullptr;
bool device107LastState = false;

Button* device108Switch = nullptr;
bool device108LastState = false;

void setupButtons();
void handleButton1Pressed(void* button_handle, void* usr_data);
void handleButton2Pressed(void* button_handle, void* usr_data);
void handleDevice101SwitchChanged(void* button_handle, void* usr_data);
void handleDevice102SwitchChanged(void* button_handle, void* usr_data);
void handleDevice103SwitchChanged(void* button_handle, void* usr_data);
void handleDevice104SwitchChanged(void* button_handle, void* usr_data);
void handleDevice105SwitchChanged(void* button_handle, void* usr_data);
void handleDevice106SwitchChanged(void* button_handle, void* usr_data);
void handleDevice107SwitchChanged(void* button_handle, void* usr_data);
void handleDevice108SwitchChanged(void* button_handle, void* usr_data);

void setup() {
  Serial.begin(115200);

  setupButtons();

  espNowHelper.begin(DEVICE_ID);
  espNowHelper.addPeer(hubAddress);
}

void loop() {
}

void setupButtons() {
  Button* button1 = new Button(BUTTON_1_PIN, false);
  button1->attachSingleClickEventCb(&handleButton1Pressed, NULL);

  Button* button2 = new Button(BUTTON_2_PIN, false);
  button2->attachSingleClickEventCb(&handleButton2Pressed, NULL);

  device101Switch = new Button(SWITCH_101_PIN, false);
  device101LastState = (digitalRead(SWITCH_101_PIN) == LOW);
  device101Switch->attachPressDownEventCb(handleDevice101SwitchChanged, nullptr);
  device101Switch->attachPressUpEventCb(handleDevice101SwitchChanged, nullptr);

  device102Switch = new Button(SWITCH_102_PIN, false);
  device102LastState = (digitalRead(SWITCH_102_PIN) == LOW);
  device102Switch->attachPressDownEventCb(handleDevice102SwitchChanged, nullptr);
  device102Switch->attachPressUpEventCb(handleDevice102SwitchChanged, nullptr);

  device103Switch = new Button(SWITCH_103_PIN, false);
  device103LastState = (digitalRead(SWITCH_103_PIN) == LOW);
  device103Switch->attachPressDownEventCb(handleDevice103SwitchChanged, nullptr);
  device103Switch->attachPressUpEventCb(handleDevice103SwitchChanged, nullptr);

  device104Switch = new Button(SWITCH_104_PIN, false);
  device104LastState = (digitalRead(SWITCH_104_PIN) == LOW);
  device104Switch->attachPressDownEventCb(handleDevice104SwitchChanged, nullptr);
  device104Switch->attachPressUpEventCb(handleDevice104SwitchChanged, nullptr);

  device105Switch = new Button(SWITCH_105_PIN, false);
  device105LastState = (digitalRead(SWITCH_105_PIN) == LOW);
  device105Switch->attachPressDownEventCb(handleDevice105SwitchChanged, nullptr);
  device105Switch->attachPressUpEventCb(handleDevice105SwitchChanged, nullptr);

  device106Switch = new Button(SWITCH_106_PIN, false);
  device106LastState = (digitalRead(SWITCH_106_PIN) == LOW);
  device106Switch->attachPressDownEventCb(handleDevice106SwitchChanged, nullptr);
  device106Switch->attachPressUpEventCb(handleDevice106SwitchChanged, nullptr);

  device107Switch = new Button(SWITCH_107_PIN, false);
  device107LastState = (digitalRead(SWITCH_107_PIN) == LOW);
  device107Switch->attachPressDownEventCb(handleDevice107SwitchChanged, nullptr);
  device107Switch->attachPressUpEventCb(handleDevice107SwitchChanged, nullptr);

  device108Switch = new Button(SWITCH_108_PIN, false);
  device108LastState = (digitalRead(SWITCH_108_PIN) == LOW);
  device108Switch->attachPressDownEventCb(handleDevice108SwitchChanged, nullptr);
  device108Switch->attachPressUpEventCb(handleDevice108SwitchChanged, nullptr);
}

void handleButton1Pressed(void* button_handle, void* usr_data) {
  espNowHelper.sendTravelOverride(hubAddress, DEVICE_ID);
}

void handleButton2Pressed(void* button_handle, void* usr_data) {
  espNowHelper.sendResetOverride(hubAddress, DEVICE_ID);
}

void handleDevice101SwitchChanged(void* button_handle, void* usr_data) {
  bool currentState = (digitalRead(SWITCH_101_PIN) == LOW);
  if (currentState == device101LastState)
    return;
  device101LastState = currentState;

  espNowHelper.sendModuleOverride(hubAddress, DEVICE_101_ID, currentState);
}

void handleDevice102SwitchChanged(void* button_handle, void* usr_data) {
  bool currentState = (digitalRead(SWITCH_102_PIN) == LOW);
  if (currentState == device102LastState)
    return;
  device102LastState = currentState;

  espNowHelper.sendModuleOverride(hubAddress, DEVICE_102_ID, currentState);
}

void handleDevice103SwitchChanged(void* button_handle, void* usr_data) {
  bool currentState = (digitalRead(SWITCH_103_PIN) == LOW);
  if (currentState == device103LastState)
    return;
  device103LastState = currentState;

  espNowHelper.sendModuleOverride(hubAddress, DEVICE_103_ID, currentState);
}

void handleDevice104SwitchChanged(void* button_handle, void* usr_data) {
  bool currentState = (digitalRead(SWITCH_104_PIN) == LOW);
  if (currentState == device104LastState)
    return;
  device104LastState = currentState;

  espNowHelper.sendModuleOverride(hubAddress, DEVICE_104_ID, currentState);
}

void handleDevice105SwitchChanged(void* button_handle, void* usr_data) {
  bool currentState = (digitalRead(SWITCH_105_PIN) == LOW);
  if (currentState == device105LastState)
    return;
  device105LastState = currentState;

  espNowHelper.sendModuleOverride(hubAddress, DEVICE_105_ID, currentState);
}

void handleDevice106SwitchChanged(void* button_handle, void* usr_data) {
  bool currentState = (digitalRead(SWITCH_106_PIN) == LOW);
  if (currentState == device106LastState)
    return;
  device106LastState = currentState;

  espNowHelper.sendModuleOverride(hubAddress, DEVICE_106_ID, currentState);
}

void handleDevice107SwitchChanged(void* button_handle, void* usr_data) {
  bool currentState = (digitalRead(SWITCH_107_PIN) == LOW);
  if (currentState == device107LastState)
    return;
  device107LastState = currentState;

  espNowHelper.sendModuleOverride(hubAddress, DEVICE_107_ID, currentState);
}

void handleDevice108SwitchChanged(void* button_handle, void* usr_data) {
  bool currentState = (digitalRead(SWITCH_108_PIN) == LOW);
  if (currentState == device108LastState)
    return;
  device108LastState = currentState;

  espNowHelper.sendModuleOverride(hubAddress, DEVICE_108_ID, currentState);
}