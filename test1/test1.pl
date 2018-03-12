#!/usr/bin/env perl
use v5.24;
use warnings;
use diagnostics;

use utf8;
use open IO => qw/:encoding(UTF-8) :std/;

use List::Util qw/max/;


# main
sub {
  my $input = shift;
  say get_max_pass_string_length($input);
}->(@ARGV);


sub get_max_pass_string_length {
  my $input = shift;
  my @res = $input =~ /([a-zA-Z]*[A-Z][a-zA-Z]*)/g; # [a-zA-Z] からなり, [A-Z] を 1 文字以上含む
  # say STDERR for @res;

  return (max map { length $_ } @res) // -1; # undef なら -1
}
