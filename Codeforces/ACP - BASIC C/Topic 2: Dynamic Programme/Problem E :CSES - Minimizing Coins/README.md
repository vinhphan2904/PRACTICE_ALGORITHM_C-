# E. CSES - Minimizing Coins | Giảm thiểu đồng xu

## Ý tưởng

Đây là bài toán **Quy hoạch động (Dynamic Programming)**.

Gọi:

- `dp[i]` là số lượng đồng xu ít nhất để tạo ra tổng tiền `i`.

Ban đầu:

- `dp[0] = 0` vì không cần đồng xu nào để tạo tổng `0`.
- Các giá trị còn lại được gán là vô cùng (`INF`), biểu thị chưa thể tạo được.

Với mỗi tổng tiền `i` từ `1` đến `x`, thử sử dụng từng loại đồng xu `coin[j]`.

Nếu `i >= coin[j]` thì có thể lấy thêm đồng xu này sau khi đã tạo được tổng `i - coin[j]`.

Công thức:

```
dp[i] = min(dp[i], dp[i - coin[j]] + 1)
```

Sau khi tính xong:

- Nếu `dp[x]` vẫn là `INF` thì không tồn tại cách tạo ra tổng `x`, in `-1`.
- Ngược lại in `dp[x]`.

---

## Thuật toán

1. Đọc `n`, `x`.
2. Đọc giá trị các đồng xu.
3. Khởi tạo:
   - `dp[0] = 0`
   - Các phần tử còn lại bằng `INF`.
4. Duyệt tổng tiền từ `1 → x`.
5. Với mỗi đồng xu:
   - Nếu có thể sử dụng thì cập nhật `dp[i]`.
6. In kết quả.

---

## Độ phức tạp

- Thời gian: **O(n × x)**
- Bộ nhớ: **O(x)**

Với:

- `n ≤ 100`
- `x ≤ 10^6`

thuật toán đáp ứng tốt giới hạn đề bài.