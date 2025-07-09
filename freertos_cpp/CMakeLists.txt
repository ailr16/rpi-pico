cmake_minimum_required(VERSION 3.13)

if (NOT FREERTOS_KERNEL_PATH AND NOT DEFINED ENV{FREERTOS_KERNEL_PATH})
    message("Skipping FreeRTOS examples as FREERTOS_KERNEL_PATH not defined")
    return()
endif()

include(pico_sdk_import.cmake)
include(FreeRTOS_Kernel_import.cmake)

project(test_project)

pico_sdk_init()

add_subdirectory(src)
include_directories(inc)