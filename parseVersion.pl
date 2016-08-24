#!/usr/bin/perl

use strict;
use DateTime;

while (<>) {
    if ( $_ =~ /(\d{4}) (\d{2}) (\d{2}) (\d{2})\:(\d{2})\:(\d{2}) \d+\.\d+\.\d+\.\d+ (.*)/) {
        # printf ( "y = $1 m=$2 d=$3 $4:$5:$6 [$7] \n" );
        my $dt = DateTime->new( year   => $1, month  => $2, day => $3, hour   => $4, minute => $5, 
        second => $6  );
        my $ep  = $dt->epoch;
        # printf ("epoch = %d \n", $dt->epoch);

        my $platform = "Linux";
        if ( $7 =~ /Darwin/ ) {
            $platform = "Darwin";
        }

        my $packing = "CMSSW";
        if ( $7 =~ /Standalone/) {
            $packing = "Standalone";
        }
        printf("$ep $platform $packing \n");
    }

}
