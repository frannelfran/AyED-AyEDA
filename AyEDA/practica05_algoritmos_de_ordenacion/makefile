main:
	@echo "Compilando ficheros..."
	g++ -std=c++20 -I src src/main.cc src/options/options.cc src/key/key.cc src/sequence/sequence.cc src/sortmethod/sortmethod.cc -o ordenacion

.PHONY: clean

# Eliminar archivos
clean:
	@echo "Eliminando ficheros compilados..."
	rm -f ordenacion