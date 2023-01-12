#include "timeProbe.h"

void timeProbe_start(timeProbe_t *timeProbe) {
    timeProbe->time = esp_timer_get_time();
}

int64_t timeProbe_stop(timeProbe_t *timeProbe) {
    return esp_timer_get_time() - timeProbe->time;
}