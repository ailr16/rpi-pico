#ifndef TASK_HPP
#define TASK_HPP

#include "FreeRTOS.h"
#include "task.h"
#include <cstring>

#define MAX_NAME_LEN 20

class Task{
    public:
        Task();
        virtual ~Task();
        virtual bool start(const char *name, UBaseType_t priority = tskIDLE_PRIORITY);
        virtual bool stop();
        virtual TaskHandle_t getTask();

    protected:
        static void vTask(void* pvParameters);
        virtual void run() = 0;
        virtual configSTACK_DEPTH_TYPE getMaxStackSize() = 0;

        TaskHandle_t xHandle = NULL;
        char pName[MAX_NAME_LEN];
};

#endif