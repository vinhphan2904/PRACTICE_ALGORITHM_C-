# F. Dãy con tăng W (W-Increasing Subsequence)

## Ý tưởng

Với `n ≤ 40`, không thể duyệt tất cả `2^40` tập con. Ta sử dụng kỹ thuật **Meet in the Middle (MITM)** để chia bài toán thành hai nửa.

Chia mảng thành:

* Nửa trái: `1 → n/2`
* Nửa phải: `n/2 + 1 → n`

Sau đó sinh tất cả các dãy con tăng của từng nửa và ghép kết quả lại.

---

## Quan sát

Một dãy con tăng hoàn chỉnh gồm:

* một dãy tăng ở nửa trái;
* một dãy tăng ở nửa phải.

Hai dãy này chỉ ghép được nếu:

* phần tử cuối của nửa trái nhỏ hơn phần tử đầu của nửa phải;
* tổng trọng số của hai dãy không vượt quá `W`.

---

## Lưu thông tin nửa trái

Sinh tất cả các dãy con tăng của nửa trái bằng quay lui.

Với mỗi dãy thu được:

* lưu tổng các phần tử;
* lưu theo **vị trí kết thúc** của dãy.

```text
vector<long long> v[i]
```

`v[i]` chứa tất cả tổng của các dãy con tăng có phần tử cuối cùng ở vị trí `i`.

Ngoài ra:

* `v[0]` lưu dãy rỗng (tổng bằng `0`).

Sau khi sinh xong, sắp xếp từng `v[i]` để có thể tìm kiếm nhị phân.

---

## Sinh nửa phải

Tiếp tục quay lui để sinh mọi dãy con tăng của nửa phải.

Đối với mỗi dãy:

* biết tổng hiện tại `sum`;
* biết vị trí phần tử đầu tiên (`start`).

Duyệt mọi vị trí kết thúc của nửa trái.

Nếu

```text
a[end] < a[start]
```

thì hai dãy có thể ghép thành một dãy tăng.

Lúc này chỉ cần đếm trong `v[end]` có bao nhiêu tổng thỏa

```text
leftSum ≤ W − sum
```

---

## Binary Search

Do mỗi `v[i]` đã được sắp xếp, số lượng tổng không vượt quá `W - sum` được tính nhanh bằng:

```cpp
upper_bound(v[i].begin(), v[i].end(), W - sum) - v[i].begin();
```

`upper_bound()` trả về iterator tới phần tử đầu tiên lớn hơn `W - sum`.

Khoảng cách từ `begin()` tới iterator chính là số lượng phần tử hợp lệ.

Nhờ đó mỗi lần ghép chỉ mất `O(log M)`.

---

## Độ phức tạp

Giả sử mỗi nửa có khoảng `20` phần tử.

* Sinh nửa trái: `O(2^(n/2))`
* Sinh nửa phải: `O(2^(n/2))`
* Mỗi lần ghép dùng `upper_bound`: `O(log(2^(n/2)))`

Độ phức tạp tổng quát:

```text
O(2^(n/2) · log(2^(n/2)))
```

với bộ nhớ:

```text
O(2^(n/2))
```

Thuật toán đáp ứng tốt giới hạn `n ≤ 40`.

---

## Kiến thức sử dụng

* Meet in the Middle (MITM)
* Backtracking (Quay lui)
* Binary Search (`upper_bound`)
* Vector
* Sắp xếp (`sort`)
