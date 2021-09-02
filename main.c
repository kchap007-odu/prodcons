#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

#include "records.h"
#include "producer.h"
#include "consumer.h"

char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main(int argc, char *argv[])
{
    clock_t begin = clock();
    srand(time(NULL));

    int p = atoi(argv[1]);
    int c = atoi(argv[2]);
    int b = atoi(argv[3]);

    buffer_t *sm = buffer_constructor(b);

    producer_t *ps[p];
    consumer_t *cs[c];

    double totalSales[12] = {0};

    pthread_t t[p + c];

    for (int i = 0; i < p; i++)
    {
        ps[i] = producer_constructor(sm, i + 1);
        int rc = pthread_create(&(t[i]), NULL, (void *)producer_produce, (void *)ps[i]);
    }

    for (int i = p; i < (p + c); i++)
    {
        cs[i - p] = consumer_constructor(sm, (i - p) + 1);
        int rc = pthread_create(&t[i], NULL, (void *)consumer_consume, (void *)cs[i - p]);
    }

    for (int i = 0; i < (p + c); i++)
        pthread_join(t[i], NULL);

    for (int i = 0; i < p; i++)
        producer_destructor(ps[i]);

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < 12; j++)
            totalSales[j] += cs[i]->sales[j];
        consumer_destructor(cs[i]);
    }

    printf("*****************************\n");
    printf("        Sales by Month       \n");
    printf("-----------------------------\n");
    double sum = 0;
    for (int i = 0; i < 12; i++)
    {
        printf("%10s: $%15.2f\n", months[i], totalSales[i]);
        sum += totalSales[i];
    }
    printf("-----------------------------\n");
    printf("%10s: $%15.2f\n", "Total", sum);
    printf("*****************************\n");
    printf("\n\n");

    printf("*****************************\n");
    printf("        Sales by Store       \n");
    printf("-----------------------------\n");
    sum = 0;
    for (int i = 0; i < p; i++)
    {
        printf("Store %4d: $%15.2f\n", i, ps[i]->totalSales);
        sum += ps[i]->totalSales;
    }

    printf("-----------------------------\n");
    printf("%10s: $%15.2f\n", "Total", sum);
    printf("*****************************\n");
    printf("\n\n");

    buffer_destructor(sm);

    clock_t end = clock();
    double elapsed = ((double)end - begin) / CLOCKS_PER_SEC;

    printf("Total simulation time: %0.2f seconds\n", elapsed);

    return 0;
}