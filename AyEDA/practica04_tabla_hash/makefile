main:
	@echo "Compilando ficheros..."
	g++ -std=c++20 -I src src/main.cc src/options/options.cc src/nif/nif.cc src/dispersion_function/dispersion_function.cc -o tabla_hash

.PHONY: clean

# Eliminar archivos
clean:
	@echo "Eliminando ficheros compilados..."
	rm -f tabla_hash