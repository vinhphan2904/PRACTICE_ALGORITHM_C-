# P. CSES - Money Sums | Khoản tiền

## 📌 Đề bài

Cho `n` đồng xu, mỗi đồng xu có một giá trị nhất định. Mỗi đồng xu chỉ được sử dụng **một lần**.

Hãy tìm **tất cả các khoản tiền khác nhau** có thể tạo được từ các đồng xu đã cho.

---

## 💡 Ý tưởng

Đây là bài toán **Subset Sum (0/1 Knapsack)**.

Ta sử dụng quy hoạch động để xác định xem một tổng tiền có thể được tạo thành hay không.

Định nghĩa:

- `dp[i][j] = true` nếu có thể tạo được tổng `j` bằng cách sử dụng **i đồng xu đầu tiên**.
- `dp[i][j] = false` nếu không thể.

Mỗi đồng xu có hai lựa chọn:

- Không chọn đồng xu hiện tại.
- Chọn đồng xu hiện tại.

---

## 🔄 Công thức chuyển

Nếu không chọn đồng xu thứ `i`:

```cpp
dp[i][j] = dp[i - 1][j];
```

Nếu chọn đồng xu thứ `i`:

```cpp
if (j >= a[i])
    dp[i][j] |= dp[i - 1][j - a[i]];
```

Ghép lại:

```cpp
dp[i][j] = dp[i - 1][j];

if (j >= a[i])
    dp[i][j] |= dp[i - 1][j - a[i]];
```

---

## 🚀 Khởi tạo

```cpp
dp[0][0] = true;
```

Không chọn đồng xu nào thì chỉ tạo được tổng bằng `0`.

Các trạng thái còn lại ban đầu đều bằng `false`.

---

## 📊 Ví dụ

Input

```
4
4 2 5 2
```

Quá trình cập nhật:

| Sau khi xét | Các tổng tạo được |
|-------------|-------------------|
| Ban đầu | 0 |
| 4 | 0 4 |
| 2 | 0 2 4 6 |
| 5 | 0 2 4 5 6 7 9 11 |
| 2 | 0 2 4 5 6 7 8 9 11 13 |

Bỏ tổng `0`, ta thu được đáp án:

```
2 4 5 6 7 8 9 11 13
```

---

## ⏱️ Độ phức tạp

Gọi:

- `n ≤ 100`
- `sum = tổng giá trị các đồng xu ≤ 100000`

### Thời gian

```
O(n × sum)
```

### Bộ nhớ

```
O(n × sum)
```

---

## ⭐ Tối ưu

Có thể tối ưu xuống **DP một chiều** vì mỗi trạng thái chỉ phụ thuộc vào hàng trước.

```cpp
bool dp[100001];
dp[0] = true;

for (int i = 1; i <= n; i++) {
    for (int j = sum; j >= a[i]; j--) {
        dp[j] |= dp[j - a[i]];
    }
}
```

Lưu ý phải **duyệt ngược** để mỗi đồng xu chỉ được sử dụng **một lần**.

---

## 🎯 Kiến thức rút ra

- Đây là bài toán **Subset Sum (0/1 Knapsack)**.
- Trạng thái DP lưu khả năng tạo được một tổng tiền.
- Mỗi đồng xu chỉ được sử dụng một lần.
- Có thể tối ưu từ DP hai chiều xuống DP một chiều bằng cách duyệt ngược.
- Sau khi hoàn thành DP, duyệt từ `1` đến `sum` để in tất cả các tổng có thể tạo được.