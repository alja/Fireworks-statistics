#! /bin/bash

ps -C receiveFireworksCrash -o pid=
if [ $? -gt 0 ]; then
   echo "receiveFireworksCrash not running" | mail "receiveFireworksCrash not running" amraktadel@ucsd.edu

    nohup ~/bin/receiveFireworksCrash &
fi


ps -C receiveFireworksVersion.pl -o pid=
if [ $? -gt 0 ]; then
   echo "receiveFireworksVersion not running" | mail "receiveFireworksVersion not running" amraktadel@ucsd.edu

   nohup ~/bin/receiveFireworksVersion.pl &
fi
