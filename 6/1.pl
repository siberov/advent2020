#!/usr/bin/perl
use warnings;
use strict;

my $n = 0;
my @groups;
$groups[0] = {};
while (<>) {
	if (/^(\r\n|\r|\n)$/) {
		$n++;
		$groups[$n] = {};
		next;
	}
	for (split //) {
		next unless /\w/; # IDK why this is necessary. I get unprintable
				  # chars otherwise, even with chomp.
		$groups[$n]{$_} = 1;
	}
}

my $ans = 0;
$ans += scalar(keys %{$_}) for @groups; # :^)
print "$ans\n";
