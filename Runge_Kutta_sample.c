//
//  Runge_Kutta.c
//  Project1
//
//  Created by Xiaobo Sun on 4/5/14.
//  Copyright (c) 2014 Xiaobo Sun. All rights reserved.
//

#include <stdio.h>

/*************************************************************
 *      Runge–Kutta 4th-Order Method
 * solve the following ordinary differential equations:
 *    u' = f(t, u)   where u(t0) = u0
 *
 * f:   function pointer of f in the above equation
 * t0:  initial value of t
 * u0:  initial value of u
 * tn:  final value of t
 * div: step numbers
 *
 * returns u(tn)
 *************************************************************/
double Runge_Kutta(double (*f)(double t, double u, int x), int x, double t0,
                   double u0, double tn, int div)
{
    double h = tn-t0;
    int i = 0;
    double t = t0;
    double u = u0;
    double k1, k2, k3, k4;

    
    // calculate step size
    if(div > 0)
    {
        h = h / div;
    }
    
    for(i = 0; i < div; i++)
    {
        // k1
        k1 = (*f)(t, u, x);
        k2 = (*f)(t + h / 2, u + k1 * h / 2, x);
        k3 = (*f)(t + h / 2, u + k2 * h / 2, x);
        k4 = (*f)(t + h, u + k3 * h, x);
        
        u += (k1 + 2 * k2 + 2 * k3 + k4) * h / 6;
        t += h;
    }
    
    return u;
}