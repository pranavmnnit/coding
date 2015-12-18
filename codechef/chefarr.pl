open($fh, '>', 'a1');
print $fh "500000\n";
for(my $i=0; $i<500000; $i++) {
    print $fh "1000000000\n";
}
