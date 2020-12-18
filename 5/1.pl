#!/usr/bin/perl
use warnings;
use strict;

# We are calculating the "binary space partitioning" of the boarding passes.
# Consider the entire 0..127 rows. If the first letter is a F (for "Front"),
# then consider rows 64..127, until you have gone through all 7 letters in the
# input, when you should have only one row left.
#
# $row and $col are pointing to the middle of the currently considered range of
# numbers. Since we have an even number of seats, they should be equal to ##.5,
# and only becoming a whole number when the seat is found. We can avoid the
# floating point arithmetic by doubling them, and then halving them when the
# answer is found. Not too relevant when using Perl, but oh well.

my $ans = 0;
while (<>) {
	my $row = 127;
	my $col = 7;
	my $rd = 64;
	my $cd = 4;
	chomp;
	for (split //) {
		if    (/F/) { $row -= $rd; $rd /= 2; }
		elsif (/B/) { $row += $rd; $rd /= 2; }
		elsif (/R/) { $col += $cd; $cd /= 2; }
		elsif (/L/) { $col -= $cd; $cd /= 2; }
	}
	my $id = $row/2 * 8 + $col/2;
	$ans = $id if $id > $ans; 
}
print "Answer: $ans\n";
