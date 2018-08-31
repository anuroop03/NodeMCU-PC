# NodeMCU-PC
A simple project to remote start any Desktop using NodeMCU connected to WIFI.
 
 *Power the NodeMCU by connecting the Standby 5v to the Vin and connect the ground to any ground from SATA power connector.
 * Find the Power Pin of the motherboard by consulting the Manual of your motherboard.
 * There will be two power pins. If you short these two pins the computer should boot..
 * Connect the ground of NodeMCU to one of the pin and check if the computer boots. If it boots connect it to the PwPin.
 * Find the IP address of NodeMCU. 
 * To boot your computer ping 192.168.X.X/S (Replace X.X with NodeMCU's IP).
 * Use port fowarding on the Wifi router to control the NodeMCU from outside the LAN.
 
