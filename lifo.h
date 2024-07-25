// LIFO //
#pragma once
#include "main.h"
#include <iostream>

using namespace std;

void lifo()
{
    do
    {
        for (int i = arr.size() - 1; i >= 0;)
        {
            if (clocker >= arr[i].ti)
            {
                if (arr[i].tf == 0)
                {
                    if (i == 0)
                        arr[i].tf = arr[i].t + arr[i].ti;
                    else
                        arr[i].tf = clocker + arr[i].t;

                    clocker = arr[i].tf;
                    i = arr.size() - 1;
                }
                else
                    i--;
            }
            else
                i--;
        }

        clocker++;

    } while (todavia_ceros());

    clocker--;
    cout << "  Clock Final: " << clocker << endl;
    clocker = 0;
}