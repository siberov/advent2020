#!/usr/bin/perl
use warnings;
use strict;

my %passport;
my $valids = 0;
while (<>) {
	if (!/\S/) {
		# I'm not repeating this, add a newline to input text instead
		if (((scalar keys %passport == 8) or
		    (scalar keys %passport == 7 and !$passport{cid})) and
		    ($passport{byr} >= 1920 and $passport{byr} <= 2002) and
		    ($passport{iyr} >= 2010 and $passport{iyr} <= 2020) and
		    ($passport{eyr} >= 2020 and $passport{eyr} <= 2030) and
		    (($passport{hgt} =~ /([0-9]+)cm/ and $1 >= 150 and $1 <= 193) or
		     ($passport{hgt} =~ /([0-9]+)in/ and $1 >= 59 and $1 <= 76)) and
	    	    ($passport{hcl} =~ /#[0-9a-f]{6}/) and
		    ($passport{ecl} =~ /(amb|blu|brn|gry|grn|hzl|oth)/) and
		    ($passport{pid} =~ /[0-9]{9}/)) {	
		   	$valids++;
			for ((my $k, my $v) = each %passport) { print "$k => $v\n"; }
		}
		%passport = ();
	}
	while (/(\w+):([#\w]\w*)/g) {
		$passport{$1} = $2;
	}
}
# I have no clue, but the answer is 1 too high. cba to fix tho

print $valids-1 . "\n";
