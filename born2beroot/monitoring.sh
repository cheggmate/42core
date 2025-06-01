#!/bin/bash

# Required actions
# Display architecture of your operation system and its kernel version
echo "#Architecture: $(uname -a)"

# Display number of physical processors
# Get number of physical cores (optional: per core count)
phys_cores=$(grep "core id" /proc/cpuinfo | sort -u | wc -l)
if $phys_cores==0 ; then 
	phys_cores=0
fi
echo "#CPU Physical: $phys_cores"

# Display number of virtual processors
vcpus=$(grep -c ^processor /proc/cpuinfo)
echo "#vCPU : $vcpus"

# Display current available RAM on your server and its utilization rate as a percentage
echo "#Memory Usage: $(free | awk '/Mem:/ {printf("%d/%dMB (%.2f%%)", $3/1024, $2/1024, $3/$2 * 100)}')"

# Display current available storage on your server and its utilization rate as a percentage
df -k / | awk 'NR==2 {used=$3; total=used+$4; printf("#Disk Usage: %d/%dGb (%f%%) \n", used/1024/1000, total/1024/1000, used/total*100)}'

# Display current utilization rate of your processors as a percentage
echo "#CPU load: $(top -bn1 | grep '%Cpu'| awk '{print $2 + $4}')%"

# Display the date and time of the last reboot
echo "#Last boot: $(who -b | awk 'NR==1 {print $3, $4}')"

# Display whether LVM is active or not
if lsblk | grep -q "lvm"; then
    echo "#LVM use: yes"
else
    echo "#LVM use: no"
fi

# Display the number of active connections
echo "#Connections TCP : $(ss -tan | grep ESTABLISHED | wc -l) ESTABLISHED"

# Display the number of users using the server
echo "#User log: $(users | wc -w)"

# Display the IPv4 address of your server and its MAC address
ipadd=$(ip -4 addr show | awk '/inet/ && $2 !~ /^127/ {print $2}' | cut -d/ -f1)
macadd=$(ip link show| awk '/ether/ {print $2}')
echo "#Network: $ipadd ($macadd)"

# Display the number of commands executed with the sudo program
echo "#Sudo : $(journalctl _COMM=sudo | grep -c COMMAND) cmd"

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