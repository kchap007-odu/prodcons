#include "producer.h"

/**
 * Constructor for producer.
 *
 * @param b the shared memory buffer
 * @param sn the unique store number associated with the producer
 *
 * @return a pointer to the newly created producer structure
 */
producer_t *producer_constructor(buffer_t *b, int sn)
{
    producer_t *p = malloc(sizeof(producer_t));
    p->sharedMemory = b;
    p->storeID = sn;
    p->totalSales = 0.0;

    return p;
}

/**
 * Frees memory associated with a producer structure.
 *
 * @param p the producer to destroy
 */
void producer_destructor(producer_t *p)
{
    free(p);
}

/**
 * Begins the production process until the stop criteria is met.
 *
 * @param a the producer, cast to void pointer for compatibility with pthread
 */
void producer_produce(void *a)
{
    producer_t *p = (producer_t *)a;
    int keepGoing = 1;
    int openPosition = -1;

    while (keepGoing)
    {
        pthread_mutex_lock(&(p->sharedMemory->lock));
        if (p->sharedMemory->totalProduced < MAX_PRODUCED)
        {
            openPosition = buffer_findInOccupied(*(p->sharedMemory), 0);
            if (openPosition != -1)
            {
                record_t *r = generateRandomRecord(p->storeID);
                buffer_addToBuffer(p->sharedMemory, r, openPosition);
                p->totalSales += r->saleAmount;
            }
        }
        else
            keepGoing = 0;
        pthread_mutex_unlock(&(p->sharedMemory->lock));

        sleep((double)randomBetween(5, 40) / 100);
    }
}