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
