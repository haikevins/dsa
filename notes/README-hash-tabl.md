# Bảng băm (Hash Table)

Hash table là cấu trúc dữ liệu dùng để lưu dữ liệu theo dạng **key-value**.

Ví dụ:

```text
"An"   → 8.5
"Bình" → 7.0
"Chi"  → 9.0
```

Trong đó:

```text
key   = khóa dùng để tìm dữ liệu
value = giá trị được lưu tương ứng với key
```

Hash table thường hỗ trợ các thao tác **thêm**, **tìm kiếm** và **xóa** với độ phức tạp trung bình là **O(1)**, nếu hàm hash phân bố đều và số lượng bucket đủ lớn.

---

## Mục lục

- [1. Key](#1-key)
- [2. Value](#2-value)
- [3. Hash function](#3-hash-function)
- [4. Bucket](#4-bucket)
- [5. Collision](#5-collision)
    - [5.1. Separate chaining](#51-separate-chaining)
    - [5.2. Open addressing](#52-open-addressing)
- [6. Độ phức tạp](#6-độ-phức-tạp)
- [7. Lưu ý](#7-lưu-ý)
    - [7.1. Cùng một key phải luôn cho cùng một hash value](#71-Cùng-một-key-phải-luôn-cho-cùng-một-hash-value)
    - [7.2. Hai key giống nhau phải có hash giống nhau](#72-Hai-key-giống-nhau-phải-có-hash-giống-nhau)
    - [7.3. Hai key khác nhau có thể có hash giống nhau](#73-Hai-key-khác-nhau-có-thể-có-hash-giống-nhau)
    - [7.4. Hash function nên phân bố đều](#74-Hash-function-nên-phân-bố-đều)

---

## 1. Key

**Key** là khóa dùng để định danh dữ liệu.

Ví dụ:

```text
key   = "An"
value = 8.5
```

Muốn lấy điểm của An, ta tìm theo key `"An"`.

---

## 2. Value

**Value** là dữ liệu được lưu tương ứng với key.

Ví dụ:

```text
"An" → 8.5
```

Ở đây:

```text
"An" là key
8.5  là value
```

---

## 3. Hash function

**Hash function** là hàm nhận `key` làm đầu vào và tạo ra **hash value** hoặc **hash code**.

Ví dụ:

```text
hash("An") = 123456
```

Sau đó hash table dùng hash value để tính vị trí lưu trong bảng:

```text
index = hash(key) % số_bucket
```

Ví dụ:

```text
hash("An") = 123456
số_bucket  = 10
index      = 123456 % 10 = 6
```

Vậy cặp dữ liệu sau:

```text
"An" → 8.5
```

sẽ được lưu ở **bucket số 6**.

Cần phân biệt rõ:

| Khái niệm | Ý nghĩa |
|---|---|
| `key` | Dữ liệu đầu vào của hàm hash |
| `hash value` / `hash code` | Kết quả của hàm hash |
| `index` | Vị trí bucket sau khi lấy modulo |

Luồng xử lý:

```text
key → hash(key) → hash value → hash value % số_bucket → index
```

---

## 4. Bucket

**Bucket** là một ô hoặc một vị trí trong hash table.

Ví dụ hash table có 10 bucket:

```text
index:  0   1   2   3   4   5   6   7   8   9
data:                       An
```

Nếu:

```text
index = 6
```

thì dữ liệu được lưu tại:

```c
hashTable[6]
```

---

## 5. Collision

**Collision** là hiện tượng hai key khác nhau nhưng được đưa vào cùng một bucket.

Ví dụ:

```text
hash("An")  % 10 = 6
hash("Nam") % 10 = 6
```

Cả `"An"` và `"Nam"` đều rơi vào bucket số `6`. Đây gọi là **va chạm băm**.

Collision là điều bình thường trong hash table, vì số lượng key có thể rất lớn còn số bucket là hữu hạn.

---

## 5.1. Separate chaining

**Separate chaining** là cách xử lý collision bằng cách cho mỗi bucket chứa một **danh sách liên kết** các phần tử.

Ví dụ:

```text
bucket 6: ("An", 8.5) → ("Nam", 7.5) → NULL
```

Khi tìm `"Nam"`, hash table sẽ:

1. Tính index của `"Nam"`.
2. Đi tới bucket tương ứng.
3. Duyệt danh sách trong bucket đó.
4. So sánh key để tìm đúng phần tử.

Trong C, separate chaining thường được cài bằng linked list:

```c
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;
```

Ví dụ mỗi bucket là con trỏ đầu danh sách:

```c
Node* hashTable[TABLE_SIZE];
```

Khi thêm node mới vào đầu danh sách tại bucket `index`:

```c
node->next = hashTable[index];
hashTable[index] = node;
```

Ý nghĩa:

```text
node->next = hashTable[index];  // node mới trỏ tới danh sách cũ
hashTable[index] = node;        // cập nhật node mới thành đầu danh sách
```

Ví dụ trước khi thêm:

```text
hashTable[6] → A → B → NULL
```

Thêm node mới `C` vào đầu:

```text
hashTable[6] → C → A → B → NULL
```

---

## 5.2. Open addressing

**Open addressing** là cách xử lý collision không dùng linked list.

Nếu bucket cần lưu đã có dữ liệu, ta tìm bucket trống tiếp theo.

Ví dụ:

```text
hash("An") = 5
bucket 5 đã đầy
→ thử bucket 6
→ nếu bucket 6 đầy, thử bucket 7
```

Một số cách dò vị trí phổ biến:

| Phương pháp | Ý nghĩa |
|---|---|
| Linear probing | Kiểm tra lần lượt `index + 1`, `index + 2`, ... |
| Quadratic probing | Kiểm tra theo bước nhảy bình phương |
| Double hashing | Dùng thêm một hàm hash thứ hai |

Với open addressing, **load factor phải nhỏ hơn 1** vì mọi phần tử đều nằm trực tiếp trong mảng.

---

## 6. Độ phức tạp

Nếu hash function tốt, phân bố đều và load factor không quá lớn:

| Thao tác | Độ phức tạp trung bình |
|---|---|
| Thêm | O(1) |
| Tìm kiếm | O(1) |
| Xóa | O(1) |

Trường hợp xấu nhất:

```text
O(n)
```

Vì nếu nhiều key rơi vào cùng một bucket, ta có thể phải duyệt nhiều phần tử.

Ví dụ collision nặng:

```text
bucket 3: A → B → C → D → E → NULL
```

Nếu cần tìm `E`, ta có thể phải duyệt qua nhiều node.

---

## 7. Lưu ý

## 7.1. Cùng một key phải luôn cho cùng một hash value

Ví dụ:

```text
hash(7) phải luôn cho ra cùng một kết quả, không được lúc thì ra 123, lúc thì ra 999
```

Vì nếu không, lúc insert(7) nó lưu ở một bucket, nhưng lúc find(7) lại đi tìm ở bucket khác.

## 7.2 Hai key giống nhau phải có hash giống nhau

Ví dụ:

```text
key = 10
hash(10) = 1000
```

Lần nào gặp key 10 thì hash value cũng phải là 1000.

## 7.3 Hai key khác nhau có thể có hash giống nhau

Ví dụ:

```text
hash(10) = 5
hash(21) = 5
```

Chuyện này được phép xảy ra. Đó gọi là collision.

Hash table phải có cách xử lý collision, ví dụ code của bạn dùng linked list / separate chaining.

## 7.4. Hash function nên phân bố đều
Hash function tốt là hàm giúp key rơi đều vào các bucket.

Ví dụ không tốt:

```text
unsigned int hash(int key) {
    return 0;
}
```

Hàm này vẫn “đúng” về mặt chạy được, nhưng rất tệ vì mọi key đều rơi vào một bucket:

```text
hashTable[0] → node → node → node → node → ...
```

Khi đó hash table gần giống linked list, tìm kiếm có thể thành O(n).