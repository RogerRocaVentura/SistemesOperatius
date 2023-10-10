#include <stdio.h>
#include <string.h>

#define MAX_VUELOS 77

typedef struct {
    int identificador;
    char compania[100];
    char dias[8]; // 7 días + 1 carácter NULL al final.
    char aeropuerto_salida[100];
    char aeropuerto_llegada[100];
} ProgramaVuelo;

ProgramaVuelo vuelos[MAX_VUELOS];

int vuelosEnDias(const char* dias) {
    int count = 0;
    for (int i = 0; i < MAX_VUELOS; i++) {
        int todosEncontrados = 1;
        for (int j = 0; j < strlen(dias); j++) {
            if (strchr(vuelos[i].dias, dias[j]) == NULL) {
                todosEncontrados = 0;
                break;
            }
        }
        if (todosEncontrados) count++;
    }
    return count;
}

int modificarDiasVuelo(int id, const char* nuevosDias) {
    for (int i = 0; i < MAX_VUELOS; i++) {
        if (vuelos[i].identificador == id) {
            strcpy(vuelos[i].dias, nuevosDias);
            return 0;
        }
    }
    return -1;
}

int main() {
    // Por simplicidad, inicializaremos solo un programa de vuelo en el ejemplo.
    vuelos[0].identificador = 1;
    strcpy(vuelos[0].compania, "AeroComp");
    strcpy(vuelos[0].dias, "LXXJVSX");
    strcpy(vuelos[0].aeropuerto_salida, "AeroInicio");
    strcpy(vuelos[0].aeropuerto_llegada, "AeroFinal");

    printf("Número de vuelos que operan los Lunes y Viernes: %d\n", vuelosEnDias("LV"));

    int id;
    char nuevosDias[8];

    printf("Introduce el identificador del programa de vuelo: ");
    scanf("%d", &id);

    printf("Introduce los nuevos días (L a D) que opera el vuelo: ");
    scanf("%s", nuevosDias);

    int resultado = modificarDiasVuelo(id, nuevosDias);
    if (resultado == 0) {
        printf("Días de vuelo modificados con éxito.\n");
    } else {
        printf("Error: Programa de vuelo no encontrado.\n");
    }

    return 0;
}
