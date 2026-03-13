#include "main_functions.h"

/**
* @brief      Arduino setup function
*/
extern "C" void setup()
{
    setup_func();
}

/**
* @brief      Get data and run inferencing
*/
extern "C" void loop()
{
    loop_func();
}
