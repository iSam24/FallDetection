#include <string.h>
#include "process_prediction.h"
#include "ble_util.h"

prediction_label_t parse_prediction(const char* label, float anomaly_score) {
    if (anomaly_score > 0.3f) {
        return PREDICTION_ANOMALY;
    }
    if (strcmp(label, "ADL") == 0) {
        Serial.println("parse_prediction: ADL detected");
        return PREDICTION_ADL;
    }
    if (strcmp(label, "FALL") == 0) {
        Serial.println("parse_prediction: FALL detected");
        return PREDICTION_FALL;
    }
    return PREDICTION_UNCERTAIN;
}

void handle_prediction(const char* label, float anomaly_score) {
    prediction_label_t prediction = parse_prediction(label, anomaly_score);

    switch (prediction) {
        case  PREDICTION_ANOMALY:
            // Notify anomoly over BLE
            sendBLENotification(prediction, anomaly_score);
            break;

        case PREDICTION_ADL:
            sendBLENotification(prediction, anomaly_score);
            break;

        case PREDICTION_FALL:
            // Send bluetooth notification of a fall with timestamp
            sendBLENotification(prediction, anomaly_score);
            break;

        case PREDICTION_UNCERTAIN:
            // Notify over BLE
            sendBLENotification(prediction, anomaly_score);
            break;

        default:
            // do something
            break;
    }
}
