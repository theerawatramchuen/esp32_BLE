// GPT-4 prompt : Give code of program sets up the ESP32 as a Bluetooth Low Energy device with a custom service and characteristic. It then starts advertising, with the signal strength (RSSI) included as part of the manufacturer data in the advertising payload.
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// Unique service and characteristic UUIDs
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");

  // Initialize BLE and set it up as a server
  BLEDevice::init("310009490-0");
  BLEServer *pServer = BLEDevice::createServer();

  // Create a new service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a new characteristic
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristic->setValue("COLOR VISION DEVELOPMENT");

  // Start the service
  pService->start();

  // Start advertising
  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();

  Serial.println("Characteristic defined! Now you can read it in your phone!");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
}

