#include <zephyr/kernel.h> // includes timings and delays 
#include <zephyr/drivers/gpio.h> // allows functions to control gpio pins

#define LSB_NODE DT_NODELABEL(bus_lsb) // finds node in app overlayt
#define MSB_NODE DT_NODELABEL(bus_msb) // finds msb node in app overlay 

static const struct gpio_dt_spec lsb = // gets config for d2 and d3 stores controller and settings 
    GPIO_DT_SPEC_GET(LSB_NODE, gpios); 
static const struct gpio_dt_spec msb = 
    GPIO_DT_SPEC_GET(MSB_NODE, gpios); 

static void write_bus(uint8_t value) 
{    gpio_pin_set_dt(&lsb, (value >> 0) & 1); // look at bit 0 and 1 to see if its high or low 
    gpio_pin_set_dt(&msb, (value >> 1) & 1);  // looks at only bit 1 to see if high or low 
} 

int main(void) 
{   int count; 
    uint8_t values[10] = { 0x0, 0x2, 0x0, 0x0, 0x0, 0x1, 0x3, 0x1, 0x0, 0x0 }; // hexadecimal to see if d2 or d3 are high or low 
// unsigned 8 bit stores numbers from 0 to 255
gpio_pin_configure_dt(&lsb, GPIO_OUTPUT_INACTIVE); 
gpio_pin_configure_dt(&msb, GPIO_OUTPUT_INACTIVE); // both set as low  

while (1) { 
    for (count = 0; count < 10; count++) { //loops through hexadecimal 
        write_bus(values[count]); // determines if d2 or d3 should be high or low 
        k_sleep(K_MSEC(10)); 
    } 
  } 
  return 0; 
}    