#include <stdio.h>
#include <stdlib.h>
#include "Funcionalidades.h"
#define   ARCHIVOBIN "LotePrueba.bin"
int main()
{
    crearArch(ARCHIVOBIN);
    printf("LISTA DESORDENADA\n\n");
    LeerArchivo(ARCHIVOBIN);
    ordenArch(ARCHIVOBIN, sizeof(tEstudiante), accion);
    printf("LISTA ORDENADA\n\n");
    LeerArchivo(ARCHIVOBIN);

    return 0;
}
