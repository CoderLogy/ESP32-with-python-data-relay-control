#include <WiFi.h>
const char* ssid = "wifi ip address";
const char* pass = "wifi password";
const uint16_t port = 8091;
const char* host = "ip of your host";
int led = 2;
void setup(){
    pinMode(led, OUTPUT);
    Serial.begin(115200);
    WiFi.begin(ssid, pass);
     while (WiFi.status() != WL_CONNECTED) {
        delay(600);
        Serial.println("...Waitning for connection...");
    }
    Serial.println(WiFi.localIP());
}
void loop(){
    WiFiClient client;
    if(!client.connect(host, port)){
        Serial.println("stopping...");
        return;
    }
    client.println("We are friend right human");
    client.read();
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led,LOW);
    client.stop();
    delay(10000);
}
