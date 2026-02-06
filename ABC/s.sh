for((i=1; i<=1000; i++)); {
    echo $i
    ./gen364 $i > int2
    ./E_364 < int2 > out11
    ./E_364_2 < int2 > out22
    diff -w out11 out22 || break
}