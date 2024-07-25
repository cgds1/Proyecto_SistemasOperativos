#pragma once
#include "fifo.h"
#include "lifo.h"
#include "RR.h"

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void correr_algoritmo(int num, microseconds &tiempo)
{
    high_resolution_clock::time_point inicio, final;    

    switch (num)
    {
    case 0:
        inicio = high_resolution_clock::now();
        fifo();
        final = high_resolution_clock::now();
        tiempo = duration_cast<microseconds>(final - inicio);
        break;
    case 1:
        inicio = high_resolution_clock::now();
        lifo();
        final = high_resolution_clock::now();
        tiempo = duration_cast<microseconds>(final - inicio);
        break;
    case 2:
        inicio = high_resolution_clock::now();
        RR();
        final = high_resolution_clock::now();
        tiempo = duration_cast<microseconds>(final - inicio);
        break;
    }
}