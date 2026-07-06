# CSES - Removing Digits | Loại bỏ chữ số

## Ý tưởng

Sử dụng Quy hoạch động (Dynamic Programming).

Gọi `dp[i]` là số bước ít nhất để biến `i` thành `0`.

Với mỗi số `i`, ta xét từng chữ số của nó. Nếu chữ số là `d > 0`, ta có thể chuyển từ `i` sang `i - d`.

Do đó:
