# Q. Xếp gỗ

## Ý tưởng

Bài toán yêu cầu đếm số cách xếp các khối gỗ để đạt đúng chiều cao `N`. Mỗi loại khối gỗ có thể sử dụng không giới hạn số lần và **thứ tự xếp các khối được tính là khác nhau**.

Sử dụng **Quy hoạch động (Dynamic Programming)**.

Đặt `dp[i]` là số cách tạo được chiều cao đúng bằng `i`.

* `dp[0] = 1`: Có đúng một cách tạo chiều cao 0 là không sử dụng khối nào.
* Với mỗi chiều cao `i` từ `1` đến `N`, thử chọn từng loại khối có chiều cao `H[j]` làm khối cuối cùng.
* Nếu `i >= H[j]` thì mọi cách tạo được chiều cao `i - H[j]` đều có thể thêm khối `H[j]` để tạo thành chiều cao `i`.

Công thức chuyển trạng thái:

```cpp
dp[i] = (dp[i] + dp[i - H[j]]) % MOD;
```

Để tối ưu, sắp xếp mảng chiều cao trước. Khi `H[j] > i`, có thể dừng vòng lặp vì các khối phía sau đều lớn hơn.

## Thuật toán

1. Đọc `N`, `K` và chiều cao các loại khối.
2. Sắp xếp mảng chiều cao tăng dần.
3. Khởi tạo `dp[0] = 1`.
4. Duyệt `i` từ `1` đến `N`.
5. Với mỗi loại khối:

   * Nếu `H[j] > i` thì dừng.
   * Ngược lại cập nhật:

     ```cpp
     dp[i] = (dp[i] + dp[i - H[j]]) % MOD;
     ```
6. In `dp[N]`.

## Chứng minh tính đúng đắn

Xét một cách xếp có tổng chiều cao bằng `i`.

Khối gỗ cuối cùng chắc chắn là một trong `K` loại có chiều cao `H[j]`.

Nếu bỏ khối cuối đi thì phần còn lại phải có chiều cao đúng bằng `i - H[j]`.

Theo định nghĩa của mảng `dp`, số cách tạo chiều cao `i - H[j]` là `dp[i - H[j]]`. Ghép thêm khối `H[j]` vào cuối sẽ tạo thành một cách hợp lệ đạt chiều cao `i`.

Mỗi cách xếp có đúng một khối cuối cùng nên được đếm đúng một lần, và mọi khả năng đều được xét. Vì vậy công thức quy hoạch động là chính xác.

## Độ phức tạp

* **Thời gian:** `O(N × K)`
* **Bộ nhớ:** `O(N)`
