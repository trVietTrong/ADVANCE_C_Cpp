#include <stdio.h>
#include <setjmp.h>

// Định nghĩa các mã lỗi
enum ErrorCodes { NO_ERROR, FILE_ERROR, NETWORK_ERROR, CALCULATION_ERROR };

// Biến lỗi và thông báo lỗi
jmp_buf jump_buffer;
int error_code = NO_ERROR;
const char *error_message = NULL;


#define TRY if ((error_code = setjmp(jump_buffer)) == 0)
#define CATCH(error) else if (error_code == error)
#define THROW(code, message) \
    do { \
        error_code = code; \
        error_message = message; \
        longjmp(jump_buffer, code); \
    } while (0)

// Hàm đọc file
void readFile() {
    printf("Đọc file...\n");
    THROW(FILE_ERROR, "Lỗi đọc file: File không tồn tại.");
}

// Hàm xử lý mạng
void networkOperation() {
    printf("Thực hiện xử lý mạng...\n");
    THROW(NETWORK_ERROR, "Lỗi xử lý mạng: Không thể kết nối.");
}

// Hàm tính toán dữ liệu
void calculateData() {
    printf("Tính toán dữ liệu...\n");
    THROW(CALCULATION_ERROR, "Lỗi tính toán: Phép tính không hợp lệ.");
}

int main() {
    printf("Bắt đầu chương trình...\n");

    TRY {
        readFile();
        networkOperation();
        calculateData();
    }
    CATCH(FILE_ERROR) {
        printf("%s\n", error_message);
    }
    CATCH(NETWORK_ERROR) {
        printf("%s\n", error_message);
    }
    CATCH(CALCULATION_ERROR) {
        printf("%s\n", error_message);
    }
    
    printf("Chương trình kết thúc an toàn.\n");

    return 0;
}
