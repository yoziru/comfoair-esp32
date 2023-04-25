#ifndef MQTT_H
#define MQTT_H

#include <inttypes.h>
#include <PubSubClient.h>
#include <map>

namespace comfoair {
  class MQTT {
    public:
      MQTT();
      void subscribeTo(const char* const topic, MQTT_CALLBACK_SIGNATURE);
      void setup();
      void loop();
      void writeToTopic(const char* const topic, const char* const payload);

    private:
      PubSubClient client;
      std::map<std::string, std::function<void(char*, uint8_t*, unsigned int)>> callbackMap;
      void subscribeToTopics();
      void ensureConnected();
  };
}

#endif