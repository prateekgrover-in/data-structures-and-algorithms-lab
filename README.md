# Data Structures and Algorithms Lab

C lab work from a university course on data structures and algorithms. Each
folder is one week's exercises, implemented from scratch in C (no library
containers).

## Week II - Linked Lists

A singly linked list (`linkedlist.h`/`.c`) with `insertFirst`, `deleteFirst`,
`search`, and element-based `delete`. `driver.c` reads integers from
`example.txt`, inserts them into the list, and writes the resulting list out
to `result.txt`.

```sh
cc driver.c linkedlist.c -o driver
./driver
```

## Week III - Queues

A basic FIFO queue (`que.h`/`.c`) built on singly linked nodes, plus a
priority queue (`multiq.h`/`.c`) implemented as an array of queues — one per
priority level, so the highest non-empty priority is always served first.
`que_test.c` and `multi_q_driver.c` exercise the two structures; `input10.txt`,
`input100.txt`, and `input10000.txt` are sample workloads at different sizes.

```sh
cc que_test.c que.c -o que_test
cc multi_q_driver.c multiq.c que.c -o multi_q_driver
```

## Week IV - Circular and Cyclic Linked Lists

Cycle detection and correction on singly linked lists:

- `floyds.c` — Floyd's cycle-detection algorithm ("tortoise and hare"),
  benchmarked (`test_floyd*` variants) with a custom allocator that tracks
  heap usage. `result_floyd.csv` holds timing/memory results across input
  sizes.
- `cycle1.c` / `cycle2.c` + `cycle.h` / `main.c` — detects a cycle in a list
  and reverses/repairs the list structure around it; `result_linkreversal.csv`
  holds the corresponding benchmark results.

```sh
cc floyds.c -o floyds
cc main.c cycle1.c linkedlist.c -o main
```

## Running

Each week's driver compiles standalone with any C compiler (`gcc`/`cc`); no
external dependencies. Build artifacts (`*.o`, `*.exe`) are gitignored — the
`.csv` files in Week IV are benchmark results, not build output, and are kept.
