#ifndef MORE_MATH_H
#define MORE_MATH_H

#include"vectorLL.h"
/*
 * @param two natural numbers x and y
 * 
 * @returns the greatest common divisor of x and y
*/
long long GCD(long long x, long long y);

/*
 * @param two natural numbers x and y
 *
 * @returns the lowest common multiple of x and y
*/
long long LCM(long long x, long long y);

/*
 * @param two natural numbers x and y
 *
 * @returns the maximum of the two numbers
*/
long long max(long long x, long long y);

/*
 * @param two natural numbers x and y
 *
 * @returns the minimum of the two numbers
*/
long long min(long long x, long long y);

/*
 * @param a natural number x
 *
 * @returns the square root of x, rounded up to the nearest integer
*/
long long roofSqrt(long long x);

/*
 * @param a natural number x and a vectorLL of long long integers
 *
 * The vectorLL is initialized with all the factors of x
*/
void allFactors(long long x, vectorLL* arr);

/* 
 * @param vectorLL to be searched in and the number to be searched for
 * 
 * @returns the index of the number in the vectorLL, index of the closest number greater than it if it is not found
 */
int upperBound(vectorLL* arr, long long x);


#endif