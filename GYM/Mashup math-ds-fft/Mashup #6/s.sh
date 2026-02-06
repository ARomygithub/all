for((i=0;i<1000;i++)) {
    echo $i
    py gen.py $i > tc
    ./E.exe < tc > rom
    ./E_umnik.exe < tc > ans
    diff -w rom ans || break
}