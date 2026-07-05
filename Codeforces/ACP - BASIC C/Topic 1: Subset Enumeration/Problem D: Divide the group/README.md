# D. Chia nhóm

## Ý tưởng

Sử dụng thuật toán **Meet in the Middle (MITM)**.

- Chia `N` người thành hai nửa.
- Sinh tất cả tổng độ tin cậy của mỗi nửa bằng DFS (`2^(N/2)` trạng thái).
- Lưu số lần xuất hiện của từng tổng.
- Với mỗi tổng của nửa trái, dùng **binary search** trên các tổng của nửa phải để tìm tổng gần `total / 2` nhất.
- Tính độ chênh lệch `|total - 2 * chosenSum|` và cập nhật:
  - Độ chênh lệch nhỏ nhất.
  - Số cách đạt được độ chênh lệch đó.
- Mỗi cách phân chia được đếm hai lần (đổi hai nhóm cho nhau), vì vậy kết quả cuối cùng chia cho `2`.

## Độ phức tạp

- Sinh tập con: **O(2^(N/2))**
- Sắp xếp/Tìm kiếm: **O(2^(N/2) log 2^(N/2))**
- Bộ nhớ: **O(2^(N/2))**

Phù hợp với `N ≤ 32`.