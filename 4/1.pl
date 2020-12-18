#!/usr/bin/perl
use warnings;
use strict;

my %passport;
my $valids = 0;
while (<>) {
	if (!/\S/) {
		if (scalar keys %passport == 8 or
		   (scalar keys %passport == 7 and !$passport{cid})) {	
		   	$valids++;
		}
		%passport = ();
	}
	while (/(\w+):([#\w]\w*)/g) {
		$passport{$1} = $2;
	}
}
# One more time baby
if (scalar keys %passport == 8 or
   (scalar keys %passport == 7 and !$passport{cid})) {	
   	$valids++;
}
print "$valids\n";
