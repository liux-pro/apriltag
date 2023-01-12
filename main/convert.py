import cv2
import numpy as np

imread = cv2.imread("2.png")
cv2.imshow("img", imread)

# Convert to grayscale
gray_image = cv2.cvtColor(imread, cv2.COLOR_BGR2GRAY)

gray_image_u8 = gray_image.astype(np.uint8)

# cv2.imshow("gray",gray_image_u8)
# print(gray_image_u8[30])

with open("pic.c", "w") as rom:
    rom.write("#include <stdint.h>\n")
    rom.write("const uint8_t pic[] = {")
    for cow in gray_image_u8:
        rom.write(",".join([str(hex(x)) for x in cow]))
        rom.write(",")
        rom.write("\n")
    rom.write("};")
