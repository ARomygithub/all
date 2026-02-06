for((i=0;i<1000;i++)) {
    echo $i
    ./gen $i > in2
    ./F < in2 > f2.out || break
}