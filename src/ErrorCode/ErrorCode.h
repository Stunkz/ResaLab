#ifndef ERROR_CODE_H
#define ERROR_CODE_H

#include <Arduino.h>

#define CODE_SUCCESS (0)



// Server error codes
#define ERROR_SERVER_CONNECTION_FAILED  (200) // Connection to the server failed
#define ERROR_INVALID_REQUEST           (201) // The request is invalid
#define ERROR_INVALID_SERVER_PAYLOAD    (202) // The server payload is invalid
#define ERROR_WIFI_DISCONNECTED         (203) // The wifi is disconnected
#define ERROR_SERVER_DISCONNECTED       (204) // The server is disconnected
#define ERROR_INVALID_SERVER_RESPONSE   (205) // The server response is invalid


extern uint8_t errorCode; // Global variable to store the error code

#endif // ERROR_CODE_H