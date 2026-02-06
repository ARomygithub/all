for((i=1; ; i++)); {
    echo $i
    ./tc_gen $i > int2
    ./D < int2 > out11
    ./D_tatyam < int2 > out22
    diff -w out11 out22 || break
}