
#ifndef PARALLELSM_H_
#define PARALLELSM_H_

#include "../src/sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'ParallelSM'.
*/


/*! Enumeration of all states */ 
typedef enum
{
	ParallelSM_last_state,
	ParallelSM_Main_Region_Setup,
	ParallelSM_Main_Region_Loop,
	ParallelSM_LED_LED_On,
	ParallelSM_LED_LED_Off,
	ParallelSM_LoRa_Incoming,
	ParallelSM_LoRa_Outgoing,
	ParallelSM_LoRa_LoRa,
	ParallelSM_LoRa_Parse,
	ParallelSM_LoRa_Serialize,
	ParallelSM_Motion_Sensor_Motion_Sensor,
	ParallelSM_Motion_Sensor_Someone,
	ParallelSM_Motion_Sensor_No_One,
	ParallelSM_Counter_Counter,
	ParallelSM_Counter_Reset,
	ParallelSM_Potentiometer_Potentiometer,
	ParallelSM_Potentiometer_Increase_Value,
	ParallelSM_Potentiometer_Decrease_Value
} ParallelSMStates;

/*! Type definition of the data structure for the ParallelSMIfaceInitiation interface scope. */
typedef struct
{
	sc_boolean success_raised;
	sc_boolean reset_raised;
} ParallelSMIfaceInitiation;

/*! Type definition of the data structure for the ParallelSMIfaceLED interface scope. */
typedef struct
{
	sc_boolean toggle_raised;
} ParallelSMIfaceLED;

/*! Type definition of the data structure for the ParallelSMIfaceSensor interface scope. */
typedef struct
{
	sc_boolean low_raised;
	sc_boolean high_raised;
} ParallelSMIfaceSensor;

/*! Type definition of the data structure for the ParallelSMIfaceMessage interface scope. */
typedef struct
{
	sc_boolean receive_raised;
	sc_boolean send_raised;
} ParallelSMIfaceMessage;

/*! Type definition of the data structure for the ParallelSMIfaceCounter interface scope. */
typedef struct
{
	sc_integer x;
} ParallelSMIfaceCounter;

/*! Type definition of the data structure for the ParallelSMIfacePot interface scope. */
typedef struct
{
	sc_boolean inc_raised;
	sc_boolean dec_raised;
	sc_integer val;
} ParallelSMIfacePot;

/*! Type definition of the data structure for the ParallelSMTimeEvents interface scope. */
typedef struct
{
	sc_boolean parallelSM_LoRa_Incoming_tev0_raised;
	sc_boolean parallelSM_LoRa_Outgoing_tev0_raised;
	sc_boolean parallelSM_LoRa_Parse_tev0_raised;
	sc_boolean parallelSM_LoRa_Serialize_tev0_raised;
	sc_boolean parallelSM_Motion_Sensor_Someone_tev0_raised;
	sc_boolean parallelSM_Motion_Sensor_No_One_tev0_raised;
	sc_boolean parallelSM_Counter_Counter_tev0_raised;
	sc_boolean parallelSM_Counter_Reset_tev0_raised;
} ParallelSMTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define PARALLELSM_MAX_ORTHOGONAL_STATES 6

/*! Define indices of states in the StateConfVector */
#define SCVI_PARALLELSM_MAIN_REGION_SETUP 0
#define SCVI_PARALLELSM_MAIN_REGION_LOOP 0
#define SCVI_PARALLELSM_LED_LED_ON 1
#define SCVI_PARALLELSM_LED_LED_OFF 1
#define SCVI_PARALLELSM_LORA_INCOMING 2
#define SCVI_PARALLELSM_LORA_OUTGOING 2
#define SCVI_PARALLELSM_LORA_LORA 2
#define SCVI_PARALLELSM_LORA_PARSE 2
#define SCVI_PARALLELSM_LORA_SERIALIZE 2
#define SCVI_PARALLELSM_MOTION_SENSOR_MOTION_SENSOR 3
#define SCVI_PARALLELSM_MOTION_SENSOR_SOMEONE 3
#define SCVI_PARALLELSM_MOTION_SENSOR_NO_ONE 3
#define SCVI_PARALLELSM_COUNTER_COUNTER 4
#define SCVI_PARALLELSM_COUNTER_RESET 4
#define SCVI_PARALLELSM_POTENTIOMETER_POTENTIOMETER 5
#define SCVI_PARALLELSM_POTENTIOMETER_INCREASE_VALUE 5
#define SCVI_PARALLELSM_POTENTIOMETER_DECREASE_VALUE 5

/*! 
 * Type definition of the data structure for the ParallelSM state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	ParallelSMStates stateConfVector[PARALLELSM_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	ParallelSMIfaceInitiation ifaceInitiation;
	ParallelSMIfaceLED ifaceLED;
	ParallelSMIfaceSensor ifaceSensor;
	ParallelSMIfaceMessage ifaceMessage;
	ParallelSMIfaceCounter ifaceCounter;
	ParallelSMIfacePot ifacePot;
	ParallelSMTimeEvents timeEvents;
} ParallelSM;


/*! Initializes the ParallelSM state machine data structures. Must be called before first usage.*/
extern void parallelSM_init(ParallelSM* handle);

/*! Activates the state machine */
extern void parallelSM_enter(ParallelSM* handle);

/*! Deactivates the state machine */
extern void parallelSM_exit(ParallelSM* handle);

/*! Performs a 'run to completion' step. */
extern void parallelSM_runCycle(ParallelSM* handle);

/*! Raises a time event. */
extern void parallelSM_raiseTimeEvent(const ParallelSM* handle, sc_eventid evid);

/*! Raises the in event 'success' that is defined in the interface scope 'initiation'. */ 
extern void parallelSMIfaceInitiation_raise_success(ParallelSM* handle);

/*! Raises the in event 'reset' that is defined in the interface scope 'initiation'. */ 
extern void parallelSMIfaceInitiation_raise_reset(ParallelSM* handle);

/*! Raises the in event 'toggle' that is defined in the interface scope 'LED'. */ 
extern void parallelSMIfaceLED_raise_toggle(ParallelSM* handle);

/*! Raises the in event 'low' that is defined in the interface scope 'sensor'. */ 
extern void parallelSMIfaceSensor_raise_low(ParallelSM* handle);

/*! Raises the in event 'high' that is defined in the interface scope 'sensor'. */ 
extern void parallelSMIfaceSensor_raise_high(ParallelSM* handle);

/*! Raises the in event 'receive' that is defined in the interface scope 'message'. */ 
extern void parallelSMIfaceMessage_raise_receive(ParallelSM* handle);

/*! Raises the in event 'send' that is defined in the interface scope 'message'. */ 
extern void parallelSMIfaceMessage_raise_send(ParallelSM* handle);

/*! Gets the value of the variable 'x' that is defined in the interface scope 'counter'. */ 
extern sc_integer parallelSMIfaceCounter_get_x(const ParallelSM* handle);
/*! Sets the value of the variable 'x' that is defined in the interface scope 'counter'. */ 
extern void parallelSMIfaceCounter_set_x(ParallelSM* handle, sc_integer value);
/*! Raises the in event 'inc' that is defined in the interface scope 'pot'. */ 
extern void parallelSMIfacePot_raise_inc(ParallelSM* handle);

/*! Raises the in event 'dec' that is defined in the interface scope 'pot'. */ 
extern void parallelSMIfacePot_raise_dec(ParallelSM* handle);

/*! Gets the value of the variable 'val' that is defined in the interface scope 'pot'. */ 
extern sc_integer parallelSMIfacePot_get_val(const ParallelSM* handle);
/*! Sets the value of the variable 'val' that is defined in the interface scope 'pot'. */ 
extern void parallelSMIfacePot_set_val(ParallelSM* handle, sc_integer value);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean parallelSM_isActive(const ParallelSM* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean parallelSM_isFinal(const ParallelSM* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean parallelSM_isStateActive(const ParallelSM* handle, ParallelSMStates state);



#ifdef __cplusplus
}
#endif 

#endif /* PARALLELSM_H_ */
