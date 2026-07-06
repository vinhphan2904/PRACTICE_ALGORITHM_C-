# C. Tổng lớn nhất trong mảng

## Ý tưởng

Gọi `dp[i]` là tổng lớn nhất của một đoạn con kết thúc tại vị trí `i`.

Tại mỗi vị trí có hai lựa chọn:

* Bắt đầu một đoạn mới từ `a[i]`.
* Nối `a[i]` vào đoạn tốt nhất kết thúc ở `i - 1`.

Công thức quy hoạch động:

```cpp
dp[i] = max(a[i], dp[i - 1] + a[i]);
```

Đáp án là giá trị lớn nhất trong các `dp[i]`.

Có thể tối ưu bộ nhớ bằng cách chỉ lưu giá trị `dp[i - 1]`, đây chính là thuật toán **Kadane**.

## Thuật toán

1. Đọc mảng.
2. Khởi tạo:

   * `cur = a[1]`
   * `ans = a[1]`
3. Với mỗi phần tử tiếp theo:

   * `cur = max(a[i], cur + a[i])`
   * `ans = max(ans, cur)`
4. In `ans`.

## Độ phức tạp

* Thời gian: **O(n)**
* Bộ nhớ: **O(1)** (phiên bản Kadane)
