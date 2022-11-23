#include "../secrets.h"
#include <WiFi.h>
#include "wifi.h"

namespace comfoair {
  void WiFi::setup() {
      Serial.println();
      Serial.print("Connecting to ");
      Serial.println(WIFI_SSID);
      ::WiFi.hostname(HOSTNAME);

      ::WiFi.onEvent([](WiFiEvent_t _event, WiFiEventInfo_t info) {
        Serial.println("Wifi Disconnected! Reason:");
        Serial.println(info.disconnected.reason);

        ::WiFi.disconnect();
        ::WiFi.reconnect();
      }, SYSTEM_EVENT_STA_DISCONNECTED);
      
      ::WiFi.begin(WIFI_SSID, WIFI_PASS);
      ::WiFi.setAutoReconnect(true);
      while (::WiFi.status() != WL_CONNECTED) {
          delay(500);
          Serial.print(".");
      }
      Serial.println("");
      Serial.println("WiFi Connected. IP: ");
      Serial.println(::WiFi.localIP());
  }
  
  void WiFi::loop() {
      // Do nothing!
  }
} 