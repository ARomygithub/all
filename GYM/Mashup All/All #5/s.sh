for((i=0;i<1000;i++)) {
    echo $i
    py gen.py $i > d/tcx
    ./D.exe < d/tcx > d/out
    py brute.py < d/tcx > d/ans
    diff -w d/out d/ans || break
}