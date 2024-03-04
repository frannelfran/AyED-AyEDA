main:
	@echo "Compilando ficheros..."
	g++ -std=c++17 -I src src/main.cc src/cellace/cellace.cc src/cellace/cellace30.cc src/cellace/cellace110.cc src/options/options.cc src/lattice/lattice1D/lattice1D.cc src/position/position.cc src/lattice/lattice1D/lattice1D_open.cc src/lattice/lattice1D/lattice1D_periodic.cc -o automata_celular_general

.PHONY: clean

# Eliminar archivos
clean:
	@echo "Eliminando ficheros compilados..."
	rm -f automata_celular_general