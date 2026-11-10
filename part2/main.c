#include <zephyr/kernel.h> 
#include <zephyr/drivers/gpio.h> 

#define SWITCH_NODE DT_NODELABEL(external_switch) // finds the swithc defined in app.overlay gives name swithc node 
#define LED_NODE DT_NODELABEL(external_led) // finds led defined in app overlay gives name led node 

static const struct gpio_dt_spec switchinput = 
    GPIO_DT_SPEC_GET(SWITCH_NODE, gpios); // creates constant gpio requirements for switch and recives all infomration from it from device tree
static const struct gpio_dt_spec light = 
    GPIO_DT_SPEC_GET(LED_NODE, gpios); // creates constant requiremenrs for led and recives all information from device tree 


int main(void) 
{    gpio_pin_configure_dt(&switchinput, GPIO_INPUT); // configs led pin as input to read state 
    gpio_pin_configure_dt(&light, GPIO_OUTPUT_INACTIVE); //  configs led pin as out put 

    while (1) { //infinite loop checks the switch 
int switch_value = gpio_pin_get_dt(&switchinput); 
    if (switch_value == 1) { // checks if switch is acitve 
        gpio_pin_set_dt(&light, 1); // led on 
    } else { 
        gpio_pin_set_dt(&light, 0); 
    } 
   k_sleep(K_MSEC(10)); // pauses loop for 10 ms
  } 
  return 0; // successful return
}   