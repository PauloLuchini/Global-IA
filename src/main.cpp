#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

#define DHTPIN 4          
#define DHTTYPE DHT22
#define NUM_ELEMENTOS 10


#define POTPIN 34

const char* mqtt_server = "test.mosquitto.org"; 

WiFiClient espClient;
PubSubClient client(espClient);

DHT dht(DHTPIN, DHTTYPE);

void setup_wifi() {
  delay(10);
  Serial.print("Conectando-se ao Wi-Fi");
  WiFi.begin("Wokwi-GUEST", "", 6);  
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Conectado!");
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  setup_wifi();
  client.setServer(mqtt_server, 1883);

}

void sendSensorData() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int potValue = analogRead(POTPIN);

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Leitura do DHT22 falhou (Simulação). Usando valores padrão.");
    humidity = random(300, 800) / 10.0;     
    temperature = random(150, 300) / 10.0;
  }

  
  float consumoEnergia = map(potValue, 0, 4095, 0, 100) / 10.0;

  
  if (client.publish("empresa/sensor/temperatura", String(temperature).c_str())) {
    Serial.println("Temperatura publicada com sucesso!");
  } else {
    Serial.println("Falha ao publicar temperatura.");
  }

  if (client.publish("empresa/sensor/umidade", String(humidity).c_str())) {
    Serial.println("Umidade publicada com sucesso!");
  } else {
    Serial.println("Falha ao publicar umidade.");
  }

  if (client.publish("empresa/sensor/consumoenergia", String(consumoEnergia).c_str())) {
    Serial.println("Consumo de Energia publicado com sucesso!");
  } else {
    Serial.println("Falha ao publicar consumo de energia.");
  }


  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.print(" °C, Umidade: ");
  Serial.print(humidity);
  Serial.print(" %, Consumo de Energia: ");
  Serial.print(consumoEnergia);
  Serial.println(" kWh");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando reconectar...");
    if (client.connect("ESP32Client_")) {
      Serial.println("Conectado ao broker MQTT");
      client.subscribe("empresa/#");
    } else {
      Serial.print("Falha na reconexão. Tentando novamente em 10 segundos.");
      delay(10000);  
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  sendSensorData();
  delay(5000); 
}
