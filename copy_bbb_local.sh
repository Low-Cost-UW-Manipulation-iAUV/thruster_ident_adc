#!/bin/bash
echo "I'll copy all ADIS_Interface files over to the BBB"

rsync -avzh ./src/*.cpp 						BBB_local:/home/ubuntu/uwesub_catkin_workspace/src/thruster_ident_adc/src/
rsync -avzh ./include/thruster_ident_adc/*.hpp 			BBB_local:/home/ubuntu/uwesub_catkin_workspace/src/thruster_ident_adc/include/thruster_ident_adc/
rsync -avzh CMakeLists.txt 						BBB_local:/home/ubuntu/uwesub_catkin_workspace/src/thruster_ident_adc/
rsync -avzh *.md								BBB_local:/home/ubuntu/uwesub_catkin_workspace/src/thruster_ident_adc/
rsync -avzh *.xml								BBB_local:/home/ubuntu/uwesub_catkin_workspace/src/thruster_ident_adc/
rsync -avzh ./msg/*.msg							BBB_local:/home/ubuntu/uwesub_catkin_workspace/src/thruster_ident_adc/msg/
rsync -avzh ./launch/*.launch					BBB_local:/home/ubuntu/uwesub_catkin_workspace/src/thruster_ident_adc/launch/


echo "All done, Good Success!"