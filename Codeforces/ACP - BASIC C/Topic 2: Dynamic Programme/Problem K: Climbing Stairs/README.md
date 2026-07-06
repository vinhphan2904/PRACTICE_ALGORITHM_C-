# K. Bậc thang

## 📖 Mô tả

Lucky đang đứng ở **bậc 1** của một cầu thang gồm **n bậc**.

Ở mỗi bước, Lucky có thể:

- Đi lên **1 bậc**
- Nhảy lên **2 bậc**

Tuy nhiên, có **k bậc bị hỏng**, Lucky **không được đặt chân lên** các bậc này.

Yêu cầu tính số cách để Lucky đi từ **bậc 1 đến bậc n**.

Kết quả lấy modulo:

```
14062008
```

---

## 💡 Ý tưởng

Đây là bài toán **Quy hoạch động (Dynamic Programming)**.

### Trạng thái

Gọi:

```
dp[i]
```

là số cách để đến được bậc `i`.

---

### Khởi tạo

Lucky bắt đầu ở bậc 1:

```
dp[1] = 1
```

Các bậc bị hỏng sẽ có:

```
dp[i] = 0
```

---

### Công thức chuyển

Muốn đến bậc `i`:

- đi từ `i-1`
- hoặc nhảy từ `i-2`

Do đó:

```
dp[i] = dp[i-1] + dp[i-2]
```

Nếu bậc `i` bị hỏng:

```
dp[i] = 0
```

Lấy modulo sau mỗi phép cộng:

```
dp[i] = (dp[i-1] + dp[i-2]) % MOD
```

---

## ✅ Thuật toán

1. Đọc `n`, `k`.
2. Đánh dấu các bậc bị hỏng.
3. Khởi tạo:

```
dp[1] = 1
```

4. Duyệt từ `2 → n`

- Nếu bậc bị hỏng:
  - `dp[i] = 0`
- Ngược lại:
  - `dp[i] = dp[i-1] + dp[i-2]`

5. In `dp[n]`.

---

## 📈 Độ phức tạp

- **Thời gian**

```
O(n)
```

- **Bộ nhớ**

```
O(n)
```

---

## Ví dụ

### Input

```
4 2
2 3
```

Các bậc:

```
1 2 3 4
  X X
```

Lucky không thể đi qua bậc 2 hoặc 3 nên không thể tới bậc 4.

Output

```
0
```

---

## Minh họa DP

Ví dụ:

```
n = 6

Không có bậc hỏng
```

| i | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| dp[i] | 1 | 1 | 2 | 3 | 5 | 8 |

Số cách chính là dãy Fibonacci bắt đầu từ bậc 1.

Nếu bậc 4 bị hỏng:

| i | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| dp[i] | 1 | 1 | 2 | 0 | 2 | 2 |

---

## Kiến thức sử dụng

- Dynamic Programming (DP)
- Mảng đánh dấu
- Quy hoạch động 1 chiều
- Fibonacci DP
- Modulo