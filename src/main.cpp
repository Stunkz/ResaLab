#include <Arduino.h>
#include <ScreenOutput.h>

#include <ServerConnection.h>


extern "C" int lwip_hook_ip6_input(void *p) {
  return 1; // Retourne 1 pour indiquer que le paquet IPv6 est accepté
}

ServerConnection server = ServerConnection();

void setup() {

}

void loop() {

}
