# Cân thăng bằng - Meet in the Middle

## Ý tưởng

Mỗi quả cân có **3 trạng thái**:

- Không sử dụng.
- Đặt lên đĩa A (cùng phía với vật).
- Đặt lên đĩa B (đối diện vật).

Gọi

- `A` là tổng khối lượng các quả cân đặt trên đĩa A.
- `B` là tổng khối lượng các quả cân đặt trên đĩa B.

Do vật có khối lượng `M` được đặt trên đĩa A nên để cân thăng bằng ta cần:

\[
M + A = B
\]

hay

\[
B - A = M
\]

Định nghĩa

```text
diff = B - A
```

Khi đó bài toán trở thành:

> Đếm số cách chọn trạng thái của các quả cân sao cho

```text
diff = M
```

---

## Tại sao dùng Meet in the Middle?

Mỗi quả cân có 3 lựa chọn nên nếu duyệt trực tiếp sẽ có

\[
3^n
\]

trạng thái.

Với `n = 20`

\[
3^{20} \approx 3.4 \times 10^9
\]

là quá lớn.

Ta chia mảng thành hai nửa:

```text
0 .......... m-1 | m .......... n-1
      Left               Right
```

Khi đó mỗi nửa chỉ có khoảng 10 phần tử.

Số trạng thái mỗi nửa là

\[
3^{10}=59049
\]

hoàn toàn có thể duyệt.

---

## Sinh trạng thái nửa trái

Duyệt đệ quy tất cả các cách đặt quả cân.

Với mỗi quả cân có ba lựa chọn:

- Không dùng

```cpp
genLeft(l + 1, m, diff);
```

- Đặt lên A

```cpp
genLeft(l + 1, m, diff - a[l]);
```

vì

```text
A tăng
=> B - A giảm
```

- Đặt lên B

```cpp
genLeft(l + 1, m, diff + a[l]);
```

vì

```text
B tăng
=> B - A tăng
```

Khi duyệt hết nửa trái, lưu số cách tạo được mỗi giá trị `diff`.

```cpp
cntLeft[diff]++;
```

---

## Sinh trạng thái nửa phải

Tương tự, sinh tất cả các giá trị

```text
diffRight
```

Muốn tổng hiệu bằng `M` thì cần

```text
diffLeft + diffRight = M
```

hay

```text
diffLeft = M - diffRight
```

Do đó chỉ cần tìm

```cpp
cntLeft[M - diffRight]
```

Nếu tồn tại thì cộng số cách tương ứng vào đáp án.

---

## Ví dụ

Giả sử

```text
M = 4
```

Sau khi sinh nửa trái:

| diffLeft | Số cách |
|----------|---------|
| 0 | 2 |
| 1 | 5 |
| 3 | 4 |

Khi sinh nửa phải thu được

```text
diffRight = 1
```

Ta cần

```text
diffLeft = 4 - 1 = 3
```

Có

```text
cntLeft[3] = 4
```

nên có thêm 4 cách hợp lệ.

---

## Chứng minh tính đúng

Mỗi quả cân luôn thuộc đúng một trong ba trạng thái:

- Không dùng.
- Đặt lên A.
- Đặt lên B.

Meet in the Middle chỉ chia tập quả cân thành hai phần độc lập.

Mỗi cách phân bố đầy đủ tương ứng duy nhất với:

- một trạng thái của nửa trái,
- một trạng thái của nửa phải.

Thuật toán chỉ ghép hai trạng thái khi

```text
diffLeft + diffRight = M
```

nên mọi cách được đếm đều hợp lệ.

Ngược lại, mọi cách hợp lệ đều có đúng một cặp `(diffLeft, diffRight)` thỏa mãn điều kiện trên, vì vậy không bỏ sót và cũng không đếm trùng.

---

## Độ phức tạp

Mỗi nửa sinh

\[
3^{n/2}
\]

trạng thái.

- Sinh nửa trái:

\[
O(3^{n/2})
\]

- Sinh nửa phải:

\[
O(3^{n/2})
\]

- Mỗi lần tra cứu `map`:

\[
O(\log 3^{n/2})
\]

Tổng độ phức tạp:

\[
O(3^{n/2}\log 3^{n/2})
\]

Bộ nhớ:

\[
O(3^{n/2})
\]

---

## Ý nghĩa các biến

| Biến | Ý nghĩa |
|------|----------|
| `diff` | Hiệu `B - A` của các quả cân |
| `cntLeft` | Lưu số cách tạo mỗi giá trị `diff` ở nửa trái |
| `cnt` | Tổng số cách cân hợp lệ |
| `genLeft()` | Sinh mọi trạng thái của nửa trái |
| `genRight()` | Sinh mọi trạng thái của nửa phải và ghép với nửa trái |