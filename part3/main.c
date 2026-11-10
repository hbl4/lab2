#include <zephyr/kernel.h> 
#include <zephyr/drivers/gpio.h> 

#define LSB_NODE DT_NODELABEL(bus_lsb) 
#define MSB_NODE DT_NODELABEL(bus_msb) 

static const struct gpio_dt_spec lsb = 
    GPIO_DT_SPEC_GET(LSB_NODE, gpios); 
static const struct gpio_dt_spec msb = 
    GPIO_DT_SPEC_GET(MSB_NODE, gpios); 

static void write_bus(uint8_t value) 
{    gpio_pin_set_dt(&lsb, (value >> 0) & 1); 
    gpio_pin_set_dt(&msb, (value >> 1) & 1); 
} 

int main(void) 
{   int count; 
    uint8_t values[10] = { 0x0, 0x2, 0x0, 0x0, 0x0, 0x1, 0x3, 0x1, 0x0, 0x0 };

gpio_pin_configure_dt(&lsb, GPIO_OUTPUT_INACTIVE); 
gpio_pin_configure_dt(&msb, GPIO_OUTPUT_INACTIVE); 

while (1) { 
    for (count = 0; count < 10; count++) { 
        write_bus(values[count]); 
        k_sleep(K_MSEC(10)); 
    } 
  } 
  return 0; 
}    