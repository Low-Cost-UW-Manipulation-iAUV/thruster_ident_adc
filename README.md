thruster_ident_adc
===========================
Reads the ADC value from the BBB and publishes it. It uses the Pins: 
It requires you to load the overlay beforehand (activates the ADC. THis will change with new versions of the linux kernel I believe):

```bash
echo "echo cape-bone-iio > /sys/devices/bone_capemgr.9/slots" | sudo sh
rosrun thruster_ident_adc adc_pub
```
