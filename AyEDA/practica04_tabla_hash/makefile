main:
	@echo "Compilando ficheros..."
	g++ -std=c++20 -I src src/main.cc src/options/options.cc src/key/key.cc src/dispersion_function/dispersion_function.cc src/exploration_function/exploration_function.cc src/sequence/sequence.cc src/hash_table/hash_table.cc -o tabla_hash

.PHONY: clean

# Eliminar archivos
clean:
	@echo "Eliminando ficheros compilados..."
	rm -f tabla_hash