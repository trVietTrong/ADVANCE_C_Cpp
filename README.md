# Advance_C_Cpp
## Contents

<details>
<summary>LESSON 1: COMPILER - MACRO</summary>

---

### **I. Compiler**
- Compiler là quá trình chuyển đổi ngôn ngữ bậc cao sang ngôn ngữ máy.
- Gồm 4 giai đoạn chính:
  
  ![Compiler stages](compiler1..jpg)

#### **1. Preprocessor (Tiền xử lý)** 
Command: `gcc -E main.c -o main.i`

- Các file trong source code (ví dụ: `a.c`, `a.h`, `b.h`, `b.c`, `main.c`,…) sẽ được hợp nhất thành một file duy nhất: `main.i`.
- Giai đoạn này thực hiện:
  - Copy toàn bộ nội dung của các file thư viện (`#include <stdio.h>`, `#include "hello.h"`,…).
  - Thay thế các nội dung được định nghĩa bởi `#define`.
  - Xóa toàn bộ chú thích, giữ lại khai báo biến và hàm.

#### **2. Compiler**
- File `main.i` được biên dịch thành file `main.s` (ngôn ngữ assembly).
  

#### **3. Assembler**
- Biên dịch mã assembly trong file `main.s` thành ngôn ngữ máy, tạo file đối tượng: `main.o`.

#### **4. Linker**
- Liên kết một hoặc nhiều file `.o` thành file thực thi (`.exe`).

---

## II. MACRO  
### 1. Định nghĩa  

Trong ngôn ngữ lập trình C, **macro** là một cơ chế giúp định nghĩa một khối mã nguồn có thể tái sử dụng nhiều lần trong chương trình. Macro được khai báo bằng chỉ thị `#define`. Khi biên dịch, trình tiền xử lý sẽ thay thế các macro bằng nội dung mà chúng định nghĩa trước khi mã nguồn được biên dịch.

Macro trong C bao gồm:  
1. **Chỉ thị bao hàm tệp** (`#include`)  
2. **Chỉ thị định nghĩa** (`#define`)  
3. **Chỉ thị biên dịch có điều kiện** (`#ifdef`, `#ifndef`, ...)  

---

### 1. Chỉ thị bao hàm tệp  

Trong C, chỉ thị bao hàm tệp (`#include`) được sử dụng để đưa nội dung của một tệp header vào chương trình trước khi biên dịch.

#### 1.1 Bao hàm tệp header bằng `<>`  

Khi sử dụng `#include <header.h>`, trình biên dịch sẽ tìm kiếm tệp header trong các thư mục hệ thống chuẩn.  
Ví dụ:  
```c
#include <stdio.h>
#include <math.h>
```
#### 1.2 Bao hàm tệp header bằng `""`
Khi sử dụng #include "header.h", trình biên dịch sẽ tìm kiếm tệp header trong cùng thư mục với tệp mã nguồn hiện tại trước khi tìm trong các thư mục khác.
Điều này thường áp dụng cho các tệp header do người dùng tự tạo.
Vis dụ:
```c
#include"myheader.h"
#include"Hello.hh"
```

### 2. Chỉ thị định nghĩa macro  

Chỉ thị `#define` trong ngôn ngữ lập trình C có thể được sử dụng để định nghĩa nhiều loại giá trị và cấu trúc khác nhau. 

Khi sử dụng chỉ thị `#define` để định nghĩa một macro, tất cả các chỗ trong mã nguồn sử dụng macro đó sẽ được thay thế trong quá trình tiền xử lý bằng nội dung mà chúng ta đã định nghĩa.

#### 2.1 Định nghĩa hằng số  

Macro thường được sử dụng để định nghĩa các giá trị hằng.
Ví dụ:  
```c
#define PI 3.14159
#define MAX_SIZE 100
```
#### 2.2 Định nghĩa chuỗi
Macro cũng có thể định nghĩa một chuỗi để có thể sử dụng nhiều lần trong chương trình.
Ví dụ:
```c
#define HELLO "Hello World"
#define MYNAME "Viet Trong"
```
#### 2.3 Định nghĩa một hàm
Macro cũng có thể định nghĩa một hàm.
Chú ý dùng dấu `\` khi để nối các đoạn mã trong macro nhiều dòng.
```c
#define FUNC(name, cmd) \
void name(){            \
    printf("cmd");      \
}

FUNC(Test11, "My name is Trong");
```
#### 2.4 Chỉ thị hủy định nghĩa một macro  

Nếu muốn hủy bỏ hoặc loại bỏ định nghĩa của một macro trong mã nguồn, bạn có thể dùng chỉ thị `#undef`.  

Ví dụ:  
```c
#include <stdio.h>

#define PI 3.14159  // Định nghĩa macro PI

int main() {
    printf("Giá trị của PI: %.2f\n", PI);  // Sử dụng macro PI
    #undef PI  // Hủy định nghĩa macro PI
    #define PI 55  // Định nghĩa lại macro PI
    printf("Giá trị hiện tại là: %.2f\n", PI);  // PI hiện tại bằng 55
    return 0;
}
```
Output:

```c
Giá trị của PI: 3.14
Giá trị hiện tại là: 55.00
```






### 3. Chỉ thị biên dịch có điều kiện
#### 3.1 `#if`, `#elif`, `#else`, `#endif` 

**`#if`** được sử dụng để bắt đầu một điều kiện tiền xử lý.  
- Nếu điều kiện trong `#if` là đúng, các dòng mã nguồn sau `#if` sẽ được biên dịch.  
- Nếu điều kiện sai, sẽ xét các điều kiện tiếp theo **`#elif`** tiếp theo nếu cócó.

**`#elif`** được sử dụng để thêm một điều kiện mới khi điều kiện trước đó trong `#if` hoặc `#elif` là sai.  
- Nếu điều kiện trong `#elif` là đúng, các dòng mã nguồn sau `#elif` sẽ được biên dịch.  
- Nếu điều kiện sai, quá trình kiểm tra sẽ tiếp tục đến các chỉ thị `#elif` hoặc `#else` tiếp theo.

**`#else`** dùng khi không có điều kiện nào ở trên đúng.  

**`#endif`** dùng để kết thúc.
Ví dụ:
```c
#include <stdio.h>

#define ESP32 1
#define STM32 2
#define ATmega 3

#define MCU STM32

int main(int argc, char const *argv[])
{
    while (1)
    {
        #if MCU == STM32
            printf("STM32");
        #elif MCU == ESP32
            printf("ESP32");
        #else 
            printf("0");
        #endif
    }
    return 0;
}
``` 
#### 3.2 `#ifef` và `#ifndef`.

 **`#ifdef`**
   - Dùng để kiểm tra xem một macro đã được định nghĩa hay chưa.
   - Nếu macro đã được định nghĩa trước đó, mã nguồn sau chỉ thị `#ifdef` sẽ được biên dịch.
   - Thường được sử dụng khi bạn muốn mã nguồn chỉ được biên dịch khi một macro đã được định nghĩa.

**`#ifndef`** (If Not Defined):
   - Dùng để kiểm tra xem một macro có **chưa** được định nghĩa.
   - Nếu macro chưa được định nghĩa trước đó, mã nguồn sau chỉ thị `#ifndef` sẽ được biên dịch.
   - Thường được sử dụng khi muốn tránh việc định nghĩa lại một macro, ví dụ như trong các file header.


**Ví dụ với `#ifdef`:**
```c
#include <stdio.h>

#define DEBUG

int main() {
    #ifdef DEBUG
        printf("Debug mode is enabled.\n");
    #endif

    return 0;
}
```
###### Giải thích:
- Ở đây, macro **DEBUG** được định nghĩa trước.
-  Chỉ thị **#ifdef DEBUG** kiểm tra xem macro **DEBUG** đã được định nghĩa chưa. Vì đã được định nghĩa, 
  phần mã trong khối **#ifdef** sẽ được biên dịch và in ra "Debug mode is enabled."


**Ví dụ với `#ifnndef`:**

**File `config.h`**.

```c
#ifndef CONFIG_H  // Kiểm tra xem CONFIG_H đã được định nghĩa chưa
#define CONFIG_H  // Định nghĩa CONFIG_H nếu chưa được định nghĩa

// Nội dung của file header
void print_message();

#endif  // Kết thúc chỉ thị 

```

**File `main.c`**.

```c
#include <stdio.h>
#include "config.h"  // Bao gồm file header config.h

void print_message() {
    printf("Hello World.\n");
}

int main() {
    print_message();  // Gọi hàm từ config.h
    return 0;
}

```

##### Giải thích:
- Chỉ thị **#ifndef CONFIG_H:** Kiểm tra xem macro **CONFIG_H** đã được định nghĩa chưa.
  - Nếu **CONFIG_H** chưa được định nghĩa, mã trong khối **#ifndef** sẽ được biên dịch, và macro **CONFIG_H** sẽ được
 định nghĩa.
  - Nếu **CONFIG_H** đã được định nghĩa rồi (ví dụ: trong các lần bao gồm file header khác), mã trong khối **#ifndef** sẽ không được biên dịch nữa, ngăn chặn việc định nghĩa lại macro và các hàm trong file header này.

**Tại sao sử dụng #ifndef:**
Tránh định nghĩa lại: Nếu file header config.h được bao gồm nhiều lần trong các file khác nhau, chỉ thị #ifndef giúp đảm bảo rằng nội dung trong file này chỉ được biên dịch một lần, tránh tình trạng lỗi khi macro và hàm bị định nghĩa lại.



#### 3.3 Phân biệt chỉ thị biên dịch có điều kiện và câu lệnh có điều kiện.
| **Tiêu chí**                | **Chỉ thị biên dịch có điều kiện**            | **Câu lệnh điều kiện**                     |
|-----------------------------|----------------------------------------------|-------------------------------------------|
| **Thời điểm xử lý**          | **Trước khi biên dịch** (tiền xử lý)         | **Khi chương trình chạy** (runtime)       |
| **Mục đích**                 | Quyết định phần mã nào sẽ được biên dịch    | Quyết định phần mã nào sẽ được thực thi   |
| **Câu lệnh**                 | `#if`, `#ifdef`, `#ifndef`, `#else`, `#endif` | `if`, `else if`, `else`                   |
| **Điều kiện**                | Biểu thức phải là hằng số xác định trước khi biên dịch | Điều kiện có thể là bất kỳ biểu thức nào có giá trị tại runtime |


#### 4.Variadic Macro trong C
Variadic macros là một tính năng trong ngôn ngữ lập trình C cho phép bạn định nghĩa một macro với số lượng tham số thay đổi. Điều này có nghĩa là số lượng tham số truyền vào macro có thể thay đổi mỗi khi bạn sử dụng macro đó.

**Cách định nghĩa Variadic Macro:**
Để định nghĩa một variadic macro, bạn sử dụng ba dấu chấm ... trong định nghĩa của macro, thay cho số lượng tham số cụ thể. Bên trong macro, bạn có thể sử dụng __VA_ARGS__ để đại diện cho các tham số được truyền vào.

**Cách sử dụng Variadic Macro:**
**...:** Được dùng để chỉ ra rằng macro có thể nhận một số lượng tham số thay đổi.
__VA_ARGS__: Dùng để truy cập tất cả các tham số được truyền vào trong macro.

</details>

<details>
<summary>LESSON 2: STDARG - ASSERT</summary>

## 1.Thư viện `stdarg.h`

Thư viện `stdarg.h` trong ngôn ngữ lập trình C cung cấp các công cụ để làm việc với các hàm có số lượng đối số biến đổi. Thư viện này bao gồm một số cấu trúc và hàm quan trọng sau:

- **`va_list`**: Đây là kiểu dữ liệu dùng để lưu trữ các tham số biến đổi trong một hàm.
- **`va_start`**: Hàm này được sử dụng để khởi tạo `va_list` và thiết lập con trỏ đến tham số đầu tiên trong danh sách tham số biến đổi.
- **`va_arg`**: Hàm này được dùng để truy xuất các tham số tiếp theo trong danh sách tham số biến đổi.
- **`va_end`**: Hàm này được sử dụng để kết thúc việc truy cập các tham số biến đổi, giúp giải phóng bộ nhớ và tránh rò rỉ bộ nhớ.

Những hàm và cấu trúc này giúp bạn làm việc với các hàm có số lượng tham số không xác định (biến đổi), như các hàm in ra màn hình (`printf`, `fprintf`).


**Ví dụ 1:**
```c
#include <stdio.h>
#include <stdarg.h>

#define tong(...) sum(__VA_ARGS__, 0)

int sum(int count,...)
{
    va_list args;

    va_start(args, count);

    int result = count; // bắt đầu tính tổng từ count
    int value;

    while((value = va_arg(args, int)) != 0)
    {
        result += value;
    }

    va_end(args);

    return result;
}

int main(int argc, char const *argv[])
{
    printf("Tong = %d\n", tong(3, 2, 4, 5, 7)); // sum(3, 2, 4, 5, 7, 0)
    return 0;
}

```
**Giải thích:**
- Hàm sum nhận một số nguyên đầu tiên (count) để xác định số lượng đối số tiếp -  theo cần tính tổng.
-   Trong hàm sum, chúng ta sử dụng va_list, va_start và va_arg để truy cập các đối số biến đổi và tính tổng của chúng.
-   Cuối cùng, chúng ta gọi hàm sum với số lượng đối số khác nhau và in ra kết quả.

**Ví dụ 2:**
```C
#include <stdio.h>
#include <stdarg.h>

#define tong(...) sum(__VA_ARGS__, 0)

int sum(int count,...)
{
    va_list args;

    va_start(args, count);

    int result = count; // bắt đầu tính tổng từ count
    int value;

    while((value = va_arg(args, int)) != 0)
    {
        result += value;
    }

    va_end(args);

    return result;
}

int main(int argc, char const *argv[])
{
    printf("Tong = %d\n", tong(3, 2, 4, 5, 7)); // sum(3, 2, 4, 5, 7, 0)
    return 0;
}
```

Trong ví dụ này ta sử dụng một các tối ưu hơn là: 
- Định nghĩa macro ***#define tong(...)  sum(VA_ARGS, 0)*** để gọi hàm sum với các tham số mà macro tong nhận được và thêm một số 0 vào cuối danh sách tham số.
***Nhược điểm***: Vòng lặp tính tổng sẽ dừng nếu gặp số 0, mà sẽ không xét đến các số tiếp theo nếu có.

**Ví dụ 3:**
```c
#include <stdio.h>
#include <stdarg.h>

#define tong(...) sum(__VA_ARGS__, '\n')

int sum(int count,...)
{
    va_list args;
    va_list check;

    va_start(args, count);

    va_copy(check, args);

    int result = count; 

    while(( va_arg(check, char*)) != (char*)'\n')
    {
        result += va_arg(args, int);
    }

    va_end(args);

    return result;
}

int main(int argc, char const *argv[])
{
    printf("Tong = %d\n", tong(3, 10, 4, 0, 5)); 
    return 0;
}
```
Trong đoạn code này sẽ khắc phục lỗi của cả 2 ví dụ trên: 

***Sử dụng ký tự '\n' thay vì số 0:***
-   Trong ví dụ mới,sử dụng ký tự '\n' để đánh dấu kết thúc danh sách tham số 
thay vì sử dụng số 0 như trong ví dụ trước đó. Điều này giúp vòng lặp sẽ duyệt
tới vị trí cuối cùng của dãy số truyền vào.

***Sử dụng va_copy để sao chép danh sách tham số:***
-   Trong hàm sum, sử dụng ***va_copy*** để sao chép danh sách tham số (args) sang một 
biến khác (check). Điều này giúp bạn kiểm tra điều kiện kết thúc vòng lặp mà không 
thay đổi vị trí của con trỏ trong danh sách tham số chính.(Vì mỗi lần gọi hàm ***va_arg***
sẽ trỏ tới một số.)

***Điều kiện dừng vòng lặp trong hàm sum:***
-   Trong vòng lặp while, kiểm tra điều kiện dừng bằng cách so sánh giá trị của tham số hiện tại 
trong danh sách (va_arg(check, char*)) với ký tự '\n'. Khi gặp ký tự '\n', vòng lặp sẽ dừng.

## 2. THƯ VIỆN ASSERT
- Dùng để phát hiện lỗi, debug chương trình, thể hiện lỗi cụ thể trong code.
- Nếu điều kiện đúng (true), chương trình được thực thi.
- Nếu điều kiện sai (false), chương trình báo lỗi và sẽ sừng lại.

```c
#include <stdio.h>
#include <assert.h>
int main() {
   int x = 88;

   assert(x == 88);

   // Chương trình sẽ tiếp tục thực thi nếu điều kiện là đúng, và ngược lại.
   printf("X is: %d", x);
   
   return 0;
}
```
Trong đoạn code này điều kiện *** x = 88 *** là đúng nên chương trình sẽ thực thi.

```c
    #include <stdio.h>
#include <assert.h>
int main() {
   int x = 5;

   assert(x == 1010);

   // Chương trình sẽ tiếp tục thực thi nếu điều kiện là đúng, và ngược lại.
   printf("X is: %d", x);
   
   return 0;
}
```
Trong đoạn code trên biến x không bằng 1010 nên trương trình sẽ gặp lỗi và dừng lại.
output: Assertion failed: x == 88, file D:\LEARN\CODE_C\ADVANCE_C_Cpp\stdarg.c, line 6













</details>


<details>
<summary>LESSON 3: BITMASK </summary> 

## Bit mask
- Bitmask là một kỹ thuật sử dụng các bit để lưu trữ và thao tác với các cờ (flags) hoặc trạng thái. Có thể sử dụng bitmask để đặt, xóa và kiểm tra trạng thái của các bit cụ thể trong một từ (word).

- Bitmask thường được sử dụng để tối ưu hóa bộ nhớ, thực hiện các phép toán logic trên một cụm bit, và quản lý các trạng thái, quyền truy cập, hoặc các thuộc tính khác của một đối tượng.
  
***Các phép toán bitwise (thự hiện trên bit)***

***AND (&):***

    - Phép toán AND (và) trên hai bit, trả về 1 nếu cả hai bit đều là 1, ngược lại trả về 0.
***OR (|):***

    - Phép toán OR (hoặc) trên hai bit, trả về 1 nếu một trong hai bit hoặc cả hai bit là 1, ngược lại trả về 0.
***XOR (^):***

    - Phép toán XOR (hoặc loại trừ) trên hai bit, trả về 1 nếu hai bit khác nhau, ngược lại trả về 0.
***NOT (~):***

    - Phép toán NOT (phủ định) hoán đổi các bit, chuyển 0 thành 1 và ngược lại.
***Shift Left (<<):***

    - Phép toán dịch trái, dịch các bit sang trái và điền vào các bit bên phải bằng 0.
***Shift Right (>>):***

    - Phép toán dịch phải, dịch các bit sang phải và điền vào các bit bên trái bằng 0 hoặc 1 (phụ thuộc vào loại dịch).

![Các phép toán bitwise](bit.jpg)

***Ví dụ***

```c
#include <stdio.h>
int main()
{
    // a = 5 (00000101), b = 9 (00001001 )
    unsigned int a = 5, b = 9;

    printf("a = %u, b = %u\n", a, b);
    printf("a&b = %u\n", a & b);

    printf("a|b = %u\n", a | b);

    printf("a^b = %u\n", a ^ b);

    printf("~a = %u\n", a = ~a);

    printf("b<<1 = %u\n", b << 1);

    printf("b>>1 = %u\n", b >> 1);

    return 0;
}
```

Output:

    a = 5, b = 9

    a&b = 1

    a|b = 13

    a^b = 12

    ~a = 4294967290

    b<<1 = 18
    
    b>>1 = 4

### Thư viên stdint.h 
- Thư viện stdint.h trong C cung cấp các kiểu dữ liệu số nguyên có độ rộng cố định với các kích thước cụ thể, 
  không phụ thuộc vào nền tảng hoặc trình biên dịch cụ thể.
  
  Dưới đây là một số kiểu dữ liệu phổ biến được định nghĩa trong stdint.h:

    ***int8_t, int16_t, int32_t, int64_t:***

    Các kiểu số nguyên có độ rộng cố định với số bit cụ thể (8, 16, 32, 64 bit) và dấu.
    ***uint8_t, uint16_t, uint32_t, uint64_t:***

    Các kiểu số nguyên không dấu có độ rộng cố định với số bit cụ thể (8, 16, 32, 64 bit).

## Ứng dụng bitmask trong thực tế
```c

#include <stdio.h>
#include <stdint.h>


#define GENDER        1 << 0  //0b00000001
#define TSHIRT        1 << 1  //0b00000010
#define HAT           1 << 2  //0b00000100
#define SHOES         1 << 3  //0b00001000
// Tự thêm tính năng khác
#define FEATURE1      1 << 4  //0b00010000
#define FEATURE2      1 << 5  //0b00100000
#define FEATURE3      1 << 6  //0b01000000
#define FEATURE4      1 << 7  //0b10000000

/*
    Sử dụng bit wise | để bật 1 tính năng mà không ảnh hưởng đến bit khác
    ví dụ bật tín năng số 1:
    0b10000000 (option)
    |
    0b00000001 
    ----------
    0b10000001
*/

void enableFeature(uint8_t *option, uint8_t feature) {
    *option |= feature;
}

/*
    Sử dụng bit wise & tắt 1 tính năng mà không ảnh hưởng tới bit khác
    Vi dụ tắt tính năng sô 1:
    0b00000111 (option), 0b00000001(feature), 0b11111110(~feature)
    
    0b00000111(option)
    &
    0b11111110(~feature)
    ----------
    0b00000110
*/

void disableFeature(uint8_t *option, uint8_t feature) {
    *option &= ~feature;
}

// Kiểm tra những bit nao được bật 
int isFeatureEnabled(uint8_t option, uint8_t option) {
    return (option & option) != 0;
}

void listSelectedFeatures(uint8_t option) {
    printf("Selected Features:\n");

    if (option & GENDER) {
        printf("- Gender\n");
    }
    if (option & TSHIRT) {
        printf("- T-Shirt\n");
    }
    if (option & HAT) {
        printf("- Hat\n");
    }
    if (option & SHOES) {
        printf("- Shoes\n");
    }

    for (int i = 0; i < 8; i++)
    {
        printf("feature selected: %d\n", (option >> i) & 1);
    }
    

    // Thêm các điều kiện kiểm tra cho các tính năng khác
}



int main() {
    uint8_t options = 0;

    // Thêm tính năng 
    enableFeature(&options, GENDER | TSHIRT | HAT | SHOES);

    disableFeature(&options, TSHIRT);

    // Liệt kê các tính năng đã chọn
    listSelectedFeatures(options);
    
    return 0;
}

```
Output:
```c
Selected Features:
- Gender
- Hat
- Shoes
feature selected: 1
feature selected: 0
feature selected: 1
feature selected: 1
feature selected: 0
feature selected: 0
feature selected: 0
feature selected: 0
```