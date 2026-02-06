for((i=0;;i++)) {
    echo $i
    ./tc_gen $i > inp
    ./F < inp > out1
    ./F_kevinsogo < inp > out2
    diff -w out1 out2 || break
}