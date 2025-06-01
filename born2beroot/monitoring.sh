#!/bin/bash

# Required actions
# Display architecture of your operation system and its kernel version
echo "#Architecture: $(uname -a)"

# Display number of physical processors
echo "#CPU Physical: $(grep "physical id" /proc/cpuinfo | sort -u | wc -l)"

# Display number of virtual processors
echo "#vCPU : $(nproc --all)"

# Display current available RAM on your server and its utilization rate as a percentage
echo "#Memory Usage: $(free | awk '/Mem:/ {printf("%d/%d MB (%.2f%%)", $3/1024, $2/1024, $3/$2 * 100)}')"

# Display current available storage on your server and its utilization rate as a percentage
echo "#Disk Usage: $(df -h / | awk '{printf("%d/%d GB (.2f%%)", $3/$2, $3/$2 * 100)}')"

# Display current utilization rate of your processors as a percentage
echo "#CPU load: $(top)"

# Display the date and time of the last reboot
echo "#Last boot: $(who -b | head -1)"

# Display whether LVM is active or not
echo "#LVM use: $(lvs -a)"														#need to refine to show only required info
echo "#LVM use: $(lvs -a | awk if [$1]; then echo "yes" else echo "no")"

# Display the number of active connections
echo "#Connections TCP : $(wc -l  /proc/net/tcp) ##### ESTABLISHED"

# Display the number of users using the server
echo "#User log: $(users | wc -w)"

# Display the IPv4 address of your server and its MAC address
echo "#Network: $(ipconfig getifaddr en0)"

# Display the number of commands executed with the sudo program
echo "#Sudo : $(journalctl _COMM=sudo | grep -c COMMAND)"

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