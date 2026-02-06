for((i=0;i<1000;i++)) {
    echo $i
    py gen.py $i > inp
    ./D-Micchon < inp > ans
    ./D < inp > out
    diff -w ans out || break
}