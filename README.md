thruster_ident_adc
===========================
Reads the ADC value from the BBB and publishes it.
It requires you to run the following beforehand:

<code>
echo "echo cape-bone-iio > /sys/devices/bone_capemgr.9/slots" | sudo sh
</code>
