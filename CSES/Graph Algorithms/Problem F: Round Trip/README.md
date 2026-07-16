# CSES - Round Trip

## Ý tưởng

Ta cần tìm **một chu trình** trong đồ thị vô hướng.

Sử dụng DFS kết hợp với mảng `parent[]` để lưu cha của mỗi đỉnh trong cây DFS.

Trong quá trình DFS từ đỉnh `u`:

- Nếu gặp một đỉnh `v` chưa được thăm:
  - Gán `parent[v] = u`.
  - Tiếp tục DFS từ `v`.
- Nếu gặp một đỉnh `v` đã được thăm và `v` **không phải cha của `u`**, ta đã phát hiện một chu trình.

Lúc này:

- `v` là đỉnh bắt đầu của chu trình.
- `u` là đỉnh hiện tại.

Để khôi phục chu trình:

- Bắt đầu từ `u`, lần lượt đi ngược theo `parent[]` cho đến khi gặp `v`.
- Thêm `v` vào đầu và cuối của dãy để hoàn thành chu trình.
- Đảo ngược dãy để thu được thứ tự đi từ điểm bắt đầu quay trở lại chính nó.

Nếu DFS trên tất cả các thành phần liên thông mà không phát hiện chu trình thì in:

```
IMPOSSIBLE
```

---

## Tại sao đúng?

Trong DFS của đồ thị vô hướng:

- Mỗi cạnh chỉ thuộc một trong hai loại:
  - Cạnh của cây DFS (tree edge).
  - Cạnh ngược (back edge).

Nếu từ đỉnh `u` gặp một đỉnh `v` đã được thăm và `v` không phải cha của `u`, thì `v` là một tổ tiên của `u` trong cây DFS.

Khi đó:

- Đường đi từ `v` đến `u` trong cây DFS.
- Cạnh `(u, v)`.

Ghép lại sẽ tạo thành đúng một chu trình của đồ thị.

Nếu không tồn tại cạnh ngược nào thì đồ thị không chứa chu trình.

---

## Độ phức tạp

- Thời gian: **O(n + m)**
- Bộ nhớ: **O(n + m)**

---

## Kiến thức sử dụng

- DFS
- Đồ thị vô hướng
- Phát hiện chu trình
- Mảng `parent[]`
- Khôi phục đường đi (Path Reconstruction)