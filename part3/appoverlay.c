{ 
 bus_outputs { 
    compatible = "gpio-leds"; 

bus_lsb: led_1 { 
    gpios = <&gpio0 29 GPIO_ACTIVE_HIGH>; 
    label = "Bus LSB"; 
}; 

bus_msb: led_2 { 
    gpios = <&gpio1 23 GPIO_ACTIVE_HIGH>; 
    label = "Bus MSB"; 
   }; 
  }; 
}; 
