#include <zephyr/kernel.h> 
#include <zephyr/drivers/gpio.h> 
#define SWITCH_NODE DT_NODELABEL(external_switch) 
#define LED_NODE DT_NODELABEL(external_led)

static const struct gpio_dt_spec switchinput = 
    GPIO_DT_SPEC_GET(SWITCH_NODE, gpios); 
static const struct gpio_dt_spec light = 
    GPIO_DT_SPEC_GET(LED_NODE, gpios); 


int main(void) 
{    gpio_pin_configure_dt(&switchinput, GPIO_INPUT); 
    gpio_pin_configure_dt(&light, GPIO_OUTPUT_INACTIVE);

    while (1) { 
int switch_value = gpio_pin_get_dt(&switchinput); 
    if (switch_value == 1) { 
        gpio_pin_set_dt(&light, 1); 
    } else { 
        gpio_pin_set_dt(&light, 0); 
    } 
   k_sleep(K_MSEC(10)); 
  } 
  return 0; 
}