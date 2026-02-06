for((i=6066;;i++)) {
    echo $i
    ./gen $i > inp.txt
    ./A_2 < inp.txt > out1.txt
    ./A_other < inp.txt > out2.txt
    diff -w out1.txt out2.txt || break
}