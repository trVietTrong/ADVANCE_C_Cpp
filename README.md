# Advance_C_Cpp
## Contents

<details>
<summary>LESSON : COMPILER - MACRO</summary>

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
<summary>LESSON 5: Storage Classes</summary> 

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





</details>


<details>
<summary>LESSON 6: STRUCT - UNION </summary> 






## STRUCT 
Struct là  một kiểu dữ liệu người dùng định nghĩa, cho phép nhóm nhiều biến (còn gọi là trường) có kiểu dữ liệu khác nhau thành một thực thể logic duy nhất. Điều này giúp tổ chức dữ liệu tốt hơn, đặc biệt khi làm việc với các tập hợp dữ liệu phức tạp.

### 1. Cách khai báo
**Cách 1:**
```c
struct TênCấuTrúc {
    kiểu_dữ_liệu trường1;
    kiểu_dữ_liệu trường2;
    // Các trường khác
};
```

**Cách 2: sử dụng `typedef`**
```c
typedef struct {
    kiểu_dữ_liệu trường1;
    kiểu_dữ_liệu trường2;
} TênCấuTrúc;

```
### 2. Truy xuất dữ liệu
**Truy xuất với dữ liệu thường: Ta sử dụng dấu `.`:**
**Ví dụ:**
```c
#include <stdio.h>

// Định nghĩa struct
struct SinhVien {
    char ten[50];
    int tuoi;
    float diemTB;
};

int main() {
    struct SinhVien sv;

    // Gán giá trị
    printf("Nhap ten: ");
    fgets(sv.ten, sizeof(sv.ten), stdin);

    printf("Nhap tuoi: ");
    scanf("%d", &sv.tuoi);

    printf("Nhap diem trung binh: ");
    scanf("%f", &sv.diemTB);

    // Truy xuất dữ liệu
    printf("\nThong tin sinh vien:\n");
    printf("Ten: %s", sv.ten);
    printf("Tuoi: %d\n", sv.tuoi);
    printf("Diem TB: %.2f\n", sv.diemTB);

    return 0;
}

```
**Truy xuất với con trỏ: Ta sử dụng dấu `->`:**
**Ví dụ:**
```c
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa kiểu struct với cú pháp của bạn
typedef struct {
    char ten[50];
    int tuoi;
    float diemTB;
} SinhVien *sv1;

int main() {
    // Khai báo một biến kiểu sv1 và cấp phát bộ nhớ
    sv1 sv = (sv1)malloc(sizeof(*sv)); // Cấp phát bộ nhớ cho con trỏ sv

    if (sv == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }

    // Nhập thông tin cho sinh viên qua con trỏ
    printf("Nhap ten: ");
    fgets(sv->ten, sizeof(sv->ten), stdin);

    printf("Nhap tuoi: ");
    scanf("%d", &sv->tuoi);

    printf("Nhap diem trung binh: ");
    scanf("%f", &sv->diemTB);

    // Hiển thị thông tin
    printf("\nThong tin sinh vien:\n");
    printf("Ten: %s", sv->ten);
    printf("Tuoi: %d\n", sv->tuoi);
    printf("Diem TB: %.2f\n", sv->diemTB);

    // Giải phóng bộ nhớ
    free(sv);

    return 0;
}

```

### 3. Data align trong struct:
Data alignment trong struct của C là cách trình biên dịch sắp xếp các thành phần 
của struct trong bộ nhớ sao cho tối ưu hóa truy cập dữ liệu, đồng thời tuân theo
các quy tắc về canh chỉnh (alignment rules) của phần cứng.
**Ví dụ:**
```c
#include <stdio.h>

typedef struct {
    char a;   // 1 byte
    int b;    // 4 bytes
    short c;  // 2 bytes
} MyStruct;

int main() {
    printf("Size of struct: %lu bytes\n", sizeof(MyStruct));
    return 0;
}

```
**Output:**
```c
Size of struct: 12 bytes
```
**Giải thích:**
-   Trường `char a`:
    -   char chiếm 1 byte.
    -   biến char chiếm vị trí đầu tiên trong 4 byte được cấp phát.
    -   Trống 3 byte.
-   Trường int b:

    -   int chiếm 4 bytes.
    -   Vì int phải nằm ở vị trí chia hết cho 4 nên sẽ được cấp phát thêm 4 byte để lưu biến int.
    -   Padding 3 vị trí còn thừa sau lần cấp phát đầu tiên để đảm vị trí cuả biến int.
-   Trường short c:

    -   short chiếm 2 bytes.
    -   short thường cần canh chỉnh tại một địa chỉ là bội số của 2.
    -   Vì sau b (chiếm 4 bytes), không cần thêm padding để đảm bảo rằng c bắt đầu tại một địa chỉ chia hết cho 2.
    -   Padding 2 byte còn lại. 

**Kết Luận: Tổng là 12 byte**
| Thành phần | Kích thước | Địa chỉ     | Giải thích                                   |
|------------|------------|-------------|---------------------------------------------|
| a          | 1 byte     | 0           | Được lưu tại địa chỉ 0                      |
| padding    | 3 bytes    | 1-3         | Padding để canh chỉnh `b` tại địa chỉ 4     |
| b          | 4 bytes    | 4-7         | Được lưu tại địa chỉ 4                      |
| c          | 2 bytes    | 8-9         | Được lưu tại địa chỉ 8                      |
| padding    | 2 bytes    | 10-11       | Padding để đảm bảo tổng kích thước là bội số của 4 |

### 4. Ứng dụng của struct
**Ví dụ: Trong lập trình vi điều khiển**
```c
#include "stm32f10x.h"  // Thư viện STM32F1

// Định nghĩa cấu trúc cho GPIO
typedef struct {
    volatile uint32_t CRL;     
    volatile uint32_t CRH;    
    volatile uint32_t IDR;     
    volatile uint32_t ODR;     
    volatile uint32_t BSRR;    
    volatile uint32_t BRR;     // 0x18: GPIO port configuration lock register
} GPIO_TypeDef;

// Địa chỉ của GPIOA trong STM32F103C8T6
#define GPIOA ((GPIO_TypeDef *) 0x40010800)

void delay_ms(int ms) {
    int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 1000; j++) {
            // Delay đơn giản
        }
    }
}

int main(void) {
    // Bật clock cho GPIOA
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    // Cấu hình GPIOA pin 5 như một output
    GPIOA->CRL &= ~(0xF << (5 * 4));  // Xóa cấu hình cũ của pin 5
    GPIOA->CRL |= (0x01 << (5 * 4));  // Cấu hình pin 5 là output 
    while (1) {
        // Bật LED (set pin 5 HIGH)
        GPIOA->ODR |= (1 << 5);  // Đặt trạng thái của pin 5 là HIGH (LED bật)

        delay_ms(500);  // Delay 500ms

        // Tắt LED (set pin 5 LOW)
        GPIOA->ODR &= ~(1 << 5);  // Đặt trạng thái của pin 5 là LOW (LED tắt)

        delay_ms(500);  // Delay 500ms
    }

    return 0;
}
```

**Giải thích:**
-   Cấu trúc GPIO_TypeDef chứa các thanh ghi của cổng GPIO, tương ứng với các thanh ghi điều khiển chân GPIO của STM32F103C8T6. 
-   Cấu trúc này giúp dễ dàng thao tác với các thanh ghi GPIO qua con trỏ tới cấu trúc.

### 5. Tổng kết đặc điểm của Struct
-   Tập hợp các kiểu dữ liệu khác nhau
-   Mỗi thành viên có tên và kiểu riêng
-   Lưu trữ liên tiếp trong bộ nhớ:
-   Truy cập các thành viên thông qua dấu chấm (.) hoặc con trỏ (->):
-   Kích thước của struct:  tổng kích thước của tất cả các thành viên cộng với các byte padding cần thiết




## UNION
`union` là một kiểu dữ liệu đặc biệt trong C, cho chép lưu trữ nhiều kiểu dữ liệu trong một vùng nhớ. Tuy nhiên, trong một union, các trường **chia sẻ cùng một vùng nhớ**. Kích thước của `union` sẽ bằng kích thước trường lớn nhất trong `union`.

**Cú pháp khia báo: Cũng giống như cách khai báo một struct**
```c 
typedef union{
    kieu_du_lieu1 thanh_phan1;
    kieu_du_lieu2 thanh_phan2;
    ...
} TenUnion;
```
**Ví dụ:**
```c
#include <stdio.h>
#include<stdint.h>

// Định nghĩa union bằng typedef
typedef union {
    uint8_t i;
    uint16_t f;
    uint32_t h;
} Data;

int main() {
    
    Data data;

    data.h = 456928226;

    // Vì các thành phần dùng chung bộ nhớ, giá trị sẽ bị ghi đè
    printf("data.i: %u\n", data.i); 
    printf("data.f: %u\n", data.f); 
    printf("data.f: %u\n", data.h); 

    return 0;
}
```
**Output:**
```c
data.i: 6
data.f: 2050
data.h: 456928226
```
**Giải thích:**
-   Dạng nhị phân của 456928226 là 0001 1011 0110 1111 1111 0100 0010.
-   `data.i` có kích thuớc 1 byte nên chỉ đọc 8 bit đầu tiên là  `0100 0010` và có giá trị là 66.
-   `data.f` có kích thuớc 2 byte nên chỉ đọc 16 bit đầu tiên là  `1111 1111 0100 0010 ` và có giá trị là 2050.
-   `data.h` có kích thuớc 4 byte nên  đọc tất cả các bit  là  `0001 1011 0110 1111 1111 0100 0010 0100 0010` và có giá trị là 456928226 .


## Sự giống nhau và khác nhau giữa struct và union.
**Giống nhau:**
-   Cùng là kiểu dữ liệu người dùng định nghĩa.
-   Cùng cách khai báo.
-   Cùng cách truy cập

**Khác nhau:**
| **Tiêu chí**         | **Union**                                                                                           | **Struct**                                                                                           |
|-----------------------|-----------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------|
| **Bộ nhớ sử dụng**    | - Các trường (members) chia sẻ cùng một vùng nhớ.                                                   | - Mỗi trường có vùng nhớ riêng, tổng bộ nhớ bằng tổng kích thước của tất cả các trường.               |
|                       | - Kích thước của union bằng kích thước trường lớn nhất.                                             | - Kích thước của struct bằng tổng kích thước của các trường, có thể có thêm phần căn chỉnh (padding). |
| **Lưu trữ giá trị**   | - Tại một thời điểm, chỉ một trường có thể lưu trữ giá trị hợp lệ (các trường khác sẽ bị ghi đè).     | - Tất cả các trường đều có thể lưu trữ giá trị đồng thời.                                            |
| **Mục đích sử dụng**  | - Dùng khi muốn tiết kiệm bộ nhớ và chỉ cần lưu trữ một giá trị tại một thời điểm.                   | - Dùng khi cần lưu trữ nhiều giá trị khác nhau tại cùng một thời điểm.                               |
| **Truy cập dữ liệu**  | - Khi gán giá trị cho một trường, giá trị của các trường khác có thể bị thay đổi do chia sẻ bộ nhớ. | - Các trường độc lập, giá trị của một trường không ảnh hưởng đến trường khác.                       |





</details>















<details>
<summary>LESSON 7: GOTO - SETJMP</summary>




## GOTO
Câu lệnh `goto` trong ngôn ngữ lập trình C cho phép chương trình nhảy đến một nhãn (label) được định nghĩa trong `cùng một hàm`. Nó cung cấp cơ chế điều khiển luồng chương trình bằng cách bỏ qua các dòng lệnh khác để nhảy trực tiếp đến một đoạn mã cụ thể. (Chú ý: Câu lệnh goto chỉ sử dụng trong phạm vi của một hàm).
**Cú pháp:**
```c
goto label;
// các câu lệnnh khác
label:
// đoạn mã thực thithi
```
**Giải thích:**
1.  `goto label;` : câu lệnh yếu cầu chường trình nhảy đến vị trí của label.
2.  `label:` : đây là nhãn (label), được định nghĩa như một tên hợp lệ trong C, nó kết thúc bằng dấu `:`.

**Ví dụ 1: Sử dụng trong vòng lặp**
```c
#include <stdio.h>

int main() {
    int i = 0;

    printf("Trước khi nhảy.\n");

    for (i = 0; i < 10; i++) {
        if (i == 5)
            goto skip;
        else
            printf("%d ", i);
    }

skip:
    printf("\nSau khi nhảy.\n");

    return 0;
}

```
**Output:**
```c
Trước khi nhảy.
0 1 2 3 4 
Sau khi nhảy.
```

**Giải thích:**
-   Vòng lặp for chạy từ i = 0 đến i < 10.
-   Nếu i == 5, chương trình sẽ nhảy tới nhãn skip và thoát khỏi vòng lặp.
-   In ra dòng "Sau khi nhảy.".


**Ví dụ 2: Sử dụng trong tạo menu đơn giản**
```c
#include <stdio.h>

int main() {
    int option;

menu:
    printf("Chọn một tùy chọn:\n");
    printf("1. Lựa chọn 1\n");
    printf("2. Lựa chọn 2\n");
    printf("3. Thoát\n");
    printf("Nhập lựa chọn: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Bạn chọn Lựa chọn 1.\n");
            goto menu;
        case 2:
            printf("Bạn chọn Lựa chọn 2.\n");
            goto menu;
        case 3:
            printf("Thoát chương trình.\n");
            break;
        default:
            printf("Lựa chọn không hợp lệ. Thử lại.\n");
            goto menu;
    }

    return 0;
}
```
**Output :**
```c
Chọn một tùy chọn:
1. Lựa chọn 1
2. Lựa chọn 2
3. Thoát
Nhập lựa chọn: 1
Bạn chọn Lựa chọn 1.
```

**Ưu điểm của `goto`**
-   Dễ dàng nhảy qua hoặc thoát khỏi các khối lệnh lớn, đặc biệt trong các vòng lặp lồng nhau.
-   Hữu ích để thoát ra khỏi các đoạn mã phức tạp khi phát hiện lỗi.



## SETJMP
`setjmp` và `longjmp` là hai hàm trong thư viện `<setjmp.h>` của C, dùng để thực hiện nhảy không điều kiện.
**Cách hoạt động**
1.  `setjmp(jmp_buf env):`
    -   Lưu trạng thái hiện tại của chương trình (bao gồm con trỏ chương trình, con trỏ ngăn xếp, và các thông tin cần thiết khác) vào biến kiểu `jmp_buf`.
    -   Trả về giá trị bằng 0 trong lần gọi trực tiếp đầu tiên.
2.  `longjmp(jmp_buf, int val):`
    -   Khi hàm `longjmp` được gọi, chương trình sẽ quay trở lại vị trí mà hàm setjmp đã được gọi và tiếp tục thực thi từ đó.
    -   Trả về một giá trị khác 0 cho lệnh `setjmp`.

**Ví dụ:**
```c
#include <setjmp.h>
#include <stdio.h>
jmp_buf env;

void func() {
    printf("Trong hàm func(). Nhảy ra ngoài!\n");
    longjmp(env, 1); // Nhảy về điểm setjmp
}

int main() {
    if (setjmp(env) == 0) {
        printf("Điểm ban đầu (setjmp) trong main().\n");
        func(); // Gọi hàm và nhảy ra ngoài
    } else {
        printf("Quay lại sau longjmp.\n");
    }
    return 0;
}

```

**Giải thích:**
1.  setjmp(env):
    -   Lưu trạng thái chương trình vào env.
    -   Trả về 0 (nếu không có longjmp nào xảy ra).
2.  Gọi hàm func():
    -   Trong func(), gọi longjmp(env, 1).
    -   Trạng thái của chương trình được phục hồi, quay lại chỗ setjmp(env).
3.  Lúc này, setjmp(env) sẽ trả về giá trị 1 (từ longjmp).
4.  Chương trình tiếp tục từ nhánh else trong main().
**Lưu ý: Giá trị trả về từ setjmp khi nhảy lại từ longjmp không bao giờ là 0. Nếu dùng longjmp(env, 0), giá trị trả về của setjmp sẽ là 1.**

**Ví dụ: Xử lý lỗi**
```c
#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

void divide(int a, int b) {
    if (b == 0) {
        printf("Lỗi: Chia cho 0!\n");
        longjmp(env, 1); // Nhảy về setjmp
    }
    printf("Kết quả: %d\n", a / b);
}

int main() {
    if (setjmp(env) == 0) {
        divide(10, 2); // Không lỗi
        divide(10, 0); // Gây lỗi
        printf("Kết thúc.\n");
    } else {
        printf("Đã xử lý lỗi và quay lại main().\n");
    }
    return 0;
}

```
**Output:**
```c
Kết quả: 5
Lỗi: Chia cho 0!
Đã xử lý lỗi và quay lại main().
```

</details>















<details>
<summary>LESSON 8 : MEMORY LAYOUT</summary>

### Memory layout.
    Chương trình main.exe ( trên window), main.hex ( nạp vào vi điều khiển) được lưu ở bộ nhớ SSD hoặc FLASH. Khi nhấn run chương trình trên window ( cấp nguồn cho vi điều khiển) thì những chương trình này sẽ được copy vào bộ nhớ RAM để thực thi.
### Sơ đồ tổng quát.
![Memory layout ](Memory-Layout-of-C-1.webp)

### Text segment
1.   Chứa tập hợp các lệnh thực thi
2.   Quyền truy cập
-   Chỉ đọc và thực thi:
    -   Không có quyền ghi: Giúp bảo vệ mã chương trình khỏi bị thay đổi trong quá trình chạy .
    -   Điều này đảm bảo rằng các đoạn mã tĩnh như chuỗi ký tự hoặc hằng số không thể bị ghi đè.
3.  Lưu hằng số toàn cục và chuỗi hằng.
-   Hằng số toàn cục(const):
    **Ví dụ:**
    ```c
    const int MAX = 100;
    ```
    Biến `MAX` được lưu trong `Text Segment` và không thể thay đổi giá trị sau khi khởi tạo.
-   Chuỗi hằng:
    **Ví dụ:**
    ```c
    char* msg = "Hello, World!";
    ```
    Chuỗi `"Hello, World!"` được lưu trong Text Segment. Mặc dù có thể gán con trỏ `msg` tới chuỗi này, nhưng nếu cố thay đổi nội dung chuỗi, lỗi sẽ xảy ra.
    ```c
    msg[0] = 'h'; // Lỗi: Segmentation fault
    ```
4.  Biến trong Text Segment chỉ được đọc.
**Ví dụ:**
```c
#include <stdio.h>

const int GLOBAL_CONST = 42; // Lưu ở Text Segment

int main() {
    const char* str = "Immutable String"; // Chuỗi hằng, lưu ở Text Segment
    printf("%s\n", str);

    // Thử thay đổi giá trị chuỗi hằng (sẽ gây lỗi)
    // str[0] = 'i'; 

    return 0;
}

```

### Initialized Data Segment
1.  Chứa các biến toàn cục được khởi tạo với giá trị khác 0.
```c
    int global_var = 10; // Lưu trong Initialized Data Segment
```
-   global_var là biến toàn cục và được khởi tạo với giá trị 10.
-   Giá trị này sẽ được lưu trong Initialized Data Segment.
2.  Chứa các biến static được khởi tạo với giá trị khác 0
-   Các biến static có thể là:

    -   Global static: Biến static toàn cục.
    -   Local static: Biến static cục bộ trong một hàm.
**Ví dụ:**
```c

    static int static_global_var = 5; // Lưu trong Initialized Data Segment

    void func() {
        static int static_local_var = 3; // Lưu trong Initialized Data Segment
    }
```
-   `static_global_var` và `static_local_va`r được lưu trong `Initialized Data Segment` vì chúng có từ khóa static và được khởi tạo với giá trị khác 0.

3.   Quyền truy cập là đọc và ghi
Có thể thay đổi giá trị của các biến trong Initialized Data Segment trong thời gian chạy của chương trình.
**Ví dụ:**
```c
#include <stdio.h>

int global_var = 10; // Initialized Data Segment

int main() {
    printf("Before: %d\n", global_var);
    global_var = 20; // Giá trị có thể thay đổi
    printf("After: %d\n", global_var);
    return 0;
}
```

**Output:**
```c
Before: 10
After: 20

```

4. Bộ nhớ được thu hồi khi chương trình kết thúc
-   Các biến trong `Initialized Data Segmen`t` tồn tại trong suốt thời gian sống của chương trình.
-   Khi chương trình kết thúc, toàn bộ bộ nhớ được giải phóng bởi hệ điều hành.




### Uninitialized Data Segment
1. Chứa các biến toàn cục khởi tạo với giá trị bằng 0 hoặc không gán giá trị.
**Ví dụ:**
```c
int global_var;       // Lưu trong BSS Segment
int global_var2 = 0;  // Lưu trong BSS Segment
```
-   global_var không được khởi tạo rõ ràng nên sẽ mặc định được khởi tạo bằng 0.
-   global_var2 được gán giá trị bằng 0, vì vậy nó cũng thuộc BSS Segment.

2. Chứa các biến static với giá trị khởi tạo bằng 0 hoặc không gán giá trị.
-   Biến static có thời gian sống xuyên suốt chương trình, và nếu không được gán giá trị hoặc gán giá trị bằng 0, chúng sẽ được lưu trong BSS Segment.
**Ví dụ:**
```c
static int static_var;       // Lưu trong BSS Segment
static int static_var2 = 0;  // Lưu trong BSS Segment
```
-   static_var được khởi tạo mặc định bằng 0.
-   static_var2 được khởi tạo bằng 0, nên cả hai đều được lưu trong BSS Segment.

3. Quyền truy cập: Đọc và ghi
-   Các biến trong BSS Segment có thể được đọc và thay đổi giá trị trong thời gian chạy của chương trình.
```c
#include <stdio.h>

int global_var; // lưu trong BSS Segment

int main() {
    printf("Before: %d\n", global_var);
    global_var = 42; // Thay đổi giá trị
    printf("After: %d\n", global_var);
    return 0;
}
```
**Output:**
```c
Before: 0
After: 42
```

#### Ví dụ tổng quát:
```c
#include <stdio.h>

typedef struct 
{
    int x;
    int y;
} Point_Data;


int a = 0;
int b;

static int global = 0;
static int global_2;

static Point_Data p1 = {0,0};

void test()
{
    static int local = 0;
    static int local_2;
}

int main() {

    global = 10;
    printf("a: %d\n", a);
    printf("global: %d\n", global);

    return 0;
}
```

**1. Biến toàn cục**
-   int a = 0;

    -   Được khởi tạo bằng 0, lưu trong BSS Segment.
-   int b;

    -   Không được khởi tạo, mặc định giá trị là 0. Lưu trong BSS Segment.
-   static int global = 0;

    -   Biến static toàn cục được khởi tạo bằng 0, lưu trong BSS Segment.
-   static int global_2;

    -   Biến static toàn cục chưa được khởi tạo, mặc định bằng 0. Lưu trong BSS Segment.
-   static Point_Data p1 = {0,0};

    -   p1 là một biến struct tĩnh (static), được khởi tạo với {0, 0}.
    -   Lưu trong Initialized Data Segment vì nó được khởi tạo rõ ràng.

**2. Biến cục bộ trong hàm test()**
-   static int local = 0;

    -   Biến static cục bộ, được khởi tạo bằng 0. Lưu trong BSS Segment.
-   static int local_2;

    -   Biến static cục bộ, chưa được khởi tạo. Mặc định bằng 0, lưu trong BSS Segment.


### Stack
1. Chứa các biến cục bộ (trừ static cục bộ) và tham số truyền vào hàm
-   Biến cục bộ không có từ khóa static sẽ được lưu trong Stack Segment.
-   Tham số của hàm cũng được lưu ở đây, như các giá trị được truyền khi gọi hàm.
  

**Ví dụ:**
```c
void example(int param) {
    int local_var = 10; // Lưu trên Stack
}
```
-   param là tham số truyền vào hàm → Lưu trên Stack.
-   local_var là biến cục bộ trong hàm → Lưu trên Stack.

2. Hằng số cục bộ có thể thay đổi thông qua con trỏ
-   Hằng số trong hàm (ví dụ: mảng hằng số) thường được lưu trên Stack, nhưng nếu được truy cập qua con trỏ, bạn có thể thay đổi giá trị của chúng.


**Ví dụ:**
```c
#include<stdio.h>

void func() {
    const int local_const = 42;
    int *ptr = (int *)&local_const; // Ép kiểu từ `const int*` sang `int*`
    *ptr = 100; // Thay đổi giá trị qua con trỏ (không khuyến khích)
    printf("local_const = %d\n", local_const);
}

int main() {
    func();
    return 0;
}

```

**Output**
```c
local_const = 100
```
3. Quyền truy cập: Đọc và ghi
-   Các biến trong `Stack Segment` có thể đọc và ghi giá trị trong thời gian chạy của chương trình.

**Ví dụ:**
```c
void example() {
    int local_var = 5; // Lưu trên Stack
    local_var = 10;    // Có thể thay đổi
}
```


4. Thu hồi vùng nhớ sau khi hàm kết thúc
-   Khi một hàm kết thúc, toàn bộ bộ nhớ của các biến cục bộ và tham số trên Stack sẽ được giải phóng tự động.

-   Stack hoạt động theo cơ chế LIFO (Last In, First Out), tức là vùng nhớ mới nhất được sử dụng sẽ là vùng nhớ được giải phóng đầu tiên.

**Ví dụ:**
```c
void func1() {
    int x = 10; // Lưu trên Stack
} // Sau khi func1 kết thúc, `x` sẽ được thu hồi.

void func2() {
    func1(); // Gọi func1, Stack sẽ tạo vùng nhớ riêng cho biến `x`
}
```
### Heap
- Đặc điểm: Bộ nhớ heap dùng để phân bổ bộ nhớ động, tức là bộ nhớ được cấp phát khi chương trình đang chạy (cấp phát động).
- Hoạt động:
	- Cấp phát động: Dữ liệu như đối tượng, cấu trúc dữ liệu có thể được cấp phát bộ nhớ tại thời điểm chạy.Điều này cho phép chương trình tạo ra và giải phóng bộ nhớ theo nhu cầu, thích ứng với sự biến đổi của dữ liệu trong quá trình chạy.
	- Quản lý bộ nhớ: Người lập trình phải giải phóng bộ nhớ khi không còn sử dụng để tránh rò rỉ bộ nhớ (memory leaks).
	- Phân mảnh: Khi bộ nhớ được cấp phát và giải phóng, có thể tạo ra các khoảng trống, dẫn đến phân mảnh bộ nhớ.
   	- Quyền truy cập: Bộ nhớ trên heap thường có quyền đọc và ghi, nghĩa là dữ liệu có thể được đọc và sửa đổi trong suốt thời gian chương trình chạy.
   	- Cấp Phát và Giải Phóng Bộ Nhớ: Các hàm như malloc()(Tham số truyền vào: kích thước mong muốn(byte), Giá trị trả về: con trỏ void), calloc(), realloc(), và free() được sử dụng để cấp phát và giải phóng bộ nhớ trên heap.
	- Kích Thước Thay Đổi: Kích thước của heap có thể thay đổi trong quá trình thực thi của chương trình, tùy thuộc vào các thao tác cấp phát và giải phóng bộ nhớ.
	- Không Giữ Giá Trị Mặc Định: Bộ nhớ trên heap không giữ giá trị mặc định như trong Data Segment. Nếu không được khởi tạo, giá trị của biến trên heap sẽ không xác định.
	```c
	 #include <stdlib.h>
	int main() {
	    int *arr_malloc, *arr_calloc;
	    size_t size = 5;
	
	    // Sử dụng malloc
	    arr_malloc = (int*)malloc(size * sizeof(int));
	
	    // Sử dụng calloc
	    arr_calloc = (int*)calloc(size, sizeof(int));
	
	    // ...
	
	    // Giải phóng bộ nhớ
	    free(arr_malloc);
	    free(arr_calloc);
	
	    return 0;
	}
- ví dụ
  	``c
	  #include <stdio.h>
	 #include <stdlib.h>
	int main(int argc, char const *argv[])
	{  
	    int soluongkytu = 0;
	
	    char* ten = (char*) malloc(sizeof(char) * soluongkytu);
	    for (int i = 0; i < 3; i++)
	    {
	        printf("Nhap so luong ky tu trong ten: \n");
	        scanf("%d", &soluongkytu);
	        ten = realloc(ten, sizeof(char) * soluongkytu);
	        printf("Nhap ten cua ban: \n");
	        scanf("%s", ten);
	
	        printf("Hello %s\n", ten);
	    }
	    return 0;
	}
### Stack và Heap
- Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
- Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C).
- Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động giải phóng khi hàm thực hiện xong công việc của mình.
- Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay giải phóng vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ.
  ```c
	  #include <stdio.h>
	  #include <stdlib.h>
	
	void test1()
	{
	    int array[3];
	    for (int i = 0; i < 3; i++)
	    {
	        printf("address of array[%d]: %p\n", i, (array+i));
	    }
	    printf("----------------------\n");
	}
	
	void test2()
	{
	    int *array = (int*)malloc(3*sizeof(int));
	    for (int i = 0; i < 3; i++)
	    {
	        printf("address of array[%d]: %p\n", i, (array+i));
	    }
	    printf("----------------------\n");
	    //free(array);
	}
	int main(int argc, char const *argv[])
	{  
	    test1();
	    test1();
	    test2();
	    test2();
	    return 0;
	}
- Stack: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...
	```c
	int foo(int x){
	    printf("De quy khong gioi han\n");
	    return foo(x);
	}
- Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.
	```c
int *A = (int *)malloc(18446744073709551615)

#### So sánh malloc - calloc - realloc
1.  malloc (Memory Allocation):

-   Chỉ cấp phát một vùng nhớ có kích thước bằng tham số size.
-   Không khởi tạo giá trị trong vùng nhớ.
-   Vùng nhớ chứa dữ liệu không xác định (garbage value).

**Ví dụ:**
```c
int *arr = (int *)malloc(5 * sizeof(int)); // Cấp phát vùng nhớ cho 5 số nguyên.
```

2.  calloc (Contiguous Allocation):

-   Cấp phát vùng nhớ cho một số lượng phần tử, mỗi phần tử có kích thước bằng size.
-   Tự động khởi tạo tất cả các byte trong vùng nhớ về 0.
-   Thích hợp khi cần vùng nhớ sạch (zeroed memory).

**Ví dụ:**

```c
int *arr = (int *)calloc(5, sizeof(int)); // Cấp phát vùng nhớ cho 5 số nguyên và khởi tạo về 0.

```
3.  realloc (Reallocation):

-   Thay đổi kích thước vùng nhớ đã cấp phát bằng malloc hoặc calloc.
-   Nếu kích thước mới lớn hơn, các byte mới được khởi tạo (không xác định).
-   Nếu kích thước mới nhỏ hơn, vùng nhớ bị cắt ngắn.
-   Nếu ptr là NULL, realloc hoạt động giống như malloc.

**Ví dụ:**
```c
arr = (int *)realloc(arr, 10 * sizeof(int)); // Mở rộng vùng nhớ cho 10 số nguyên.

```



</details>
 <details><summary>LESSON 9: STACK AND QUEUE </summary>
  <p>
  
 ## LESSON 11: STACK AND QUEUE
 ### STACK
 - Trong ngôn ngữ C, stack (ngăn xếp) là một vùng nhớ được sử dụng để lưu trữ dữ liệu tạm thời trong suốt quá trình thực thi chương trình. Nó đặc biệt quan trọng trong quản lý bộ nhớ, đặc biệt khi làm việc với các hàm, các biến cục bộ, và các đối số của hàm.
#### Đặc điểm của Stack:
- Nguyên lý hoạt động (Last In, First Out - LIFO): Stack hoạt động theo nguyên lý LIFO, nghĩa là dữ liệu được lưu vào stack sẽ được lấy ra theo thứ tự ngược lại (mới nhất vào trước, cũ nhất ra trước). Trong thuật ngữ ngăn xếp, hoạt động chèn được gọi là hoạt động PUSH và hoạt động xóa được gọi là hoạt động POP.
  ![image](https://github.com/user-attachments/assets/c8833a29-ef73-4d44-9667-a1ecf25bf818)
- Lưu trữ dữ liệu tạm thời: Stack chủ yếu dùng để lưu trữ:
	- Các biến cục bộ (local variables)
	- Các tham số (parameters) của hàm
	- Địa chỉ trả về (return addresses) khi gọi hàm
- Tự động cấp phát và giải phóng bộ nhớ:
	- Bộ nhớ trên stack được cấp phát khi một hàm được gọi và giải phóng khi hàm đó hoàn tất.
	- Vì vậy, stack có tính "tự động" trong việc quản lý bộ nhớ: không cần phải dùng malloc() hay free() như với heap (đống).
-Hạn chế về kích thước: Kích thước của stack là có hạn và thường nhỏ hơn so với heap. Nếu chương trình sử dụng quá nhiều bộ nhớ trên stack (ví dụ: đệ quy quá sâu), có thể dẫn đến stack overflow.
#### Các thao tác trên Stack
- "push" để thêm một phần tử vào đỉnh của stack
- "pop" để xóa một phần tử ở đỉnh stack.
- “top” để lấy giá trị của phần tử ở đỉnh stack.
- Is_Full(): Kiểm tra xem ngăn xếp đã đầy chưa
- Is_Empty(): Kiểm tra xem ngăn xếp có trống hay không.
#### Định nghĩa Stack
	 ```c
	typedef struct Stack {
	    int* items; // mảng chứa các giá trị trong ngăn xếp
	    int size;   // kích thước của mảng đó
	    int top;   // giá trị của phần tử trên cùng
	  } Stack;
 #### Khởi tạo 1 stack
 	```c
	void initialize( Stack *stack, int size) {
	    stack->items = (int*) malloc(sizeof(int) * size); //cấp phát động 1 mảng chứa các giá trị
	    stack->size = size; // truyền vào kích thước mong muốn
	    stack->top = -1; // gắn giá trị trên cùng bằng -1
	}
#### Hoạt động Is_Full() trong cấu trúc dữ liệu ngăn xếp
	```c
	int Is_Full( Stack stack) {
	    return stack.top == stack.size - 1;
	}
#### Hoạt động Is_Empty() trong cấu trúc dữ liệu ngăn xếp
	 ```c
	int Is_Empty( Stack stack) {
	    return stack.top == -1;
	 }
#### Hoạt động Push() trong cấu trúc dữ liệu ngăn xếp
	```c
	void Push( Stack *stack, int value) {
	    if (!is_full(*stack)) {
	        stack->items[++stack->top] = value;
	    } else {
	        printf("Stack overflow\n");
	    }
	}
#### Hoạt động Pop() trong cấu trúc dữ liệu ngăn xếp
	```c
	int Pop( Stack *stack) {
	    if (!is_empty(*stack)) {
	        return stack->items[stack->top--];
	    } else {
	        printf("Stack underflow\n");
	        return -1;
	    }
	}
#### Hoạt động Top() trong cấu trúc dữ liệu ngăn xếp
	```c
	int Top( Stack stack) {
	    if (!is_empty(stack)) {
	        return stack.items[stack.top];
	    } else {
	        printf("Stack is empty\n");
	        return -1;
	    }
	}
#### ví dụ
	```c
	#include <stdio.h>
	#include <stdlib.h>
	
	typedef struct Stack {
	    int* items;
	    int size;
	    int top;
	} Stack;
	
	void initialize( Stack *stack, int size) {
	    stack->items = (int*) malloc(sizeof(int) * size);
	    stack->size = size;
	    stack->top = -1;
	}
	
	int is_empty( Stack stack) {
	    return stack.top == -1;
	}
	
	int is_full( Stack stack) {
	    return stack.top == stack.size - 1;
	}
	
	void push( Stack *stack, int value) {
	    if (!is_full(*stack)) {
	        stack->items[++stack->top] = value;
	    } else {
	        printf("Stack overflow\n");
	    }
	}
	
	int pop( Stack *stack) {
	    if (!is_empty(*stack)) {
	        return stack->items[stack->top--];
	    } else {
	        printf("Stack underflow\n");
	        return -1;
	    }
	}
	
	int top( Stack stack) {
	    if (!is_empty(stack)) {
	        return stack.items[stack.top];
	    } else {
	        printf("Stack is empty\n");
	        return -1;
	    }
	}
	
	int main() {
	    Stack stack1;
	    initialize(&stack1, 5);
	
	
	    push(&stack1, 10);
	    push(&stack1, 20);
	    push(&stack1, 30);
	    push(&stack1, 40);
	    push(&stack1, 50);
	    push(&stack1, 60);
	
	    printf("Top element: %d\n", top(stack1));
	
	    printf("Pop element: %d\n", pop(&stack1));
	    printf("Pop element: %d\n", pop(&stack1));
	
	    printf("Top element: %d\n", top(stack1));
	
	    return 0;
	}
 ### QUEUE
 - Queue (hàng đợi) là một cấu trúc dữ liệu dùng để lưu trữ và quản lý các phần tử theo nguyên lý FIFO (First In, First Out - Vào trước, ra trước). Điều này có nghĩa là phần tử được thêm vào đầu tiên sẽ được lấy ra đầu tiên. Queue thường được sử dụng trong các bài toán yêu cầu xử lý các phần tử theo thứ tự thời gian như trong các hệ thống lên lịch, xử lý sự kiện, hoặc các thuật toán tìm kiếm.
   ![image](https://github.com/user-attachments/assets/93917cbc-0101-45df-a710-3f3ce897ddae)
#### Đặc điểm của Queue
- Chỉ để cập tới Circular queue, ta có hai từ khóa front và rear:
	- front đại diện cho vị trí của phần tử đầu tiên trong hàng đợi. Đây là phần tử sẽ được lấy ra đầu tiên khi thực hiện thao tác dequeue (lấy phần tử ra).
	-rear đại diện cho vị trí của phần tử cuối cùng trong hàng đợi. Đây là phần tử cuối cùng được thêm vào khi thực hiện thao tác enqueue (thêm phần tử vào).
- Khi queue rỗng, front và rear bằng -1.
- Khi queue đầy, (rear + 1) % size == front.
- Khi thực hiện dequeue, chỉ số front sẽ được tăng lên để trỏ tới phần tử tiếp theo trong hàng đợi.
- Khi thực hiện enqueue, rear sẽ được tăng lên để trỏ tới vị trí mới cho phần tử vừa được thêm vào hàng đợi.
- Nếu hàng đợi đầy, rear sẽ quay vòng theo cơ chế vòng tròn (circular queue), điều này có nghĩa là khi rear đạt tới giới hạn của mảng, nó sẽ quay về 0 để sử dụng lại vị trí cũ chỉ khi có phần tử được dequeue.
  #### Các thao tác trên Queue
- enqueue(): Thêm 1 phần tử dữ liệu vào trong hàng đợi
- dequeue(): Xóa 1 phần tử từ hàng đợi
- Front(): lấy phần tử ở đầu hàng đợi, mà không xóa phần tử này
- Is_Full(): Kiểm tra xem hàng đợi đã đầy chưa
- Is_Empty(): Kiểm tra xem hàng đợi có trống hay không
  	```c
	#include <stdio.h>
	#include <stdlib.h>
	
	
	typedef struct Queue {
	    int* items;
	    int size;
	    int front, rear;
	} Queue;
	
	void initialize(Queue *queue, int size) 
	{
	    queue->items = (int*) malloc(sizeof(int)* size);
	    queue->front = -1;
	    queue->rear = -1;
	    queue->size = size;
	}
	
	int is_empty(Queue queue) {
	    return queue.front == -1;
	}
	
	int is_full(Queue queue) {
	    return (queue.rear + 1) % queue.size == queue.front;
	}
	
	void enqueue(Queue *queue, int value) {
	    if (!is_full(*queue)) {
	        if (is_empty(*queue)) {
	            queue->front = queue->rear = 0;
	        } else {
	            queue->rear = (queue->rear + 1) % queue->size;
	        }
	        queue->items[queue->rear] = value;
	    } else {
	        printf("Queue overflow\n");
	    }
	}
	
	int dequeue(Queue *queue) {
	    if (!is_empty(*queue)) {
	        int dequeued_value = queue->items[queue->front];
	        if (queue->front == queue->rear) {
	            queue->front = queue->rear = -1;
	        } else {
	            queue->front = (queue->front + 1) % queue->size;
	        }
	        return dequeued_value;
	    } else {
	        printf("Queue underflow\n");
	        return -1;
	    }
	}
	
	int front(Queue queue) {
	    if (!is_empty(queue)) {
	        return queue.items[queue.front];
	    } else {
	        printf("Queue is empty\n");
	        return -1;
	    }
	}
	
	int main() {
	    Queue queue;
	    initialize(&queue, 3);
	
	    enqueue(&queue, 10);
	    enqueue(&queue, 20);
	    enqueue(&queue, 30);
	
	    printf("Front element: %d\n", front(queue));
	
	    printf("Dequeue element: %d\n", dequeue(&queue));
	    printf("Dequeue element: %d\n", dequeue(&queue));
	
	    printf("Front element: %d\n", front(queue));
	
	    enqueue(&queue, 40);
	    enqueue(&queue, 50);
	    printf("Dequeue element: %d\n", dequeue(&queue));
	    printf("Front element: %d\n", front(queue));
	
	    return 0;
	}

</details>















<details><summary>LESSON 10: LINKED LIST </summary>
  <p>
  
 ## LESSON 10: LINKED LIST
 ### Khái niệm Linked list 
 - Linked list là một cấu trúc dữ liệu trong lập trình máy tính, được sử dụng để tổ chức và lưu trữ dữ liệu. Một linked list bao gồm một chuỗi các "nút" (nodes) được lưu trữ không liền kề nhau trong bộ nhớ, mỗi nút chứa một giá trị dữ liệu và một con trỏ (pointer) đến nút tiếp theo trong chuỗi.
- Khác với mảng (array), trong đó các phần tử được lưu trữ liên tiếp trong bộ nhớ, linked list cho phép linh hoạt hơn trong việc thêm và xóa phần tử mà không cần phải thay đổi kích thước hoặc di chuyển các phần tử khác.
![image](https://github.com/user-attachments/assets/edcf0aa4-5c38-4d7b-8846-c8435ea056c6)
### Các loại linked list
- Có hai loại linked list chính:
	- Singly Linked List (Danh sách liên kết đơn): Mỗi nút chỉ chứa một con trỏ đến nút tiếp theo trong chuỗi.
	- Doubly Linked List (Danh sách liên kết đôi): Mỗi nút chứa hai con trỏ, một trỏ đến nút tiếp theo và một trỏ đến nút trước đó.
### Tính chất
- Danh sách liên kết có thể mở rộng và thu hẹp một cách linh hoạt.
- Mặc định nodes sẽ chưa liên kết với nhau => phải liên kết các nodes thông qua con trỏ.
- Phần tử cuối cùng trong Linked list sẽ trỏ vào NULL (con trỏ NULL), đánh dấu sự kết thúc của danh sách.
- Linked list có thể thay đổi kích thước linh hoạt. Bạn có thể thêm hoặc xóa các node mà không cần phải thay đổi kích thước của danh sách hoặc di chuyển các phần tử khác, như trong mảng.
- Để truy cập một phần tử bất kỳ trong linked list, bạn phải bắt đầu từ node đầu tiên và duyệt lần lượt qua các node tiếp theo cho đến khi tìm thấy phần tử cần tìm. Điều này làm cho việc truy cập các phần tử ngẫu nhiên (random access) kém hiệu quả hơn so với mảng.
- Đây là kiểu cấu trúc dữ liệu kiểu cấp phát động có nghĩa là còn bộ nhớ thì còn cấp phát được, cấp phát đến khi nào hết bộ nhớ thì thôi - Vùng nhớ cấp phát : Heap.
- Linked list chỉ sử dụng bộ nhớ cho các node đã được tạo ra. Điều này giúp tiết kiệm bộ nhớ khi số lượng phần tử thay đổi liên tục. Không lãng phí bộ nhớ nhưng cần thêm bộ nhớ để lưu phần con trỏ.
- Thêm hoặc xóa node ở đầu hoặc giữa danh sách có thể thực hiện nhanh chóng (O(1)) nếu bạn đã có địa chỉ của node cần thay đổi. Tuy nhiên, nếu muốn xóa hoặc thêm ở cuối danh sách, bạn cần phải duyệt qua danh sách trước (O(n)).
### Cấu trúc của 1 node
- Trong C, ta thường dùng cấu trúc (struct) để định nghĩa một node. Cấu trúc này bao gồm:
	- Dữ liệu (data): chứa giá trị hoặc thông tin của phần tử.
	- Con trỏ (pointer): chứa địa chỉ của node tiếp theo trong danh sách.
 		```c
		  typedef struct Node { // có Node ở dòng 1 để khi phiên dịch mã sẽ hiểu Node* next ở dòng 3, không báo lỗi
		    int data;           // Giá trị (dữ liệu) của node
		    struct Node* next;  // Con trỏ trỏ đến node tiếp theo
		};
  	- Node ở đây có phần dữ liệu là kiểu số nguyên, ngoài ra nó có 1 con trỏ next trỏ tới chính struct node (là địa chỉ của node tiếp theo trong linked list)
### Các thao tác với linked list
#### Khởi tạo Node 
    ```c
	#include <stdio.h>
	#include <stdlib.h>
	
	struct Node {
	    int data;     // Dữ liệu của node
	    struct Node* next; // Con trỏ tới node tiếp theo
	  };
	
	// Khởi tạo một node mới với dữ liệu là 10
	struct Node* createNode(int data) {
	    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // khởi tạo địa chỉ cho Node
	    newNode->data = data;
	    newNode->next = NULL; // chưa liên kết Node với nhau thì phải Null trước
	    return newNode; // trả về lại vị trí của newNode
	    }
	
	int main() {
	    struct Node* node1 = createNode(10);
	    printf("Data of the new node: %d\n", node1->data);
	    return 0;
	    }
#### Thêm một Node vào vị trí cuối cùng trong list
![image](https://github.com/user-attachments/assets/bd1b4279-90f5-4346-985b-9762961f2952)
- quy trình thêm một node vào cuối danh sách là:
	- Tạo node mới với dữ liệu bạn muốn thêm.
	- Nếu danh sách rỗng, gán node mới làm head.
	- Nếu danh sách không rỗng, duyệt qua danh sách đến node cuối cùng, sau đó gán con trỏ next của node cuối cùng trỏ đến node mới.
    ```c
	#include <stdio.h>
	#include <stdlib.h>
	
	struct Node {
	    int data;
	    struct Node* next;
	};
	
	// Hàm tạo node mới
	struct Node* createNode(int data) {
	    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	    newNode->data = data;
	    newNode->next = NULL;
	    return newNode;
	}
	
	// Hàm thêm node vào cuối danh sách
	void append(struct Node** head, int data) {
	    struct Node* newNode = createNode(data);
	    
	    // Nếu danh sách rỗng, gán node mới làm head
	    if (*head == NULL) {
	        *head = newNode;
	        return;
	    }
	
	    // Duyệt đến node cuối cùng
	    struct Node* last = *head;
	    while (last->next != NULL) {
	        last = last->next;
	    }
	
	    // Gán con trỏ next của node cuối cùng trỏ đến node mới
	    last->next = newNode;
	}
	
	// Hàm in danh sách liên kết
	void printList(struct Node* head) {
	    struct Node* temp = head;
	    while (temp != NULL) {
	        printf("%d -> ", temp->data);
	        temp = temp->next;
	    }
	    printf("NULL\n");
	}
	
	int main() {
	    struct Node* head = NULL;
	    
	    append(&head, 10);
	    append(&head, 20);
	    append(&head, 30);
	    
	    printList(head);  // Output: 10 -> 20 -> 30 -> NULL
	    return 0;}
#### Chèn một node vào vị trí đầu tiên trong list
- Tạo một node mới với dữ liệu bạn muốn chèn.
- Gán con trỏ next của node mới trỏ đến head hiện tại (node đầu tiên của danh sách).
- Cập nhật head để trỏ đến node mới
  ```c
	  // Hàm thêm một node vào đầu danh sách
	void insertAtHead(struct Node** head, int data) {
	    struct Node* newNode = createNode(data);  // Tạo node mới với dữ liệu
	
	    // Gán con trỏ next của node mới trỏ đến node đầu tiên (head) hiện tại
	    newNode->next = *head;
	    
	    // Cập nhật head để trỏ đến node mới
	    *head = newNode;
	}
	
	// Hàm in danh sách liên kết
	void printList(struct Node* head) {
	    struct Node* temp = head;
	    while (temp != NULL) {
	        printf("%d -> ", temp->data);  // In dữ liệu của node
	        temp = temp->next;             // Di chuyển đến node tiếp theo
	    }
	    printf("NULL\n");  // In kết thúc danh sách
	}
#### Chèn một node vào vị trí bất kì
- Tạo một node mới với dữ liệu bạn muốn chèn.
- Duyệt đến vị trí chèn: Bạn cần duyệt qua danh sách cho đến vị trí cần chèn. Vị trí này sẽ được chỉ định dưới dạng chỉ số (index).
- Chỉnh sửa các con trỏ: Sau khi tìm thấy vị trí chèn, bạn sẽ thực hiện các bước sau:
	- Gán con trỏ next của node mới trỏ tới node tại vị trí tiếp theo (nếu có).
	- Gán con trỏ next của node trước vị trí chèn (node tại vị trí index-1) trỏ tới node mới.
   ```c
	   // Hàm thêm một node vào vị trí bất kỳ trong danh sách
	void insertAtPosition(struct Node** head, int data, int position) {
	    // Nếu vị trí không hợp lệ (vị trí nhỏ hơn 0)
	    if (position < 0) {
	        printf("Vị trí không hợp lệ.\n");
	        return;
	    }
	
	    // Tạo node mới với dữ liệu cần thêm
	    struct Node* newNode = createNode(data);
	
	    // Nếu thêm ở đầu (vị trí 0)
	    if (position == 0) {
	        newNode->next = *head;  // Con trỏ next của node mới trỏ đến node đầu tiên
	        *head = newNode;        // Cập nhật head trỏ đến node mới
	        return;
	    }
	
	    // Duyệt đến node trước vị trí cần chèn (node ở vị trí position - 1)
	    struct Node* temp = *head;
	    for (int i = 0; i < position - 1 && temp != NULL; i++) {
	        temp = temp->next;
	    }
	
	    // Nếu temp là NULL, vị trí quá lớn, không thể thêm
	    if (temp == NULL) {
	        printf("Vị trí vượt quá danh sách hiện tại.\n");
	        free(newNode);
	        return;
	    }
	
	    // Gắn con trỏ next của node mới trỏ đến node tiếp theo của node hiện tại
	    newNode->next = temp->next;
	
	    // Gắn con trỏ next của node hiện tại trỏ đến node mới
	    temp->next = newNode;
	}
#### Xóa node đầu list
 	```c
		// Hàm xóa node đầu tiên trong danh sách
	void deleteAtHead(struct Node** head) {
	    // Kiểm tra danh sách có rỗng không
	    if (*head == NULL) {
	        printf("Danh sách rỗng, không có node để xóa.\n");
	        return;
	    }
	
	    // Lưu trữ node đầu tiên
	    struct Node* temp = *head;
	
	    // Cập nhật head để trỏ đến node tiếp theo
	    *head = (*head)->next;
	
	    // Giải phóng bộ nhớ của node đầu tiên
	    free(temp);
	}
#### xóa node cuối list
	```c
	// Hàm xóa node cuối cùng trong danh sách
	void deleteAtEnd(struct Node** head) {
	    // Kiểm tra danh sách có rỗng không
	    if (*head == NULL) {
	        printf("Danh sách rỗng, không có node để xóa.\n");
	        return;
	    }
	
	    // Nếu chỉ có một node duy nhất
	    if ((*head)->next == NULL) {
	        free(*head);  // Giải phóng bộ nhớ của node duy nhất
	        *head = NULL; // Cập nhật head về NULL
	        return;
	    }
	
	    // Duyệt đến node trước node cuối cùng
	    struct Node* temp = *head;
	    while (temp->next != NULL && temp->next->next != NULL) {
	        temp = temp->next;  // Di chuyển đến node trước node cuối cùng
	    }
	
	    // Xóa node cuối cùng
	    free(temp->next);  // Giải phóng bộ nhớ của node cuối cùng
	    temp->next = NULL;  // Cập nhật con trỏ next của node trước node cuối cùng thành NULL
#### Lấy kích thước của list
	```c
	// Hàm lấy kích thước của danh sách liên kết
	int getSize(struct Node* head) {
	    int size = 0;  // Khởi tạo biến đếm kích thước
	    struct Node* temp = head;
	    
	    // Duyệt qua danh sách và đếm số node
	    while (temp != NULL) {
	        size++;
	        temp = temp->next;  // Di chuyển đến node tiếp theo
	    }
	    
	    return size;
	}
  </details>









  <details><summary>LESSON 12: BINARY SEARCH - FILE OPERATIONS - CODE STANDARDS </summary>
  <p>
  
 ## LESSON 12: BINARY SEARCH - FILE OPERATIONS - CODE STANDARDS
 ### BINARY SEARCH
 - Binary Search (tìm kiếm nhị phân) là một thuật toán tìm kiếm hiệu quả trong một danh sách đã được sắp xếp (tăng dần hoặc giảm dần). Thuật toán này hoạt động bằng cách liên tục chia đôi danh sách và so sánh giá trị cần tìm với phần tử ở giữa, từ đó loại bỏ một nửa của danh sách và tiếp tục tìm kiếm trong nửa còn lại.
#### Các bước mô tả thuật toán
- Khởi tạo: Đặt hai chỉ số left và right lần lượt trỏ tới phần tử đầu và phần tử cuối của danh sách.
- Tính giữa: Tính chỉ số của phần tử ở giữa danh sách bằng công thức: mid = (left + right) /2
- So sánh:
	- Nếu phần tử giữa bằng giá trị cần tìm, thuật toán kết thúc và trả về chỉ số của phần tử.
	- Nếu phần tử giữa lớn hơn giá trị cần tìm, tìm kiếm sẽ tiếp tục ở nửa bên trái của danh sách, tức là điều chỉnh lại right = mid - 1.
	- Nếu phần tử giữa nhỏ hơn giá trị cần tìm, tìm kiếm sẽ tiếp tục ở nửa bên phải của danh sách, tức là điều chỉnh lại left = mid + 1.
- Lặp lại: Lặp lại bước 2 và 3 cho đến khi giá trị được tìm thấy hoặc không còn phần tử nào để kiểm tra (left > right).
#### Đặc điểm:
- Thời gian chạy: Thuật toán tìm kiếm nhị phân có thời gian chạy O(log n), rất nhanh khi so với tìm kiếm tuyến tính O(n), đặc biệt là với các danh sách có kích thước lớn.
- Yêu cầu: Danh sách phải được sắp xếp (theo thứ tự tăng dần hoặc giảm dần).
#### Ví dụ tìm kiếm nhị phân
	 ```c
	#include <stdio.h>
	#include <stdlib.h>
	
	int binarySearch(int* arr, int l, int r, int x)
	{
	    if (r >= l)
	    {
	        int mid = (r + l) / 2;
	
	  
	        if (arr[mid] == x)  return mid;
	
	   
	        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
	
	  
	        return binarySearch(arr, mid + 1, r, x);
	    }
	
	
	
	
	    return -1;
	}
	
	void swap(int *a, int *b)
	{
	    int temp = *a; // 0x02 (10), 0x03 (20)
	    *a = *b;
	    *b = temp;
	}
	
	void bubbleSort(int arr[], int n)
	{
	    int i, j;
	    for (i = 0; i < n - 1; i++)
	    {
	       
	        for (j = 0; j < n - i - 1; j++)
	        {
	           
	            if (arr[j] > arr[j + 1])
	                swap(&arr[j], &arr[j + 1]);
	        }
	    }
	}
	
	int main()
	{
		int n, x, i;
	    printf("Nhap so phan tu cua mang: ");
	    scanf_s("%d", &n);
	    int* arr = (int*)malloc(n * sizeof(int));
	    printf("Nhap cac phan tu cua mang: ");
	    for (i = 0; i < n; i++)
	    {
	        scanf_s("%d", &arr[i]);
	    }
	
	    bubbleSort(arr, n);
	    for (int i = 0; i < n; i++)
	    {
	        printf_s("i = %d\n", arr[i]);
	    }
	
	    printf_s("Nhap gia tri can tim: ");
	    scanf_s("%d", &x);
	    int result = binarySearch(arr, 0, n - 1, x);
	    if (result == -1)
	        printf_s("Khong tim thay %d trong mang.\n", x);
	    else
	        printf_s("Tim thay %d tai vi tri %d trong mang.\n", x, result);
	    free(arr);
	    return 0;
	}
### FILE OPERATIONS
- Ngôn ngữ lập trình C cung cấp một số thư viện và hàm tiêu biểu để thực hiện các thao tác với file. 
- File CSV (Comma-Separated Values) là một loại file văn bản được sử dụng để lưu trữ và truyền tải dữ liệu có cấu trúc dưới dạng bảng, trong đó các dữ liệu của các cột được phân tách bằng dấu phẩy (,) hoặc một ký tự ngăn cách khác.
#### Mở file
- Để mở một file, bạn có thể sử dụng hàm fopen(). Hàm này trả về một con trỏ FILE, và cần được kiểm tra để đảm bảo file đã mở thành công.
	```c
	FILE *file = fopen(const char *file_name, const char *access_mode);
	// filename: Tên tệp tin.
	// mode: Chế độ mở tệp tin (ví dụ: "r", "w", "a", "r+", "w+", ...).
#### Đọc file
- Đọc từ tệp tin: Sau khi mở tệp tin, bạn có thể đọc dữ liệu từ tệp bằng các hàm như fgetc(), fgets(), hoặc fread().
	- fgetc(FILE *stream): Đọc một ký tự từ tệp tin.
	- fgets(char *str, int num, FILE *stream): Đọc một dòng từ tệp tin.
	- fread(void *ptr, size_t size, size_t count, FILE *stream): Đọc dữ liệu vào bộ nhớ.
#### Ghi file
- Ghi vào tệp tin: Bạn có thể ghi dữ liệu vào tệp bằng các hàm như fputc(), fputs(), hoặc fwrite().

	- fputc(int char, FILE *stream): Ghi một ký tự vào tệp.
	- fputs(const char *str, FILE *stream): Ghi một chuỗi vào tệp.
	- fwrite(const void *ptr, size_t size, size_t count, FILE *stream): Ghi dữ liệu vào tệp từ bộ nhớ.
 #### Đóng file
- Đóng tệp tin: Sau khi hoàn thành việc thao tác với tệp, bạn cần đóng tệp để giải phóng tài nguyên bằng cách sử dụng hàm fclose().

	```c
	int fclose(FILE *stream);
#### Kiểm tra lỗi hoặc kết thúc tệp
- feof(FILE *stream): Kiểm tra nếu con trỏ tệp đang ở cuối tệp.
- ferror(FILE *stream): Kiểm tra nếu có lỗi xảy ra khi làm việc với tệp.
#### Di chuyển con trỏ tệp:
- fseek(FILE *stream, long offset, int whence): Di chuyển con trỏ tệp đến vị trí mới.
- ftell(FILE *stream): Lấy vị trí hiện tại của con trỏ tệp.
- rewind(FILE *stream): Đặt con trỏ tệp về vị trí đầu của tệp.
  
#### Ví dụ về thao tác với tệp tin trong C:
	```c

	#include <stdio.h>
	
	int main() {
	    FILE *file;
	    char str[100];
	
	    // Mở tệp để ghi
	    file = fopen("example.txt", "w");
	    if (file == NULL) {
	        printf("Không thể mở tệp\n");
	        return 1;
	    }
	
	    // Ghi vào tệp
	    fprintf(file, "Hello, World!\n");
	    fclose(file);
	
	    // Mở tệp để đọc
	    file = fopen("example.txt", "r");
	    if (file == NULL) {
	        printf("Không thể mở tệp\n");
	        return 1;
	    }
	
	    // Đọc dữ liệu từ tệp
	    while (fgets(str, sizeof(str), file)) {
	        printf("%s", str);
	    }
	
	    fclose(file);
	
	    return 0;
	}
#### Các chế độ mở tệp tin:
Tham số truyền vào access_mod là quyền sử dụng file:

- r: Mở file với chế độ chỉ đọc file. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL.
- rb: Mở file với chế độ chỉ đọc file theo định dạng binary. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL.
- w: Mở file với chế độ ghi vào file. Nếu file đã tồn tại, thì sẽ ghi đè vào nội dung bên trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL.
- wb: Mở file với chế độ ghi vào file theo định dạng binary. Nếu file đã tồn tại, thì sẽ ghi đè vào nội dung bên trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL.
- a: Mở file với chế độ nối. Nếu mở file thành công thì trả về địa chỉ của phần tử cuối cùng trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL.
- ab: Mở file với chế độ nối dưới định dạng binary. Nếu mở file thành công thì trả về địa chỉ của phần tử cuối cùng trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL.
- r+: Mở file với chế độ đọc và ghi file. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL.
- rb+: Mở file với chế độ đọc và ghi file dưới định dạng binary. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL.
</details>