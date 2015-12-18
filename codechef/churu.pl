open($fh, '>', 'big.txt');
print $fh "5000\n";
for(my $i=1; $i<=5000; $i++) {
    print $fh "$i ";
}
print $fh "\n";
for (my $i=1; $i<=4990; $i++) {
    my $j = $i + 10;
    print $fh "$i $j";
    print $fh "\n";
}
for (my $i=1; $i<=10; $i++) {
    my $j = $i * 10;
    print $fh "$i $j";
    print $fh "\n";
}
