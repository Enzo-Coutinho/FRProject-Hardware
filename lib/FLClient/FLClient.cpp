#include "FLClient.h"

bool FLClient::clientStatus = false;

void FLClient::initWiFi() {
    setChannel();
    WiFi.onEvent(events);
}

void FLClient::setChannel() {
  int n = WiFi.scanNetworks();
  if (n == 0) {
    log_d("no networks found");
  } else {
      int canais[n];
      int canaisFix[14] = {};
      log_d("networks found");
      for (int i = 0; i < n; ++i) {
          canais[i] = WiFi.channel(i);
          canaisFix[canais[i]]++;
      }
      int low = 20;
      int channel = 1;
      for(int i = 1; i < 14; i++) {
        if(canaisFix[i] < low) {
          channel = i;
          low = canaisFix[i];
        }
      }
  WiFi.softAP(ssid, password, channel);
  }
}

void FLClient::events(WiFiEvent_t event){
    Serial.printf("[WiFi-event] event: %d\n", event);

    switch (event) {
        case ARDUINO_EVENT_WIFI_READY: 
            Serial.println("WiFi interface ready");
            break;
        case ARDUINO_EVENT_WIFI_SCAN_DONE:
            Serial.println("Completed scan for access points");
            break;
        case ARDUINO_EVENT_WIFI_STA_START:
            Serial.println("WiFi client started");
            break;
        case ARDUINO_EVENT_WIFI_STA_STOP:
            Serial.println("WiFi clients stopped");
            break;
        case ARDUINO_EVENT_WIFI_STA_CONNECTED:
            Serial.println("Connected to access point");
            break;
        case ARDUINO_EVENT_WIFI_STA_DISCONNECTED:
            Serial.println("Disconnected from WiFi access point");
            break;
        case ARDUINO_EVENT_WIFI_STA_AUTHMODE_CHANGE:
            Serial.println("Authentication mode of access point has changed");
            break;
        case ARDUINO_EVENT_WIFI_STA_GOT_IP:
            Serial.print("Obtained IP address: ");
            Serial.println(WiFi.localIP());
            break;
        case ARDUINO_EVENT_WIFI_STA_LOST_IP:
            Serial.println("Lost IP address and IP address is reset to 0");
            break;
        case ARDUINO_EVENT_WIFI_AP_STACONNECTED:
            Serial.println("Client AP connected");
            break;
        case ARDUINO_EVENT_WIFI_AP_STAIPASSIGNED:
            clientStatus = true;
            Serial.println("IP assigned");
            break;
        case ARDUINO_EVENT_WIFI_AP_STADISCONNECTED:
            clientStatus = false;
            Serial.println("Client disconnected");
            break;
        case ARDUINO_EVENT_WIFI_AP_START:
            break;
        case ARDUINO_EVENT_WIFI_AP_STOP:
            break;
    }
}

void FLClient::reconnect(void * arg) {
    TickType_t xDelay = 500 / portTICK_PERIOD_MS;
    while(1) {
        if(WiFi.status() != WL_CONNECTED) {
            log_e("ESP32 desconectada da rede!");
            WiFi.reconnect();
            vTaskDelay(xDelay);
        }
    }
}

int * FLClient::getEmotes() {
    if(clientStatus) {
        client.begin(url);

        int code = client.GET();
        log_d("Código de resposta HTTP", code);
                // Get the raw and the decoded stream
            Stream& rawStream = client.getStream();
            ChunkDecodingStream decodedStream(client.getStream());

            // Choose the right stream depending on the Transfer-Encoding header
            Stream& response =
                client.header("Transfer-Encoding") == "chunked" ? decodedStream : rawStream;

            // Parse response
            JsonDocument doc;
            deserializeJson(doc, response);
            
        colors[0] = doc["r"];
        colors[1] = doc["g"];
        colors[2] = doc["b"];
        // Read values
    client.end();
    }
    return colors;
}