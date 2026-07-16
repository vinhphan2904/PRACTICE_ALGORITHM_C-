# Labyrinth (CSES)

## Ý tưởng

Bài toán yêu cầu tìm **đường đi ngắn nhất** từ ô `A` đến ô `B` trên ma trận, chỉ được di chuyển theo 4 hướng:

- Lên (`U`)
- Phải (`R`)
- Xuống (`D`)
- Trái (`L`)

Vì mỗi bước di chuyển đều có cùng trọng số (1), **BFS** là thuật toán phù hợp để tìm đường đi ngắn nhất.

---

## Thuật toán

1. Đọc ma trận và xác định vị trí của `A`.
2. Thực hiện BFS từ `A`.
3. Với mỗi ô mới được thăm:
   - Đánh dấu `visited`.
   - Lưu ô cha (`parent`).
   - Lưu hướng đã đi từ cha đến ô hiện tại (`path`).
4. Nếu BFS đến được `B`:
   - Truy vết ngược từ `B` về `A` bằng mảng `parent`.
   - Lấy các ký tự trong `path`.
   - Đảo ngược chuỗi để thu được đường đi từ `A` đến `B`.
5. Nếu BFS kết thúc mà không gặp `B`, in `NO`.

---

## Truy vết đường đi

Khi từ ô `(x, y)` di chuyển sang ô `(nx, ny)`:

```cpp
parent[nx][ny] = {x, y};
path[nx][ny] = direction;
```

Trong đó:

- `parent` lưu ô trước đó.
- `path` lưu hướng đã đi từ `parent` đến ô hiện tại.

Sau khi tìm được `B`, lần lượt đi ngược theo `parent` về `A`, lấy các ký tự trong `path`, sau đó đảo ngược để thu được đáp án.

---

## Độ đúng

- BFS luôn duyệt các ô theo khoảng cách tăng dần từ điểm xuất phát.
- Lần đầu tiên gặp `B` chính là đường đi ngắn nhất.
- Mỗi ô chỉ được thăm một lần nên không bỏ sót hoặc xét lặp.

Vì vậy thuật toán luôn tìm được đường đi ngắn nhất nếu tồn tại.

---

## Độ phức tạp

- **Time:** `O(n × m)`
- **Memory:** `O(n × m)`

Mỗi ô được đưa vào hàng đợi nhiều nhất một lần.

---

## Kiến thức sử dụng

- BFS trên ma trận
- Shortest Path trên đồ thị không trọng số
- Truy vết đường đi (Path Reconstruction)
- Queue
- Duyệt 4 hướng

---

## Lưu ý

- Không nên dùng DFS vì DFS **không đảm bảo** tìm được đường đi ngắn nhất.
- Dùng hai mảng hướng để duyệt các ô lân cận:

```cpp
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char dir[4] = {'U', 'R', 'D', 'L'};
```

- Chỉ lưu một `parent` cho mỗi ô vì BFS chỉ thăm mỗi ô một lần.

---

## Bài học rút ra

Đây là bài cơ bản về **Shortest Path trên Grid bằng BFS**.

Qua bài này cần nắm được:

- Khi nào dùng BFS để tìm đường đi ngắn nhất.
- Cách lưu `parent` để truy vết đường đi.
- Cách lưu hướng di chuyển (`U`, `R`, `D`, `L`) trong quá trình BFS.
- Kỹ thuật Path Reconstruction sẽ tiếp tục xuất hiện ở nhiều bài như:
  - Monsters
  - Message Route
  - Building Roads (truy vết biến thể)
  - Các bài Shortest Path trên đồ thị không trọng số.