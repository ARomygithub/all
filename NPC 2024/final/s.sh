for((i=0;i<1000;i++)) {
    echo $i
    py gen.py $i > in
    ./brute.exe < in > out1
    ./F.exe < in > out2
    diff -w out1 out2 || break
}