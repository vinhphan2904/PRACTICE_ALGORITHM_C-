# Building Roads (CSES)

## Ý tưởng

Mỗi thành phần liên thông (Connected Component) của đồ thị đã có thể đi đến mọi đỉnh bên trong nó.

Giả sử đồ thị có `k` thành phần liên thông.

Để toàn bộ đồ thị trở thành liên thông, chỉ cần xây thêm:

```
k - 1
```

cạnh.

Ta chỉ cần chọn một đỉnh đại diện của mỗi thành phần rồi nối các đại diện đó lại.

---

## Thuật toán

1. Đọc đồ thị.
2. Duyệt tất cả các đỉnh.
3. Nếu gặp một đỉnh chưa được thăm:
   - Đây là một thành phần liên thông mới.
   - Thực hiện DFS/BFS để duyệt toàn bộ thành phần.
   - Lưu lại một đỉnh đại diện của thành phần.
4. Sau khi tìm được tất cả các thành phần:
   - Nếu có `k` thành phần thì nối:
     - đại diện 1 với đại diện 2
     - đại diện 2 với đại diện 3
     - ...
     - đại diện `k-1` với đại diện `k`

Số cạnh cần xây là `k - 1`.

---

## Ý tưởng trong code

Trong lời giải này:

- DFS được dùng để tìm từng thành phần liên thông.
- Sau khi DFS của một thành phần kết thúc, đỉnh trên cùng của stack được dùng làm đại diện.
- Khi phát hiện thành phần mới, nối đại diện của thành phần trước với đỉnh đầu tiên của thành phần hiện tại.

Nhờ đó thu được đúng `k - 1` cạnh cần xây.

---

## Độ đúng

Giả sử đồ thị có `k` thành phần liên thông.

- Mỗi cạnh mới được thêm sẽ nối hai thành phần khác nhau.
- Sau mỗi lần nối, số thành phần liên thông giảm đi 1.
- Sau `k - 1` lần nối, chỉ còn một thành phần liên thông.

Đây cũng là số cạnh nhỏ nhất có thể, vì mỗi cạnh mới chỉ có thể giảm số thành phần nhiều nhất một.

---

## Độ phức tạp

- **Time:** `O(n + m)`
- **Memory:** `O(n + m)`

Mỗi đỉnh và mỗi cạnh chỉ được DFS duyệt đúng một lần.

---

## Kiến thức sử dụng

- DFS
- BFS
- Connected Components
- Đồ thị vô hướng
- Biểu diễn bằng danh sách kề

---

## Lưu ý

Có một cách cài đặt đơn giản hơn là lưu trực tiếp một đỉnh đại diện của mỗi thành phần:

```cpp
vector<int> representative;

for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
        representative.push_back(i);
        DFS(i);
    }
}
```

Sau đó nối:

```cpp
for (int i = 1; i < representative.size(); i++)
    cout << representative[i - 1] << " " << representative[i] << '\n';
```

Cách này ngắn gọn và dễ hiểu hơn việc dùng `stack`.

---

## Bài học rút ra

Đây là bài cơ bản về **Connected Components trên đồ thị vô hướng**.

Qua bài này cần nắm được:

- Tìm thành phần liên thông bằng DFS/BFS.
- Đếm số thành phần liên thông.
- Chứng minh cần tối thiểu `k - 1` cạnh để nối `k` thành phần.
- Chọn một đỉnh đại diện cho mỗi thành phần để xây các cạnh mới.

Ý tưởng này sẽ còn được sử dụng trong nhiều bài về kết nối đồ thị và Union-Find (DSU).