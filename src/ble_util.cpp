#include "ble_util.h"

BLEService fallService(FALL_DETECTION_SERVICE_UUID);

BLEByteCharacteristic prediction(PREDICTION_UUID, BLENotify | BLERead);
BLEFloatCharacteristic anomalyScore(ANOMALY_SCORE_UUID, BLENotify | BLERead);
BLEUnsignedLongCharacteristic timestamp(TIMESTAMP_UUID, BLENotify | BLERead);
BLEShortCharacteristic sequence(SEQUENCE_UUID, BLENotify | BLERead);

/**
*   @brief  Setups BLE service and characteristics
*   @return 1 if successful
*/
int bleSetup(void) {
    
    BLE.begin();

    BLE.setDeviceName("Fall Detection");
    BLE.setLocalName("Fall Detection Sensing");

    fallService.addCharacteristic(prediction);
    fallService.addCharacteristic(anomalyScore);
    fallService.addCharacteristic(timestamp);
    fallService.addCharacteristic(sequence);

    BLE.addService(fallService);

    BLE.setAdvertisedService(fallService);

    BLE.advertise();

    return 1;
}
/**
 *  @brief  Sends BLE notification
 *  
 *  @param  prediction, anomaly_score
 *  @return int, 0 = success, 1 = error
 * 
 */
int sendBLENotification(prediction_label_t prediction_val, float anomaly_score) {
    BLEDevice central = BLE.central();
    
    static uint8_t seq = 0;

    // Check if a central device is connected (avoids wasting energy sending to no one listening)
    if (central && central.connected()) {
        sequence.writeValue(seq++);

        // ADL       = 1
        // FALL      = 2
        // UNCERTAIN = 3
        // ANOMALY   = 4
        prediction.writeValue((uint8_t)prediction_val + 1);
        anomalyScore.writeValue(anomaly_score);
        timestamp.writeValue((unsigned long)millis());
    } else {
        Serial.println("BLE: no central device connected");
        return 1;
    }

    return 0;
}
