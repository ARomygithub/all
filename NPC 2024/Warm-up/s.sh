for((i=0;i<1000;i++)) {
    echo $i
    ./gen $i > in2
    ./D2 < in2 > f2.out
    py D-aldy.py < in2 > a2.out
    diff -w f2.out a2.out || break
}