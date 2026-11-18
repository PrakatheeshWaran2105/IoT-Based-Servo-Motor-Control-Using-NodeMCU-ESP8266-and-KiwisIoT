
#include <ESP8266WiFi.h>
#include <KiwisIoT.h>
#include <Servo.h>

// WiFi Credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// KiwisIoT Configuration
KiwisIoT kiwis;

// Servo Configuration
Servo myServo;
#define SERVO_PIN D5

int servoAngle = 90;

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");

  // Initialize Servo
  myServo.attach(SERVO_PIN);
  myServo.write(servoAngle);

  // Initialize KiwisIoT
  kiwis.begin();
}

void loop() {
  kiwis.loop();

  // Read servo angle from KiwisIoT Dashboard
  // Connect the dashboard slider to servoAngle
  // using your KiwisIoT variable/widget callback.

  myServo.write(servoAngle);

  delay(20);
}
