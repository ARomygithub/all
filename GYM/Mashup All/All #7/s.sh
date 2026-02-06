for((i=0;i<1000;i++)) {
    echo $i
    py gen.py $i > in
    ./D-clean.exe < in > out || break
}