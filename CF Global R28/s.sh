for((i=0;i<1000;i++)) {
    echo $i
    py gen.py $i > tce2
    ./E.exe < tce2 || break 
}