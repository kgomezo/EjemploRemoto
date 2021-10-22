

all: fig.pdf
sumas.x: sumas.cpp
#restas.x: restas.cpp

%.x: %.cpp
	c++ $< -o $@ #me resume los dos target. Regla generica. Para varios archivos cpp

# sumas.x: sumas.cpp
	#c++ $< -o $@
#restas.x: restas.cpp
	#c++ $< -o $@

datos.txt: sumas.x
	./$< > $@
#./sumas.x > datos.txt

fig.pdf: plot.gp datos.txt
	gnuplot $<

clean:
	rm -f a.out *.x *.txt *.pdf
