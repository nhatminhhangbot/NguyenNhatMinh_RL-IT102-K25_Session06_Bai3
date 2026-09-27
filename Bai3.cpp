#include <stdio.h>
#include <string.h>

int main() {
    char maPhieu[100][20];
    char maSach[100][20];
    int soNgayMuon[100];
    int soLuong = 0;
    int choice;

    do {
        printf("\n================ HE THONG QUAN LY MUON TRA SACH (LOGISTICS) ================\n");
        printf("1. Them moi phieu muon sach (Create)\n");
        printf("2. Hien thi danh sach phieu muon & Tien phat qua han (Read)\n");
        printf("3. Cap nhat so ngay muon sach (Update)\n");
        printf("4. Xac nhan tra sach / Xoa phieu muon (Delete)\n");
        printf("5. Thoat chuong trinh\n");
        printf("===========================================================================\n");
        printf("Lua chon cua ban (1-5): ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Lua chon khong hop le, vui long chon lai!\n");
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1: {
                if (soLuong >= 100) {
                    printf("Bo nho danh sach da day, khong the them moi!\n");
                    break;
                }
                char tempMa[20];
                printf("--- THEM MOI PHIEU MUON ---\n");
                printf("Nhap ma phieu: ");
                scanf("%s", tempMa);
                while (getchar() != '\n');

                int exists = 0;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], tempMa) == 0) {
                        exists = 1;
                        break;
                    }
                }

                if (exists) {
                    printf("Ma phieu da ton tai trong he thong!\n");
                    break;
                }

                strcpy(maPhieu[soLuong], tempMa);
                printf("Nhap ma sach: ");
                scanf("%s", maSach[soLuong]);
                while (getchar() != '\n');

                do {
                    printf("Nhap so ngay muon: ");
                    scanf("%d", &soNgayMuon[soLuong]);
                    while (getchar() != '\n');
                    if (soNgayMuon[soLuong] <= 0) {
                        printf("So ngay muon phai lon hon 0!\n");
                    }
                } while (soNgayMuon[soLuong] <= 0);

                soLuong++;
                printf("Them moi phieu muon thanh cong!\n");
                break;
            }
            case 2: {
                if (soLuong == 0) {
                    printf("Danh sach phieu muon hien dang rong!\n");
                    break;
                }
                printf("================================ DANH SACH PHIEU MUON ================================\n");
                printf("STT\tMA PHIEU\tMA SACH\t\tSO NGAY\tTRANG THAI\tTIEN PHAT (VND)\n");
                for (int i = 0; i < soLuong; i++) {
                    int tienPhat = 0;
                    char* trangThai = "DUNG HAN";
                    if (soNgayMuon[i] > 14) {
                        int ngayQuaHan = soNgayMuon[i] - 14;
                        tienPhat = ngayQuaHan * 5000;
                        trangThai = "QUA HAN";
                    }
                    printf("%d\t%-10s\t%-10s\t%d\t%-10s\t%d\n", i + 1, maPhieu[i], maSach[i], soNgayMuon[i], trangThai, tienPhat);
                }
                printf("======================================================================================\n");
                break;
            }
            case 3: {
                char searchMa[20];
                printf("Nhap ma phieu can cap nhat: ");
                scanf("%s", searchMa);
                while (getchar() != '\n');

                int pos = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], searchMa) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("Khong tim thay ma phieu trong he thong!\n");
                } else {
                    printf("So ngay muon hien tai cua phieu %s la: %d\n", maPhieu[pos], soNgayMuon[pos]);
                    do {
                        printf("Nhap so ngay muon moi: ");
                        scanf("%d", &soNgayMuon[pos]);
                        while (getchar() != '\n');
                        if (soNgayMuon[pos] <= 0) {
                            printf("So ngay muon phai lon hon 0!\n");
                        }
                    } while (soNgayMuon[pos] <= 0);
                    printf("Cap nhat so ngay muon thanh cong!\n");
                }
                break;
            }
            case 4: {
                char searchMa[20];
                printf("Nhap ma phieu xac nhan tra/xoa: ");
                scanf("%s", searchMa);
                while (getchar() != '\n');

                int pos = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], searchMa) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("Khong tim thay ma phieu can xoa!\n");
                } else {
                    for (int i = pos; i < soLuong - 1; i++) {
                        strcpy(maPhieu[i], maPhieu[i + 1]);
                        strcpy(maSach[i], maSach[i + 1]);
                        soNgayMuon[i] = soNgayMuon[i + 1];
                    }
                    soLuong--;
                    printf("Xac nhan tra sach va xoa phieu muon thanh cong!\n");
                }
                break;
            }
            case 5:
                printf("Cam on ban da su dung he thong!\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
