// Bluetooth utlity functions

#ifndef _BLE_SERVICE_H
#define _BLE_SERVICE_H

#include <ArduinoBLE.h>
#include "process_prediction.h"

// Fall Detection BLE Service
#define FALL_DETECTION_SERVICE_UUID         "4fafc201-1fb5-459e-8fcc-c5c9c331914b"

// Characteristics
#define PREDICTION_UUID                "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define ANOMALY_SCORE_UUID             "6d68efa7-c4b0-4b6f-ae9a-c3e5f1a9e2d1"
#define TIMESTAMP_UUID                 "a9e1c5f2-3d7b-4e8a-b0f6-2c1d9e4a7f3b"
#define SEQUENCE_UUID                  "f23639za-22h2-678z-a7f5-oap7321zf6a9"

int bleSetup(void);
int sendBLENotification(prediction_label_t prediction, float anomaly_score);


#endif // _BLE_SERVICE_H