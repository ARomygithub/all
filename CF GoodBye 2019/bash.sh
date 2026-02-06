for((i=1000;;i++)){
    echo $i
    ./C $i || break
}