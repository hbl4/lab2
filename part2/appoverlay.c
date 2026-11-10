{    external_leds {  // after root had been opened creates a section for leds
    compatible = "gpio-leds";  // these are gpio controlled leds
    external_led: led_4 {  // asssigned variable to call on later
        gpios = <&gpio0 29 GPIO_ACTIVE_HIGH>; // active high measn leds on 
        label = "External LED"; 
    };
}; // ends external led section
    external_switches { // section for external switches
    compatible = "gpio-keys"; // these are gpio contorlled keys 
    external_switch: switch_0 {  // callable name for main
        gpios = <&gpio1 23 (GPIO_PULL_UP | GPIO_ACTIVE_LOW)>; // enables pull up makes low active
        label = "External Switch";
     };
   }; // ends external switch section
}; // ends main hardware 
