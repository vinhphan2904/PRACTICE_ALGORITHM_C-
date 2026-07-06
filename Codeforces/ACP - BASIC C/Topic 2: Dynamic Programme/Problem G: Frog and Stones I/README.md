# G. Chú ếch và hòn đá 1 (Frog 1)

## Ý tưởng

Sử dụng **Quy hoạch động (Dynamic Programming - DP)**.

Gọi `dp[i]` là **chi phí nhỏ nhất để con ếch đi từ hòn đá 1 đến hòn đá i**.

Để đến hòn đá `i`, con ếch chỉ có thể nhảy từ:

- Hòn đá `i - 1`.
- Hòn đá `i - 2`.

Vì vậy, chi phí nhỏ nhất để đến `i` sẽ là giá trị nhỏ hơn trong hai cách trên.

## Công thức DP

### Khởi tạo

```cpp
dp[1] = 0;
dp[2] = abs(h[2] - h[1]);
```

### Chuyển trạng thái

```cpp
dp[i] = min(
    dp[i - 1] + abs(h[i] - h[i - 1]),
    dp[i - 2] + abs(h[i] - h[i - 2])
);
```

với `i ≥ 3`.

## Thuật toán

1. Đọc `N` và mảng chiều cao `h`.
2. Khởi tạo `dp[1]` và `dp[2]`.
3. Duyệt từ `3` đến `N`, tính `dp[i]` theo công thức DP.
4. In ra `dp[N]`.

## Chứng minh

Để đến hòn đá `i`, bước nhảy cuối cùng chỉ có thể xuất phát từ:

- `i - 1`
- `i - 2`

Nếu đi từ `i - 1`, tổng chi phí là:

```text
dp[i - 1] + |h[i] - h[i - 1]|
```

Nếu đi từ `i - 2`, tổng chi phí là:

```text
dp[i - 2] + |h[i] - h[i - 2]|
```

Lấy giá trị nhỏ hơn của hai trường hợp trên sẽ thu được chi phí nhỏ nhất để đến hòn đá `i`.

Do đó công thức DP luôn đúng và thuật toán tìm được đáp án tối ưu.

## Độ phức tạp

- **Thời gian:** `O(N)`
- **Bộ nhớ:** `O(N)`

> Có thể tối ưu xuống **O(1)** bộ nhớ vì mỗi trạng thái chỉ phụ thuộc vào hai trạng thái trước đó.