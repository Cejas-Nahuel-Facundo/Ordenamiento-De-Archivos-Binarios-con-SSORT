#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dni;
    char nombre[20];
    float nota;
} tEstudiante;

int crearArch(const char *nomArch);
int LeerArchivo(const char *nomArch);
void ordenArch(const char*nom, int tam, int accion(void*, void*));
int accion(void *num1, void*num2);
