#!/bin/bash

# Required actions
# Display architecture of your operation system and its kernel version
echo "#Architecture: $(uname -a)"

# Display number of physical processors
echo "#CPU Physical: $(nproc --all)"

# Display number of virtual processors
echo "#vCPU : "

# Display current available RAM on your server and its utilization rate as a percentage
echo "#Memory Usage: "; free -h | grep Mem | awk '{printf("%d/%dMB (%0.2f%%)\n",$3, $4, $3/$4 * 100)}'

# Display current available storage on your server and its utilization rate as a percentage
echo "#Disk Usage: "

# Display current utilization rate of your processors as a percentage
echo "#CPU load: "

# Display the date and time of the last reboot
echo "#Last boot: "

# Display whether LVM is active or not
echo "#LVM use: "

# Display the number of active connections
echo "#Connections TCP : ##### ESTABLISHED"

# Display the number of users using the server
echo "#User log: "

# Display the IPv4 address of your server and its MAC address
echo "#Network: "

# Display the number of commands executed with the sudo program
echo "#Sudo : "

# --------------
# example
# --------------
#Architecture: Linux wil 4.19.0-16-amd64 #1 SMP Debian 4.19.181-1 (2021-03-19) x86_64 GNU/Linux
#CPU physical : 1
#vCPU : 1
#Memory Usage: 74/987MB (7.50%)
#Disk Usage: 1009/2Gb (49%)
#CPU load: 6.7%
#Last boot: 2021-04-25 14:45
#LVM use: yes
#Connections TCP : 1 ESTABLISHED
#User log: 1
#Network: IP 10.0.2.15 (08:00:27:51:9b:a5)
#Sudo : 42 cmd