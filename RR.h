// RR //
#pragma once
#include "main.h"
#include <iostream>

using namespace std;

void RR()
{
    int temp_t[arr.size()];

    for (int i = 0; i < arr.size(); i++)
        temp_t[i] = arr[i].t;

    do
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (clocker >= arr[i].ti)
            {
                if (arr[i].tf == 0)
                {
                    if (temp_t[i] <= quantum)
                    {
                        arr[i].tf = clocker + temp_t[i];
                        clocker = arr[i].tf;
                    }
                    else
                    {
                        temp_t[i] -= quantum;
                        clocker += quantum;
                    }
                    contador = i;
                    
                }
            }
        }

        if (arr[contador].t == temp_t[contador])
            clocker++;

    } while (todavia_ceros());

    cout << "  Clock Final: " << clocker << endl;
    clocker = 0;
    contador = 0;
}