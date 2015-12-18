open($fh, '>', 'big.txt');
print $fh "93894 99990\n";
for(my $i=1; $i<=21000; $i++) {
    print $fh "$i";
}
print $fh "\n";
for (my $i=1; $i<=99990; $i++) {
    my $j = $i + 10;
    print $fh "2 $i $j";
    print $fh "\n";
}
