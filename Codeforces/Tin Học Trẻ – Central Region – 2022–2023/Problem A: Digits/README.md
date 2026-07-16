# A. DIGITS

## Ý tưởng

Đề bài yêu cầu tìm **chữ số cuối cùng** của tổng các số Fibonacci từ vị trí `L` đến `R`. Vì chỉ quan tâm đến chữ số cuối nên mọi phép tính đều được thực hiện theo **modulo 10**.

Một tính chất quan trọng là dãy Fibonacci theo modulo 10 có **chu kỳ Pisano bằng 60**, tức là:

* `fib(i) % 10 = fib(i + 60) % 10`.

Do đó, chỉ cần tính trước 60 giá trị đầu tiên của dãy.

Tiền xử lý:

* `F[i]`: chữ số cuối của số Fibonacci thứ `i`.
* `pre[i]`: tổng các giá trị `F[1]` đến `F[i]` (lấy modulo 10).

Trong đó `pre[60]` là tổng của một chu kỳ.

Để tính tổng từ `fib(1)` đến `fib(x)`, chia dãy thành:

* `x / 60` chu kỳ đầy đủ.
* `x % 60` phần tử còn lại.

Khi đó:

[
S(x)=\left(\frac{x}{60}\times pre[60]+pre[x\bmod60]\right)\bmod10
]

Tổng cần tìm được tính theo công thức:

[
fib(L)+fib(L+1)+\cdots+fib(R)=S(R)-S(L-1)
]

Sau khi lấy modulo 10 ta thu được chữ số cuối cùng của đáp án.

## Thuật toán

1. Đọc `a`, `b`, `L`, `R`.
2. Sinh 60 số Fibonacci đầu tiên theo modulo 10.
3. Tính mảng tổng tiền tố `pre`.
4. Xây dựng hàm `sum(x)` tính tổng từ `fib(1)` đến `fib(x)` theo công thức chu kỳ.
5. Kết quả là `(sum(R) - sum(L - 1) + 10) % 10`.

## Độ phức tạp

* Tiền xử lý: **O(60)**.
* Tính kết quả mỗi test: **O(1)**.

Vì 60 là hằng số nên tổng độ phức tạp là **O(T)**, với `T ≤ 100`.
