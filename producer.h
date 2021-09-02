#ifndef PRODUCERS_H_INCLUDED
#define PRODUCERS_H_INCLUDED

#include <pthread.h>
#include <unistd.h>

#include "buffer.h"
#include "records.h"
#include "helpers.h"

typedef struct producer_t
{
    buffer_t *sharedMemory;
    double totalSales;
    int storeID;
} producer_t;

producer_t *producer_constructor(buffer_t *, int);
void producer_destructor(producer_t *);

void producer_produce(void *);

#endif