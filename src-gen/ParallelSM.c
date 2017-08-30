
#include <stdlib.h>
#include <string.h>
#include "../src/sc_types.h"
#include "ParallelSM.h"
#include "ParallelSMRequired.h"
/*! \file Implementation of the state machine 'ParallelSM'
*/

/* prototypes of all internal functions */
static sc_boolean parallelSM_check_Main_Region_Setup_tr0_tr0(const ParallelSM* handle);
static sc_boolean parallelSM_check_Main_Region_Loop_tr0_tr0(const ParallelSM* handle);
static sc_boolean parallelSM_check_LED_LED_On_tr0_tr0(const ParallelSM* handle);
static sc_boolean parallelSM_check_LED_LED_Off_tr0_tr0(const ParallelSM* handle);
static sc_boolean parallelSM_check_LoRa_Incoming_tr0_tr0(const ParallelSM* handle);
static sc_boolean parallelSM_check_LoRa_Outgoing_tr0_tr0(const ParallelSM* handle);
static sc_boolean parallelSM_check_LoRa_LoRa_tr0_tr0(const ParallelSM* handle);
static sc_boolean parallelSM_check_LoRa_LoRa_tr1_tr1(const ParallelSM* handle);
static sc_boolean parallelSM_check_LoRa_Parse_tr0_tr0(const ParallelSM* handle);
static sc_boolean parallelSM_check_LoRa_Serialize_tr0_tr0(const ParallelSM* handle);
static sc_boolean parallelSM_check_Motion_Sensor_Motion_Sensor_tr0_tr0(const ParallelSM* handle);
static sc_boolean parallelSM_check_Motion_Sensor_Motion_Sensor_tr1_tr1(const ParallelSM* handle);
static sc_boolean parallelSM_check_Motion_Sensor_Someone_tr0_tr0(const ParallelSM* handle);
static sc_boolean parallelSM_check_Motion_Sensor_No_One_tr0_tr0(const ParallelSM* handle);
static sc_boolean parallelSM_check_Counter_Counter_lr0_lr0(const ParallelSM* handle);
static sc_boolean parallelSM_check_Counter_Counter_tr0_tr0(const ParallelSM* handle);
static sc_boolean parallelSM_check_Counter_Reset_tr0_tr0(const ParallelSM* handle);
static sc_boolean parallelSM_check_Potentiometer_Potentiometer_tr0_tr0(const ParallelSM* handle);
static sc_boolean parallelSM_check_Potentiometer_Potentiometer_tr1_tr1(const ParallelSM* handle);
static sc_boolean parallelSM_check_Potentiometer_Increase_Value_tr0_tr0(const ParallelSM* handle);
static sc_boolean parallelSM_check_Potentiometer_Decrease_Value_tr0_tr0(const ParallelSM* handle);
static void parallelSM_effect_Main_Region_Setup_tr0(ParallelSM* handle);
static void parallelSM_effect_Main_Region_Loop_tr0(ParallelSM* handle);
static void parallelSM_effect_LED_LED_On_tr0(ParallelSM* handle);
static void parallelSM_effect_LED_LED_Off_tr0(ParallelSM* handle);
static void parallelSM_effect_LoRa_Incoming_tr0(ParallelSM* handle);
static void parallelSM_effect_LoRa_Outgoing_tr0(ParallelSM* handle);
static void parallelSM_effect_LoRa_LoRa_tr0(ParallelSM* handle);
static void parallelSM_effect_LoRa_LoRa_tr1(ParallelSM* handle);
static void parallelSM_effect_LoRa_Parse_tr0(ParallelSM* handle);
static void parallelSM_effect_LoRa_Serialize_tr0(ParallelSM* handle);
static void parallelSM_effect_Motion_Sensor_Motion_Sensor_tr0(ParallelSM* handle);
static void parallelSM_effect_Motion_Sensor_Motion_Sensor_tr1(ParallelSM* handle);
static void parallelSM_effect_Motion_Sensor_Someone_tr0(ParallelSM* handle);
static void parallelSM_effect_Motion_Sensor_No_One_tr0(ParallelSM* handle);
static void parallelSM_effect_Counter_Counter_lr0_lr0(ParallelSM* handle);
static void parallelSM_effect_Counter_Counter_tr0(ParallelSM* handle);
static void parallelSM_effect_Counter_Reset_tr0(ParallelSM* handle);
static void parallelSM_effect_Potentiometer_Potentiometer_tr0(ParallelSM* handle);
static void parallelSM_effect_Potentiometer_Potentiometer_tr1(ParallelSM* handle);
static void parallelSM_effect_Potentiometer_Increase_Value_tr0(ParallelSM* handle);
static void parallelSM_effect_Potentiometer_Decrease_Value_tr0(ParallelSM* handle);
static void parallelSM_enact_LoRa_Incoming(ParallelSM* handle);
static void parallelSM_enact_LoRa_Outgoing(ParallelSM* handle);
static void parallelSM_enact_LoRa_Parse(ParallelSM* handle);
static void parallelSM_enact_LoRa_Serialize(ParallelSM* handle);
static void parallelSM_enact_Motion_Sensor_Someone(ParallelSM* handle);
static void parallelSM_enact_Motion_Sensor_No_One(ParallelSM* handle);
static void parallelSM_enact_Counter_Counter(ParallelSM* handle);
static void parallelSM_enact_Counter_Reset(ParallelSM* handle);
static void parallelSM_enact_Potentiometer_Increase_Value(ParallelSM* handle);
static void parallelSM_enact_Potentiometer_Decrease_Value(ParallelSM* handle);
static void parallelSM_exact_LoRa_Incoming(ParallelSM* handle);
static void parallelSM_exact_LoRa_Outgoing(ParallelSM* handle);
static void parallelSM_exact_LoRa_Parse(ParallelSM* handle);
static void parallelSM_exact_LoRa_Serialize(ParallelSM* handle);
static void parallelSM_exact_Motion_Sensor_Someone(ParallelSM* handle);
static void parallelSM_exact_Motion_Sensor_No_One(ParallelSM* handle);
static void parallelSM_exact_Counter_Counter(ParallelSM* handle);
static void parallelSM_exact_Counter_Reset(ParallelSM* handle);
static void parallelSM_enseq_Main_Region_Setup_default(ParallelSM* handle);
static void parallelSM_enseq_Main_Region_Loop_default(ParallelSM* handle);
static void parallelSM_enseq_LED_LED_On_default(ParallelSM* handle);
static void parallelSM_enseq_LED_LED_Off_default(ParallelSM* handle);
static void parallelSM_enseq_LoRa_Incoming_default(ParallelSM* handle);
static void parallelSM_enseq_LoRa_Outgoing_default(ParallelSM* handle);
static void parallelSM_enseq_LoRa_LoRa_default(ParallelSM* handle);
static void parallelSM_enseq_LoRa_Parse_default(ParallelSM* handle);
static void parallelSM_enseq_LoRa_Serialize_default(ParallelSM* handle);
static void parallelSM_enseq_Motion_Sensor_Motion_Sensor_default(ParallelSM* handle);
static void parallelSM_enseq_Motion_Sensor_Someone_default(ParallelSM* handle);
static void parallelSM_enseq_Motion_Sensor_No_One_default(ParallelSM* handle);
static void parallelSM_enseq_Counter_Counter_default(ParallelSM* handle);
static void parallelSM_enseq_Counter_Reset_default(ParallelSM* handle);
static void parallelSM_enseq_Potentiometer_Potentiometer_default(ParallelSM* handle);
static void parallelSM_enseq_Potentiometer_Increase_Value_default(ParallelSM* handle);
static void parallelSM_enseq_Potentiometer_Decrease_Value_default(ParallelSM* handle);
static void parallelSM_enseq_Main_Region_default(ParallelSM* handle);
static void parallelSM_enseq_LED_default(ParallelSM* handle);
static void parallelSM_enseq_LoRa_default(ParallelSM* handle);
static void parallelSM_enseq_Motion_Sensor_default(ParallelSM* handle);
static void parallelSM_enseq_Counter_default(ParallelSM* handle);
static void parallelSM_enseq_Potentiometer_default(ParallelSM* handle);
static void parallelSM_exseq_Main_Region_Setup(ParallelSM* handle);
static void parallelSM_exseq_Main_Region_Loop(ParallelSM* handle);
static void parallelSM_exseq_LED_LED_On(ParallelSM* handle);
static void parallelSM_exseq_LED_LED_Off(ParallelSM* handle);
static void parallelSM_exseq_LoRa_Incoming(ParallelSM* handle);
static void parallelSM_exseq_LoRa_Outgoing(ParallelSM* handle);
static void parallelSM_exseq_LoRa_LoRa(ParallelSM* handle);
static void parallelSM_exseq_LoRa_Parse(ParallelSM* handle);
static void parallelSM_exseq_LoRa_Serialize(ParallelSM* handle);
static void parallelSM_exseq_Motion_Sensor_Motion_Sensor(ParallelSM* handle);
static void parallelSM_exseq_Motion_Sensor_Someone(ParallelSM* handle);
static void parallelSM_exseq_Motion_Sensor_No_One(ParallelSM* handle);
static void parallelSM_exseq_Counter_Counter(ParallelSM* handle);
static void parallelSM_exseq_Counter_Reset(ParallelSM* handle);
static void parallelSM_exseq_Potentiometer_Potentiometer(ParallelSM* handle);
static void parallelSM_exseq_Potentiometer_Increase_Value(ParallelSM* handle);
static void parallelSM_exseq_Potentiometer_Decrease_Value(ParallelSM* handle);
static void parallelSM_exseq_Main_Region(ParallelSM* handle);
static void parallelSM_exseq_LED(ParallelSM* handle);
static void parallelSM_exseq_LoRa(ParallelSM* handle);
static void parallelSM_exseq_Motion_Sensor(ParallelSM* handle);
static void parallelSM_exseq_Counter(ParallelSM* handle);
static void parallelSM_exseq_Potentiometer(ParallelSM* handle);
static void parallelSM_react_Main_Region_Setup(ParallelSM* handle);
static void parallelSM_react_Main_Region_Loop(ParallelSM* handle);
static void parallelSM_react_LED_LED_On(ParallelSM* handle);
static void parallelSM_react_LED_LED_Off(ParallelSM* handle);
static void parallelSM_react_LoRa_Incoming(ParallelSM* handle);
static void parallelSM_react_LoRa_Outgoing(ParallelSM* handle);
static void parallelSM_react_LoRa_LoRa(ParallelSM* handle);
static void parallelSM_react_LoRa_Parse(ParallelSM* handle);
static void parallelSM_react_LoRa_Serialize(ParallelSM* handle);
static void parallelSM_react_Motion_Sensor_Motion_Sensor(ParallelSM* handle);
static void parallelSM_react_Motion_Sensor_Someone(ParallelSM* handle);
static void parallelSM_react_Motion_Sensor_No_One(ParallelSM* handle);
static void parallelSM_react_Counter_Counter(ParallelSM* handle);
static void parallelSM_react_Counter_Reset(ParallelSM* handle);
static void parallelSM_react_Potentiometer_Potentiometer(ParallelSM* handle);
static void parallelSM_react_Potentiometer_Increase_Value(ParallelSM* handle);
static void parallelSM_react_Potentiometer_Decrease_Value(ParallelSM* handle);
static void parallelSM_react_Main_Region__entry_Default(ParallelSM* handle);
static void parallelSM_react_LED__entry_Default(ParallelSM* handle);
static void parallelSM_react_LoRa__entry_Default(ParallelSM* handle);
static void parallelSM_react_Motion_Sensor__entry_Default(ParallelSM* handle);
static void parallelSM_react_Counter__entry_Default(ParallelSM* handle);
static void parallelSM_react_Potentiometer__entry_Default(ParallelSM* handle);
static void parallelSM_clearInEvents(ParallelSM* handle);
static void parallelSM_clearOutEvents(ParallelSM* handle);


void parallelSM_init(ParallelSM* handle)
{
		sc_integer i;
	
		for (i = 0; i < PARALLELSM_MAX_ORTHOGONAL_STATES; ++i)
		{
			handle->stateConfVector[i] = ParallelSM_last_state;
		}
		
		
		handle->stateConfVectorPosition = 0;
	
		parallelSM_clearInEvents(handle);
		parallelSM_clearOutEvents(handle);
	
		/* Default init sequence for statechart ParallelSM */
		handle->ifaceCounter.x = 0;
		handle->ifacePot.val = 0;
}

void parallelSM_enter(ParallelSM* handle)
{
	/* Default enter sequence for statechart ParallelSM */
	parallelSM_enseq_Main_Region_default(handle);
	parallelSM_enseq_LED_default(handle);
	parallelSM_enseq_LoRa_default(handle);
	parallelSM_enseq_Motion_Sensor_default(handle);
	parallelSM_enseq_Counter_default(handle);
	parallelSM_enseq_Potentiometer_default(handle);
}

void parallelSM_exit(ParallelSM* handle)
{
	/* Default exit sequence for statechart ParallelSM */
	parallelSM_exseq_Main_Region(handle);
	parallelSM_exseq_LED(handle);
	parallelSM_exseq_LoRa(handle);
	parallelSM_exseq_Motion_Sensor(handle);
	parallelSM_exseq_Counter(handle);
	parallelSM_exseq_Potentiometer(handle);
}

sc_boolean parallelSM_isActive(const ParallelSM* handle)
{
	sc_boolean result = bool_false;
	int i;
	
	for(i = 0; i < PARALLELSM_MAX_ORTHOGONAL_STATES; i++)
	{
		result = result || handle->stateConfVector[i] != ParallelSM_last_state;
	}
	
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean parallelSM_isFinal(const ParallelSM* handle)
{
   return bool_false;
}

static void parallelSM_clearInEvents(ParallelSM* handle)
{
	handle->ifaceInitiation.success_raised = bool_false;
	handle->ifaceInitiation.reset_raised = bool_false;
	handle->ifaceLED.toggle_raised = bool_false;
	handle->ifaceSensor.low_raised = bool_false;
	handle->ifaceSensor.high_raised = bool_false;
	handle->ifaceMessage.receive_raised = bool_false;
	handle->ifaceMessage.send_raised = bool_false;
	handle->ifacePot.inc_raised = bool_false;
	handle->ifacePot.dec_raised = bool_false;
	handle->timeEvents.parallelSM_LoRa_Incoming_tev0_raised = bool_false;
	handle->timeEvents.parallelSM_LoRa_Outgoing_tev0_raised = bool_false;
	handle->timeEvents.parallelSM_LoRa_Parse_tev0_raised = bool_false;
	handle->timeEvents.parallelSM_LoRa_Serialize_tev0_raised = bool_false;
	handle->timeEvents.parallelSM_Motion_Sensor_Someone_tev0_raised = bool_false;
	handle->timeEvents.parallelSM_Motion_Sensor_No_One_tev0_raised = bool_false;
	handle->timeEvents.parallelSM_Counter_Counter_tev0_raised = bool_false;
	handle->timeEvents.parallelSM_Counter_Reset_tev0_raised = bool_false;
}

static void parallelSM_clearOutEvents(ParallelSM* handle)
{
}

void parallelSM_runCycle(ParallelSM* handle)
{
	
	parallelSM_clearOutEvents(handle);
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < PARALLELSM_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case ParallelSM_Main_Region_Setup:
		{
			parallelSM_react_Main_Region_Setup(handle);
			break;
		}
		case ParallelSM_Main_Region_Loop:
		{
			parallelSM_react_Main_Region_Loop(handle);
			break;
		}
		case ParallelSM_LED_LED_On:
		{
			parallelSM_react_LED_LED_On(handle);
			break;
		}
		case ParallelSM_LED_LED_Off:
		{
			parallelSM_react_LED_LED_Off(handle);
			break;
		}
		case ParallelSM_LoRa_Incoming:
		{
			parallelSM_react_LoRa_Incoming(handle);
			break;
		}
		case ParallelSM_LoRa_Outgoing:
		{
			parallelSM_react_LoRa_Outgoing(handle);
			break;
		}
		case ParallelSM_LoRa_LoRa:
		{
			parallelSM_react_LoRa_LoRa(handle);
			break;
		}
		case ParallelSM_LoRa_Parse:
		{
			parallelSM_react_LoRa_Parse(handle);
			break;
		}
		case ParallelSM_LoRa_Serialize:
		{
			parallelSM_react_LoRa_Serialize(handle);
			break;
		}
		case ParallelSM_Motion_Sensor_Motion_Sensor:
		{
			parallelSM_react_Motion_Sensor_Motion_Sensor(handle);
			break;
		}
		case ParallelSM_Motion_Sensor_Someone:
		{
			parallelSM_react_Motion_Sensor_Someone(handle);
			break;
		}
		case ParallelSM_Motion_Sensor_No_One:
		{
			parallelSM_react_Motion_Sensor_No_One(handle);
			break;
		}
		case ParallelSM_Counter_Counter:
		{
			parallelSM_react_Counter_Counter(handle);
			break;
		}
		case ParallelSM_Counter_Reset:
		{
			parallelSM_react_Counter_Reset(handle);
			break;
		}
		case ParallelSM_Potentiometer_Potentiometer:
		{
			parallelSM_react_Potentiometer_Potentiometer(handle);
			break;
		}
		case ParallelSM_Potentiometer_Increase_Value:
		{
			parallelSM_react_Potentiometer_Increase_Value(handle);
			break;
		}
		case ParallelSM_Potentiometer_Decrease_Value:
		{
			parallelSM_react_Potentiometer_Decrease_Value(handle);
			break;
		}
		default:
			break;
		}
	}
	
	parallelSM_clearInEvents(handle);
}

void parallelSM_raiseTimeEvent(const ParallelSM* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(ParallelSMTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean parallelSM_isStateActive(const ParallelSM* handle, ParallelSMStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case ParallelSM_Main_Region_Setup :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PARALLELSM_MAIN_REGION_SETUP] == ParallelSM_Main_Region_Setup
			);
			break;
		case ParallelSM_Main_Region_Loop :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PARALLELSM_MAIN_REGION_LOOP] == ParallelSM_Main_Region_Loop
			);
			break;
		case ParallelSM_LED_LED_On :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PARALLELSM_LED_LED_ON] == ParallelSM_LED_LED_On
			);
			break;
		case ParallelSM_LED_LED_Off :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PARALLELSM_LED_LED_OFF] == ParallelSM_LED_LED_Off
			);
			break;
		case ParallelSM_LoRa_Incoming :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PARALLELSM_LORA_INCOMING] == ParallelSM_LoRa_Incoming
			);
			break;
		case ParallelSM_LoRa_Outgoing :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PARALLELSM_LORA_OUTGOING] == ParallelSM_LoRa_Outgoing
			);
			break;
		case ParallelSM_LoRa_LoRa :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PARALLELSM_LORA_LORA] == ParallelSM_LoRa_LoRa
			);
			break;
		case ParallelSM_LoRa_Parse :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PARALLELSM_LORA_PARSE] == ParallelSM_LoRa_Parse
			);
			break;
		case ParallelSM_LoRa_Serialize :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PARALLELSM_LORA_SERIALIZE] == ParallelSM_LoRa_Serialize
			);
			break;
		case ParallelSM_Motion_Sensor_Motion_Sensor :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PARALLELSM_MOTION_SENSOR_MOTION_SENSOR] == ParallelSM_Motion_Sensor_Motion_Sensor
			);
			break;
		case ParallelSM_Motion_Sensor_Someone :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PARALLELSM_MOTION_SENSOR_SOMEONE] == ParallelSM_Motion_Sensor_Someone
			);
			break;
		case ParallelSM_Motion_Sensor_No_One :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PARALLELSM_MOTION_SENSOR_NO_ONE] == ParallelSM_Motion_Sensor_No_One
			);
			break;
		case ParallelSM_Counter_Counter :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PARALLELSM_COUNTER_COUNTER] == ParallelSM_Counter_Counter
			);
			break;
		case ParallelSM_Counter_Reset :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PARALLELSM_COUNTER_RESET] == ParallelSM_Counter_Reset
			);
			break;
		case ParallelSM_Potentiometer_Potentiometer :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PARALLELSM_POTENTIOMETER_POTENTIOMETER] == ParallelSM_Potentiometer_Potentiometer
			);
			break;
		case ParallelSM_Potentiometer_Increase_Value :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PARALLELSM_POTENTIOMETER_INCREASE_VALUE] == ParallelSM_Potentiometer_Increase_Value
			);
			break;
		case ParallelSM_Potentiometer_Decrease_Value :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PARALLELSM_POTENTIOMETER_DECREASE_VALUE] == ParallelSM_Potentiometer_Decrease_Value
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

void parallelSMIfaceInitiation_raise_success(ParallelSM* handle)
{
	handle->ifaceInitiation.success_raised = bool_true;
}
void parallelSMIfaceInitiation_raise_reset(ParallelSM* handle)
{
	handle->ifaceInitiation.reset_raised = bool_true;
}


void parallelSMIfaceLED_raise_toggle(ParallelSM* handle)
{
	handle->ifaceLED.toggle_raised = bool_true;
}


void parallelSMIfaceSensor_raise_low(ParallelSM* handle)
{
	handle->ifaceSensor.low_raised = bool_true;
}
void parallelSMIfaceSensor_raise_high(ParallelSM* handle)
{
	handle->ifaceSensor.high_raised = bool_true;
}


void parallelSMIfaceMessage_raise_receive(ParallelSM* handle)
{
	handle->ifaceMessage.receive_raised = bool_true;
}
void parallelSMIfaceMessage_raise_send(ParallelSM* handle)
{
	handle->ifaceMessage.send_raised = bool_true;
}




sc_integer parallelSMIfaceCounter_get_x(const ParallelSM* handle)
{
	return handle->ifaceCounter.x;
}
void parallelSMIfaceCounter_set_x(ParallelSM* handle, sc_integer value)
{
	handle->ifaceCounter.x = value;
}
void parallelSMIfacePot_raise_inc(ParallelSM* handle)
{
	handle->ifacePot.inc_raised = bool_true;
}
void parallelSMIfacePot_raise_dec(ParallelSM* handle)
{
	handle->ifacePot.dec_raised = bool_true;
}


sc_integer parallelSMIfacePot_get_val(const ParallelSM* handle)
{
	return handle->ifacePot.val;
}
void parallelSMIfacePot_set_val(ParallelSM* handle, sc_integer value)
{
	handle->ifacePot.val = value;
}

/* implementations of all internal functions */

static sc_boolean parallelSM_check_Main_Region_Setup_tr0_tr0(const ParallelSM* handle)
{
	return handle->ifaceInitiation.success_raised;
}

static sc_boolean parallelSM_check_Main_Region_Loop_tr0_tr0(const ParallelSM* handle)
{
	return handle->ifaceInitiation.reset_raised;
}

static sc_boolean parallelSM_check_LED_LED_On_tr0_tr0(const ParallelSM* handle)
{
	return handle->ifaceLED.toggle_raised;
}

static sc_boolean parallelSM_check_LED_LED_Off_tr0_tr0(const ParallelSM* handle)
{
	return handle->ifaceLED.toggle_raised;
}

static sc_boolean parallelSM_check_LoRa_Incoming_tr0_tr0(const ParallelSM* handle)
{
	return handle->timeEvents.parallelSM_LoRa_Incoming_tev0_raised;
}

static sc_boolean parallelSM_check_LoRa_Outgoing_tr0_tr0(const ParallelSM* handle)
{
	return handle->timeEvents.parallelSM_LoRa_Outgoing_tev0_raised;
}

static sc_boolean parallelSM_check_LoRa_LoRa_tr0_tr0(const ParallelSM* handle)
{
	return handle->ifaceMessage.receive_raised;
}

static sc_boolean parallelSM_check_LoRa_LoRa_tr1_tr1(const ParallelSM* handle)
{
	return handle->ifaceMessage.send_raised;
}

static sc_boolean parallelSM_check_LoRa_Parse_tr0_tr0(const ParallelSM* handle)
{
	return handle->timeEvents.parallelSM_LoRa_Parse_tev0_raised;
}

static sc_boolean parallelSM_check_LoRa_Serialize_tr0_tr0(const ParallelSM* handle)
{
	return handle->timeEvents.parallelSM_LoRa_Serialize_tev0_raised;
}

static sc_boolean parallelSM_check_Motion_Sensor_Motion_Sensor_tr0_tr0(const ParallelSM* handle)
{
	return handle->ifaceSensor.high_raised;
}

static sc_boolean parallelSM_check_Motion_Sensor_Motion_Sensor_tr1_tr1(const ParallelSM* handle)
{
	return handle->ifaceSensor.low_raised;
}

static sc_boolean parallelSM_check_Motion_Sensor_Someone_tr0_tr0(const ParallelSM* handle)
{
	return handle->timeEvents.parallelSM_Motion_Sensor_Someone_tev0_raised;
}

static sc_boolean parallelSM_check_Motion_Sensor_No_One_tr0_tr0(const ParallelSM* handle)
{
	return handle->timeEvents.parallelSM_Motion_Sensor_No_One_tev0_raised;
}

static sc_boolean parallelSM_check_Counter_Counter_lr0_lr0(const ParallelSM* handle)
{
	return handle->timeEvents.parallelSM_Counter_Counter_tev0_raised;
}

static sc_boolean parallelSM_check_Counter_Counter_tr0_tr0(const ParallelSM* handle)
{
	return (handle->ifaceCounter.x == 20) ? bool_true : bool_false;
}

static sc_boolean parallelSM_check_Counter_Reset_tr0_tr0(const ParallelSM* handle)
{
	return handle->timeEvents.parallelSM_Counter_Reset_tev0_raised;
}

static sc_boolean parallelSM_check_Potentiometer_Potentiometer_tr0_tr0(const ParallelSM* handle)
{
	return handle->ifacePot.inc_raised;
}

static sc_boolean parallelSM_check_Potentiometer_Potentiometer_tr1_tr1(const ParallelSM* handle)
{
	return handle->ifacePot.dec_raised;
}

static sc_boolean parallelSM_check_Potentiometer_Increase_Value_tr0_tr0(const ParallelSM* handle)
{
	return bool_true;
}

static sc_boolean parallelSM_check_Potentiometer_Decrease_Value_tr0_tr0(const ParallelSM* handle)
{
	return bool_true;
}

static void parallelSM_effect_Main_Region_Setup_tr0(ParallelSM* handle)
{
	parallelSM_exseq_Main_Region_Setup(handle);
	parallelSM_enseq_Main_Region_Loop_default(handle);
}

static void parallelSM_effect_Main_Region_Loop_tr0(ParallelSM* handle)
{
	parallelSM_exseq_Main_Region_Loop(handle);
	parallelSM_enseq_Main_Region_Setup_default(handle);
}

static void parallelSM_effect_LED_LED_On_tr0(ParallelSM* handle)
{
	parallelSM_exseq_LED_LED_On(handle);
	parallelSM_enseq_LED_LED_Off_default(handle);
}

static void parallelSM_effect_LED_LED_Off_tr0(ParallelSM* handle)
{
	parallelSM_exseq_LED_LED_Off(handle);
	parallelSM_enseq_LED_LED_On_default(handle);
}

static void parallelSM_effect_LoRa_Incoming_tr0(ParallelSM* handle)
{
	parallelSM_exseq_LoRa_Incoming(handle);
	parallelSM_enseq_LoRa_Parse_default(handle);
}

static void parallelSM_effect_LoRa_Outgoing_tr0(ParallelSM* handle)
{
	parallelSM_exseq_LoRa_Outgoing(handle);
	parallelSM_enseq_LoRa_Serialize_default(handle);
}

static void parallelSM_effect_LoRa_LoRa_tr0(ParallelSM* handle)
{
	parallelSM_exseq_LoRa_LoRa(handle);
	parallelSM_enseq_LoRa_Incoming_default(handle);
}

static void parallelSM_effect_LoRa_LoRa_tr1(ParallelSM* handle)
{
	parallelSM_exseq_LoRa_LoRa(handle);
	parallelSM_enseq_LoRa_Outgoing_default(handle);
}

static void parallelSM_effect_LoRa_Parse_tr0(ParallelSM* handle)
{
	parallelSM_exseq_LoRa_Parse(handle);
	parallelSM_enseq_LoRa_LoRa_default(handle);
}

static void parallelSM_effect_LoRa_Serialize_tr0(ParallelSM* handle)
{
	parallelSM_exseq_LoRa_Serialize(handle);
	parallelSM_enseq_LoRa_LoRa_default(handle);
}

static void parallelSM_effect_Motion_Sensor_Motion_Sensor_tr0(ParallelSM* handle)
{
	parallelSM_exseq_Motion_Sensor_Motion_Sensor(handle);
	parallelSM_enseq_Motion_Sensor_Someone_default(handle);
}

static void parallelSM_effect_Motion_Sensor_Motion_Sensor_tr1(ParallelSM* handle)
{
	parallelSM_exseq_Motion_Sensor_Motion_Sensor(handle);
	parallelSM_enseq_Motion_Sensor_No_One_default(handle);
}

static void parallelSM_effect_Motion_Sensor_Someone_tr0(ParallelSM* handle)
{
	parallelSM_exseq_Motion_Sensor_Someone(handle);
	parallelSM_enseq_Motion_Sensor_Motion_Sensor_default(handle);
}

static void parallelSM_effect_Motion_Sensor_No_One_tr0(ParallelSM* handle)
{
	parallelSM_exseq_Motion_Sensor_No_One(handle);
	parallelSM_enseq_Motion_Sensor_Motion_Sensor_default(handle);
}

static void parallelSM_effect_Counter_Counter_lr0_lr0(ParallelSM* handle)
{
	handle->ifaceCounter.x += 1;
}

static void parallelSM_effect_Counter_Counter_tr0(ParallelSM* handle)
{
	parallelSM_exseq_Counter_Counter(handle);
	parallelSM_enseq_Counter_Reset_default(handle);
}

static void parallelSM_effect_Counter_Reset_tr0(ParallelSM* handle)
{
	parallelSM_exseq_Counter_Reset(handle);
	parallelSM_enseq_Counter_Counter_default(handle);
}

static void parallelSM_effect_Potentiometer_Potentiometer_tr0(ParallelSM* handle)
{
	parallelSM_exseq_Potentiometer_Potentiometer(handle);
	parallelSM_enseq_Potentiometer_Increase_Value_default(handle);
}

static void parallelSM_effect_Potentiometer_Potentiometer_tr1(ParallelSM* handle)
{
	parallelSM_exseq_Potentiometer_Potentiometer(handle);
	parallelSM_enseq_Potentiometer_Decrease_Value_default(handle);
}

static void parallelSM_effect_Potentiometer_Increase_Value_tr0(ParallelSM* handle)
{
	parallelSM_exseq_Potentiometer_Increase_Value(handle);
	parallelSM_enseq_Potentiometer_Potentiometer_default(handle);
}

static void parallelSM_effect_Potentiometer_Decrease_Value_tr0(ParallelSM* handle)
{
	parallelSM_exseq_Potentiometer_Decrease_Value(handle);
	parallelSM_enseq_Potentiometer_Potentiometer_default(handle);
}

/* Entry action for state 'Incoming'. */
static void parallelSM_enact_LoRa_Incoming(ParallelSM* handle)
{
	/* Entry action for state 'Incoming'. */
	parallelSM_setTimer(handle, (sc_eventid) &(handle->timeEvents.parallelSM_LoRa_Incoming_tev0_raised) , 2 * 1000, bool_false);
}

/* Entry action for state 'Outgoing'. */
static void parallelSM_enact_LoRa_Outgoing(ParallelSM* handle)
{
	/* Entry action for state 'Outgoing'. */
	parallelSM_setTimer(handle, (sc_eventid) &(handle->timeEvents.parallelSM_LoRa_Outgoing_tev0_raised) , 2 * 1000, bool_false);
}

/* Entry action for state 'Parse'. */
static void parallelSM_enact_LoRa_Parse(ParallelSM* handle)
{
	/* Entry action for state 'Parse'. */
	parallelSM_setTimer(handle, (sc_eventid) &(handle->timeEvents.parallelSM_LoRa_Parse_tev0_raised) , 1 * 1000, bool_false);
}

/* Entry action for state 'Serialize'. */
static void parallelSM_enact_LoRa_Serialize(ParallelSM* handle)
{
	/* Entry action for state 'Serialize'. */
	parallelSM_setTimer(handle, (sc_eventid) &(handle->timeEvents.parallelSM_LoRa_Serialize_tev0_raised) , 1 * 1000, bool_false);
}

/* Entry action for state 'Someone'. */
static void parallelSM_enact_Motion_Sensor_Someone(ParallelSM* handle)
{
	/* Entry action for state 'Someone'. */
	parallelSM_setTimer(handle, (sc_eventid) &(handle->timeEvents.parallelSM_Motion_Sensor_Someone_tev0_raised) , 2 * 1000, bool_false);
}

/* Entry action for state 'No One'. */
static void parallelSM_enact_Motion_Sensor_No_One(ParallelSM* handle)
{
	/* Entry action for state 'No One'. */
	parallelSM_setTimer(handle, (sc_eventid) &(handle->timeEvents.parallelSM_Motion_Sensor_No_One_tev0_raised) , 2 * 1000, bool_false);
}

/* Entry action for state 'Counter'. */
static void parallelSM_enact_Counter_Counter(ParallelSM* handle)
{
	/* Entry action for state 'Counter'. */
	parallelSM_setTimer(handle, (sc_eventid) &(handle->timeEvents.parallelSM_Counter_Counter_tev0_raised) , 1 * 1000, bool_true);
}

/* Entry action for state 'Reset'. */
static void parallelSM_enact_Counter_Reset(ParallelSM* handle)
{
	/* Entry action for state 'Reset'. */
	parallelSM_setTimer(handle, (sc_eventid) &(handle->timeEvents.parallelSM_Counter_Reset_tev0_raised) , 3 * 1000, bool_false);
}

/* Entry action for state 'Increase Value'. */
static void parallelSM_enact_Potentiometer_Increase_Value(ParallelSM* handle)
{
	/* Entry action for state 'Increase Value'. */
	handle->ifacePot.val += 1;
}

/* Entry action for state 'Decrease Value'. */
static void parallelSM_enact_Potentiometer_Decrease_Value(ParallelSM* handle)
{
	/* Entry action for state 'Decrease Value'. */
	handle->ifacePot.val -= 1;
}

/* Exit action for state 'Incoming'. */
static void parallelSM_exact_LoRa_Incoming(ParallelSM* handle)
{
	/* Exit action for state 'Incoming'. */
	parallelSM_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.parallelSM_LoRa_Incoming_tev0_raised) );		
}

/* Exit action for state 'Outgoing'. */
static void parallelSM_exact_LoRa_Outgoing(ParallelSM* handle)
{
	/* Exit action for state 'Outgoing'. */
	parallelSM_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.parallelSM_LoRa_Outgoing_tev0_raised) );		
}

/* Exit action for state 'Parse'. */
static void parallelSM_exact_LoRa_Parse(ParallelSM* handle)
{
	/* Exit action for state 'Parse'. */
	parallelSM_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.parallelSM_LoRa_Parse_tev0_raised) );		
}

/* Exit action for state 'Serialize'. */
static void parallelSM_exact_LoRa_Serialize(ParallelSM* handle)
{
	/* Exit action for state 'Serialize'. */
	parallelSM_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.parallelSM_LoRa_Serialize_tev0_raised) );		
}

/* Exit action for state 'Someone'. */
static void parallelSM_exact_Motion_Sensor_Someone(ParallelSM* handle)
{
	/* Exit action for state 'Someone'. */
	parallelSM_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.parallelSM_Motion_Sensor_Someone_tev0_raised) );		
}

/* Exit action for state 'No One'. */
static void parallelSM_exact_Motion_Sensor_No_One(ParallelSM* handle)
{
	/* Exit action for state 'No One'. */
	parallelSM_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.parallelSM_Motion_Sensor_No_One_tev0_raised) );		
}

/* Exit action for state 'Counter'. */
static void parallelSM_exact_Counter_Counter(ParallelSM* handle)
{
	/* Exit action for state 'Counter'. */
	parallelSM_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.parallelSM_Counter_Counter_tev0_raised) );		
}

/* Exit action for state 'Reset'. */
static void parallelSM_exact_Counter_Reset(ParallelSM* handle)
{
	/* Exit action for state 'Reset'. */
	parallelSM_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.parallelSM_Counter_Reset_tev0_raised) );		
}

/* 'default' enter sequence for state Setup */
static void parallelSM_enseq_Main_Region_Setup_default(ParallelSM* handle)
{
	/* 'default' enter sequence for state Setup */
	handle->stateConfVector[0] = ParallelSM_Main_Region_Setup;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Loop */
static void parallelSM_enseq_Main_Region_Loop_default(ParallelSM* handle)
{
	/* 'default' enter sequence for state Loop */
	handle->stateConfVector[0] = ParallelSM_Main_Region_Loop;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state LED On */
static void parallelSM_enseq_LED_LED_On_default(ParallelSM* handle)
{
	/* 'default' enter sequence for state LED On */
	handle->stateConfVector[1] = ParallelSM_LED_LED_On;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state LED Off */
static void parallelSM_enseq_LED_LED_Off_default(ParallelSM* handle)
{
	/* 'default' enter sequence for state LED Off */
	handle->stateConfVector[1] = ParallelSM_LED_LED_Off;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state Incoming */
static void parallelSM_enseq_LoRa_Incoming_default(ParallelSM* handle)
{
	/* 'default' enter sequence for state Incoming */
	parallelSM_enact_LoRa_Incoming(handle);
	handle->stateConfVector[2] = ParallelSM_LoRa_Incoming;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state Outgoing */
static void parallelSM_enseq_LoRa_Outgoing_default(ParallelSM* handle)
{
	/* 'default' enter sequence for state Outgoing */
	parallelSM_enact_LoRa_Outgoing(handle);
	handle->stateConfVector[2] = ParallelSM_LoRa_Outgoing;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state LoRa */
static void parallelSM_enseq_LoRa_LoRa_default(ParallelSM* handle)
{
	/* 'default' enter sequence for state LoRa */
	handle->stateConfVector[2] = ParallelSM_LoRa_LoRa;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state Parse */
static void parallelSM_enseq_LoRa_Parse_default(ParallelSM* handle)
{
	/* 'default' enter sequence for state Parse */
	parallelSM_enact_LoRa_Parse(handle);
	handle->stateConfVector[2] = ParallelSM_LoRa_Parse;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state Serialize */
static void parallelSM_enseq_LoRa_Serialize_default(ParallelSM* handle)
{
	/* 'default' enter sequence for state Serialize */
	parallelSM_enact_LoRa_Serialize(handle);
	handle->stateConfVector[2] = ParallelSM_LoRa_Serialize;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state Motion Sensor */
static void parallelSM_enseq_Motion_Sensor_Motion_Sensor_default(ParallelSM* handle)
{
	/* 'default' enter sequence for state Motion Sensor */
	handle->stateConfVector[3] = ParallelSM_Motion_Sensor_Motion_Sensor;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state Someone */
static void parallelSM_enseq_Motion_Sensor_Someone_default(ParallelSM* handle)
{
	/* 'default' enter sequence for state Someone */
	parallelSM_enact_Motion_Sensor_Someone(handle);
	handle->stateConfVector[3] = ParallelSM_Motion_Sensor_Someone;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state No One */
static void parallelSM_enseq_Motion_Sensor_No_One_default(ParallelSM* handle)
{
	/* 'default' enter sequence for state No One */
	parallelSM_enact_Motion_Sensor_No_One(handle);
	handle->stateConfVector[3] = ParallelSM_Motion_Sensor_No_One;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state Counter */
static void parallelSM_enseq_Counter_Counter_default(ParallelSM* handle)
{
	/* 'default' enter sequence for state Counter */
	parallelSM_enact_Counter_Counter(handle);
	handle->stateConfVector[4] = ParallelSM_Counter_Counter;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state Reset */
static void parallelSM_enseq_Counter_Reset_default(ParallelSM* handle)
{
	/* 'default' enter sequence for state Reset */
	parallelSM_enact_Counter_Reset(handle);
	handle->stateConfVector[4] = ParallelSM_Counter_Reset;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state Potentiometer */
static void parallelSM_enseq_Potentiometer_Potentiometer_default(ParallelSM* handle)
{
	/* 'default' enter sequence for state Potentiometer */
	handle->stateConfVector[5] = ParallelSM_Potentiometer_Potentiometer;
	handle->stateConfVectorPosition = 5;
}

/* 'default' enter sequence for state Increase Value */
static void parallelSM_enseq_Potentiometer_Increase_Value_default(ParallelSM* handle)
{
	/* 'default' enter sequence for state Increase Value */
	parallelSM_enact_Potentiometer_Increase_Value(handle);
	handle->stateConfVector[5] = ParallelSM_Potentiometer_Increase_Value;
	handle->stateConfVectorPosition = 5;
}

/* 'default' enter sequence for state Decrease Value */
static void parallelSM_enseq_Potentiometer_Decrease_Value_default(ParallelSM* handle)
{
	/* 'default' enter sequence for state Decrease Value */
	parallelSM_enact_Potentiometer_Decrease_Value(handle);
	handle->stateConfVector[5] = ParallelSM_Potentiometer_Decrease_Value;
	handle->stateConfVectorPosition = 5;
}

/* 'default' enter sequence for region Main Region */
static void parallelSM_enseq_Main_Region_default(ParallelSM* handle)
{
	/* 'default' enter sequence for region Main Region */
	parallelSM_react_Main_Region__entry_Default(handle);
}

/* 'default' enter sequence for region LED */
static void parallelSM_enseq_LED_default(ParallelSM* handle)
{
	/* 'default' enter sequence for region LED */
	parallelSM_react_LED__entry_Default(handle);
}

/* 'default' enter sequence for region LoRa */
static void parallelSM_enseq_LoRa_default(ParallelSM* handle)
{
	/* 'default' enter sequence for region LoRa */
	parallelSM_react_LoRa__entry_Default(handle);
}

/* 'default' enter sequence for region Motion Sensor */
static void parallelSM_enseq_Motion_Sensor_default(ParallelSM* handle)
{
	/* 'default' enter sequence for region Motion Sensor */
	parallelSM_react_Motion_Sensor__entry_Default(handle);
}

/* 'default' enter sequence for region Counter */
static void parallelSM_enseq_Counter_default(ParallelSM* handle)
{
	/* 'default' enter sequence for region Counter */
	parallelSM_react_Counter__entry_Default(handle);
}

/* 'default' enter sequence for region Potentiometer */
static void parallelSM_enseq_Potentiometer_default(ParallelSM* handle)
{
	/* 'default' enter sequence for region Potentiometer */
	parallelSM_react_Potentiometer__entry_Default(handle);
}

/* Default exit sequence for state Setup */
static void parallelSM_exseq_Main_Region_Setup(ParallelSM* handle)
{
	/* Default exit sequence for state Setup */
	handle->stateConfVector[0] = ParallelSM_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Loop */
static void parallelSM_exseq_Main_Region_Loop(ParallelSM* handle)
{
	/* Default exit sequence for state Loop */
	handle->stateConfVector[0] = ParallelSM_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state LED On */
static void parallelSM_exseq_LED_LED_On(ParallelSM* handle)
{
	/* Default exit sequence for state LED On */
	handle->stateConfVector[1] = ParallelSM_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state LED Off */
static void parallelSM_exseq_LED_LED_Off(ParallelSM* handle)
{
	/* Default exit sequence for state LED Off */
	handle->stateConfVector[1] = ParallelSM_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state Incoming */
static void parallelSM_exseq_LoRa_Incoming(ParallelSM* handle)
{
	/* Default exit sequence for state Incoming */
	handle->stateConfVector[2] = ParallelSM_last_state;
	handle->stateConfVectorPosition = 2;
	parallelSM_exact_LoRa_Incoming(handle);
}

/* Default exit sequence for state Outgoing */
static void parallelSM_exseq_LoRa_Outgoing(ParallelSM* handle)
{
	/* Default exit sequence for state Outgoing */
	handle->stateConfVector[2] = ParallelSM_last_state;
	handle->stateConfVectorPosition = 2;
	parallelSM_exact_LoRa_Outgoing(handle);
}

/* Default exit sequence for state LoRa */
static void parallelSM_exseq_LoRa_LoRa(ParallelSM* handle)
{
	/* Default exit sequence for state LoRa */
	handle->stateConfVector[2] = ParallelSM_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state Parse */
static void parallelSM_exseq_LoRa_Parse(ParallelSM* handle)
{
	/* Default exit sequence for state Parse */
	handle->stateConfVector[2] = ParallelSM_last_state;
	handle->stateConfVectorPosition = 2;
	parallelSM_exact_LoRa_Parse(handle);
}

/* Default exit sequence for state Serialize */
static void parallelSM_exseq_LoRa_Serialize(ParallelSM* handle)
{
	/* Default exit sequence for state Serialize */
	handle->stateConfVector[2] = ParallelSM_last_state;
	handle->stateConfVectorPosition = 2;
	parallelSM_exact_LoRa_Serialize(handle);
}

/* Default exit sequence for state Motion Sensor */
static void parallelSM_exseq_Motion_Sensor_Motion_Sensor(ParallelSM* handle)
{
	/* Default exit sequence for state Motion Sensor */
	handle->stateConfVector[3] = ParallelSM_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state Someone */
static void parallelSM_exseq_Motion_Sensor_Someone(ParallelSM* handle)
{
	/* Default exit sequence for state Someone */
	handle->stateConfVector[3] = ParallelSM_last_state;
	handle->stateConfVectorPosition = 3;
	parallelSM_exact_Motion_Sensor_Someone(handle);
}

/* Default exit sequence for state No One */
static void parallelSM_exseq_Motion_Sensor_No_One(ParallelSM* handle)
{
	/* Default exit sequence for state No One */
	handle->stateConfVector[3] = ParallelSM_last_state;
	handle->stateConfVectorPosition = 3;
	parallelSM_exact_Motion_Sensor_No_One(handle);
}

/* Default exit sequence for state Counter */
static void parallelSM_exseq_Counter_Counter(ParallelSM* handle)
{
	/* Default exit sequence for state Counter */
	handle->stateConfVector[4] = ParallelSM_last_state;
	handle->stateConfVectorPosition = 4;
	parallelSM_exact_Counter_Counter(handle);
}

/* Default exit sequence for state Reset */
static void parallelSM_exseq_Counter_Reset(ParallelSM* handle)
{
	/* Default exit sequence for state Reset */
	handle->stateConfVector[4] = ParallelSM_last_state;
	handle->stateConfVectorPosition = 4;
	parallelSM_exact_Counter_Reset(handle);
}

/* Default exit sequence for state Potentiometer */
static void parallelSM_exseq_Potentiometer_Potentiometer(ParallelSM* handle)
{
	/* Default exit sequence for state Potentiometer */
	handle->stateConfVector[5] = ParallelSM_last_state;
	handle->stateConfVectorPosition = 5;
}

/* Default exit sequence for state Increase Value */
static void parallelSM_exseq_Potentiometer_Increase_Value(ParallelSM* handle)
{
	/* Default exit sequence for state Increase Value */
	handle->stateConfVector[5] = ParallelSM_last_state;
	handle->stateConfVectorPosition = 5;
}

/* Default exit sequence for state Decrease Value */
static void parallelSM_exseq_Potentiometer_Decrease_Value(ParallelSM* handle)
{
	/* Default exit sequence for state Decrease Value */
	handle->stateConfVector[5] = ParallelSM_last_state;
	handle->stateConfVectorPosition = 5;
}

/* Default exit sequence for region Main Region */
static void parallelSM_exseq_Main_Region(ParallelSM* handle)
{
	/* Default exit sequence for region Main Region */
	/* Handle exit of all possible states (of ParallelSM.Main_Region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case ParallelSM_Main_Region_Setup :
		{
			parallelSM_exseq_Main_Region_Setup(handle);
			break;
		}
		case ParallelSM_Main_Region_Loop :
		{
			parallelSM_exseq_Main_Region_Loop(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region LED */
static void parallelSM_exseq_LED(ParallelSM* handle)
{
	/* Default exit sequence for region LED */
	/* Handle exit of all possible states (of ParallelSM.LED) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case ParallelSM_LED_LED_On :
		{
			parallelSM_exseq_LED_LED_On(handle);
			break;
		}
		case ParallelSM_LED_LED_Off :
		{
			parallelSM_exseq_LED_LED_Off(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region LoRa */
static void parallelSM_exseq_LoRa(ParallelSM* handle)
{
	/* Default exit sequence for region LoRa */
	/* Handle exit of all possible states (of ParallelSM.LoRa) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case ParallelSM_LoRa_Incoming :
		{
			parallelSM_exseq_LoRa_Incoming(handle);
			break;
		}
		case ParallelSM_LoRa_Outgoing :
		{
			parallelSM_exseq_LoRa_Outgoing(handle);
			break;
		}
		case ParallelSM_LoRa_LoRa :
		{
			parallelSM_exseq_LoRa_LoRa(handle);
			break;
		}
		case ParallelSM_LoRa_Parse :
		{
			parallelSM_exseq_LoRa_Parse(handle);
			break;
		}
		case ParallelSM_LoRa_Serialize :
		{
			parallelSM_exseq_LoRa_Serialize(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Motion Sensor */
static void parallelSM_exseq_Motion_Sensor(ParallelSM* handle)
{
	/* Default exit sequence for region Motion Sensor */
	/* Handle exit of all possible states (of ParallelSM.Motion_Sensor) at position 3... */
	switch(handle->stateConfVector[ 3 ])
	{
		case ParallelSM_Motion_Sensor_Motion_Sensor :
		{
			parallelSM_exseq_Motion_Sensor_Motion_Sensor(handle);
			break;
		}
		case ParallelSM_Motion_Sensor_Someone :
		{
			parallelSM_exseq_Motion_Sensor_Someone(handle);
			break;
		}
		case ParallelSM_Motion_Sensor_No_One :
		{
			parallelSM_exseq_Motion_Sensor_No_One(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Counter */
static void parallelSM_exseq_Counter(ParallelSM* handle)
{
	/* Default exit sequence for region Counter */
	/* Handle exit of all possible states (of ParallelSM.Counter) at position 4... */
	switch(handle->stateConfVector[ 4 ])
	{
		case ParallelSM_Counter_Counter :
		{
			parallelSM_exseq_Counter_Counter(handle);
			break;
		}
		case ParallelSM_Counter_Reset :
		{
			parallelSM_exseq_Counter_Reset(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Potentiometer */
static void parallelSM_exseq_Potentiometer(ParallelSM* handle)
{
	/* Default exit sequence for region Potentiometer */
	/* Handle exit of all possible states (of ParallelSM.Potentiometer) at position 5... */
	switch(handle->stateConfVector[ 5 ])
	{
		case ParallelSM_Potentiometer_Potentiometer :
		{
			parallelSM_exseq_Potentiometer_Potentiometer(handle);
			break;
		}
		case ParallelSM_Potentiometer_Increase_Value :
		{
			parallelSM_exseq_Potentiometer_Increase_Value(handle);
			break;
		}
		case ParallelSM_Potentiometer_Decrease_Value :
		{
			parallelSM_exseq_Potentiometer_Decrease_Value(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state Setup. */
static void parallelSM_react_Main_Region_Setup(ParallelSM* handle)
{
	/* The reactions of state Setup. */
	if (parallelSM_check_Main_Region_Setup_tr0_tr0(handle) == bool_true)
	{ 
		parallelSM_effect_Main_Region_Setup_tr0(handle);
	} 
}

/* The reactions of state Loop. */
static void parallelSM_react_Main_Region_Loop(ParallelSM* handle)
{
	/* The reactions of state Loop. */
	if (parallelSM_check_Main_Region_Loop_tr0_tr0(handle) == bool_true)
	{ 
		parallelSM_effect_Main_Region_Loop_tr0(handle);
	} 
}

/* The reactions of state LED On. */
static void parallelSM_react_LED_LED_On(ParallelSM* handle)
{
	/* The reactions of state LED On. */
	if (parallelSM_check_LED_LED_On_tr0_tr0(handle) == bool_true)
	{ 
		parallelSM_effect_LED_LED_On_tr0(handle);
	} 
}

/* The reactions of state LED Off. */
static void parallelSM_react_LED_LED_Off(ParallelSM* handle)
{
	/* The reactions of state LED Off. */
	if (parallelSM_check_LED_LED_Off_tr0_tr0(handle) == bool_true)
	{ 
		parallelSM_effect_LED_LED_Off_tr0(handle);
	} 
}

/* The reactions of state Incoming. */
static void parallelSM_react_LoRa_Incoming(ParallelSM* handle)
{
	/* The reactions of state Incoming. */
	if (parallelSM_check_LoRa_Incoming_tr0_tr0(handle) == bool_true)
	{ 
		parallelSM_effect_LoRa_Incoming_tr0(handle);
	} 
}

/* The reactions of state Outgoing. */
static void parallelSM_react_LoRa_Outgoing(ParallelSM* handle)
{
	/* The reactions of state Outgoing. */
	if (parallelSM_check_LoRa_Outgoing_tr0_tr0(handle) == bool_true)
	{ 
		parallelSM_effect_LoRa_Outgoing_tr0(handle);
	} 
}

/* The reactions of state LoRa. */
static void parallelSM_react_LoRa_LoRa(ParallelSM* handle)
{
	/* The reactions of state LoRa. */
	if (parallelSM_check_LoRa_LoRa_tr0_tr0(handle) == bool_true)
	{ 
		parallelSM_effect_LoRa_LoRa_tr0(handle);
	}  else
	{
		if (parallelSM_check_LoRa_LoRa_tr1_tr1(handle) == bool_true)
		{ 
			parallelSM_effect_LoRa_LoRa_tr1(handle);
		} 
	}
}

/* The reactions of state Parse. */
static void parallelSM_react_LoRa_Parse(ParallelSM* handle)
{
	/* The reactions of state Parse. */
	if (parallelSM_check_LoRa_Parse_tr0_tr0(handle) == bool_true)
	{ 
		parallelSM_effect_LoRa_Parse_tr0(handle);
	} 
}

/* The reactions of state Serialize. */
static void parallelSM_react_LoRa_Serialize(ParallelSM* handle)
{
	/* The reactions of state Serialize. */
	if (parallelSM_check_LoRa_Serialize_tr0_tr0(handle) == bool_true)
	{ 
		parallelSM_effect_LoRa_Serialize_tr0(handle);
	} 
}

/* The reactions of state Motion Sensor. */
static void parallelSM_react_Motion_Sensor_Motion_Sensor(ParallelSM* handle)
{
	/* The reactions of state Motion Sensor. */
	if (parallelSM_check_Motion_Sensor_Motion_Sensor_tr0_tr0(handle) == bool_true)
	{ 
		parallelSM_effect_Motion_Sensor_Motion_Sensor_tr0(handle);
	}  else
	{
		if (parallelSM_check_Motion_Sensor_Motion_Sensor_tr1_tr1(handle) == bool_true)
		{ 
			parallelSM_effect_Motion_Sensor_Motion_Sensor_tr1(handle);
		} 
	}
}

/* The reactions of state Someone. */
static void parallelSM_react_Motion_Sensor_Someone(ParallelSM* handle)
{
	/* The reactions of state Someone. */
	if (parallelSM_check_Motion_Sensor_Someone_tr0_tr0(handle) == bool_true)
	{ 
		parallelSM_effect_Motion_Sensor_Someone_tr0(handle);
	} 
}

/* The reactions of state No One. */
static void parallelSM_react_Motion_Sensor_No_One(ParallelSM* handle)
{
	/* The reactions of state No One. */
	if (parallelSM_check_Motion_Sensor_No_One_tr0_tr0(handle) == bool_true)
	{ 
		parallelSM_effect_Motion_Sensor_No_One_tr0(handle);
	} 
}

/* The reactions of state Counter. */
static void parallelSM_react_Counter_Counter(ParallelSM* handle)
{
	/* The reactions of state Counter. */
	if (parallelSM_check_Counter_Counter_tr0_tr0(handle) == bool_true)
	{ 
		parallelSM_effect_Counter_Counter_tr0(handle);
	}  else
	{
		if (parallelSM_check_Counter_Counter_lr0_lr0(handle) == bool_true)
		{ 
			parallelSM_effect_Counter_Counter_lr0_lr0(handle);
		} 
	}
}

/* The reactions of state Reset. */
static void parallelSM_react_Counter_Reset(ParallelSM* handle)
{
	/* The reactions of state Reset. */
	if (parallelSM_check_Counter_Reset_tr0_tr0(handle) == bool_true)
	{ 
		parallelSM_effect_Counter_Reset_tr0(handle);
	} 
}

/* The reactions of state Potentiometer. */
static void parallelSM_react_Potentiometer_Potentiometer(ParallelSM* handle)
{
	/* The reactions of state Potentiometer. */
	if (parallelSM_check_Potentiometer_Potentiometer_tr0_tr0(handle) == bool_true)
	{ 
		parallelSM_effect_Potentiometer_Potentiometer_tr0(handle);
	}  else
	{
		if (parallelSM_check_Potentiometer_Potentiometer_tr1_tr1(handle) == bool_true)
		{ 
			parallelSM_effect_Potentiometer_Potentiometer_tr1(handle);
		} 
	}
}

/* The reactions of state Increase Value. */
static void parallelSM_react_Potentiometer_Increase_Value(ParallelSM* handle)
{
	/* The reactions of state Increase Value. */
	parallelSM_effect_Potentiometer_Increase_Value_tr0(handle);
}

/* The reactions of state Decrease Value. */
static void parallelSM_react_Potentiometer_Decrease_Value(ParallelSM* handle)
{
	/* The reactions of state Decrease Value. */
	parallelSM_effect_Potentiometer_Decrease_Value_tr0(handle);
}

/* Default react sequence for initial entry  */
static void parallelSM_react_Main_Region__entry_Default(ParallelSM* handle)
{
	/* Default react sequence for initial entry  */
	parallelSM_enseq_Main_Region_Setup_default(handle);
}

/* Default react sequence for initial entry  */
static void parallelSM_react_LED__entry_Default(ParallelSM* handle)
{
	/* Default react sequence for initial entry  */
	parallelSM_enseq_LED_LED_On_default(handle);
}

/* Default react sequence for initial entry  */
static void parallelSM_react_LoRa__entry_Default(ParallelSM* handle)
{
	/* Default react sequence for initial entry  */
	parallelSM_enseq_LoRa_LoRa_default(handle);
}

/* Default react sequence for initial entry  */
static void parallelSM_react_Motion_Sensor__entry_Default(ParallelSM* handle)
{
	/* Default react sequence for initial entry  */
	parallelSM_enseq_Motion_Sensor_Motion_Sensor_default(handle);
}

/* Default react sequence for initial entry  */
static void parallelSM_react_Counter__entry_Default(ParallelSM* handle)
{
	/* Default react sequence for initial entry  */
	handle->ifaceCounter.x = 10;
	parallelSM_enseq_Counter_Counter_default(handle);
}

/* Default react sequence for initial entry  */
static void parallelSM_react_Potentiometer__entry_Default(ParallelSM* handle)
{
	/* Default react sequence for initial entry  */
	parallelSM_enseq_Potentiometer_Potentiometer_default(handle);
}


