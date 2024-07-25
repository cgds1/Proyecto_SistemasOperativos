// Algoritmo para llenar los arrays. // 
#pragma once
#include "main.h"
#include <fstream>
#include <sstream>
#include <string>

ifstream DATA1;
string line;
using namespace std;

void llenado_arrays()
{
    DATA1.open("datos.txt", ios::in);
    getline(DATA1, line); // Ignora la instrucción puesta en el archivo.

    while ((getline(DATA1, line)) && (!line.empty()))
    {
        stringstream stream_check(line);

        string temp;

        getline(stream_check, temp, ',');
        var.ti = stoi(temp);

        getline(stream_check, temp, ',');
        var.t = stoi(temp);

        if (!stream_check) 
        {
            cout << "ERROR: El archivo ha fallado al ser leído. " << endl;
            break;
        }

        arr.push_back(var);
        contador++; 
    }
}