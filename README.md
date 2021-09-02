# Getting Started

**Language:** C

# Requirements

- gcc 9.3.0 or later
- make
- pthread

# Program Description

Producer and consumer structures are created to keep track of production and
consumption-related statistics.

This program uses a mutex to control access to critical sections. The producer
and consumer share similar critical section code, called producer_produce and
consumer_consume. An example of critical section code can be seen below:

```
    while (keepGoing)
    {
        pthread_mutex_lock(&(c->sharedMemory->lock));
        /* Critical section production/consumption logic */
        pthread_mutex_unlock(&(c->sharedMemory->lock));
    }
```

# Compilation

Compilation can be done using the provided makefile and running
standard `make` command on the provided `makefile` or inspecting the
`makefile` for which compiler flags were used. The pthread library is included
and needs to be accounted for in the compilation flags.

# Execution Instructions

The included executable was compiled on Ubuntu 20.04.2 LTS using
gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0. It accepts three command-line
arguments: the number of producers, the number of consumers, and the
size of the buffer to use.

To run, call using

```
./prodcons 2 2 30
./prodcons 5 2 30
./prodcons 10 2 30


./prodcons 2 5 30
./prodcons 5 5 30
./prodcons 10 5 30


./prodcons 2 10 30
./prodcons 5 10 30
./prodcons 10 10 30

```

# Results

Below are the output from the runs shown in the Execution Instructions section.

```
./prodcons 2 2 30
*****************************
        Sales by Month
-----------------------------
   January: $      410519.19
  February: $      425908.89
     March: $      416245.00
     April: $      416988.66
       May: $      445912.74
      June: $      409978.28
      July: $      408697.65
    August: $      456244.64
 September: $      416112.75
   October: $      398129.49
  November: $      416130.66
  December: $      395497.87
-----------------------------
     Total: $     5016365.82
*****************************


*****************************
        Sales by Store
-----------------------------
Store    0: $     2523941.05
Store    1: $     2492424.77
-----------------------------
     Total: $     5016365.82
*****************************


Total simulation time: 0.04 seconds
```

```
./prodcons 5 2 30
*****************************
        Sales by Month
-----------------------------
   January: $      439632.77
  February: $      402385.52
     March: $      413801.80
     April: $      419509.94
       May: $      389962.30
      June: $      377099.71
      July: $      437400.12
    August: $      409879.72
 September: $      412619.32
   October: $      446244.48
  November: $      413271.93
  December: $      436080.56
-----------------------------
     Total: $     4997888.17
*****************************


*****************************
        Sales by Store
-----------------------------
Store    0: $     1022911.54
Store    1: $     1183023.15
Store    2: $      859570.06
Store    3: $     1143234.31
Store    4: $      789149.11
-----------------------------
     Total: $     4997888.17
*****************************


Total simulation time: 0.09 seconds
```

```
./prodcons 10 2 30
*****************************
        Sales by Month
-----------------------------
   January: $      425815.35
  February: $      411256.28
     March: $      396055.68
     April: $      412947.85
       May: $      416930.04
      June: $      412931.45
      July: $      438295.81
    August: $      413375.94
 September: $      417724.58
   October: $      407468.28
  November: $      426996.93
  December: $      405430.37
-----------------------------
     Total: $     4985228.56
*****************************


*****************************
        Sales by Store
-----------------------------
Store    0: $      691908.75
Store    1: $      540912.61
Store    2: $      495800.21
Store    3: $      491518.74
Store    4: $      381762.49
Store    5: $      374330.45
Store    6: $      454655.90
Store    7: $      481809.42
Store    8: $      599325.43
Store    9: $      473204.56
-----------------------------
     Total: $     4985228.56
*****************************


Total simulation time: 0.14 seconds
```

```
./prodcons 2 5 30
*****************************
        Sales by Month
-----------------------------
   January: $      425799.19
  February: $      413261.55
     March: $      433013.38
     April: $      410315.09
       May: $      421810.59
      June: $      406384.79
      July: $      411987.76
    August: $      394693.39
 September: $      431468.17
   October: $      423003.05
  November: $      435360.11
  December: $      402701.05
-----------------------------
     Total: $     5009798.12
*****************************


*****************************
        Sales by Store
-----------------------------
Store    0: $     2522362.46
Store    1: $     2487435.66
-----------------------------
     Total: $     5009798.12
*****************************


Total simulation time: 0.09 seconds
```

```
./prodcons 5 5 30
*****************************
        Sales by Month
-----------------------------
   January: $      427476.48
  February: $      410340.88
     March: $      421271.94
     April: $      445807.39
       May: $      388393.08
      June: $      415855.79
      July: $      411130.59
    August: $      434198.82
 September: $      421233.69
   October: $      405774.63
  November: $      406290.68
  December: $      421486.88
-----------------------------
     Total: $     5009260.85
*****************************


*****************************
        Sales by Store
-----------------------------
Store    0: $      988091.92
Store    1: $     1021289.19
Store    2: $     1006747.83
Store    3: $      991888.18
Store    4: $     1001243.73
-----------------------------
     Total: $     5009260.85
*****************************


Total simulation time: 0.05 seconds
```

```
./prodcons 10 5 30
*****************************
        Sales by Month
-----------------------------
   January: $      410515.05
  February: $      431101.29
     March: $      386653.49
     April: $      407997.20
       May: $      469867.23
      June: $      414417.94
      July: $      407392.62
    August: $      445774.18
 September: $      408551.09
   October: $      396560.02
  November: $      415366.01
  December: $      422011.82
-----------------------------
     Total: $     5016207.94
*****************************


*****************************
        Sales by Store
-----------------------------
Store    0: $      537795.78
Store    1: $      570723.81
Store    2: $      402283.36
Store    3: $      343096.08
Store    4: $      543113.58
Store    5: $      527206.93
Store    6: $      503956.46
Store    7: $      491030.34
Store    8: $      519506.46
Store    9: $      577495.14
-----------------------------
     Total: $     5016207.94
*****************************


Total simulation time: 0.09 seconds
```

```
./prodcons 2 10 30
*****************************
        Sales by Month
-----------------------------
   January: $      419761.63
  February: $      420335.03
     March: $      422780.79
     April: $      407228.66
       May: $      449547.22
      June: $      401592.52
      July: $      439821.27
    August: $      425985.05
 September: $      399304.40
   October: $      414090.67
  November: $      423574.47
  December: $      384727.37
-----------------------------
     Total: $     5008749.08
*****************************


*****************************
        Sales by Store
-----------------------------
Store    0: $     2466127.77
Store    1: $     2542621.31
-----------------------------
     Total: $     5008749.08
*****************************


Total simulation time: 0.14 seconds
```

```
./prodcons 5 10 30
*****************************
        Sales by Month
-----------------------------
   January: $      433265.44
  February: $      403816.51
     March: $      400512.26
     April: $      433689.83
       May: $      398982.03
      June: $      387342.12
      July: $      408285.01
    August: $      420226.01
 September: $      413688.61
   October: $      425444.75
  November: $      385894.43
  December: $      444578.18
-----------------------------
     Total: $     4955725.18
*****************************


*****************************
        Sales by Store
-----------------------------
Store    0: $      986329.14
Store    1: $     1008724.72
Store    2: $      966366.35
Store    3: $     1006332.52
Store    4: $      987972.45
-----------------------------
     Total: $     4955725.18
*****************************


Total simulation time: 0.07 seconds
```

```
./prodcons 10 10 30
*****************************
        Sales by Month
-----------------------------
   January: $      427034.58
  February: $      413145.23
     March: $      437532.81
     April: $      416492.52
       May: $      371335.15
      June: $      417165.20
      July: $      430072.86
    August: $      413583.17
 September: $      409424.68
   October: $      438527.64
  November: $      404056.06
  December: $      414687.17
-----------------------------
     Total: $     4993057.07
*****************************


*****************************
        Sales by Store
-----------------------------
Store    0: $      496752.90
Store    1: $      500171.50
Store    2: $      492539.71
Store    3: $      502118.31
Store    4: $      494947.66
Store    5: $      490634.11
Store    6: $      524754.80
Store    7: $      486921.98
Store    8: $      492501.25
Store    9: $      511714.85
-----------------------------
     Total: $     4993057.07
*****************************


Total simulation time: 0.09 seconds
```

# Conclusion

The random sleep behavior of the producers and consumers make it difficult to
benchmark whether a particular combination of producers and consumers contribute
to better performance.

C makes surprisingly quick work of this task and, judging by the generated
totals agreeing and lack of memory leaks at the conclusion of execution, it
would seem that the mutex lock is working as intended. The pthread library
appears to be very powerful and is something that warrants further exploration
in future projects.
