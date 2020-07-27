/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app1.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app1.h"
#include "bsp/bsp.h"
#include "queue.h"


#include "app.h"
#include "peripheral/port/plib_port.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP1_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP1_DATA app1Data;

// added this line to the generated code
extern QueueHandle_t xQueue;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP1_Initialize ( void )

  Remarks:
    See prototype in app1.h.
 */

void APP1_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app1Data.state = APP1_STATE_INIT;



    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP1_Tasks ( void )

  Remarks:
    See prototype in app1.h.
 */

void APP1_Tasks ( void )
{
    // added this line to the generated code
    unsigned long qValue;

    /* Check the application's current state. */
    switch ( app1Data.state )
    {
        /* Application's initial state. */
        case APP1_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {
                LED_Off();
                app1Data.state = APP1_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP1_STATE_SERVICE_TASKS:
        {
            // added this line to the generated code
            xQueuePeek(xQueue, &qValue, 0);
            if(qValue == 1){
                LED_Toggle();
                //RLY1_Toggle();
                //vTaskDelay(QUEUE_SEND_FREQUENCY_MS-100 );
                xQueueReceive(xQueue, &qValue, 0);
                qValue = 0;
            }            
            vTaskDelay(50);
            break;
        }

        /* TODO: implement your application state machine.*/


        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
