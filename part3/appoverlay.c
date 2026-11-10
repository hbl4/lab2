{ // rooot of device tree 
 bus_outputs {  // creates two sections for the gpio out puts 
    compatible = "gpio-leds"; // tells zephyr their gpio 

bus_lsb: led_1 { // defines bit 0 
    gpios = <&gpio0 29 GPIO_ACTIVE_HIGH>; // controller 0 pin 29 active 
    label = "Bus LSB"; // variable name to call on 
}; 

bus_msb: led_2 { // bit 1 
    gpios = <&gpio1 23 GPIO_ACTIVE_HIGH>; // controller 1 pin 23 active 
    label = "Bus MSB"; 
   }; // eds bit 1 definiton
  }; // ends bus outputs 
}; //ends device tree 
