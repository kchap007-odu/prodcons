#include "buffer.h"

/**
 * Constructor for buffer.
 *
 * @param n the number of records to hold in the buffer
 *
 * @return a pointer to the newly created buffer
 */
buffer_t *buffer_constructor(int n)
{
    buffer_t *b = malloc(sizeof(buffer_t));
    pthread_mutex_init(&(b->lock), NULL);
    b->buffer = malloc(n * sizeof(record_t));
    b->occupied = calloc(n, sizeof(int));
    b->totalProduced = 0;
    b->totalConsumed = 0;
    b->bufferLength = n;

    return b;
}

/**
 * Frees the buffer.
 *
 * @param b the buffer to free
 */
void buffer_destructor(buffer_t *b)
{
    pthread_mutex_destroy(&(b->lock));
    free(b->buffer);
    free(b->occupied);
    free(b);
}

/**
 * Finds the first occurrence of a value in the occupied array.
 *
 * @param b the buffer
 * @param v the value to look for, 0 or 1
 *
 * @return the first occurrence of v in buffer's occupied array, or -1 if not
 */
int buffer_findInOccupied(const buffer_t b, int v)
{
    int p = -1;
    for (int i = 0; i < b.bufferLength; i++)
    {
        if (b.occupied[i] == v)
        {
            p = i;
            break;
        }
    }
    return p;
}

/**
 * Retrieves a record at a specified position from the buffer.
 *
 * @param b the buffer
 * @param n the position of the target record in the buffer
 *
 * @return a record from the buffer
 */
record_t *buffer_getRecord(buffer_t *b, int n)
{
    b->occupied[n] = 0;
    b->totalConsumed++;

    return b->buffer[n];
}

/**
 * Adds a record to the buffer.
 *
 * @param b the buffer
 * @param r the record to add
 * @param p the position to insert the record
 */
void buffer_addToBuffer(buffer_t *b, record_t *r, int p)
{
    b->buffer[p] = r;
    b->totalProduced++;
    b->occupied[p] = 1;
}