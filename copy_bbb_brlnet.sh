#!/bin/bash
echo "I'll copy all ADIS_Interface files over to the BBB"

rsync -avzh ./src/*.cpp 						BBB_BRLNET:/home/ubuntu/uwesub_catkin_workspace/src/thruster_ident/src/
rsync -avzh ./include/thruster_ident/*.hpp 			BBB_BRLNET:/home/ubuntu/uwesub_catkin_workspace/src/thruster_ident/include/thruster_ident/
rsync -avzh CMakeLists.txt 						BBB_BRLNET:/home/ubuntu/uwesub_catkin_workspace/src/thruster_ident/
rsync -avzh *.md								BBB_BRLNET:/home/ubuntu/uwesub_catkin_workspace/src/thruster_ident/
rsync -avzh *.xml								BBB_BRLNET:/home/ubuntu/uwesub_catkin_workspace/src/thruster_ident/
rsync -avzh ./msg/*.msg							BBB_BRLNET:/home/ubuntu/uwesub_catkin_workspace/src/thruster_ident/msg/


echo "All done, Good Success!"