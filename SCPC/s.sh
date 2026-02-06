for((i=1; i<=100; i++)); {
    echo $i
    ./gen $i > int
    ./cek < int > out1
    diff -w out1 tolak.txt || break
}