for((i=0;i<1000;i++)) {
    echo $i
    ./gen $i > tcai2
    ./A < tcai2 > out2
    ./A-sol < tcai2 > ans2
    diff -w out2 ans2 || break 
}