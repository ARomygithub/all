for((i=3;;i+=2)) {
    echo "i: $i"
    cat > "tc.in" <<EOF
$i
EOF
    ./D2_old.exe < tc.in || exit
}