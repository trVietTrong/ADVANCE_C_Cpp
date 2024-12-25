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






</details>


<details>
<summary>LESSON 4: POINTER</summary> 

# Pointer

- Trong ngôn ngữ lập trình C, con trỏ (pointer) là một biến chứa địa chỉ bộ nhớ của một đối tượng khác (biến, mảng, hàm). Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn. Con trỏ cho phép chúng ta làm việc trực tiếp với bộ nhớ, thực hiện các thao tác như truy xuất và thay đổi giá trị của các biến thông qua địa chỉ bộ nhớ của chúng.
- Cú pháp khai báo: **`type* pointer_name`**
  
**Ví dụ:**
```c
#include <stdio.h>

int main() {
    int x = 10;
    int* ptr = &x;  // ptr là con trỏ lưu địa chỉ của biến x

    printf("Địa chỉ của x: %p\n", (void*)&x);  // In ra địa chỉ của x
    printf("Giá trị của ptr: %p\n", (void*)ptr);  // In ra giá trị của ptr (địa chỉ của x)
    printf("Giá trị mà ptr trỏ tới: %d\n", *ptr);  // In ra giá trị của x thông qua con trỏ

    return 0;
}

```
## Kích thước của con trỏ
    Kích thước của con trỏ phụ thuộc vào hệ điều hành và kiến trúc của máy tính (32-bit hay 64-bit),
    nhưng nó thường là 4 byte trên hệ 32-bit và 8 byte trên hệ 64-bit.Để kiểm tr kích thuớc của con
    trỏ ta có thể sử dụng toán tử `sizeof`.
 
 ##### Ví dụ:
 ```c

#include <stdio.h>

int main() {
    int x = 10;
    int* ptr = &x;

    // Kiểm tra kích thước của con trỏ ptr
    printf("Kích thước của con trỏ ptr: %d byte\n", sizeof(ptr));

    // Kiểm tra kích thước của kiểu dữ liệu mà con trỏ trỏ tới (int)
    printf("Kích thước của kiểu dữ liệu int: %d byte\n", sizeof(int));

    return 0;
}

 ```
##### Output:
```
Kích thước của con trỏ ptr: 8 byte
Kích thước của kiểu dữ liệu int: 4 byte
```

### Ứng dụng của con trỏ
```c
#include <stdio.h>
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main()
{
   int a = 10, b = 20;
   swap(&a, &b);

   printf("value a is: %d\n", a);
   printf("value b is: %d\n", b);

    return 0;
}

```
**Giải thích:**
-   Đầu vào của hàm: Hàm **swap** nhận hai đối số là con trỏ int *a và int *b. 
-   Chúng ta truyền vào địa chỉ của biến a và b cho hàm swap bằng cách sử dụng toán tử **&** (toán tử lấy địa chỉ). 
-   *a và *b trong hàm **swap** là toán tử **dereferencing** dùng để truy cập và thay đổi giá trị tại địa chỉ mà con trỏ a và b trỏ tới.



###  1. Void Pointer
Void pointer thường dùng để trỏ để tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó.
Cú pháp: **`void *ptr_void`**

**Cách sử dụng:** khi ta sử dụng con trỏ kiểu void trong C để trỏ tới một biến có kiểu dữ liệu cụ thể (như int), ta cần phải ép kiểu con trỏ void về con trỏ có kiểu cụ thể (ví dụ: int* ). Sau đó, ta mới có thể giải tham chiếu (dereference) con trỏ để đọc giá trị của biến mà nó trỏ tới.

**Ví dụ:** 
```c
#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b)
{
    return a+b;
}

int main() {
   
    char array[] = "Hello";
    int value = 5;
    double test = 15.7;
    char letter = 'A';
   
    //Con trỏ void trỏ tới int:
    void *ptr = &value;
    printf("value is: %d\n", *(int*)(ptr));

    //Con trỏ void trỏ tới double:
    ptr = &test;
    printf("value is: %f\n", *(double*)(ptr));

    //Con trỏ void trỏ tới char:
    ptr = &letter;
    printf("value is: %c\n", *(char*)(ptr));

    //Con trỏ void trỏ tới hàm sum:
    ptr = sum;
    printf("sum: %d\n", ((int (*)(int,int))ptr)(5,6));

    //Mảng con trỏ void để lưu nhiều kiểu dữ liệuliệu
    void *ptr1[] = {&value, &test, &letter , sum, array};

    //Truy cập các phần tử trong mảng con trỏ ptr1:
    printf("value: %d\n", *(int*)ptr1[0]);

    //CCộng thêm 1 với con trỏ là để trỏ tới ký tự tiếp theo trong chuỗi "Hello", tức là 'e'.
    printf("value: %c\n", *((char*)ptr1[4]+1));

    return 0;
}

```
##### Giải thích:
Chương trình sử dụng con trỏ kiểu void để trỏ tới các kiểu dữ liệu khác nhau (như int, double, char, và hàm).
Con trỏ void không có kiểu dữ liệu xác định, vì vậy cần phải ép kiểu con trỏ về kiểu cụ thể (như int*, double*, char*,
hoặc int (*)(int, int) cho hàm) để truy cập giá trị.
##### Output:
```
value is: 5
value is: 15.700000
value is: A
sum: 11
value: 5
value: e

```

### 2. Funcion Pointer
-   Pointer to function (con trỏ hàm) là một biến mà giữ địa chỉ của một hàm. Có nghĩa là, nó trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong chương trình.
-    Trong ngôn ngữ lập trình C, con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.
-   **Cú pháp:**<return_type> (* func_pointer)(<data_type_1>, <data_type_2>);

#### 2.1 Sử dụng con trỏ hàm để gọi các phép toán.

```c
#include <stdio.h>

void tong(int a, int b)
{
    printf("%d + %d = %d\n", a, b, a + b);
}

void hieu(int a, int b)
{
    printf("%d - %d = %d\n", a, b, a - b);
}

void tich(int a, int b)
{
    printf("%d * %d = %d\n", a, b, a * b);
}

int main(int argc, char const *argv[])
{
    int a = 5, b = 3;

    void(*ptr)(int, int);  // Khai báo con trỏ hàm

    // Trỏ đến hàm tong 
    ptr = tong;            
    ptr(a, b);        // gọi hàm tong thông qua con trỏ

    // Trỏ đến hàm hieu 
    ptr = hieu;           
    ptr(a, b);       // gọi hàm hieu thông qua con trỏ

    // Trỏ đến hàm tich 
    ptr = tich;           
    ptr(a, b);       // gọi hàm tich thông qua con trỏ  

    return 0;
}

```

**Output:**
```
5 + 3 = 8
5 - 3 = 2
5 * 3 = 15
```


#### 2.2 Sử dụng con trỏ làm tham số của một hàm
```c
#include <stdio.h>

void tong(int a, int b)
{
    printf("%d + %d = %d\n", a, b, a + b);
}

void hieu(int a, int b)
{
    printf("%d - %d = %d\n", a, b, a - b);
}

void tich(int a, int b)
{
    printf("%d * %d = %d\n", a, b, a * b);
}

/* Cách 2: Sử dụng con trỏ hàm làm tham số của 1 hàm */
void tinhtoan(void(*pheptoan)(int, int), int a, int b)
{
    pheptoan(a, b);  // Gọi phép toán thông qua con trỏ hàm
}

int main()
{
    int a = 6, b = 2;

    // Gọi hàm tinhtoan với con trỏ hàm trỏ tới các phép toán khác nhau
    tinhtoan(tong, a, b);  // Truyền con trỏ hàm tong vào
    tinhtoan(hieu, a, b);  // Truyền con trỏ hàm hieu vào
    tinhtoan(tich, a, b);  // Truyền con trỏ hàm tich vào

    return 0;
}

```

**Output:**
```
6 + 2 = 8
6 - 2 = 4
6 * 2 = 12

```
**Giải thích:**
```
-   tinhtoan(tong, a, b) gọi hàm tong, tức là phép cộng. Tương tự, truyền hieu và tich 
để thực hiện phép trừ và phép nhân.
-   Mỗi lần gọi tinhtoan, hành vi của chương trình thay đổi tùy thuộc vào hàm  truyền 
vào như tong, hieu, hoặc tich.

```
**Lợi ích:** có thể thay đổi mục đích của chương trình mà không cần sửa mã trong hàm tinhtoan, chỉ cần thay đổi con trỏ hàm mà bạn truyền vào.


#### 2.3 Sử dụng mảng con trỏ hàm để gọi các phép toán

```c
#include <stdio.h>

void tong(int a, int b) {
    printf("%d + %d = %d\n", a, b, a + b);
}

void hieu(int a, int b) {
    printf("%d - %d = %d\n", a, b, a - b);
}

void tich(int a, int b) {
    printf("%d * %d = %d\n", a, b, a * b);
}

int main() {
    int a = 6, b = 2;

    // Khai báo mảng con trỏ hàm
    void (*pheptoan[])(int, int) = {tong, hieu, tich};

    // Gọi các hàm thông qua mảng con trỏ hàm
    pheptoan[0](a, b);  // Gọi hàm `tong`
    pheptoan[1](a, b);  // Gọi hàm `hieu`
    pheptoan[2](a, b);  // Gọi hàm `tich`

    return 0;
}
```
**Output**
```
6 + 2 = 8
6 - 2 = 4
6 * 2 = 12

```
**Giải thích:**
- pheptoan[]: Là một mảng chứa các con trỏ hàm.
- void (*)(int, int): Đây là kiểu của các phần tử trong mảng — mỗi phần tử là một con trỏ trỏ tới một hàm có kiểu trả về void và nhận hai tham số kiểu int.
- {tong, hieu, tich}: Gán địa chỉ các hàm tong, hieu, và tich vào các phần tử của mảng.


 **Lợi ích:** Tất cả các hàm liên quan (như các phép toán) được nhóm lại trong một mảng, dễ quản lý hơn.


### 3. Pointer to Constant
Một con trỏ kiểu "Pointer to Constant" chỉ cho phép đọc giá trị mà nó trỏ tới, không được phép thay đổi giá trị đó thông qua con trỏ.
**Cú pháp:**
```c
int const *ptr_const; 
const int *ptr_const;
```
**Ví dụ:**
```c
#include <stdio.h>

int main() {
    int num = 5;
    const int* ptr = &num; // Con trỏ chỉ đọc giá trị
    num = 6; // Hợp lệ, thay đổi trực tiếp giá trị của biến
    *ptr = 7; // Lỗi, không được phép thay đổi thông qua con trỏ

    return 0;
}
```

### 4. Constant Pointer
Định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ ) không thể thay đổi. Tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác.
**Cú pháp:** 
```c
int *const const_ptr = &value;
```
**Ví dụ:**
```c
#include <stdio.h>

int main() {
    int num1 = 10, num2 = 20;
    int *const ptr = &num1; // Con trỏ cố định trỏ tới num1
    *ptr = 15; // Hợp lệ, thay đổi giá trị của num1
    ptr = &num2; // Lỗi, không thể thay đổi địa chỉ mà con trỏ trỏ tới

    return 0;
}
```

### 5. NULL Pointer
Null Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào. Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu diễn trạng thái null. 

Sử dụng null pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa. Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) một null pointer là quan trọng để tránh lỗi chương trình.

**Ví dụ:**
```c
#include <stdio.h>

int main() {
    int *ptr = NULL;  // Gán giá trị NULL cho con trỏ 0x0000000

    if (ptr == NULL) {
        printf("Pointer is NULL\n");
    } else {
        printf("Pointer is not NULL\n");
    }

    int score_game = 5;
    if (ptr == NULL)
    {
        ptr = &score_game;
        *ptr = 30;
        ptr = NULL;
    }
    

    return 0;
}
```
**Giải thích:**
```
-   Khi ptr == NULL, chương trình gán địa chỉ của biến score_game cho ptr.
-   Dòng *ptr = 30; thay đổi giá trị của score_game từ 5 thành 30 thông qua con trỏ.
-   Sau khi hoàn tất, con trỏ ptr được gán lại giá trị NULL để đánh dấu rằng nó không còn trỏ tới bất kỳ vùng nhớ hợp lệ nào.
```

### 6. Pointer to Pointer
Con trỏ đến con trỏ (Pointer to Pointer) là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc. Cấp bậc này có thể hữu ích trong nhiều tình huống, đặc biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con trỏ.

**Ví dụ:**
```c
#include <stdio.h>

int main() {
    int value = 42;
    int *ptr1 = &value;  // Con trỏ thường trỏ đến một biến

    int **ptr2 = &ptr1;  // Con trỏ đến con trỏ

    /*
        **ptr2 = &ptr1
        ptr2 = &ptr1;
        *ptr2 = ptr1 = &value;
        **ptr2 = *ptr1 = value
    */

    printf("address of value: %p\n", &value);
    printf("value of ptr1: %p\n", ptr1);

    printf("address of ptr1: %p\n", &ptr1);
    printf("value of ptr2: %p\n", ptr2);

    printf("dereference ptr2 first time: %p\n", *ptr2);

    printf("dereference ptr2 second time: %d\n", **ptr2);

    return 0;
}
```
**Giải thích:**
```
-   ptr2 lưu địa chỉ của ptr1, tức là ptr2 = &ptr1.
-   *ptr2 trỏ đến giá trị của ptr1, tức là *ptr2 = ptr1 = &value.
-   **ptr2 trỏ đến giá trị mà ptr1 trỏ tới, tức là **ptr2 = *ptr1 = value = 42.-
```
**Output:**
```c
address of value: 0x7ffee4b3e7cc
value of ptr1: 0x7ffee4b3e7cc

address of ptr1: 0x7ffee4b3e7d0
value of ptr2: 0x7ffee4b3e7d0

dereference ptr2 first time: 0x7ffee4b3e7cc
dereference ptr2 second time: 42

```




















</details>


<details>
<summary>LESSON 5: Storage ClassesClasses</summary> 

## Extern 
Trong ngôn ngữ lập trình C, từ khóa extern được sử dụng để khai báo một biến hoặc hàm được định nghĩa ở một nơi khác (thường là trong một tệp khác) và có phạm vi sử dụng trên
toàn chương trình.

### 1. Sử dụng Extern với biến.
Khi một biến được khai báo bằng extern, nó không được cấp phát bộ nhớ tại vị trí khai
báo đó. Thay vào đó, bộ nhớ sẽ được cấp phát tại nơi biến được định nghĩa.

**Ví dụ:**
-   File `file1.c` dùng để định nghĩa biến.
```c
#include<stdio.h>

int x = 10;   // Biến được định nghĩa và cấp phát địa chỉchỉ

```
-   File `file2.c` dùng để sử dụng biến.
```c

#include <stdio.h>

extern int x; // Khai báo extern biến x để có thể sử dụng 

void printX() {
    printf("x = %d\n", x);
}

int main()
{
    printX();
}

```
-   Khi biên dịch, cần phải liên kết các tệp lại với nhau:
```
gcc file1.c file2.c -o outtputfile
```

### 2. Sử dụng Extern với hàm.
**Cách sử dụng Extern với hàm:**
-   Khai báo trong tệp tiêu đề (.h): sử dụng extern để khai báo rằng một hàm được định nghĩa ở một nơi khác.
-   Định nghĩa hàm trong tệp nguồn (.c): định nghĩa logic của hàm trong một file .c. Không cần sử dụng extern khi định nghĩa hàm.
-   Gọi hàm từ một file khác: Bao gồm tệp tiêu đề hoặc khai báo extern trực tiếp trong file cần gọi hàm.

**Ví dụ:**
-   File `file1.h` dùng để khai báo:
```c
#ifndef FILE1_H
#define FILE1_H

extern int tinhTong(int a, int b);  // Khai báo extern cho hàm
extern int tinhHieu(int a, int b);

#endif

```

-   File `file2.c` dùng để định nghĩa:
```c
#include"file1.h"

int tinhTong(int a, int b){
    return a + b;
}
int tinhHieu(int a, int b){
    return a - b;
}

```
-   file `main.c` tệp chính:
```c
#include<stdio.h>
#include<file1.h>

int main(){
    int x = 10, y = 5;

    printf("Add: %d\n", tinhTong(x, y));        
    printf("Subtract: %d\n", tinhHieu(x, y));

    return 0;
}
```

-   Liên kết các file:
```c
gcc main.c file2.c -o main.exe 
```
-   Outout:
```c
Add: 15
Subtract: 5
```

### 3. Ứng dụng của Extern trong thực tế.
Giả sử chúng ta cần chia sẻ dữ liệu nhiệt độ động cơ từ cảm biến với nhiều module khác trong hệ thống.

-   File `engine_data.h` khai báo các biến hàm sử dụng trong module khác:
```c
#ifndef ENGINE_DATA_H
#define ENGINE_DATA_H

extern float engine_temperature;        //Khai báo extern cho cảm biến nhiệt độ
extern void updateEngineTemperature(float new_temp)  // Khai báo extern cho hàmhàm
```

-   file `sensor_module.c` đọc cảm biến và cập nhật giá trị của nhiệt độ:
```c
#include "engine_data"

float engine_temperature = 0.0;     // Định nghĩa biến nhiệt độ

void updateEngineTemperature (float new_temp){
    engine_temperature = new_temp;      // Cập nhật giá trị nhiệt độ từ cảm biến 
}

void readSensor(){
    float temp = 85.5;          // Giá trị giả lập từ cảm biếnbiến
    updateTemperature(temp);
}

```

**Giải thích:**
   Hàm readSensor() mô phỏng việc đọc cảm biến và cập nhật giá trị nhiệt độ cho biến engine_temperature thông qua hàm updateEngineTemperature().

-   File `diagnostic_module.c` chẩn đoán:
```c
#include <stdio.h>
#include "engine_data.h"

void checkEngine(){
    if(engine_temperature > 100.0){
        printf("WARNING: Engine Overheating! Temperature = %.2f\n", engine_temperature);
    }
    else
        printf("Engine temperature : %.2f\n , engine_temperature);
}
```
**Giải thích:**
Hàm checkEngineStatus() in ra trạng thái của động cơ, cho biết nhiệt độ hiện tại hoặc thông báo cảnh báo nếu động cơ quá nóng.

-   File `main.c`

```c
#include "engine_data.h"

extern void readSensor();  // Khai báo extern cho hàm ở file khác
extern void checkEngineStatus(); // Khai báo extern cho hàm ở file khác

int main() {
    readSensor();          // Đọc giá trị cảm biến
    checkEngineStatus();   // Kiểm tra trạng thái động cơ
    return 0;
}
```
**Giải thích:**
Hàm main() gọi lần lượt readSensor() để cập nhật giá trị nhiệt độ và checkEngineStatus() để kiểm tra trạng thái động cơ.

-   Biên dịch chương trình:
```c
gcc main.c sensor_module.c diagnostic_module.c -o system
```

-   Output:
```c
Engine Temperature: 85.50
```

## Static local
Biến static local là một biến được khai báo với từ khóa static trong phạm vi cục bộ của 
một hàm. Biến này có một số đặc điểm sau:
**Đặc điểm của biến static local.**
1. Lưu trữ trong bộ nhớ tĩnh:
    -   Biến static local không được lưu trong stack(ngăn xếp) như các biến cục bộ thông thường, mà được lưu trong vùng bộ nhớ tĩnh(static memori).
    -   Điều này giúp biến không bị thu hồi sau khi hàm kết thúc, giá trị của biến sẽ được bảo tồn trong các lần gọi hàm.
2. Khởi tạo một lần duy nhất:
   -   Biến static local được khởi tạo chỉ một lần duy nhất khi chương trình chạy đến lần đầu tiên sử dụng hàm chứa biến đó.
   -   Các lần gọi hàm tiếp theo sẽ sử dụng giá trị đã lưu của biến từ lần gọi trước, thay vì khởi tạo lại.
3. Phạm vi:
   -   Biến static local chỉ có thể được truy cập bên trong hàm mà nó được khai báo. Nó không thể được truy cập từ bên ngoài hàm đó.
4. Thời gian tồn tại:
    -   Biến static local tồn tại trong toàn bộ thời gian chạy của chương trình, ngay cả khi hàm chứa nó đã kết thúc.

**Ví dụ:**
```c
#include <stdio.h>

void counter() {
    static int count = 0; // Biến static local, được khởi tạo một lần duy nhất
    count++;
    printf("Count: %d\n", count);
}

int main() {
    counter(); // In ra: Count: 1
    counter(); // In ra: Count: 2
    counter(); // In ra: Count: 3
    return 0;
}
```
**Phân tích:**
Biến `counter` là biến static local:
-   Nó được khởi tạo 1 lần duy nhất với giá trị bằng 0.
-   Mỗi lần gọi hàm `counter`, giá trị của biến sẽ được tăng lên và giữ nguyên giá trị giữa các lần gọi hàm.

**So sánh với biến cục bộ thông thường:**
```c
#include <stdio.h>

void counter() {
    int count = 0; // Biến cục bộ thông thường
    count++;
    printf("Count: %d\n", count);
}

int main() {
    counter(); // In ra: Count: 1
    counter(); // In ra: Count: 1
    counter(); // In ra: Count: 1
    return 0;
}
```
**Phân tích:**
Biến `counter` trong ví dụ này là biến cục bộ thông thường, sau khi hàm kết thúc vùng bộ nhớ cấp phát cho biến sẽ bị thu hồi lại và không còn tồn tại nữa. Lần tiếp theo khi hàm được gọi vùng bộ nhớ mới sẽ được cấp phát cho nó và giá trị của biến sẽ được cập nhật lại.


## Static global.
Trong C, biến static global là một biến toàn cục (global) được khai báo với từ khóa static. Nó có một số đặc điểm khác biệt so với biến toàn cục thông thường.

1.  Phạm vi:
    -   Biến static global chỉ có thể được truy cập trong file mà nó được khai báo.
    -   Nó không thể xuất hiện bên ngoài file ngay cả khi dùng từ khóa `extern` trong file khác .
2. Thời gian tồn tại:
    -   Biến static global tồn tại trong toàn bộ thời gian chạy của chương trình, giống như biến toàn cục thông thường.
3. Khởi tạo mặc định:
    -   Nếu không được khởi tạo rõ ràng, biến static global sẽ tự động được khởi tạo với giá trị mặc định:
        - Số nguyên (int) → 0
        -   Số thực (float) → 0.0
        -   Con trỏ → NULL
4. Giới hạn truy cập:
    -   Từ khóa static trong khai báo toàn cục được sử dụng để giới hạn phạm vi của biến trong file nguồn hiện tại, tránh xung đột tên với các biến toàn cục khác trong những file khác.

**Ví dụ:**

-   File `file1.c`
```c
#include<stdio.h>


static int staticGlobalVar = 40;    // Khai báo biến toàn cục static
int normalGlobalVar = 50;           // khai báo biến toàn cục thông thường

void printStaticGlobalVar(){
    printf("Global Var (file1) : %d\n", staticGlobalVar);       // In giá trị của biến toàn cục static
}
```

-   File `file2.c`
```c
#include <stdio.h>

// Khai báo extern cho biến toàn cục thông thường (được phép truy cập)
extern int normalGlobalVar;

// extern int staticGlobalVar; // Không hợp lệ, sẽ gây lỗi biên dịch

void printNormalGlobalVar() {
    printf("normalGlobalVar (file2.c): %d\n", normalGlobalVar);
}
```
-   File `main.c`
```c
#include <stdio.h>

// Khai báo các hàm từ file1.c và file2.c
void printStaticGlobalVar();
void printNormalGlobalVar();

int main() {
    printf("=== Program Start ===\n");

    // Gọi hàm in giá trị của biến static toàn cục
    printStaticGlobalVar();
    printNormalGlobalVar();

    return 0;
}

```
-   Liên kết file: 
```c
gcc main.c file1.c file2.c -o program
```

-   Output:
```c
=== Program Start ===
staticGlobalVar (file1.c): 40
normalGlobalVar (file2.c): 50
```

### So sánh biến toàn cục static và biến toàn cục thông thường.
| Đặc điểm             | Biến toàn cục thông thường        | Biến `static` global            |
|----------------------|-----------------------------------|---------------------------------|
| **Phạm vi truy cập**  | Truy cập từ bất kỳ file nào bằng `extern` | Chỉ truy cập trong file khai báo |
| **Thời gian tồn tại** | Toàn bộ thời gian chạy chương trình | Toàn bộ thời gian chạy chương trình |
| **Khả năng xung đột** | Có thể bị xung đột khi trùng tên biến | Không thể bị xung đột với file khác |


## Biến Register 
Trong C, biến register là một từ khóa được sử dụng để chỉ ra rằng một biến nên được lưu trữ trong thanh ghi (register) của vi xử lý thay vì trong bộ nhớ RAM thông thường. Điều này có thể giúp tăng tốc độ truy xuất biến, vì thanh ghi có tốc độ truy cập nhanh hơn bộ nhớ.

**Đặc điểm:**
1.  Biến được khai báo với từ khóa `register` được lưu trữ trong thanh ghi của CPU, giúp cải thiện hiệu suất khi truy xuất dữ liệu.(Lưu ý trình biên dịch có thể không chọn thanh ghi nếu không đủ tài nguyên).
2.  Không thể lấy địa chỉ của biến`register` vì thanh ghi không có địa chỉ cụ thể như Ram.
3.  Chỉ áp dụng với biến cục bộ.
4.  Tăng hiệu suất.

**Ví dụ 1: Sử dụng biến thông thường.**
```c
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    // Bắt đầu đo thời gian
    start = clock();

    // Vòng lặp cần đo thời gian
    int sum = 0;
    for (int i = 0; i < 1000000; i++) {
        sum += i;
    }

    // Kết thúc đo thời gian
    end = clock();

    // Tính toán thời gian CPU đã sử dụng
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // In kết quả
    printf("Vòng lặp mất %f giây\n", cpu_time_used);
    return 0;
}
```

**OutPut:**
```c
Vòng lặp mất 0.000300 giây
```

**Ví dụ 2: Sử dụng biến register.**
```c
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    // Bắt đầu đo thời gian
    start = clock();

    // Vòng lặp sử dụng biến register
    register int sum = 0;
    register int i;
    for (i = 0; i < 1000000; i++) {
        sum += i;
    }

    // Kết thúc đo thời gian
    end = clock();

    // Tính toán thời gian CPU đã sử dụng
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // In kết quả
    printf("Vòng lặp mất %f giây\n", cpu_time_used);
    return 0;
}

```

**OutPut:**
```c
Vòng lặp mất 0.000100 giây
```

**Giải thích:**
-   clock_t start, end;: Định nghĩa hai biến start và end kiểu clock_t, dùng để lưu thời gian bắt
 đầu và kết thúc của vòng lặp.

-   start = clock();: Lưu thời gian bắt đầu khi vòng lặp bắt đầu thực thi.

-   end = clock();: Lưu thời gian kết thúc khi vòng lặp kết thúc.

-   cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;: Tính toán thời gian sử dụng của CPU
 bằng cách lấy hiệu giữa end và start và chia cho CLOCKS_PER_SEC để chuyển từ "ticks" sang giây.

-   printf("Vòng lặp mất %f giây\n", cpu_time_used);: In ra thời gian thực thi của vòng lặp.

**Kết luận:**
Sử dụng biến register trong vòng lặp có thể giúp cải thiện hiệu suất khi truy cập biến, nhưng hiệu
 quả thực tế phụ thuộc vào nhiều yếu tố như bộ biên dịch, kiến trúc phần cứng và cách sử dụng biến.

## Biến volatile
Trong C, từ khóa volatile là một từ khóa đặc biệt được sử dụng để chỉ ra rằng giá trị của một biến có thể thay đổi bất kỳ lúc nào mà không có sự can thiệp trực tiếp từ chương trình (ví dụ như thay đổi bởi phần cứng, ngắt hoặc các tác vụ khác đang chạy song song). Điều này cảnh báo trình biên dịch không tối ưu hóa các phép truy xuất và lưu trữ giá trị của biến đó.

```c
#include "stm32f10x.h"  // Header cho STM32F103

volatile uint8_t interrupt_flag = 0;  // Biến volatile để báo hiệu khi ngắt xảy ra

// Hàm xử lý ngắt cho GPIO Pin 0, Port B
void EXTI0_IRQHandler(void) {
    if (EXTI->PR & EXTI_PR_PR0) {  // Kiểm tra nếu ngắt đến từ GPIO Pin 0 (PB0)
        interrupt_flag = 1;  // Đặt cờ ngắt thành 1
        EXTI->PR = EXTI_PR_PR0;  // Xóa cờ ngắt để chuẩn bị cho lần ngắt sau
    }
}

```

**Kết luận:**
`volatile` là từ khóa quan trọng trong C để làm việc với các biến có thể thay đổi bất ngờ, chẳng hạn như do phần cứng, ngắt, hoặc đa nhiệm.
Sử dụng volatile giúp tránh việc tối ưu hóa biến mà trình biên dịch có thể thực hiện, đảm bảo rằng giá trị của biến luôn được đọc trực tiếp từ bộ nhớ khi cần thiết.