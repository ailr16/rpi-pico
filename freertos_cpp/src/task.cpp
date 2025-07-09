#include "task.hpp"

Task::Task(){

}

Task::~Task(){
    stop();
}

bool Task::stop(){
    if(xHandle != NULL){
        vTaskDelete(xHandle);
        xHandle = NULL;
        return true;
    }
    return false;
}

TaskHandle_t Task::getTask(){
    return xHandle;
}

bool Task::start(const char *name, UBaseType_t priority){
    BaseType_t opStatus;

    if(strlen(name) >= MAX_NAME_LEN){
        memcpy(pName, name, MAX_NAME_LEN);
        pName[MAX_NAME_LEN - 1] = 0;
    }
    else{
        strcpy(pName, name);
    }

    opStatus = xTaskCreate(Task::vTask, pName, getMaxStackSize(),
                           (void*)this, priority, &xHandle);

    return opStatus == pdPASS;
}

void Task::vTask(void *pvParameters){
    Task *task = (Task*)pvParameters;
    if(task != NULL){
        task->run();
    }
}