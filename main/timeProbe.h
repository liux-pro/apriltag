#include "esp_timer.h"

typedef struct {
    int64_t time;
    char * describe;
} timeProbe_t;

/**
 * 把当前时间记录到timeProbe里
 */
void timeProbe_start(timeProbe_t *timeProbe);
/**
 * 返回当前时间到timeProbe经过的事件
 */
int64_t timeProbe_stop(timeProbe_t *timeProbe);