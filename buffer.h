#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED

#include <pthread.h>

#include "records.h"

typedef struct buffer_t
{
    pthread_mutex_t lock;
    record_t **buffer;
    int *occupied;
    int bufferLength;
    int totalProduced;
    int totalConsumed;

} buffer_t;

buffer_t *buffer_constructor(int);
void buffer_destructor(buffer_t *);

int buffer_findInOccupied(const buffer_t, int);

record_t *buffer_generateRandomRecord(int sn);
int buffer_addRecord(buffer_t *);
int buffer_recordAvailable(buffer_t *);
record_t *buffer_getRecord(buffer_t *, int);
void buffer_addToBuffer(buffer_t *, record_t *, int);

#endif