#include <stdio.h>
#include <stdint.h>

/* Number of consecutive identical samples required */
#define DEBOUNCE_COUNT 3

/*---------------------------------------------------
    Static Variables
---------------------------------------------------*/
static uint8_t stable_state;      // Current stable (debounced) state
static uint8_t previous_sample;   // Previous raw button sample
static uint8_t counter;           // Counts consecutive identical samples

/*---------------------------------------------------
    Function: button_init()
    Purpose : Initialize debounce variables
---------------------------------------------------*/
void button_init(void)
{
    stable_state = 0;      // Button starts released
    previous_sample = 0;   // Previous sample is also released
    counter = 0;           // No samples counted yet
}

/*---------------------------------------------------
    Function: button_update()
    Purpose : Process one raw button sample
    Input   : raw_state (0 = Released, 1 = Pressed)
    Return  : Stable debounced state
---------------------------------------------------*/
uint8_t button_update(uint8_t raw_state)
{
    /* Check if current sample is same as previous sample */
    if(raw_state == previous_sample)
    {
        counter++;
    }
    else
    {
        /* New sample detected */
        previous_sample = raw_state;
        counter = 1;
    }

    /* Accept new state only after enough identical samples */
    if(counter >= DEBOUNCE_COUNT)
    {
        stable_state = raw_state;
    }

    return stable_state;
}


uint8_t button_get_state(void)
{
    return stable_state;
}


int main(void)
{
    button_init();

    /* Simulated raw button readings */
    uint8_t samples[] =
    {
        0,
        0,
        1,
        0,
        1,
        1,
        1,
        1,
        0,
        0,
        0
    };

    uint8_t previous_output = button_get_state();

    printf("Raw\tStable\n");
    printf("-----------------\n");

    for(int i = 0; i < sizeof(samples) / sizeof(samples[0]); i++)
    {
        uint8_t stable;

        stable = button_update(samples[i]);

        printf("%u\t%u\n", samples[i], stable);

        /* Print only when state changes */
        if(stable != previous_output)
        {
            if(stable == 1)
            {
                printf("Button Pressed\n");
            }
            else
            {
                printf("Button Released\n");
            }

            previous_output = stable;
        }
    }

    return 0;
}
