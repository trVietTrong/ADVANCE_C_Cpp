# LESSION 1: COMPILER AND MACROMACRO
## I. ĐỊNH NGHĨA 
### Quá trình biên dịch
    Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao(NNBC) 
    (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để 
    máy tính có thể hiểu và thực thi.
### Quá trình biên dịch gồm 4 giai đoạn
    1. Giai đoạn tiền xử lý (Pre-processor).
    2. Giai đoạn dịch NNBC sang Asembly (Compiler).
    3. Giai đoạn dịch asembly sang ngôn ngữ máy (Asember).
    4. Giai đoạn liên kết (Linker).
   
   ![Quá trình biên dịch](compiler.png)
## II. HOẠT ĐỘNG 
    1. Giai đoạn tiền xử lý - Preprocessor 
    Giai đoạn này sẽ thực hiện: 
        - Nhận mã nguồn.
        - Xóa bỏ chú thích, comments của chướng trình.
        - Chỉ thị tiền xử lý(bắt đầu bằng dấu #) cũng được xử lý.
   