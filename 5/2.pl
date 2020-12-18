#!/usr/bin/perl
use warnings;
use strict;

# Same as #1, except we push all the ID:s onto an array, sort it and loop
# through it.

my @ids;
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
	push @ids, $id;
}
@ids = sort {$a <=> $b} @ids;

my $ans;
for (my $i = 0; $i < scalar @ids; $i++) {
	$ans = $ids[$i];
	last unless $ids[$i+1] == $ans + 1;
}
# We lasted on the seat before ours, so we have to add 1.
print "Answer: " . ($ans+1) . "\n";

