Montanari Matteo 928544
Pavan Massimo 945302

It's recommended to execute the command "source devel/setup.bash" every time before running the launcher.

A compilation error might occur while catkin_make for the first time. In this case it's recommended to compile once without the nodes, leaving only the messages to create their header, and then re-add them and compile again. 

the project consists in: 
	3 main nodes inside sources:
		-subscriber_node.cpp is the file describing the node that reads the arguments from the bag, and publish the odometry
			and the tf.
		-client.cpp reads the odometry messages published from the subscriber and from them it calulates the distance
			calling the service server, and then publishes the custom message under the topic /results.
		-server.cpp is a simple service server to calculate the distance from the x,y,z values of the 2 points.
	
	1 message file inside msg:
		-custom_msg.msg describing the custom message published from client, consisting of distance and flag value.
	
	1 distance file inside srv:
		-distance.srv describing the service messages between client and server, consisting of the x,y,z values of the 
			2 points and returning a float value for the distance between the 2.
	
	1 configuration file inside cfg:
		-slider.cfg in which are specified the two threshold for the parameters of the flag values unsafe and crash.


it's also included a launch file, called launcher.launch, in which are specified the parameters:
	starting latitude, longitude and h0 for the initial values of the three.

	starting crash and unsafe distance, under wich the flag is valued respectively 'crash' and 'unsafe'.


the tf tree is pretty simple, since the only two tf published are the one of the front and obstacle, besides the frame for the
world. A picture of the tf tree is provided in the file frames.pdf.

the structure of the custom message is the following:
	string status_flag
	float64 distance
please note that, as specification, no message of this type is published until both messages from front and obs are arriving.
status_flag can assume values 'safe', 'unsafe', 'crash', and, when a gps signal is missing, 'unknown'.
distance is set to nan when a gps signal is missing.


the structure of the service messages between client and server is the following:
	float64 xEastFront
	float64 yNorthFront
	float64 zUpFront
	float64 xEastObs
	float64 yNorthObs
	float64 zUpObs
	---
	float64 distance


the nodes are all started from the launch file, exception made for the bag node obviously. The two nodes for obs and front of type subscriber_node are instatiated passing as argument their respective names (front, obs) using "args", and retrieved inside the nodes
as argv[1].



We have also provided a screenshot of the odometry messages visualized in rviz (with a scale 1:200) displaying the Monza Eni Circuit

