for((i=0;i<1000;i++)) {
    echo $i
    ./gen $i > tc.in
    ./F < tc.in > F.out || break
}