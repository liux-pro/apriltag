# apriltag porting for esp-idf
This repo demonstrates how to use [apriltag](https://github.com/AprilRobotics/apriltag)
in [esp-idf](https://github.com/espressif/esp-idf).  
`maim/convert.py` can convert png image to grayscale image in uint8 formate, store as c array in `pic.c`.  
`maim/apriltag.c` will find all apriltag in this image.
It has been tested on esp32c3, esp32s3, but other esp32 family should also work.

# requirement
esp-idf 5.0