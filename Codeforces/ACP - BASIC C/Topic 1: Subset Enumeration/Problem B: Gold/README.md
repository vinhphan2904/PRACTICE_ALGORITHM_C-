# B. GOLDS

## 💡 Solution

Since `n ≤ 40`, enumerating all `2^n` subsets is impossible.

Use **Meet in the Middle**:

1. Split the array into two halves.
2. Generate all subset sums of each half using DFS.
3. Sort the subset sums of the right half.
4. For each sum in the left half, use `upper_bound()` to count how many right sums satisfy:

   ```
   left + right ≤ M
   ```

5. Sum all valid pairs.

---

### Complexity

- **Time:** `O(2^(n/2) log 2^(n/2))`
- **Memory:** `O(2^(n/2))`

---

### Techniques

- Meet in the Middle
- DFS (Subset Generation)
- Binary Search (`upper_bound`)