#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "timeProbe.h"
#include "apriltag.h"
#include "tag16h5.h"


#include "common/image_u8.h"
#include "common/zarray.h"

extern uint8_t pic[];

void app_main(void) {
    apriltag_family_t *tf = NULL;
    tf = tag16h5_create();
    apriltag_detector_t *td = apriltag_detector_create();
    apriltag_detector_add_family_bits(td, tf, 1);
    // 降低分辨率，会提高速度，降低精度 eg. 2 减小两倍
    td->quad_decimate = 2;
    //高斯模糊 eg 0.8
    td->quad_sigma = 0;
    // 线程数
    td->nthreads = 1;
    //
    td->debug = false;
    td->refine_edges = true;


    image_u8_t *im = NULL;

    static image_u8_t tmp = {
            .width=240,
            .height=240,
            .stride=240,
    };
    tmp.buf = pic;
    im = &tmp;

    timeProbe_t t;

    while (1) {
        timeProbe_start(&t);
        for (int i = 0; i < 100; ++i) {
            zarray_t *detections = apriltag_detector_detect(td, im);
            for (int i = 0; i < zarray_size(detections); i++) {
                apriltag_detection_t *det;
                zarray_get(detections, i, &det);
            printf("detection %3d: id (%2lux%2lu)-%-4d, hamming %d, margin %8.3f\n",
                   i, det->family->nbits, det->family->h, det->id, det->hamming, det->decision_margin);
            printf("x %8.3lf   y %8.3lf\n",
                   det->c[0], det->c[1]);
            }
            apriltag_detections_destroy(detections);
        }
        int64_t stop = timeProbe_stop(&t);
        ESP_LOGI("april tag detection", "%f ms", stop/1000.0);
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }


    apriltag_detector_destroy(td);
    tag16h5_destroy(tf);
}
