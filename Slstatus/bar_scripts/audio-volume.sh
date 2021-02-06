#!/bin/bash

VOL=$(amixer get Master | grep % | awk '{print $5}')
# echo $VOL | sed 's/\[//' | sed 's/\]//' | sed 's/\[60%\]//'
echo $VOL
