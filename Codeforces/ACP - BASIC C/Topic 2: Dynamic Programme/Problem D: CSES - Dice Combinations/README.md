# D. CSES - Dice Combinations | Kết hợp xúc xắc

## Ý tưởng

Đây là bài toán **Quy hoạch động (Dynamic Programming - DP)**.

Gọi `dp[i]` là số cách tạo ra tổng bằng `i`.

Để tạo ra tổng `i`, lần tung cuối cùng có thể ra một trong các số từ **1 đến 6**. Nếu lần tung cuối ra `j` thì trước đó phải tạo được tổng `i - j`.

Vì vậy:

```
dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]
```

(chỉ cộng các trạng thái hợp lệ khi `i >= j`).

### Khởi tạo

```
dp[0] = 1
```

Có đúng một cách tạo tổng bằng `0`: không tung viên xúc xắc nào.

---

## Thuật toán

1. Khởi tạo `dp[0] = 1`.
2. Duyệt `i` từ `1` đến `n`.
3. Với mỗi `i`, duyệt `j` từ `1` đến `6`.
4. Nếu `i >= j` thì:
   ```
   dp[i] += dp[i-j]
   ```
5. Lấy modulo `10^9 + 7` sau mỗi lần cộng.
6. In `dp[n]`.

---

## Ví dụ

Với `n = 3`:

| Tổng | Số cách |
|------:|---------:|
|0|1|
|1|1|
|2|2|
|3|4|

Các cách tạo tổng 3 là:

- 1 + 1 + 1
- 1 + 2
- 2 + 1
- 3

Đáp án là **4**.

---

## Chứng minh đúng

Mỗi cách tạo tổng `i` đều có một lần tung cuối cùng nhận giá trị từ `1` đến `6`.

Nếu lần tung cuối là `j` thì phần trước đó phải tạo được tổng `i-j`. Ngược lại, từ bất kỳ cách tạo tổng `i-j`, thêm một lần tung ra `j` sẽ thu được đúng một cách tạo tổng `i`.

Các trường hợp với `j = 1..6` là độc lập nên tổng số cách bằng tổng số cách của các trạng thái trước.

Do đó:

```
dp[i] = Σ dp[i-j]  (1 ≤ j ≤ 6, i ≥ j)
```

Công thức quy hoạch động là đúng.

---

## Độ phức tạp

- **Thời gian:** `O(n)`
- **Bộ nhớ:** `O(n)`