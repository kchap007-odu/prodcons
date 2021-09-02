#ifndef CONSUMER_H_INCLUDED
#define CONSUMER_H_INCLUDED

#include <pthread.h>
#include <unistd.h>

#include "buffer.h"
#include "helpers.h"

typedef struct consumer_t
{
    int id;
    buffer_t *sharedMemory;
    double sales[12];
} consumer_t;

consumer_t *consumer_constructor(buffer_t *, int);
void consumer_destructor(consumer_t *);

void consumer_consume(void *);

#endif