for((i=1; i<=1000; i++)); {
    echo $i
    ./gen $i > int2
    ./C < int2 > out11
    ./solC < int2 > out22
    diff -w out11 out22 || break
}