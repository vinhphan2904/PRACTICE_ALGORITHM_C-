# Generated Array Maximum

## Ý tưởng

Đề bài cho quy luật sinh một dãy số `A`:

- `A[0] = 0`
- `A[1] = 1`
- `A[2i] = A[i]`
- `A[2i + 1] = A[i] + A[i + 1]`

Sau đó, với mỗi giá trị `N`, cần tìm **giá trị lớn nhất trong các phần tử từ `A[1]` đến `A[N]`**.

Do có nhiều truy vấn (`T ≤ 10^5`), không thể sinh lại dãy cho từng truy vấn. Ta sẽ **tiền xử lý** toàn bộ dãy một lần.

## Thuật toán

### Bước 1: Sinh dãy `A`

Khởi tạo:

```cpp
A[0] = 0;
A[1] = 1;
```

Duyệt `i` từ `1` đến khi `2 * i <= MAXN`:

- Nếu chỉ số chẵn:
  ```
  A[2 * i] = A[i]
  ```
- Nếu chỉ số lẻ:
  ```
  A[2 * i + 1] = A[i] + A[i + 1]
  ```

Nhờ sinh theo thứ tự tăng của `i`, các giá trị cần dùng luôn đã được tính trước.

### Bước 2: Tiền xử lý giá trị lớn nhất

Tạo mảng `mx`:

```
mx[i] = max(mx[i - 1], A[i])
```

Trong đó `mx[i]` là giá trị lớn nhất của đoạn `A[1...i]`.

### Bước 3: Trả lời truy vấn

Với mỗi `N`, chỉ cần in:

```
mx[N]
```

## Độ phức tạp

- Tiền xử lý dãy `A`: `O(MAXN)`
- Tiền xử lý mảng `mx`: `O(MAXN)`
- Mỗi truy vấn: `O(1)`

Tổng độ phức tạp:

```
O(MAXN + T)
```

với `MAXN = 100000`.

## Kiến thức áp dụng

- Precomputation (Tiền xử lý)
- Prefix Maximum
- Mảng một chiều