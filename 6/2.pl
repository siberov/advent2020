#!/usr/bin/perl
use warnings;
use strict;

my $n = 0;
my @groups;
$groups[0] = {people => 0};
while (<>) {
	if (/^(\r\n|\r|\n)$/) {
		$n++;
		$groups[$n] = {people => 0};
		next;
	}
	for (split //) {
		next unless /\w/; # IDK why this is necessary. I get unprintable
				  # chars otherwise, even with chomp.
		$groups[$n]{$_}++;
	}
	$groups[$n]{people}++;
}

my $ans = 0;
for my $g (@groups) {
	while (my ($k, $v) = each %{$g}) {
		# It is probably quicker to subtract %{$g}{people} from $ans
		# after every iteration, but this is clearer imo.
		next if $k eq "people";
		$ans++ if ($v == %{$g}{people});
	}
}
print "Answer: $ans\n";
