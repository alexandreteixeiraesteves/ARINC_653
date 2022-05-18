// ARINC 653 standard headers
#include <arinc653/error.h>
#include <arinc653/partition.h>
#include <arinc653/process.h>
#include <arinc653/queuing.h>
#include <arinc653/time.h>

// Standard C library elements
#include <libc/string.h>

// RPi653-specific includes
#define RPi653
#include <libpartition/lopht-debug.h>
#include <librpi/debug.h>


// The task function
void t1(){
  RETURN_CODE_TYPE rc ;
  int cnt = 0 ;
  for(;;){
    // Each task instance prints the current instance counter
    // and then increments it for the next cycle.
    debug_printf("Task t1. Instance %d\n",cnt) ;
    cnt++ ;
    // Wait until the next task instance
    PERIODIC_WAIT(&rc) ;
    console_perror(rc,"alexandr","t1:PERIODIC_WAIT");
  }
}

// Process attribute type struct, statically initialized
PROCESS_ATTRIBUTE_TYPE t1_pat ;
PROCESS_ID_TYPE        t1_pid ;

// Partition entry point, that 
void main_process() {
  // Initialize the attributes of process t1
  t1_pat.PERIOD        = 0xf4240 ;
  t1_pat.TIME_CAPACITY = 0xf4240 ;
  t1_pat.ENTRY_POINT   = (void*)t1 ;
  t1_pat.STACK_SIZE    = 0x1000 ;
  t1_pat.BASE_PRIORITY = 0x1 ;
  t1_pat.DEADLINE      = HARD ;
  strcpy(t1_pat.NAME,"t1") ;
  // Create process t1
  RETURN_CODE_TYPE rc ;
  CREATE_PROCESS(&t1_pat,&t1_pid,&rc) ;
  console_perror(rc,"alexandr","main_process:CREATE_PROCESS");
  // Start process t1. This places it into waiting mode.
  // Actual start will take place at the temporal reference
  // point.
  START(t1_pid,&rc) ;
  console_perror(rc,"alexandr","main_process:START");
  // Enter NORMAL mode
  SET_PARTITION_MODE(NORMAL,&rc) ;
  console_perror(rc,"alexandr","main_process:SET_PARTITION_MODE");
  // In the event of an error, keep the entry point from terminating
  for(;;);
}
