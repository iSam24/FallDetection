#include "process_prediction.h"
#include <string.h>

prediction_label_t parse_prediction(const char* label, float anomaly_score) {
    if (anomaly_score > 0.3f) {
        return PREDICTION_ANOMALY;
    }
    if (strcmp(label, "ADL") == 0) {
        return PREDICTION_ADL;
    }
    if (strcmp(label, "FALL") == 0) {
        return PREDICTION_FALL;
    }
    return PREDICTION_UNCERTAIN;
}

void handle_prediction(const char* label, float anomaly_score) {
    prediction_label_t prediction = parse_prediction(label, anomaly_score);

    switch (prediction) {
        case  PREDICTION_ANOMALY:
            // write to log "Anomoly detected"
            break;

        case PREDICTION_ADL:
            // do nothing (saves power)
            break;

        case PREDICTION_FALL:
            // Send bluetooth notification of a fall with timestamp
            break;

        case PREDICTION_UNCERTAIN:
            // write to log "Uncertain classifcation"
            break;

        default:
            // do something
            break;
    }
}

