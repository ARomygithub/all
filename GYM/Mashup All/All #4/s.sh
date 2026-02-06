for((i=0;i<1000;i++)) {
    echo $i
    py gen.py $i > in
    ./C < in > out || break
}