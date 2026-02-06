for((i=0000;i<1000;i++)) {
    echo $i
    py gen.py $i > tc_s
    ./brute < tc_s > ans
    ./corporation-short < tc_s > out
    diff -w ans out || break
}