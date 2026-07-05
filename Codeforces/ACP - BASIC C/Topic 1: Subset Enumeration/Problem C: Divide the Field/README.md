# C. Chia ruộng (Divide the Field)

## Ý tưởng

Sử dụng **Meet in the Middle (MITM)**.

- Chia mảng thành hai nửa.
- Sinh tất cả trạng thái của nửa trái:
  - Mỗi thửa ruộng có 3 lựa chọn:
    - Giao cho người A.
    - Giao cho người B.
    - Giao cho người C.
  - Lưu `(sumA, sumB)` vào `map`.
- Sinh các trạng thái của nửa phải.
  - Với mỗi trạng thái, tìm `(target - sumA, target - sumB)` trong `map`.
  - Cộng số lần xuất hiện vào đáp án.

Do tổng diện tích của người C được xác định bởi:

```
sumC = total - sumA - sumB
```

nên chỉ cần lưu `(sumA, sumB)`.

Nếu tổng diện tích không chia hết cho 3 thì kết quả là `-1`.

## Độ phức tạp

- Thời gian: **O(3^(n/2) log 3^(n/2))**
- Bộ nhớ: **O(3^(n/2))**

## Kiến thức sử dụng

- Meet in the Middle (MITM)
- DFS / Backtracking
- Map