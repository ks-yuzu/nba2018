use strict;
use Test2::V0;
use Test2::Plugin::UTF8;

use FindBin;
use lib "$FindBin::Bin/lib/perl5";

use JSON;
use Path::Tiny;

use constant EXEC => 'perl test1.pl';

my $testfile = 't/patterns.json';

# main
sub {
  chdir "$FindBin::Bin/..";

  my $patterns = decode_json( path($testfile)->slurp );

  for my $pattern ( @$patterns ) {
    # subtest $pattern->{title} => sub {
      my $command = EXEC . ' ' . $pattern->{input} . ' 2> /dev/null';

      # say STDERR $command;
      my $output = qx|$command|;
      chomp $output;
      is $output, $pattern->{exp}, $pattern->{comment};
    # };
  }
}->();


done_testing;
