/*
 * Scheduler.h
 *
 *  Created on: Sep 10, 2024
 *      Author: Lochi
 */


#ifndef SCHEDULER_H_
#define SCHEDULER_H_
#include <stdint.h>


uint32_t getScheduledEvents();
void addSchedulerEvent(uint32_t event);
void removeSchedulerEvent(uint32_t event);

#define EVENT_LED_TOGGLE	(1 << 0)
#define EVENT_DELAY			(1 << 1)
#define EVENT_POLL_BUTTON	(1 << 2)
#define EVENT_APP_DELAY		(1 << 3)
#define EVENT_NEW_COMMAND	(1 << 4)


#endif /* SCHEDULER_H_ */
