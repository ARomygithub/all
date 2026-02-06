for((i = 416; i<1000; i++)) {
    echo $i;
    py gen.py $i > tcm
    ./m22 < tcm > out || break
}
