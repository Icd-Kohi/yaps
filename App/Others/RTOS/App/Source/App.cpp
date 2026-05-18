/* 
 *  An RTOS is a software that enables real-time programs to run in memory-constrained 
 *  environments, so it must be small enough and efficient.
 *  It allows a cooperatively scheduling loop to grow in complexity
 *  without compromising the program execution, by providing concurrency and 
 *  a proper task scheduling.
 *
 *  Cooperative scheduling in a non-RTOS loop
 *  as the loop works cooperatively, the data receiving 
 *  and transmission gets blocked once the overhead is big enough.
 *
 *  Ways to fix w/o a RTOS implementation: making the 
 */

#include "../../Core/Source/Core/Core.h"
#include <cstdint>
#include <sys/types.h>

#define SIZE(obj) sizeof(obj)/sizeof(obj[0])
#define ARRAY_SIZE(fun) 5
typedef u_int16_t u16;
typedef u_int32_t u32;
typedef int16_t i16;
typedef int32_t i32;

/* 
 *      Definitions
 */
static u32 angle;

static void task_led(void){
    /*
     * led_toggle();
     */
}

static void task_pot_servo(void){
    /*
     * angle = pot_read() * 180 / 4095;
     * servo_set(angle);
     */
}

static void task_display(void){
    /*
     * display_update(angle, get_ms());
    */
}

struct task{
    void (*run)(void);
    u32 interval_ms;
    u32 last_ms;
};

// array os task structs
static struct task tasks[] = {
    {task_led,         500,    0},
    {task_pot_servo,   10,     0},
    {task_display,     100,    0}
};

int Core::main(){
    int thing = 0;
    return thing;
};

int main()
{
    /*
    * init();
    */
    
    while(1){
        /*
        u32 now = get_ms();
        */
        u32 now;
        for(size_t i = 0; i <= ARRAY_SIZE(tasks); ++i){
            if(now - tasks[i].last_ms >= tasks[i].interval_ms){
                tasks[i].last_ms = now;
                tasks[i].run();
            }
        }
    }
    return Core::main();
}

