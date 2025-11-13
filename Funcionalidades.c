#include "Funcionalidades.h"

int crearArch(const char *nomArch)
{
    FILE *fp = fopen(nomArch, "wb");
    if(!fp)
    {
        return -1;
    }

tEstudiante listaEstudiantes[] =
{
    {50300, "Nahuel",   8},
    {12040, "Mariela",  6},
    {88010, "Facundo",  2},
    {33020, "Luis",     10},
    {15000, "Jorge",    4},
    {94003, "Sofia",    9},
    {23001, "Pedro",    1},
    {72011, "Lucia",    7},
    {40122, "Shuli",    3},
    {10005, "Juan",     5}
};

    fwrite(listaEstudiantes, sizeof(tEstudiante), sizeof(listaEstudiantes)/sizeof(tEstudiante), fp);
    fclose(fp);
    return 1;

}
int LeerArchivo(const char *nomArch)
{
    FILE *fp = fopen(nomArch, "rb");
    if(!fp)
    {
        return -1;
    }

    tEstudiante listaEstudiantes;
    fread(&listaEstudiantes, sizeof(tEstudiante), 1, fp);
    while(!feof(fp))
    {
        printf("DNI: %d | NOMBRE: %s | NOTA:%.1f \n\n", listaEstudiantes.dni,listaEstudiantes.nombre,listaEstudiantes.nota);
        fread(&listaEstudiantes, sizeof(tEstudiante), 1, fp);
    }

    return 1;
}
void ordenArch(const char*nom, int tam, int accion(void*, void*))
{
    FILE *f = fopen(nom,"r+b");
    if(!f)
        return;

    void *menor = malloc(tam);
    void *vec = malloc(tam);
    void *aux = malloc(tam);

    if(!vec || !menor || !aux)
    {
        fclose(f);
        return;
    }
    fseek(f, 0, SEEK_END);
    int ce = ftell(f) / tam;
    int i,j;
    int posM;
    rewind(f);

    for(i=0;i<ce-1;i++)
    {
        fseek(f,i*tam, SEEK_SET);
        fread(menor, tam, 1, f);
        posM = i;
        for(j=i+1;j<ce;j++)
        {
            fseek(f, j*tam, SEEK_SET);
            fread(vec, tam, 1, f);
            if(accion(vec, menor)<0)
            {
                memcpy(menor, vec, tam);
                posM=j;
            }
        }
        if(posM!=i)
        {
            fseek(f, i*tam, SEEK_SET);
            fread(aux, tam, 1, f);

            fseek(f, i*tam, SEEK_SET);
            fwrite(menor, tam, 1, f);

            fseek(f, posM*tam, SEEK_SET);
            fwrite(aux, tam, 1, f);

        }
    }

    free(vec);
    free(menor);
    free(aux);
    fclose(f);
}
int accion(void *num1, void*num2)
{
    tEstudiante x = *(tEstudiante*)num1;
    tEstudiante y = *(tEstudiante*)num2;
    int diferencia = x.dni - y.dni;
    return diferencia;

}
