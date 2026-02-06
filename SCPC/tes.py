while True:
    try:
        pilih_metode = input("Pilih metode yang anda kehendaki : ")
        epsilon = float(input("Masukkan nilai epsilon / toleransi error (ERROR jika terlalu besar) : "))
        Metode = NonLinearPengurungan(a,b,epsilon,persamaan)

        assert pilih_metode == '1' or '2'
        assert epsilon < 1

    except AssertionError:
        print("\n!! ERROR, METODE TIDAK TERSEDIA !!")
        time.sleep(3)
        print("\033[A"*5, chr(27)+"[0J")
        continue

    except AssertionError:
        print("\n!! ERROR, NILAI EPSILON TERLALU BESAR !!")
        time.sleep(3)
        print("\033[A"*5, chr(27)+"[0J")
        continue