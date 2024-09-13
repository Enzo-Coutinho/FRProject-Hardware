#include "FLClient.h"

void FLClient::initWiFi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, passoword);
    WiFi.onEvent(events);
    // xTaskCreatePinnedToCore(reconnect, "Reconnect", 4000, NULL, 2, &reconnectHandler, tskNO_AFFINITY);
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
        default: break;
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
    if(WiFi.status() == WL_CONNECTED) {
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