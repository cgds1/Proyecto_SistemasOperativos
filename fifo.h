// FIFO //
#pragma once
#include "main.h"
#include <iostream>

using namespace std;

void fifo()
{
    do
    {
        for (int i = 0; i < arr.size();)
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
                    i = 0;
                }
                else
                    i++;
            }
            else
                i++;
        }

        clocker++;

    } while (todavia_ceros());

    clocker--;
    cout << "  Clock Final: " << clocker << endl;
    clocker = 0;
}