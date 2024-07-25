// Acá van las variables y estructuras //
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <numeric>
#include <conio.h>

using namespace std;
struct variables {
    int ti;
    int t;
    int tf;
    int T;
    int E;
    float I;
    
}var;

vector<variables>arr;
int contador;
int clocker;
int quantum;
string alfabeto [39] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", 
"A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1", "I1", "J1", "K1", "L1", "M1"};

float arr_temp_efectividad[3];
int contador_temp = 0;

float tiempo_servicio;
float tiempo_espera;
float efectividad;

ifstream DATA1;
string line;

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

void cls() 
{
    cout << "\033c";
}

void presiona_continuar()
{
    cout << "Ingresa cualquier letra para continuar... ";
    getch();
}

void ask()
{
    cls();
    int ti, t, opc;

    cout << " - Bienvenido - " << endl;
    cout << "1. Ingresar datos manualmente " << endl;
    cout << "2. Ingresar datos automaticamente " << endl;
    cout << "-> ";
    cin >> opc;

    if (opc == 1)
    {
        cout << "Cuantas tareas queremos procesar?: ";
        cin >> contador; 

        for (int i = 0; i < contador; i++)
        {
            variables var;
        
            cout << "Ingresa el tiempo inicial de la tarea " << alfabeto[i] << ":";
            cin >> var.ti;

            cout << "Ingresa el tiempo de la tarea " << alfabeto[i] << ":";
            cin >> var.t;

            var.tf = 0;

            cout << endl;

            arr.push_back(var);
            cls();
        }
    }
    else
    {
        llenado_arrays();
    }

    cout << "Ingresa el quantum: ";
    cin >> quantum;
}

void calculos_basicos(vector<variables>&arr)
{
    float resultado;
    int sumatoriaT = 0;
    int sumatoriaE = 0;
    float sumatoriaI = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i].T = arr[i].tf - arr[i].ti;
        arr[i].E = arr[i].T - arr[i].t;
        arr[i].I = float(arr[i].t)/arr[i].T;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        sumatoriaT = sumatoriaT + arr[i].T;
        sumatoriaE = sumatoriaE + arr[i].E;
        sumatoriaI = sumatoriaI + arr[i].I;
    }

    tiempo_servicio = float(sumatoriaT)/arr.size();
    tiempo_espera = float(sumatoriaE)/arr.size();
    efectividad = float(sumatoriaI)/arr.size();
}

void vacio(vector<variables>&arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i].tf = 0;
        arr[i].T = 0;
        arr[i].E = 0;
        arr[i].I = 0;
    }

    tiempo_servicio = 0;
    tiempo_espera = 0;
    efectividad = 0;
    clocker = 0;
    contador = 0;
}

bool todavia_ceros()
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].tf == 0)
        {
            return true;
        }
    }
    return false;
}