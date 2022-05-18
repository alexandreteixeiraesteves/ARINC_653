
/*  Copyright (C) 2016, Inria
    Author: Dumitru Potop-Butucaru.

    This file is part of RPi653. 

    RPi653 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3 of the License.

    RPi653 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 */
/*----------------------------------------------------------------*/
/*                                                                */
/* PROCESS constant and type definitions and management services  */
/*                                                                */
/*----------------------------------------------------------------*/
#ifndef APEX_PROCESS
#define APEX_PROCESS

#include <arinc653/types.h>

#define MAX_NUMBER_OF_PROCESSES SYSTEM_LIMIT_NUMBER_OF_PROCESSES
#define MIN_PRIORITY_VALUE 1
#define MAX_PRIORITY_VALUE 239
#define MAX_LOCK_LEVEL 16
typedef NAME_TYPE            PROCESS_NAME_TYPE;
typedef APEX_INTEGER           PROCESS_ID_TYPE;
#define NULL_PROCESS_ID -1
typedef APEX_INTEGER           LOCK_LEVEL_TYPE;
typedef APEX_UNSIGNED          STACK_SIZE_TYPE;
/* This type seems to be the range 0..MAX_NUMBER_OF_PROCESSES */
typedef APEX_INTEGER        WAITING_RANGE_TYPE;
typedef APEX_INTEGER             PRIORITY_TYPE;

typedef enum {
  DORMANT = 0,
  READY = 1,
  RUNNING = 2,
  WAITING = 3
} PROCESS_STATE_TYPE;

typedef enum {
  SOFT = 0,
  HARD = 1
} DEADLINE_TYPE;

typedef struct {
  SYSTEM_TIME_TYPE PERIOD;
  SYSTEM_TIME_TYPE TIME_CAPACITY;
  SYSTEM_ADDRESS_TYPE ENTRY_POINT;
  STACK_SIZE_TYPE STACK_SIZE;
  PRIORITY_TYPE BASE_PRIORITY;
  DEADLINE_TYPE DEADLINE;
  PROCESS_NAME_TYPE NAME;
} PROCESS_ATTRIBUTE_TYPE;

typedef struct {
  SYSTEM_TIME_TYPE DEADLINE_TIME;
  PRIORITY_TYPE CURRENT_PRIORITY;
  PROCESS_STATE_TYPE PROCESS_STATE;
  PROCESS_ATTRIBUTE_TYPE ATTRIBUTES;
} PROCESS_STATUS_TYPE;

void CREATE_PROCESS (/*in */ PROCESS_ATTRIBUTE_TYPE *ATTRIBUTES,
		     /*out*/ PROCESS_ID_TYPE *PROCESS_ID,
		     /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

void SET_PRIORITY (/*in */ PROCESS_ID_TYPE PROCESS_ID,
		   /*in */ PRIORITY_TYPE PRIORITY,
		   /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

void SUSPEND_SELF (/*in */ SYSTEM_TIME_TYPE TIME_OUT,
		   /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

void SUSPEND (/*in */ PROCESS_ID_TYPE PROCESS_ID,
	      /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

void RESUME (/*in */ PROCESS_ID_TYPE PROCESS_ID,
	     /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

void STOP_SELF (void);

void STOP (/*in */ PROCESS_ID_TYPE PROCESS_ID,
	   /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

void START (/*in */ PROCESS_ID_TYPE PROCESS_ID,
	    /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

void DELAYED_START (/*in */ PROCESS_ID_TYPE PROCESS_ID,
		    /*in */ SYSTEM_TIME_TYPE DELAY_TIME,
		    /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

void LOCK_PREEMPTION (/*out*/ LOCK_LEVEL_TYPE *LOCK_LEVEL,
		      /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

void UNLOCK_PREEMPTION (/*out*/ LOCK_LEVEL_TYPE *LOCK_LEVEL,
			/*out*/ RETURN_CODE_TYPE *RETURN_CODE );

void GET_MY_ID (/*out*/ PROCESS_ID_TYPE *PROCESS_ID,
		/*out*/ RETURN_CODE_TYPE *RETURN_CODE );

void GET_PROCESS_ID (/*in */ PROCESS_NAME_TYPE PROCESS_NAME,
		     /*out*/ PROCESS_ID_TYPE *PROCESS_ID,
		     /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

void GET_PROCESS_STATUS (/*in */ PROCESS_ID_TYPE PROCESS_ID,
			 /*out*/ PROCESS_STATUS_TYPE *PROCESS_STATUS,
			 /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

#endif
