set(TARGET_NAME freertos_template)

add_executable(${TARGET_NAME}
    main.c
)

include_directories(${CMAKE_SOURCE_DIR}/inc)
add_library(lib_task task.cpp)
target_link_libraries(lib_task
    pico_async_context_freertos
    FreeRTOS-Kernel-Heap4
    pico_stdlib
)

target_include_directories(${TARGET_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/inc
)

target_link_libraries(${TARGET_NAME} PRIVATE
    pico_async_context_freertos
    FreeRTOS-Kernel-Heap4
    pico_stdlib
)

if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(${TARGET_NAME} PRIVATE
        pico_cyw43_arch_none
    )
endif()

target_compile_definitions(${TARGET_NAME} PRIVATE
    configNUMBER_OF_CORES=1
)

pico_add_extra_outputs(${TARGET_NAME})