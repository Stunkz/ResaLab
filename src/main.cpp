#include <Arduino.h>
#include <ScreenOutput.h>

#include <ServerConnection.h>

#include <WiFi.h>

#include <ErrorCode.h>

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
  log_i("Connecting to network...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    log_v("Waiting for connection...");
  }

  log_v("Connected to WiFi!");
  log_i("IP address: %s", WiFi.localIP().toString().c_str());
}

void setupServerConnection() {
  log_i("Connecting to server...");
  do {
    errorCode = server.connect(host);

    if (errorCode != CODE_SUCCESS) {

      display.text("Server", "Error", "", 0);
      log_e("Error connecting to server: %d", errorCode);

      delay(1000);
    } else {

      display.text("Server", "Ready", "", 0);
      log_v("Server connected successfully.");

    }
  } while (errorCode != CODE_SUCCESS);
}
