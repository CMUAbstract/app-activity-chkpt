#include <msp430.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <libmsp/mem.h>
#include <libio/log.h>
#include <msp-builtins.h>

#ifdef CONFIG_EDB
#include <libedb/edb.h>
#else
#define ENERGY_GUARD_BEGIN()
#define ENERGY_GUARD_END()
#endif

#ifdef DINO
#include <dino.h>
#endif

#include "pins.h"

static __nv unsigned curtask;

/* This is for progress reporting only */
#define SET_CURTASK(t) curtask = t

#define TASK_MAIN                   1

#ifdef DINO

#define TASK_BOUNDARY(t, x) \
        DINO_TASK_BOUNDARY_MANUAL(x); \
        SET_CURTASK(t); \

#define DINO_RESTORE_NONE() \
        DINO_REVERT_BEGIN() \
        DINO_REVERT_END() \

#define DINO_RESTORE_PTR(nm, type) \
        DINO_REVERT_BEGIN() \
        DINO_REVERT_PTR(type, nm); \
        DINO_REVERT_END() \

#define DINO_RESTORE_VAL(nm, label) \
        DINO_REVERT_BEGIN() \
        DINO_REVERT_VAL(nm, label); \
        DINO_REVERT_END() \

#else // !DINO

#define TASK_BOUNDARY(t, x) SET_CURTASK(t)

#define DINO_RESTORE_CHECK()
#define DINO_VERSION_PTR(...)
#define DINO_VERSION_VAL(...)
#define DINO_RESTORE_NONE()
#define DINO_RESTORE_PTR(...)
#define DINO_RESTORE_VAL(...)
#define DINO_REVERT_BEGIN(...)
#define DINO_REVERT_END(...)
#define DINO_REVERT_VAL(...)

#endif // !DINO

void init()
{
    WISP_init();

#ifdef CONFIG_EDB
    debug_setup();
#endif

    INIT_CONSOLE();

    __enable_interrupt();

    GPIO(PORT_LED_1, DIR) |= BIT(PIN_LED_1);
    GPIO(PORT_LED_2, DIR) |= BIT(PIN_LED_2);
#if defined(PORT_LED_3)
    GPIO(PORT_LED_3, DIR) |= BIT(PIN_LED_3);
#endif

#if defined(PORT_LED_3) // when available, this LED indicates power-on
    GPIO(PORT_LED_3, OUT) |= BIT(PIN_LED_3);
#endif

    EIF_PRINTF(".%u.\r\n", curtask);
}

int main()
{
#ifndef MEMENTOS
    init();
#endif

    DINO_RESTORE_CHECK();

    while (1)
    {
        TASK_BOUNDARY(TASK_MAIN, NULL);
        DINO_RESTORE_NONE();

        PRINTF("Hello world!\r\n");

#ifdef CONT_POWER
        volatile uint32_t delay = 0x8ffff;
        while (delay--);
#endif // CONT_POWER
    }

    return 0;
}
