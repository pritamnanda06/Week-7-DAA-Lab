For Q1
------

Algorithm: InvertCoinTriangle(n)
Input: An integer n representing the number of rows of the coin triangle
Output: Minimum number of moves and the initial/final matrix state

1. Compute Total Coins T = (n * (n + 1)) / 2
2. Compute Minimum Moves M = (n * (n + 1)) / 6
3. Initialize an n x n grid representing the upright triangle configuration
4. Identify the M outer corner coins to be relocated
5. Identify the M target empty positions for the inverted triangle
6. Map each moving corner coin from its original coordinates to a target coordinate
7. Output M and the coin relocation steps

5. Complexity Analysis
Time Complexity:Calculating the minimum moves formula takes $\mathcal{O}(1)$ time.
Printing or simulating the grid state and individual coin moves takes $\mathcal{O}(n^2)$ time, which is linear in terms of the total number of coins $T(n)$.
Space Complexity:$\mathcal{O}(1)$ auxiliary space for calculating the mathematical formula.
$\mathcal{O}(n^2)$ space when storing the 2D array representation of the coin triangle.

1. Compact Formula
The total number of coins in an $n$-row triangle is given by:
$$T(n) = \frac{n(n+1)}{2}$$
The minimum number of moves $M(n)$ required to invert the triangle is:
$$M(n) = \left\lfloor \frac{n(n+1)}{6} \right\rfloor$$

--------------------------------------------------------------------------------

For Q2
-------

## Algorithm: Egg Dropping using Dynamic Programming

1. Create a DP table `dp[E+1][F+1]`, where `dp[e][f]` represents the minimum number of droppings required with `e` eggs and `f` floors.

2. Initialize the base cases:

   * If there are `0` floors, `dp[e][0] = 0`.
   * If there is `1` floor, `dp[e][1] = 1`.
   * With only `1` egg, every floor must be tested sequentially:
     `dp[1][f] = f`.

3. For every number of eggs `e = 2` to `E`:

   * For every number of floors `f = 2` to `F`:

     * Initialize `dp[e][f]` to infinity.

4. Try dropping an egg from every possible floor `x = 1` to `f`.

5. There are two possible outcomes:

   * **Egg breaks:** The highest safe floor is below `x`, so we have `e-1` eggs and `x-1` floors remaining.
   * **Egg does not break:** The highest safe floor is `x` or above, so we still have `e` eggs and `f-x` floors remaining.

6. Therefore, for each floor `x`, calculate:

   `1 + max(dp[e-1][x-1], dp[e][f-x])`

   The `max` is used because we need the number of droppings that is sufficient in the **worst case**.

7. Choose the minimum value among all possible dropping floors:

   `dp[e][f] = min(dp[e][f], 1 + max(dp[e-1][x-1], dp[e][f-x]))`

8. After filling the table, return:

   `dp[E][F]`


The algorithm gives:

```text
dp[2][100] = 14
```

Therefore, **14 droppings are sufficient to determine the highest safe floor in the worst case**.

## Complexity Analysis

There are `E × F` DP states, and for each state we try up to `F` possible dropping floors.

### Time Complexity

```text
O(E × F²)
```

### Space Complexity

```text
O(E × F)
```

----------------

For Q3
------

## Algorithm: Reve's Puzzle using 4 Pegs

1. Let the four pegs be `A`, `B`, `C`, and `D`.

   * `A` = Source peg
   * `D` = Destination peg
   * `B`, `C` = Auxiliary pegs

2. If `n = 0`, return.

3. Choose a value `k`, where `k` disks are transferred using the 4-peg method.

4. Recursively move the top `k` disks from the source peg to an auxiliary peg using all four pegs.

5. Move the remaining `n-k` disks from the source peg to the destination peg using the standard 3-peg Tower of Hanoi method.

6. Recursively move the `k` disks from the auxiliary peg to the destination peg using all four pegs.

7. Repeat the process until all disks are transferred to the destination peg.

### Algorithm for 3-Peg Tower of Hanoi

```text
Algorithm Hanoi3(n, Source, Destination, Auxiliary)

    if n = 0
        return

    Hanoi3(n-1, Source, Auxiliary, Destination)

    Move disk from Source to Destination

    Hanoi3(n-1, Auxiliary, Destination, Source)
```

## For 8 Disks

For `n = 8`, choose:

```text
k = 4
```

The 8 disks are divided as:

```text
First 4 disks  → 4-peg solution
Remaining 4    → 3-peg solution
First 4 disks  → 4-peg solution
```

The resulting solution requires:

```text
33 moves
```

Thus, the 8-disk Reve's Puzzle can be solved in **33 moves**.

## Generalized Solution

For `n` disks, define `T(n)` as the minimum number of moves.

For every possible `k` from `1` to `n-1`:

```text
T(n) = min [ 2T(k) + 2^(n-k) - 1 ]
```

Therefore:

```text
T(n) = min over k { 2T(k) + 2^(n-k) - 1 }
```

## Complexity Analysis

**Time Complexity:**

```text
O(n²)
```

**Space Complexity:**

```text
O(n)
```

------------------------------------------------------------------------------------------------------------


