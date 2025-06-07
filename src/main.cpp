#include <Arduino.h>
#include <WiFi.h>

#include <ScreenOutput.h>
#include <ServerConnection.h>

#include <led.h>

#include "Identifier.h"

#define GREEN_LED_PIN 0
#define ORANGE_LED_PIN 9
#define RED_LED_PIN 1


extern "C" int lwip_hook_ip6_input(void *p) {
  return 1; // Retourne 1 pour indiquer que le paquet IPv6 est accepté
}

volatile bool isWifiConnected = false;

ServerConnection server;
TaskHandle_t connectionTaskHandle = NULL;

ScreenOutput screenOutput;

Led greenLed = Led(GREEN_LED_PIN);
Led orangeLed = Led(ORANGE_LED_PIN);
Led redLed = Led(RED_LED_PIN);

struct ConnectionTaskParameter {
  ServerConnection *server;
  WiFiClass *wifi;
  volatile bool *isWifiConnected;
  Led *orangeLed;
};

void connectionHandler(void *parameter);

void mainSreen();

void setup() {
  Serial.begin(115200);

  Serial.println("Starting ResaLab...");

  screenOutput.showLoading();
  WiFi.begin(ssid, password);
  ConnectionTaskParameter params = {
    .server = &server,
    .wifi = &WiFi,
    .isWifiConnected = &isWifiConnected,
    .orangeLed = &orangeLed
  };
  
  xTaskCreate(
    connectionHandler,
    "ConnectionHandler",
    2048,
    (void *)&params,
    1,
    &connectionTaskHandle
  );
  
}

void loop() {
  if (!isWifiConnected) {

  }
}

void connectionHandler(void *parameter) {

  // Cast the parameter to the expected type
  ConnectionTaskParameter *params = (ConnectionTaskParameter *)parameter;
  ServerConnection *server = params->server;
  WiFiClass *wifi = params->wifi;
  volatile bool *isWifiConnected = params->isWifiConnected;
  Led *orangeLed = params->orangeLed;

  uint8_t errorCode;
  while (true) {
    if (!(*isWifiConnected)) {
      wifi->reconnect();
      server->reconnect();
    }
    errorCode = server->checkConnection();
    
    if (errorCode == ERROR_WIFI_DISCONNECTED) {
      orangeLed->blink(1000);
    }

    if (errorCode == ERROR_SERVER_DISCONNECTED) {
      orangeLed->blink(500, 250);
      orangeLed->blink(500, 1000);
    }

    *isWifiConnected = (errorCode == CODE_SUCCESS);
  }
}

void mainScreen() {
  int hour = 12; // Example hour
  int minute = 30; // Example minute

  screenOutput.showHour(hour, minute);
  screenOutput.showInternetState(isWifiConnected);

  
}
