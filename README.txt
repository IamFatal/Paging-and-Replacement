group_0406
Task 2: TABLES
________________________________________________________________________________

    trace file: simpleloop
________________________________________________________________________________

memsize: 50

        HitRate     Hits    Misses  TotalEvicts CleanEvicts DirtyEvicts
rand    74.32       8782    3034    2984        276         2708
fifo    74.78       8838    2980    2930        206         2724
lru     76.42       9030    2786    2736        89          2647
clock   74.31       9017    2799    2749        95          2654
opt     74.8023     7947    2677    2627        26          2601

memsize: 100

        HitRate     Hits    Misses  TotalEvicts CleanEvicts DirtyEvicts
rand    76.40       9028    2788    2688        74          2614
fifo    76.62       9054    2762    2662        44          2618
lru     77.23       9126    2690    2590        2           2588
clock   77.20       9123    2693    2593        3           2590
opt     75.1506     7984    2640    2540        0           2540

memsize: 150

        HitRate     Hits    Misses  TotalEvicts CleanEvicts DirtyEvicts
rand    76.9042     9087    2729    2579        20          2559
fifo    76.97       9095    2721    2571        16          2555
lru     77.25       9129    2687    2537        0           2537
clock   77.25       9128    2688    2538        0           2538
opt     75.1506     7984    2640    2490        03          2490

memsize: 200

        HitRate     Hits    Misses  TotalEvicts CleanEvicts DirtyEvicts
rand    77.05       9105    2711    2511        17          2494
fifo    77.03       9103    2713    2513        12          2501
lru     77.25       9129    2687    2487        0           2487
clock   77.25       9129    2687    2487        0           2487
opt     75.1506     7984    2640    2440        03          2440
________________________________________________________________________________

    trace file: matmul
________________________________________________________________________________

memsize: 50

        HitRate     Hits        Misses      TotalEvicts CleanEvicts DirtyEvicts
rand    65.5642     1894390     994978      994928      955836      39092
fifo    60.9859     1762108     1127260     1127210     1083217     43993
lru     63.96       1048146     1041222     1041172     1040064     1108
clock   63.96       1848141     1041227     1041177     1040064    1113
opt     79.6597     2300693     587459      587409      586321      1088

memsize: 100

        HitRate     Hits        Misses      TotalEvicts CleanEvicts DirtyEvicts
rand    88.79       2565505     323863      323763      316209      7554
fifo    62.49       1805820     1083548     1083448     1061223     22225
lru     65.16       1882914     1006454     1006354     1005274     1080
clock   65.32       1887574     1001794     1001694     1000612     1082
opt     96.7870     2795355     92797       92697       91611       1086

memsize: 150

        HitRate     Hits        Misses      TotalEvicts CleanEvicts DirtyEvicts
rand    96.68       2793538     95830       95680       93386       2294
fifo    98.80       2854960     34408       34258       32943       1315
lru     98.86       2856483     32885       32735       31656       1079
clock   98.6051     2849063     40305       40155       39075       1080
opt     99.0785     2861538     26614       26464       25378       1086

memsize: 200

        HitRate     Hits        Misses      TotalEvicts CleanEvicts DirtyEvicts
rand    98.04       2832928     56440       56240       54606      1634
fifo    98.82       2855481     33887       33687       32433       1254
lru     98.86       2856495     32873       32673       31594       1079
clock   98.86       2856481     32887       32687       31608       1079
opt     99.3330     2868888     19264       19064       17978       1086
________________________________________________________________________________

    trace file: blocked
________________________________________________________________________________

memsize: 50

        HitRate     Hits        Misses      TotalEvicts CleanEvicts DirtyEvicts
rand    99.6579     2409976     8272        8222        5709        2513
fifo    99.7345     2411827     6421        6371        4100        2271
lru     99.7879     2413118     5130        5080        2745        2335
clock   99.7628     2412513     5735        5685        3252        2433
opt     99.8472     2414552     3696        3646        2560        1086

memsize: 100

        HitRate     Hits        Misses      TotalEvicts CleanEvicts DirtyEvicts
rand    99.7846     2413039     5209        5109        3384        1725
fifo    99.8220     2413943     4305        4205        2726        1479
lru     99.8435     2414463     3785        3685        2603        1082
clock   99.8290     2414112     4136        4036        2610        1426
opt     99.8760     2415250     2998        2898        1825        1073

memsize: 150

        HitRate     Hits        Misses      TotalEvicts CleanEvicts DirtyEvicts
rand    99.8195     2413884     4364        4214        2744        1470
fifo    99.8259     2414039     4209        4059        2636        1423
lru     99.8441     2414479     3769        3619        2558        1061
clock   99.8436     2414467     3781        3631        2570        1061
opt     99.8957     2415725     2523        2373        1297        1076

memsize: 200

        HitRate     Hits        Misses      TotalEvicts CleanEvicts DirtyEvicts
rand    99.8404     2414388     3860        3660        2323        1337
fifo    99.8692     2415085     3163        2963        1865        1098
lru     99.8472     2414552     3696        3496        2435        1061
clock   99.8676     2415046     3202        3002        1941        1061
opt     99.9060     2415975     2273        2073        1007        1066
________________________________________________________________________________

    trace file: sumprime
________________________________________________________________________________

memsize: 50

        HitRate     Hits        Misses      TotalEvicts CleanEvicts DirtyEvicts
rand    95.70       6194        278         228         92          136
fifo    95.96       6211        261         211         73          138
lru     97.12       6286        186         136         32          104
clock   97.11       6285        187         137         34          103
opt     97.83       6332        140         91          7           83

memsize: 100

        HitRate     Hits        Misses      TotalEvicts CleanEvicts DirtyEvicts
rand    97.82       6331        141         41          4           37
fifo    97.79       6329        143         43          0           43
lru     98.06       6347        125         25          0           25
clock   97.99       6342        130         30          0           30
opt     98.08       6348        124         24          0           24

memsize: 150

        HitRate     Hits        Misses      TotalEvicts CleanEvicts DirtyEvicts
rand    98.08       6348        124         0           0           0
fifo    98.08       6348        124         0           0           0
lru     98.08       6348        124         0           0           0
clock   98.08       6348        124         0           0           0
opt     98.08       6348        124         0           0           0      

memsize: 200

        HitRate     Hits        Misses      TotalEvicts CleanEvicts DirtyEvicts
rand    98.08       6348        124         0           0           0
fifo    98.08       6348        124         0           0           0
lru     98.08       6348        124         0           0           0
clock   98.08       6348        124         0           0           0
opt     98.08       6348        124         0           0           0   
________________________________________________________________________________

    COMPARING ALGORITHMS
________________________________________________________________________________

As expected, we see that: FIFO < LRU = CLOCK < OPT.

RU and CLOCK have very similar numbers since CLOCK is an approximation of
exact LRU. 

Obviously, OPT performs the best since it always evicts the page which won't
be used for the longest time, which maximizes hit rate.

FIFO, LRU, and CLOCK all perform well in trace files where locality is
maximized (data is put into blocks before computational steps). RAND performs
poorly in these traces since it cannot utilize locality to optimize. However,
in matmul, where the data is generated dynamically and more likely to result in
non-contiguous data, locality is reduced and these algorithms end up performing
worse than RAND, which doesn't rely on locality.
________________________________________________________________________________

    LRU AS MEMORY SIZE INCREASES
________________________________________________________________________________

table: LRU hit-rates per program

            50      100     150     200
simpleloop  76.42   77.23   77.25   77.25
matmul      63.96   65.16   96.86   98.86
blocked     99.78   99.84   99.84   99.84
sumprime    97.12   98.06   98.08   98.08

Generally, as the memory size increases, so does hit rate. LRU makes use of
locality and is good at analyzing past use to evict the optimal page. When a 
page needs to be evicted, LRU selects the page which hasn't been used for the
longest period of time. With increased memory size, more pages are stored in 
memory so we have more data to work with and this leads to increased precision
in the eviction process and increased hit rates.
