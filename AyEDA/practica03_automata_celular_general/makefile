main:
	@echo "Compilando ficheros..."
	g++ -std=c++17 -I src src/main.cc src/cellace/cellace.cc src/cellace/cellace30.cc src/cellace/cellace110.cc src/cellLife/cellLife.cc src/cellLife/cellLife23_3.cc src/cellLife/cellLife51_346.cc src/options/options.cc src/lattice/lattice1D/lattice1D.cc src/position/position.cc src/lattice/lattice1D/lattice1D_open.cc src/lattice/lattice1D/lattice1D_periodic.cc src/lattice/lattice2D/lattice2D.cc src/lattice/lattice2D/lattice2D_reflective.cc -o automata_celular_general

.PHONY: clean

# Eliminar archivos
clean:
	@echo "Eliminando ficheros compilados..."
	rm -f automata_celular_general