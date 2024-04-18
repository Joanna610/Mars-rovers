APP=sterowanie-lazikiem


__start__: obj dat  pliki_do_rysowania ./${APP}
	rm -f core.* core; ./${APP}

# Tworzy katalog "obj" gdy go nie ma
# 
obj:
	mkdir obj

dat:
	mkdir dat

pliki_do_rysowania:
	mkdir pliki_do_rysowania


./${APP}: obj/main.o obj/lacze_do_gnuplota.o obj/PowierzchniaMarsa.o obj/ObiektGeom.o obj/Wektor3D.o obj/SMacierz.o obj/Macierz3D.o obj/Lazik.o obj/Scena.o\
	  obj/ObrysXY.o obj/Wektor2D.o obj/ProbkaRegolitu.o obj/TypKolizji.o obj/LazikSFR.o
	g++ -o ./${APP} obj/main.o obj/lacze_do_gnuplota.o obj/PowierzchniaMarsa.o\
                        obj/ObiektGeom.o obj/Wektor3D.o obj/SMacierz.o obj/Macierz3D.o obj/Lazik.o obj/Scena.o obj/ObrysXY.o obj/Wektor2D.o obj/ProbkaRegolitu.o obj/TypKolizji.o obj/LazikSFR.o

obj/main.o: src/main.cpp inc/lacze_do_gnuplota.hh inc/ObiektGeom.hh inc/PowierzchniaMarsa.hh inc/Kolory.hh inc/Wektor3D.hh inc/rozmiar.h inc/SMacierz.hh inc/Macierz3D.hh\
	    inc/Lazik.hh inc/Scena.hh inc/ObrysXY.hh inc/Wektor2D.hh inc/ProbkaRegolitu.hh inc/TypKolizji.hh inc/LazikSFR.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/main.o src/main.cpp

obj/lacze_do_gnuplota.o: src/lacze_do_gnuplota.cpp inc/lacze_do_gnuplota.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/PowierzchniaMarsa.o: src/PowierzchniaMarsa.cpp inc/PowierzchniaMarsa.hh inc/lacze_do_gnuplota.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/PowierzchniaMarsa.o src/PowierzchniaMarsa.cpp

obj/ObiektGeom.o: src/ObiektGeom.cpp inc/ObiektGeom.hh inc/lacze_do_gnuplota.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/ObiektGeom.o src/ObiektGeom.cpp

obj/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/Wektor3D.o src/Wektor3D.cpp

obj/SMacierz.o: src/SMacierz.cpp inc/SMacierz.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/SMacierz.o src/SMacierz.cpp

obj/Macierz3D.o: src/Macierz3D.cpp inc/Macierz3D.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/Macierz3D.o src/Macierz3D.cpp

obj/Lazik.o: src/Lazik.cpp inc/Lazik.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/Lazik.o src/Lazik.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/Scena.o src/Scena.cpp

obj/Wektor2D.o: src/Wektor2D.cpp inc/Wektor2D.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/Wektor2D.o src/Wektor2D.cpp

obj/ObrysXY.o: src/ObrysXY.cpp inc/ObrysXY.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/ObrysXY.o src/ObrysXY.cpp

obj/ProbkaRegolitu.o: src/ProbkaRegolitu.cpp inc/ProbkaRegolitu.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/ProbkaRegolitu.o src/ProbkaRegolitu.cpp

obj/TypKolizji.o: src/TypKolizji.cpp inc/TypKolizji.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/TypKolizji.o src/TypKolizji.cpp

obj/LazikSFR.o: src/LazikSFR.cpp inc/LazikSFR.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/LazikSFR.o src/LazikSFR.cpp

clean:
	rm -f obj/* ./${APP} core.* core liki_do_rysowania/*



help:
	@echo
	@echo " make        - tworzenie i uruchomienie aplikacji"
	@echo " make clean  - usuniecie produktow kompilacji i konsolidacji"
	@echo " make help   - wyswietla niniejsza informacje"
	@echo
