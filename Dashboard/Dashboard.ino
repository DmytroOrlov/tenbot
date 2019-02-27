#include <TM1650.h>
#include <Wire.h>
/*
 *  _______         ____        _   
 * |__   __|       |  _ \      | |  
 *    | | ___ _ __ | |_) | ___ | |_ 
 *    | |/ _ \ '_ \|  _ < / _ \| __|
 *    | |  __/ | | | |_) | (_) | |_ 
 *    |_|\___|_| |_|____/ \___/ \__|
 *                                  
 *    Dashboard Firmware 
 * Board manager URL: https://sandeepmistry.github.io/arduino-nRF5/package_nRF5_boards_index.json
 * Board type : Generic nRF51
 */
TM1650 d;
#define SDA 4 // Temporary pins mapping
#define SCL 6
#define buzzer 7
#define throttle 8
#define brake 9
#define uart 10
#define headlight 11
bool isScooterTurnedOn = false;
bool isScooterLocked = false;
bool isHeadlightTurnedOn = false;
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
  Wire.setPins(SDA, SCL);
  Wire.begin();
  pinMode(throttle, INPUT);
  pinMode(brake, INPUT);
  pinMode(headlight, OUTPUT);
  d.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
void controlBoardCommandHandler(byte command, int payload[16]) {
  int currentSpeed;
  int batteryState;
  switch (command) {
    case SET_SCOOTER_STATE:
      isScooterTurnedOn = payload[0];
      // TODO: turn on or off the dashboard
      analogWrite(buzzer, 127);
      delay(200);
      digitalWrite(buzzer, LOW);
      break;
    case SPEED_UPDATE:
      currentSpeed = payload[0];
      // TODO: Display the speed on the screen using I²C
      break;
    case SET_HEADLIGHT_STATE:
      isHeadlightTurnedOn = payload[0];
      digitalWrite(headlight, isHeadlightTurnedOn);
      break;
    case BATTERY_STATE:
      batteryState = payload[0];
      // TODO: Display the battery level on the screen using I²C
      break;
  }
}
