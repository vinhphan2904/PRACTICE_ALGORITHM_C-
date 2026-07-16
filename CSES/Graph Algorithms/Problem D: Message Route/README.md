# Message Route (CSES)

## Ý tưởng

Đồ thị là **vô hướng, không trọng số**, cần tìm đường đi từ đỉnh `1` đến đỉnh `n` sao cho số lượng đỉnh (hay số cạnh) trên đường đi là nhỏ nhất.

Với đồ thị không trọng số, **BFS** luôn tìm được đường đi ngắn nhất từ một đỉnh nguồn đến tất cả các đỉnh còn lại.

---

## Thuật toán

1. Đọc đồ thị dưới dạng danh sách kề.
2. Thực hiện BFS từ đỉnh `1`.
3. Khi thăm một đỉnh mới:
   - Đánh dấu `visited`.
   - Lưu đỉnh cha (`parent`) của nó.
4. Sau khi BFS kết thúc:
   - Nếu đỉnh `n` chưa được thăm thì in `IMPOSSIBLE`.
   - Ngược lại, truy vết từ `n` về `1` bằng mảng `parent`.
   - Đảo ngược dãy thu được để có đường đi đúng chiều.

---

## Truy vết đường đi

Trong BFS:

```cpp
parent[v] = u;
```

nghĩa là:

- `u` là đỉnh được duyệt trước.
- `v` được khám phá từ `u`.

Sau khi BFS kết thúc:

```
n
↑
parent
↑
...
↑
parent
↑
1
```

Đi ngược theo `parent` cho đến `-1`, sau đó đảo ngược kết quả là thu được đường đi từ `1` đến `n`.

---

## Độ đúng

- BFS duyệt các đỉnh theo khoảng cách tăng dần từ đỉnh nguồn.
- Lần đầu tiên một đỉnh được thăm chính là khoảng cách ngắn nhất đến đỉnh đó.
- Vì `parent` được lưu ngay khi đỉnh được khám phá nên truy vết sẽ thu được một đường đi ngắn nhất.

Do đó, nếu tồn tại đường đi từ `1` đến `n`, thuật toán luôn trả về một đường đi ngắn nhất.

---

## Độ phức tạp

- **Time:** `O(n + m)`
- **Memory:** `O(n + m)`

Mỗi đỉnh được đưa vào hàng đợi nhiều nhất một lần và mỗi cạnh chỉ được xét tối đa hai lần.

---

## Kiến thức sử dụng

- BFS
- Shortest Path trên đồ thị không trọng số
- Path Reconstruction
- Queue
- Danh sách kề (Adjacency List)

---

## Lưu ý

- Không nên dùng DFS vì DFS **không đảm bảo** tìm được đường đi ngắn nhất.
- Có thể dừng BFS ngay khi lấy được đỉnh `n` ra khỏi hàng đợi (hoặc ngay khi phát hiện `n`) để tiết kiệm thời gian, tuy nhiên vẫn giữ nguyên độ phức tạp `O(n + m)`.
- Đường đi được truy vết bằng mảng `parent`, không cần lưu toàn bộ đường đi trong quá trình BFS.

---

## Bài học rút ra

Đây là bài cơ bản về **Shortest Path trên đồ thị không trọng số**.

Qua bài này cần nắm được:

- Khi nào sử dụng BFS thay vì DFS.
- Cách lưu mảng `parent` để truy vết đường đi.
- Kỹ thuật Path Reconstruction trên đồ thị.
- BFS là nền tảng cho nhiều bài nâng cao như:
  - Labyrinth
  - Monsters
  - Flight Routes Check (kết hợp thuật toán khác)
  - Các bài shortest path trên đồ thị không trọng số.