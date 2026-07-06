# Dãy con tăng đơn điệu dài nhất (Longest Increasing Subsequence - LIS)

## Mô tả

Cho dãy số nguyên gồm `N` phần tử. Hãy tìm **độ dài của dãy con tăng đơn điệu dài nhất**.

Một dãy con tăng đơn điệu là dãy các phần tử có chỉ số tăng dần và giá trị cũng tăng dần.

---

## Ý tưởng

Sử dụng **Quy hoạch động (Dynamic Programming - DP)**.

Định nghĩa:

* `dp[i]` là độ dài của dãy con tăng dài nhất **kết thúc tại vị trí `i`**.

Ban đầu, mỗi phần tử đều có thể tự tạo thành một dãy con tăng có độ dài `1`, nên:

```cpp
dp[i] = 1;
```

Sau đó, với mỗi vị trí `i`, duyệt tất cả các vị trí trước nó `j`.

Nếu:

```cpp
a[j] < a[i]
```

thì có thể nối `a[i]` vào sau dãy con tăng kết thúc tại `j`.

Khi đó cập nhật:

```cpp
dp[i] = max(dp[i], dp[j] + 1);
```

Trong quá trình tính toán, lưu lại giá trị lớn nhất của `dp[i]`.

---

## Thuật toán

1. Đọc `N` và mảng `a`.
2. Khởi tạo `dp[i] = 1` với mọi `i`.
3. Với mỗi `i` từ `1` đến `N`:

   * Duyệt `j` từ `1` đến `i - 1`.
   * Nếu `a[j] < a[i]` thì:

     ```cpp
     dp[i] = max(dp[i], dp[j] + 1);
     ```
4. Lấy giá trị lớn nhất trong mảng `dp`.
5. In kết quả.

---

## Ví dụ

**Input**

```
6
1 2 5 4 6 2
```

Quá trình tính `dp`:

| i | A[i] | dp[i] |
| - | ---: | ----: |
| 1 |    1 |     1 |
| 2 |    2 |     2 |
| 3 |    5 |     3 |
| 4 |    4 |     3 |
| 5 |    6 |     4 |
| 6 |    2 |     2 |

Đáp án:

```
4
```

Một dãy con tăng dài nhất là:

```
1 2 4 6
```

---

## Chứng minh tính đúng đắn

Ta chứng minh rằng `dp[i]` luôn bằng độ dài của dãy con tăng dài nhất kết thúc tại vị trí `i`.

* Ban đầu, mỗi phần tử tự tạo thành một dãy con tăng có độ dài `1`, nên `dp[i] = 1` là đúng.
* Với mỗi `j < i`, nếu `a[j] < a[i]` thì mọi dãy con tăng kết thúc tại `j` đều có thể mở rộng bằng cách thêm `a[i]`, tạo thành dãy mới có độ dài `dp[j] + 1`.
* Thuật toán xét tất cả các vị trí `j` thỏa mãn điều kiện và lấy giá trị lớn nhất, nên không bỏ sót bất kỳ dãy con tăng nào kết thúc tại `i`.

Do mọi dãy con tăng đều kết thúc tại một vị trí trong mảng, giá trị lớn nhất của `dp[i]` chính là độ dài của dãy con tăng dài nhất.

Vì vậy thuật toán luôn cho kết quả chính xác.

---

## Độ phức tạp

* **Thời gian:** `O(N²)`
* **Bộ nhớ:** `O(N)`

---

## Kiến thức sử dụng

* Dynamic Programming (DP)
* Mảng một chiều
* Duyệt hai vòng lặp
* Bài toán Longest Increasing Subsequence (LIS)
