for((i=1;i<1000;i++)) {
    echo $i
    ./gen > in.in
    ./I < in.in > out1.out
    ./I-Berted < in.in > out2.out
    diff -w out1.out out2.out || break
}