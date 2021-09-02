#ifndef RECORDS_H_INCLUDED
#define RECORDS_H_INCLUDED

#include "helpers.h"

typedef struct record_t
{
    int year;
    int month;
    int day;
    int registerNumber;
    float saleAmount;
    int storeNumber;
} record_t;

record_t *generateRandomRecord(int);
void printRecord(record_t);

#endif