//
//  main.c
//  Homework_tech
//
//  Created by Владислав Агафонов on 26.09.16.
//  Copyright © 2016 Владислав Агафонов. All rights reserved.
//

#include <stdio.h>
#include <math.h>

const int INFROOTS = -1;
const double EPS = 1E-6;

int SqEquation (double a, double b, double c, double* x1, double* x2);
int LinearEquation (double b, double c, double* x1);
int Sign (double a);

int main() {
    printf("#SqEquation v1.0 © VA, 2016\n");

    printf("#Enter a b c:\n");
    double a = 0, b = 0, c = 0;
    scanf("%lg %lg %lg", &a, &b, &c);
    
    double x1 = 0, x2 = 0;
    int nRoots = SqEquation(a, b, c, &x1, &x2);
    
    switch (nRoots) {
        case 2:
            printf("x1 = %lg\n", x1);
            printf("x2 = %lg\n", x2);
            break;
    
        case 1:
            printf("x1 = %lg\n", x1);
            break;
        
        case 0:
            printf("NOROOTS\n");
            break;
        
        case INFROOTS:
            printf("INFROOTS\n");
            break;
        
        default:
            printf("%d", nRoots);
            return 1;
            break;
    }
    
    return 0;
}

int SqEquation(double a, double b, double c, double* x1, double* x2) {
    
    if (Sign(a) == 0)
        return LinearEquation(b, c, x1);
    
       double d = b*b - 4 * a * c;
        switch (Sign(d)) {
            case 0:
                *x1 = (-b) / (2 * a);
                return 1;
                break;
                
            case 1:
                d = sqrt (d);
                *x1=( (-b + d) / (2*a) );
                *x2=( (-b - d) / (2*a) );
                return 2;
                break;
                
            default:
                return 0;
                break;
        }
    
}


int LinearEquation (double b, double c, double* x1) {
    if (Sign(b)==0)
        {
        if (Sign(c)==0)
            return INFROOTS;
        else
            return 0;
        }
    else
        {
        if (Sign(c)==0)
            {
            *x1=0;
            return 1;
            }
        else
            {
            *x1=(-c)/b;
            return 1;
            }
        }
}

int Sign(double a)
    {
    if (fabs(a)<EPS)
        return 0;
    else
        if (a>0)
            return 1;
        else
            return -1;
}
