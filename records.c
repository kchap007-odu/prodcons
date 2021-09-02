#include "records.h"

/**
 * Generates a random record from a store.
 *
 * @param sn the store number
 *
 * @return pointer to the record structure.
 */
record_t *generateRandomRecord(int sn)
{
    record_t *t = malloc(sizeof(record_t));
    t->storeNumber = sn;
    t->month = randomBetween(1, 12);
    int nd = t->month == 2 ? 27 : 30 + (t->month % 2);
    t->day = randomBetween(1, nd);
    t->year = YEAR;
    t->registerNumber = randomBetween(1, NUM_REGISTERS);
    t->saleAmount = (double)randomBetween(SALE_MIN, SALE_MAX) / 100;

    return t;
}

/**
 * Prints the contents of a sale record.
 *
 * @param r the sale record
 */
void printRecord(record_t r)
{
    printf("%02d/%02d/%04d %2d %2d $%6.2f\n", r.day, r.month, r.year, r.storeNumber, r.registerNumber, r.saleAmount);
}