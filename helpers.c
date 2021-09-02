#include "helpers.h"

/**
 * Generates a random integer between two numbers, inclusive.
 *
 * @param l the low end of the range
 * @param h the high end of the range
 *
 * @return a random number between l and h
 */
int randomBetween(int l, int h)
{
    double p = (double)rand() / (double)RAND_MAX;
    return (int)((double)((h + 1) - l) * p) + l;
}
