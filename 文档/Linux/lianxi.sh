#!/bin/bash
echo "lianxi.sh hello"

haizei=$(ls /home/)

for i in $haizei; do
	cd /home/$i
	ls > /tmp/$i.log
done
