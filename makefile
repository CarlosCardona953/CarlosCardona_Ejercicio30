

LAX.gif: lax.dat grafica.py
	python grafica.py
    
lax.dat: CarlosCardona_Ejercicio30.x
	./CarlosCardona_Ejercicio30.x 

CarlosCardona_Ejercicio30.x: CarlosCardona_Ejercicio30.cpp
	g++ CarlosCardona_Ejercicio30.cpp -o CarlosCardona_Ejercicio30.x

clean:
	rm -rf *.x *.dat *.png