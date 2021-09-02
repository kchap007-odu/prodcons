#include "consumer.h"

/**
 * A constructor for the consumer structure.
 *
 * @param b the shared memory buffer
 * @param id a unique identifier for the consumer
 *
 * @return a pointer to the newly created consumer
 */
consumer_t *consumer_constructor(buffer_t *b, int id)
{
    consumer_t *c = malloc(sizeof(consumer_t));
    c->sharedMemory = b;
    c->id = id;
    for (int i = 0; i < 12; i++)
        c->sales[i] = 0;

    return c;
}

/**
 * Frees memory associated with consumer structure.
 *
 * @param c the consumer to destroy
 */
void consumer_destructor(consumer_t *c)
{
    free(c);
}

/**
 * Begin the consumer process.
 *
 * @param a the consumer, cast to a void pointer for compatibility with pthread
 */
void consumer_consume(void *a)
{
    consumer_t *c = (consumer_t *)a;
    int keepGoing = 1;
    int consumePosition = -1;

    while (keepGoing)
    {
        pthread_mutex_lock(&(c->sharedMemory->lock));
        if (c->sharedMemory->totalConsumed < MAX_PRODUCED)
        {
            consumePosition = buffer_findInOccupied(*(c->sharedMemory), 1);
            if (consumePosition != -1)
            {
                record_t *r = buffer_getRecord(c->sharedMemory, consumePosition);
                c->sales[r->month - 1] += r->saleAmount;
                free(r);
            }
        }
        else
            keepGoing = 0;
        pthread_mutex_unlock(&(c->sharedMemory->lock));

        sleep((double)randomBetween(5, 40) / 100);
    }
}