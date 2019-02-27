/*
 *  _______         ____        _   
 * |__   __|       |  _ \      | |  
 *    | | ___ _ __ | |_) | ___ | |_ 
 *    | |/ _ \ '_ \|  _ < / _ \| __|
 *    | |  __/ | | | |_) | (_) | |_ 
 *    |_|\___|_| |_|____/ \___/ \__|
 *                                  
 *    Control Board Firmware                          
 * Board manager URL: http://dan.drown.org/stm32duino/package_STM32duino_index.json
 * Board type : Generic STM32F103C
 */
bool isScooterTurnedOn = false;
bool isScooterLocked = false;
/* 
 * TenbotMessages protocol implementation
 * 
 * TenbotMessages follow this scheme : 1 byte command + 1 to 16 int payload (can be omitted if the command doesn't require it)
 * For more details on the protocol, please check the Wiki page
 * Dashboard <-> Control Board messsages :
 */
#define SET_SCOOTER_STATE 0x01
#define SET_SCOOTER_LOCK 0x02
#define BRAKE_THROTTLE_UPDATE 0x03
#define SPEED_UPDATE 0x04
#define SETTINGS_UPDATE 0x05
#define SET_HEADLIGHT_STATE 0x06
#define BATTERY_STATE 0x07
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
void dashboardCommandHandler(byte command, int payload[16]) {
  int brakeValue;
  int throttleValue;
  switch (command) {
    case SET_SCOOTER_LOCK:
      isScooterLocked = payload[0];
      // TODO: set the real lock...
      break;
    case BRAKE_THROTTLE_UPDATE:
      brakeValue = payload[0];
      throttleValue = payload[1];
      // TODO: Power the motor according to these values, and make the rearlight blink when braking 
      break;
    case SETTINGS_UPDATE:
      int setting = payload[0];
      //updateSetting(setting, &payload[1]);
      break;
  }
}
