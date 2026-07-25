# Data structures and algorithms lab

C lab work from a university course on data structures and algorithms. Each folder is one week's exercises, implemented from scratch (no library containers).

## Week 2: linked lists

A singly linked list (`linkedlist.h` / `linkedlist.c`) with `insertFirst`, `deleteFirst`, `search`, and element based `delete`. `linked_list_demo.c` reads integers from `example.txt`, inserts them into the list, and writes the resulting list out to `result.txt`.

```sh
cc linked_list_demo.c linkedlist.c -o linked_list_demo
./linked_list_demo
```

## Week 3: queues

A basic FIFO queue (`queue.h` / `queue.c`) built on singly linked nodes, plus a priority queue (`priority_queue.h` / `priority_queue.c`) implemented as an array of queues, one per priority level, so the highest non-empty priority is always served first. `queue_test.c` and `priority_queue_demo.c` exercise the two structures; `input10.txt`, `input100.txt`, and `input10000.txt` are sample workloads at different sizes.

```sh
cc queue_test.c queue.c -o queue_test
cc priority_queue_demo.c priority_queue.c queue.c -o priority_queue_demo
```

Note: `priority_queue.c` predates a compiler that enforces implicit pointer or integer conversions as errors (it stores a `TaskID` directly in a `void *` field). It compiles as a warning on older toolchains but fails to build on newer clang or gcc without relaxing that check.

## Week 4: circular and cyclic linked lists

Two independent techniques for detecting a cycle in a linked list, sharing one interface (`cycle_detection.h`):

- **`floyd_cycle_detection.c`**: Floyd's cycle detection algorithm, the tortoise and hare.
- **`reversal_cycle_detection.c`**: a list reversal method. Reverses the list twice and compares the traversal count against the list's recorded length to spot a cycle.

Two drivers link against one implementation at a time:

- **`cycle_detection_demo.c`**: reads a size `n` from standard input, builds a randomized list that may or may not contain a cycle, and reports the result for a single run.
- **`reversal_cycle_benchmark.c`**: sweeps `n` from 1,000 to 100,000, times each run, and writes `reversal_benchmark_results.csv`.

`floyd_cycle_benchmark.c` is a self-contained benchmark for the Floyd's algorithm case, with its own custom allocator that tracks heap usage; its results are `floyd_benchmark_results.csv`.

```sh
cc floyd_cycle_benchmark.c -o floyd_cycle_benchmark
cc cycle_detection_demo.c floyd_cycle_detection.c linkedlist.c -o cycle_detection_demo
cc reversal_cycle_benchmark.c reversal_cycle_detection.c linkedlist.c -o reversal_cycle_benchmark
```

## Running

Each week's driver compiles standalone with any C compiler (gcc or clang), no external dependencies. Build artifacts (`.o`, `.exe`) are gitignored; the `.csv` files in week 4 are benchmark results, not build output, and are kept.
