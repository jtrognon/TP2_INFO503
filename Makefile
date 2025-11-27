.PHONY: all clean # .PHONY -> précise que certaines cibles ne correspondent pas à des fichiers (cible mais pas fichier)

# Cible principale
all: bin/TP2_INFO503_JULIEN-DODSWORTH_TROGNON

# Règle pour construire l'exécutable
bin/TP2_INFO503_JULIEN-DODSWORTH_TROGNON: main.o libTriDenombrement.a libTriRapide.a libTriRapideHybride.a
	gcc $< -g -O0 -Wall -Wextra -I./include -L./lib -lTriDenombrement -lTriRapide -lTriRapideHybride -o $@ 
# -I pour le chemin des '#include'

# Ecrit ici car pas de .h donc marche par avec regle generique 
main.o: src/main.c libTriDenombrement.a libTriRapide.a libTriRapideHybride.a
	gcc -c $< -g -O0  -Wall -Wextra -I./include -L./lib -lTriDenombrement -lTriRapide -lTriRapideHybride -o $@

# creation de la lib math
lib%.a: %.o
	ar -crs lib/$@ $<

%.o: src/%.c include/%.h
	gcc -c $< -I./include -o $@

# Cible pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f *.o ./lib/* ./bin/*