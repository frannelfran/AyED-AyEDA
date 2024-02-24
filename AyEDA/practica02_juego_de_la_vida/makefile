main:
	@echo "Compilando ficheros..."
	g++ -std=c++17 -I./include src/options.cc src/lattice.cc src/cell.cc src/main.cc -o juego_de_la_vida

.PHONY: clean

# Eliminar archivos
clean:
	@echo "Eliminando ficheros compilados..."
	rm -f juego_de_la_vida