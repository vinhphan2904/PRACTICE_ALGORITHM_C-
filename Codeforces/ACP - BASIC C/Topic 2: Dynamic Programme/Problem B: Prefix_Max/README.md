# Mảng Tiền Tố Max (Prefix Maximum)

## Ý tưởng

Mảng tiền tố max (Prefix Maximum) là kỹ thuật tiền xử lý giúp tìm giá trị lớn nhất trong đoạn từ **1 đến i** một cách nhanh chóng.

Thay vì phải duyệt lại từ đầu mảng cho mỗi truy vấn (`O(n)`), ta xây dựng trước một mảng `prefMax`, trong đó:

```cpp
prefMax[i] = max(a[1], a[2], ..., a[i]);
```

Công thức quy hoạch:

```cpp
prefMax[1] = a[1];

for (int i = 2; i <= n; i++)
    prefMax[i] = max(prefMax[i - 1], a[i]);
```

Sau khi tiền xử lý, mỗi truy vấn chỉ cần in:

```cpp
prefMax[x]
```

---

## Ví dụ

Cho mảng:

```
-2 5 4 6 3
```

Mảng Prefix Maximum:

| i | a[i] | prefMax[i] |
|---|------|------------|
|1|-2|-2|
|2|5|5|
|3|4|5|
|4|6|6|
|5|3|6|

Ví dụ:

- x = 1 → -2
- x = 3 → 5
- x = 5 → 6

---

## Thuật toán

1. Đọc mảng.
2. Xây dựng mảng `prefMax`.
3. Với mỗi truy vấn `x`, in `prefMax[x]`.

---

## Độ phức tạp

- Tiền xử lý: **O(N)**
- Mỗi truy vấn: **O(1)**
- Tổng thời gian: **O(N + Q)**
- Bộ nhớ: **O(N)**

---

## Code minh họa

```cpp
prefMax[1] = a[1];

for (int i = 2; i <= n; i++)
    prefMax[i] = max(prefMax[i - 1], a[i]);

while (q--) {
    int x;
    cin >> x;
    cout << prefMax[x] << '\n';
}
```

---

## Ghi nhớ

- `prefMax[i]` là **giá trị lớn nhất trong đoạn từ 1 đến i**.
- Xây dựng trong **O(N)**.
- Mỗi truy vấn trả lời trong **O(1)**.
- Thường dùng trong các bài toán truy vấn giá trị lớn nhất trên đoạn tiền tố.