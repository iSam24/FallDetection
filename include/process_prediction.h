// Provides an interface to take an action based on the predicted class.

#ifndef _PROCESS_PREDICTION_H
#define _PROCESS_PREDICTION_H

typedef enum {
    PREDICTION_ADL = 0,
    PREDICTION_FALL,
    PREDICTION_UNCERTAIN,
    PREDICTION_ANOMALY
} prediction_label_t;


prediction_label_t parse_prediction(const char* label, float anomaly_score);
void handle_prediction(const char* label, float anomaly_score);


#endif // _PROCESS_PREDICTION_H
