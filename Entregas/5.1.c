#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 100
#define MAX_TITULO 100
#define MAX_AUTOR 100

typedef struct {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int precio;
    int likes;
} Libro;

int filtrarLibros(Libro libros[], int totalLibros, int N, char resultado[][MAX_TITULO + 10]) {
    int contador = 0;
    for (int i = 0; i < totalLibros; i++) {
        if (libros[i].likes > N) {
            sprintf(resultado[contador], "%s*%d", libros[i].titulo, libros[i].precio);
            contador++;
        }
    }
    return contador;
}

int main() {
    Libro libros[MAX_LIBROS] = {
        {"El Señor de los Anillos", "J.R.R. Tolkien", 20, 1000},
        {"Harry Potter", "J.K. Rowling", 15, 1500},
        {"Cien Años de Soledad", "Gabriel García Márquez", 25, 900},
        
    };
    
    int totalLibros = 3; // Ara mateix hi tenim 3 llibres
    int N;
    printf("Ingrese el número mínimo de 'likes': ");
    scanf("%d", &N);
    
    char librosFiltrados[MAX_LIBROS][MAX_TITULO + 10];
    int totalLibrosFiltrados = filtrarLibros(libros, totalLibros, N, librosFiltrados);
    
    printf("Libros con más de %d 'likes':\n", N);
    for (int i = 0; i < totalLibrosFiltrados; i++) {
        char* token = strtok(librosFiltrados[i], "*");
        printf("Título: %s, ", token);
        token = strtok(NULL, "*");
        printf("Precio: %s\n", token);
    }

    return 0;
}
