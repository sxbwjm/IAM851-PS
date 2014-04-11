//
//  RungeKutta1.c
//  KDV
//
//  Created by Can Xiong on 4/8/14.
//  Copyright (c) 2014 Can Xiong. All rights reserved.
//
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define E 2.718282f

double rk4(double(*f)(double, double), double h, double x, double y)
{
    printf("rk4===== x:%g, y:%g\n", x, y);
    
	double	k1 = f(x, y),
    k2 = f(x + h / 2, y + k1 / 2),
    k3 = f(x + h / 2, y + k2 / 2),
    k4 = f(x + h, y + k3);
    
    double newY = y + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    
    //printf("------ k1:%g, k2:%g, k3:%g, k4:%g, newY:%g\n", k1, k2, k3, k4, newY);

	return newY;
}

double function(double x, double y)
{
	return 3 * pow(E, -x) - 0.4 * y; //x * sqrt(y);
}

int main(void)
{
	double *y, x;
	double x0 = 0, x1 = 3, dx = 1.5;
	int i, n = 1 + (x1 - x0)/dx;
	y = malloc(sizeof(double) * n);
    
    
	for (y[0] = 5, i = 1; i < n; i++){
		y[i] = rk4(function, dx, x0 + dx * (i - 1), y[i-1]); //function, h, x0, y0
        printf("y[%d]:%g\n", i, y[i]);
    }
    
    
	return 0;
}