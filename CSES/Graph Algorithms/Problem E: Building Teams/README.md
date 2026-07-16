# CSES - Building Teams

## Ý tưởng

Ta cần chia các đỉnh thành **2 nhóm** sao cho hai đỉnh có cạnh nối không nằm trong cùng một nhóm.

Đây chính là bài toán kiểm tra **đồ thị hai phía (Bipartite Graph)**.

Ta dùng **BFS tô màu**:

- `color = 0`: chưa được tô.
- `color = 1`: đội 1.
- `color = 2`: đội 2.

Với mỗi thành phần liên thông:

- Chọn một đỉnh bất kỳ và gán `color = 1`.
- BFS từ đỉnh đó.
- Với mỗi cạnh `(u, v)`:
    - Nếu `v` chưa được thăm:
        - Gán `color[v] = 3 - color[u]`.
        - Đưa `v` vào hàng đợi.
    - Nếu `v` đã được thăm:
        - Nếu `color[v] == color[u]` thì tồn tại hai đỉnh kề nhau cùng màu.
        - Không thể chia thành hai đội → in `IMPOSSIBLE`.

Sau khi BFS hết tất cả các thành phần liên thông:

- Nếu không phát hiện xung đột thì mảng `color` chính là đáp án.

## Tại sao đúng?

Trong đồ thị hai phía, mọi cạnh luôn nối hai đỉnh thuộc hai tập khác nhau.

Thuật toán BFS luôn gán cho mỗi đỉnh kề màu đối lập với đỉnh hiện tại.

Nếu trong quá trình duyệt xuất hiện một cạnh nối hai đỉnh cùng màu thì tồn tại chu trình lẻ, đồ thị không còn là đồ thị hai phía, do đó không tồn tại cách chia đội.

Ngược lại, nếu BFS kết thúc mà không xảy ra xung đột thì mọi cạnh đều nối hai đỉnh khác màu, nên cách tô màu thu được chính là một cách chia đội hợp lệ.

## Độ phức tạp

- Thời gian: **O(n + m)**
- Bộ nhớ: **O(n + m)**

## Kiến thức sử dụng

- BFS
- Danh sách kề (Adjacency List)
- Đồ thị hai phía (Bipartite Graph)
- Tô màu đồ thị (Graph Coloring)