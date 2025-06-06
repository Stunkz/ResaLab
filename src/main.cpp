#include <Arduino.h>
#include <WiFi.h>

#include <ScreenOutput.h>
#include <ServerConnection.h>
#include <ErrorCode.h>

#include "Identifier.h"

extern "C" int lwip_hook_ip6_input(void *p) {
  return 1; // Retourne 1 pour indiquer que le paquet IPv6 est accepté
}

ServerConnection server = ServerConnection();

void setupWifiConnection();
void setupServerConnection();

void setup() {

}

void loop() {

}

void setupWifiConnection() {
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
}

void setupServerConnection() {
  do {
    errorCode = server.connect(host);

    if (errorCode != CODE_SUCCESS) {
      delay(1000);
    } else {
    }
  } while (errorCode != CODE_SUCCESS);
}
