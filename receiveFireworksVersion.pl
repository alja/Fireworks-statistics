#!/usr/bin/perl -w

$|++;
use IO::Socket;
use strict;
use vars qw($sec $min $hour $mday $mon $year $wday $yday $isdst);
my ($datagram,$flags);

my $port = 9698;
my $response = IO::Socket::INET->new(Proto=>"udp",LocalPort=>$port) or die "Can't make UDP server: $@";

open (MYFILE, '>> /home/alja/fireworks/VersionInfo.txt');
MYFILE->autoflush;

while (1)
{
   $response->recv($datagram,256,$flags);  
   ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime(time);

   # print "Got message from ", $response->peerhost,", flags ",$flags || "none",": $datagram\n";
   printf MYFILE "%.4d %.2d %.2d %.2d:%.2d:%.2d %s %s", 
                  $year + 1900, $mon + 1, $mday, $hour, $sec, $min, 
                  $response->peerhost, $datagram;
}

close (MYFILE); 
