#!/usr/bin/perl -w
use strict;

while (my $fname = shift) {
        next unless -f $fname;
        open F,"<$fname" or die "Cannot open $fname: $!\n";
        my $file = join('',<F>);
        close F;
        $file =~ s/\r\n?/\n/g;
        open F,">$fname" or die "Cannot write $fname: $!\n";
        print F $file;
        close F;
}