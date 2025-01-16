#include <stdio.h>
#include <string.h>

#define MAX 100 // Định nghĩa kích thước tối đa cho tên và số điện thoại

// Cấu trúc lưu trữ thông tin của một người
typedef struct {
    char ten[MAX];
    char so_dien_thoai[MAX];
} Nguoi;

// Hàm tìm kiếm theo số điện thoại trong danh sách
int tim_kiem_so_dien_thoai(Nguoi danh_sach[], int so_luong, char so_dien_thoai_can_tim[]) {
    for (int i = 0; i < so_luong; i++) {
        if (strcmp(danh_sach[i].so_dien_thoai, so_dien_thoai_can_tim) == 0) {
            return i; // Trả về chỉ số nếu tìm thấy
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy số điện thoại
}

int main() {
    // Khởi tạo danh sách người dùng với tên và số điện thoại
    Nguoi danh_sach[] = {
        {"Nguyen Anh Tu", "0123456789"},
        {"Tran Minh Hoang", "0987654321"},
        {"Pham Thi Lan", "0912345678"},
        {"Le Thi Mai", "0901234567"}
    };

    int so_luong = 4; // Số lượng người trong danh sách
    char so_dien_thoai_can_tim[MAX];

    printf("Nhap so dien thoai can tim: ");
    fgets(so_dien_thoai_can_tim, MAX, stdin);

    // Gọi hàm tìm kiếm
    int vi_tri = tim_kiem_so_dien_thoai(danh_sach, so_luong, so_dien_thoai_can_tim);

    if (vi_tri != -1) {
        printf("Tim thay so dien thoai '%s' cua '%s'.\n", so_dien_thoai_can_tim, danh_sach[vi_tri].ten);
    } else {
        printf("Khong tim thay so dien thoai '%s' trong danh sach.\n", so_dien_thoai_can_tim);
    }

    return 0;
}
