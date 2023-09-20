#include <stdio.h>
#include <string.h>


struct Partida {
    char jugador1[50];
    char jugador2[50];
    int puntos1;
    int puntos2;
    char lugar[50];
};


void agregarPartida(struct Partida partidas[], int *numPartidas, char partidaStr[]) {
    sscanf(partidaStr, "%[^/]/%d/%[^/]/%d/%[^/]/", partidas[*numPartidas].jugador1, &partidas[*numPartidas].puntos1, 
    partidas[*numPartidas].jugador2, &partidas[*numPartidas].puntos2, partidas[*numPartidas].lugar);
    (*numPartidas)++;
}

void DamePerdedores(struct Partida partidas[], int numPartidas, char jugadorGanador[], char perdedores[][50], int *numPerdedores) {
    *numPerdedores = 0;

    for (int i = 0; i < numPartidas; i++) {
        if (strcmp(partidas[i].jugador1, jugadorGanador) == 0) {
            strcpy(perdedores[*numPerdedores], partidas[i].jugador2);
            (*numPerdedores)++;
        } else if (strcmp(partidas[i].jugador2, jugadorGanador) == 0) {
            strcpy(perdedores[*numPerdedores], partidas[i].jugador1);
            (*numPerdedores)++;
        }
    }
}

char *jugadorConMasPuntos(struct Partida partidas[], int numPartidas) {
    char *jugadorMaxPuntos = NULL;
    int maxPuntos = -1;

    for (int i = 0; i < numPartidas; i++) {
        if (partidas[i].puntos1 > maxPuntos) {
            maxPuntos = partidas[i].puntos1;
            jugadorMaxPuntos = partidas[i].jugador1;
        }
        if (partidas[i].puntos2 > maxPuntos) {
            maxPuntos = partidas[i].puntos2;
            jugadorMaxPuntos = partidas[i].jugador2;
        }
    }

    return jugadorMaxPuntos;
}

int main() {
    struct Partida partidas[100]; 
    int numPartidas = 0;

    agregarPartida(partidas, &numPartidas, "Juan/23/Pedro/15/Lugo/");
    agregarPartida(partidas, &numPartidas, "Ana/30/Luis/20/Madrid/");
    agregarPartida(partidas, &numPartidas, "Pedro/18/Maria/25/Barcelona/");

    // Llamar a la función para obtener el jugador con más puntos
    char *jugadorMaxPuntos = jugadorConMasPuntos(partidas, numPartidas);

    if (jugadorMaxPuntos != NULL) {
        printf("El jugador con más puntos es: %s\n", jugadorMaxPuntos);
    } else {
        printf("No se encontraron partidas\n");
    }

    char jugadorGanador[] = "Juan";
    char perdedores[100][50];
    int numPerdedores = 0;

    DamePerdedores(partidas, numPartidas, jugadorGanador, perdedores, &numPerdedores);

    printf("Nombres de los perdedores de %s:\n", jugadorGanador);
    for (int i = 0; i < numPerdedores; i++) {
        printf("%s\n", perdedores[i]);
    }

    return 0;
}
