# I. Xếp hàng mua vé (Queue for Tickets)

## Ý tưởng

Mỗi người cần mua **1 vé**, nhưng người bán cho phép **một người mua tối đa 2 vé**.

Điều này có nghĩa là:

- Người `i` có thể tự mua vé của mình với thời gian `t[i]`.
- Hoặc người `i` mua luôn vé cho người `i+1` với thời gian `r[i]`.

Ta cần tìm cách chia cả hàng thành các nhóm gồm:

- **1 người** (tự mua)
- **2 người liên tiếp** (người đầu mua cho cả hai)

để **tổng thời gian nhỏ nhất**.

---

## Quy hoạch động (Dynamic Programming)

### Trạng thái

`dp[i]` = thời gian nhỏ nhất để phục vụ **i người đầu tiên**.

---

### Khởi tạo

```cpp
dp[0] = 0;
dp[1] = t[1];
```

- Chưa có ai ⇒ mất 0 thời gian.
- Chỉ có người đầu tiên ⇒ bắt buộc tự mua.

---

### Chuyển trạng thái

Có hai cách để hoàn thành người thứ `i`.

### Trường hợp 1

Người `i` tự mua vé.

Khi đó:

```
dp[i] = dp[i-1] + t[i]
```

---

### Trường hợp 2

Người `i-1` mua luôn vé cho người `i`.

Khi đó hai người cuối tạo thành một nhóm.

```
dp[i] = dp[i-2] + r[i-1]
```

---

Lấy nhỏ nhất:

```cpp
dp[i] = min(dp[i-1] + t[i],
            dp[i-2] + r[i-1]);
```

---

## Minh họa

```
Người:

1 2 3 4 5
```

Ví dụ tối ưu:

```
1 mua cho 1,2
3 tự mua
4 mua cho 4,5
```

Thời gian:

```
r1 + t3 + r4
```

---

## Tại sao đúng?

Để phục vụ xong `i` người đầu tiên, người cuối cùng chỉ có hai khả năng:

- tự mua;
- hoặc được người đứng ngay trước mua hộ.

Không tồn tại cách thứ ba vì:

- chỉ được mua tối đa 2 vé;
- chỉ được nhờ người đứng trước.

Do đó mọi phương án tối ưu đều được xét.

---

## Độ phức tạp

Có `N` trạng thái.

Mỗi trạng thái tính trong `O(1)`.

- **Thời gian:** `O(N)`
- **Bộ nhớ:** `O(N)`

Có thể tối ưu xuống `O(1)` bộ nhớ vì mỗi trạng thái chỉ phụ thuộc vào hai trạng thái trước.

---

## Code

```cpp
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int t[n + 1], r[n];

    for (int i = 1; i <= n; i++)
        cin >> t[i];

    for (int i = 1; i < n; i++)
        cin >> r[i];

    int dp[n + 1];

    dp[0] = 0;
    dp[1] = t[1];

    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1] + t[i],
                    dp[i - 2] + r[i - 1]);
    }

    cout << dp[n];
}
```