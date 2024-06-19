#include <iostream>
#include <fstream>
using namespace std;
void uno(int contLote[6][3], string productos[], string colores[])
{
    int mayor = contLote[0][0];
    int posI, posJ, i, j;
    for (i = 0; i < 6; i++)
        for (j = 0; j < 3; j++)
            if (contLote[i][j] > mayor)
            {
                mayor = contLote[i][j];
                posI = i;
                posJ = j;
            }
    cout << "La mayor cantidad de unidades fue: " << productos[posI] << " " << colores[posJ] << " " << mayor << endl;
}
void dos(int contLote[6][3], string productos[], string colores[])
{
    int totales[6]{};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            totales[i] += contLote[i][j];
        }
    }

    int menor = totales[0];
    int pos = 0;
    for (int i = 0; i < 6; i++)
    {
        if (i < menor)
        {
            menor = totales[i];
            pos = i;
        }
    }

    cout << "Producto con la cantidad menor: " << productos[pos] << " cantidad:" << menor<< endl;
}
void tres(int contLote[6][3], int contProm[6][3], string productos[], string colores[])
{
    float promedios[6][3]{};
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 3; j++)
            promedios[i][j] = contLote[i][j] / contProm[i][j];

    float mayor = promedios[0][0];
    int posI, posJ, i, j;
    for (i = 0; i < 6; i++)
        for (j = 0; j < 3; j++)
            if (promedios[i][j] > mayor)
            {
                mayor = promedios[i][j];
                posI = i;
                posJ = j;
            }
    cout << "El mayor promedio fue: " << productos[posI] << " " << colores[posJ] << " " << mayor << endl;

}
void loteSemanal(string productos[], string colores[])
{
    const int dimPro = 6;
    const int dimCol = 3;
    int producto;
    int color;
    int cantidad;
    int contLote[dimPro][dimCol]{};
    int contProm[dimPro][dimCol]{};
    ifstream lotes;
    lotes.open("lote.txt");
    if (lotes)
        cout << "Archivo lotes, abiero correctamente" << endl;

    while (lotes)
    {
        lotes >> producto;
        lotes >> color;
        lotes >> cantidad;
        contLote[producto][color] += cantidad;
        contProm[producto][color]++;
    }

    uno(contLote, productos, colores);
    dos(contLote, productos, colores);
    tres(contLote, contProm, productos, colores);
}

int main()
{
    // VECTORES Y VARIABLES
    const int dimPro = 6;
    const int dimCol = 3;
    string productos[dimPro]{};
    string colores[dimCol]{};

    // APERTURA DE ARCHIVOS
    ifstream codigos;
    codigos.open("codigos.txt");
    if (codigos)
        cout << "Archivo codigos, abierto correctamente" << endl;

    // PARSE DE PROD,COL
    for (int i = 0; i < 6; i++)
        codigos >> productos[i];
    for (int i = 0; i < 3; i++)
        codigos >> colores[i];

    codigos.close();

    loteSemanal(productos, colores);
    return 0;
}