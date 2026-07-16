# Counting Rooms (CSES)

## Ý tưởng

Mỗi ô `.` được xem là một đỉnh của đồ thị, hai ô kề nhau theo 4 hướng (lên, xuống, trái, phải) sẽ có một cạnh nối.

Một **room** chính là một **thành phần liên thông** của các ô `.`.

Ta duyệt toàn bộ ma trận:

- Nếu gặp một ô `.` chưa được thăm:
  - Tăng số lượng phòng lên 1.
  - Thực hiện BFS (hoặc DFS) từ ô đó để đánh dấu toàn bộ các ô trong cùng phòng.

Sau khi BFS kết thúc, tất cả các ô của phòng đó đã được đánh dấu nên sẽ không bị đếm lại.

---

## Thuật toán

1. Đọc ma trận.
2. Khởi tạo mảng `visited`.
3. Duyệt từng ô trong ma trận.
4. Nếu ô hiện tại là `.` và chưa được thăm:
   - `cnt++`
   - Gọi BFS/DFS.
5. In `cnt`.

---

## Độ đúng

- BFS bắt đầu từ một ô sẽ đi đến tất cả các ô có thể đi được trong cùng phòng.
- Mỗi phòng chỉ được BFS đúng một lần.
- Mọi phòng đều sẽ được duyệt khi quét toàn bộ ma trận.

Vì vậy số lần gọi BFS chính là số lượng phòng.

---

## Độ phức tạp

- **Time:** `O(n × m)`
- **Memory:** `O(n × m)`

Với `n, m ≤ 1000`, thuật toán đáp ứng tốt giới hạn đề bài.

---

## Kiến thức sử dụng

- BFS trên ma trận
- DFS trên ma trận (có thể thay thế BFS)
- Flood Fill
- Connected Components trên Grid
- Duyệt 4 hướng

---

## Lưu ý

- Không cần xây dựng đồ thị, mỗi ô của ma trận được xem là một đỉnh.
- Nên dùng **BFS** thay vì DFS đệ quy vì ma trận có thể có tới `10^6` ô, DFS đệ quy dễ gây tràn ngăn xếp (Stack Overflow).
- Có thể sử dụng hai mảng hướng để duyệt các ô kề:

```cpp
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
```

---

## Bài học rút ra

Đây là bài cơ bản nhất về **Connected Components trên Grid**.

Ý tưởng "duyệt toàn bộ lưới, gặp ô chưa thăm thì BFS/DFS" sẽ xuất hiện rất nhiều trong các bài như:

- Labyrinth
- Monsters
- Number of Islands
- Flood Fill
- Multi-source BFS
- Các bài đếm vùng liên thông trên ma trận