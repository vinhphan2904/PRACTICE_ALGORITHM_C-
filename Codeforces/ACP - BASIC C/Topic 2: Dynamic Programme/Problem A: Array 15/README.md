# Range Sum Query - Prefix Sum

## Ý tưởng

Bài toán yêu cầu thực hiện nhiều truy vấn tính tổng các phần tử trong đoạn `[u, v]`.

Nếu với mỗi truy vấn ta duyệt từ `u` đến `v` để cộng các phần tử thì mỗi truy vấn mất `O(N)`, dẫn đến tổng thời gian `O(N × Q)`, không đáp ứng được khi `N, Q ≤ 10^5`.

Ta sử dụng **Prefix Sum (mảng cộng dồn)** để tiền xử lý mảng, từ đó mỗi truy vấn chỉ cần `O(1)`.

---

## Thuật toán

### Bước 1: Xây dựng mảng cộng dồn

Gọi `dp[i]` là tổng của `i` phần tử đầu tiên trong mảng.

Công thức:

```cpp
dp[0] = 0;
for (int i = 1; i <= n; i++)
    dp[i] = dp[i - 1] + a[i];
```

---

### Bước 2: Trả lời truy vấn

Tổng các phần tử từ `u` đến `v` được tính bằng:

```cpp
dp[v] - dp[u - 1]
```

Vì:

- `dp[v]` là tổng từ `1` đến `v`.
- `dp[u - 1]` là tổng từ `1` đến `u - 1`.

Lấy hiệu sẽ thu được đúng tổng đoạn `[u, v]`.

---

## Minh họa

Mảng:

```
1 4 5 1 4 3 3 4
```

Prefix Sum:

```
0 1 5 10 11 15 18 21 25
```

Ví dụ truy vấn:

```
u = 3
v = 5
```

Kết quả:

```
dp[5] - dp[2]
= 15 - 5
= 10
```

Đúng với:

```
5 + 1 + 4 = 10
```

---

## Chứng minh

Theo định nghĩa:

```
dp[i] = A1 + A2 + ... + Ai
```

Ta có:

```
dp[v]
= A1 + A2 + ... + A(u-1) + Au + ... + Av

dp[u-1]
= A1 + A2 + ... + A(u-1)
```

Suy ra:

```
dp[v] - dp[u-1]
= Au + Au+1 + ... + Av
```

Chính là tổng cần tìm.

Do đó công thức luôn đúng.

---

## Độ phức tạp

- Xây dựng Prefix Sum: **O(N)**
- Mỗi truy vấn: **O(1)**
- Tổng thời gian: **O(N + Q)**

### Bộ nhớ

Sử dụng hai mảng `a` và `dp` kích thước `N`.

```
O(N)
```

---

## Kiến thức sử dụng

- Prefix Sum (Mảng cộng dồn)
- Tiền xử lý (Preprocessing)
- Range Sum Query