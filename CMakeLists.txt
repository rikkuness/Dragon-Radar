cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(ESP32-S3-LCD-2.8C-Test)

set(SRC
	# ...existing sources...
	src/ui_grid.c  # added
)

# Or if using idf_component_register:
# idf_component_register(SRCS "..." "src/ui_grid.c" INCLUDE_DIRS "src")
