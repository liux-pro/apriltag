set(APRILTAG_SRCS "apriltag/apriltag.c" "apriltag/apriltag_pose.c" "apriltag/apriltag_quad_thresh.c")
file(GLOB TAG_FILES apriltag/tag*.c)
file(GLOB COMMON_SRC apriltag/common/*.c)


idf_component_register(SRCS ${APRILTAG_SRCS} ${TAG_FILES}  ${COMMON_SRC}
        INCLUDE_DIRS "apriltag"
        )

target_compile_options(${COMPONENT_LIB} PRIVATE -w)
