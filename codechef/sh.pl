open($fh, '>', 'big.txt');
print $fh "1000 1000000000\n";
for(my $i=0; $i<1000; $i++) {
    print $fh "1000 ";
}
#open($fh, '>', 'big.txt');
#print $fh "5\n";
#$str = $str.'q';
#for(my $i=2; $i<200000; $i++) {
#    $str = $str.'a';
#}
#$str = $str.'q';
#for(my $i=0; $i<200000; $i++) {
#    $str2 = $str2.'a';
#}
#for (my $i=1;$i<=5;$i++) {
#    print "test case 1\n";
#    print $fh "200000 $str\n";
#    printf $fh "200000 $str2\n";
#}
