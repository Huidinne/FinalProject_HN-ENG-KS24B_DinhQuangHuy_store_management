#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char id[10];
    char name[10];
} Category;

Category categories[50];
int categoryCount = 0;

void mainCategory();
void loadFile();
void saveFile();
void showMenuCategory();
void showCategories();
void addCategory();
void editCategory();
void deleteCategory();
void searchCategoryByName();
void sortCategories();
int showSubMenu();

typedef struct {
    char productID[20];
    char productName[50];
    int quantity;
    float price;
    char categoryID[10];;
} Product;

Product products[50];
int productCount = 0;

void mainProduct();
void loadProducts();
void saveProducts();
void showMenuProduct();
void showProducts();
void addProduct();
void editProduct();
void deleteProduct();
void searchProduct();


int main() {
	int pick;
	do{
		system("cls");
		printf("\n===========MAIN MENU===========\n\n");
		printf("[1]. Quan Li Danh Muc\n");
		printf("[2]. Quan Li San Pham\n");
		printf("[3]. Thoat\n");
		printf("\n===============================\n");
		printf("Lua chon cua ban la: ");
		scanf("%d", &pick);
	
			switch(pick){
				case 1:{
					mainCategory();
					break;
				}
				case 2:{
					mainProduct();
					break;
				}
				case 3:{
					printf("Thoat\n");
					break;
				}
				default:{
					printf("Lua chon khong hop le\n");
					break;
				}
			}
		}while(pick!=3);
    return 0;
}

void mainCategory(){
	loadFile();
    int choice;
    do {
        showMenuCategory();
        printf("\nNhap lua chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                showCategories();
                break;
            case 2:
                addCategory();
                break;
            case 3:
                editCategory();
                break;
            case 4:
                deleteCategory();
                break;
            case 5:
                searchCategoryByName();
                break;
            case 6:
                sortCategories(); 
                break;
            case 7:
                saveFile();
                printf("\nDu lieu da duoc luu. Thoat...\n");
                break;
            default:
                printf("\nLua chon khong hop le.\n");
        }
    } while (choice != 7);
    return;
}

void loadFile() {
    FILE* file = fopen("categories.dat", "rb");
    if (file == NULL) {
        printf("\nKhong the mo file!\n");
        return;
    }
    fread(&categoryCount, sizeof(int), 1, file);
    fread(categories, sizeof(Category), categoryCount, file);
    fclose(file);
}

void saveFile() {
    FILE* file = fopen("categories.dat", "wb");
    if (file == NULL) {
        printf("\nKhong the mo file!\n");
        return;
    }
    fwrite(&categoryCount, sizeof(int), 1, file);
    fwrite(categories, sizeof(Category), categoryCount, file);
    fclose(file);
}

void showMenuCategory() {
	system("cls");
    printf("\n===== Quan Ly Danh Muc =====\n");
    printf("[1]. Hien thi danh sach danh muc\n");
    printf("[2]. Them danh muc\n");
    printf("[3]. Sua danh muc\n");
    printf("[4]. Xoa danh muc\n");
    printf("[5]. Tim kiem danh muc theo ten\n");
    printf("[6]. Sap xep danh sach danh muc theo ten\n");
    printf("[7]. Luu va Thoat\n");
}

void showCategories() {
	system("cls");  
    if (categoryCount == 0) {
        printf("\nKhong co danh muc nao!\n");
        return;
    }
    printf("\n*********DANH SACH DANH MUC**********\n\n");
    printf("+------------+----------------------+\n");
    printf("|     ID     |      Ten danh muc    |\n");
    printf("+------------+----------------------+\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("| %-10s | %-20s |\n", categories[i].id, categories[i].name);
    }
    printf("+------------+----------------------+\n");
    showSubMenu();
}

void addCategory() {
	system("cls");
    printf("\n**********THEM DANH MUC**********\n");
    if (categoryCount >= 50) {
        printf("\nKhong the them danh muc.\n");
        return;
    }
    Category newCategory;
    while (1) {
        printf("\nNhap ID danh muc: ");
        fgets(newCategory.id, sizeof(newCategory.id), stdin);
        if (newCategory.id[strlen(newCategory.id) - 1] != '\n') {
            printf("\nID qua dai! Hay nhap lai.\n");
            while (getchar() != '\n');
            continue;
        }
        newCategory.id[strcspn(newCategory.id, "\n")] = 0;

        if (strlen(newCategory.id) == 0) {
            printf("\nID khong hop le! Hay nhap lai.\n");
            continue;
        }
        int flag = -1;
        for (int i = 0; i < categoryCount; i++) {
            if (strcmp(categories[i].id, newCategory.id) == 0) {
                printf("\nID \"%s\" da ton tai. Hay nhap ID khac!\n", newCategory.id);
                flag = 1;
                break;
            }
        }
        if (flag==-1) break;
    }
    while (1) {
        printf("\nNhap Ten danh muc: ");
        fgets(newCategory.name, sizeof(newCategory.name), stdin);
        if (newCategory.name[strlen(newCategory.name) - 1] != '\n') {
            printf("\nTen qua dai! Hay nhap lai.\n");
            while (getchar() != '\n');
            continue;
        }
        newCategory.name[strcspn(newCategory.name, "\n")] = 0;
        if (strlen(newCategory.name) == 0) {
            printf("\nTen khong hop le! Hay nhap lai.\n");
            continue;
        }
        int flag = -1;
        for (int i = 0; i < categoryCount; i++) {
            if (strcmp(categories[i].name, newCategory.name) == 0) {
                printf("\nTen \"%s\" da ton tai. Hay nhap ten khac!\n", newCategory.name);
                flag = 1;
                break;
            }
        }
        if (flag==-1) break;
    }
    categories[categoryCount++] = newCategory;
    printf("\nThem danh muc thanh cong!\n");
    showSubMenu();
}

void editCategory() {
	system("cls");
    printf("\n********** SUA DANH MUC **********\n");
    char id[10];
    while (1) {
        printf("Nhap ID danh muc can sua: ");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = 0;
        if (strlen(id) == 0) {
            printf("\nID khong hop le! Hay nhap lai.\n");
            continue;
        }
        break;
    }

    int flag = -1;
    for (int i = 0; i < categoryCount; i++) {
        if (strcmp(categories[i].id, id) == 0) {
            flag = i;
            break;
        }
    }
    if (flag == -1) {
        printf("\nDanh muc voi ID \"%s\" khong ton tai.\n", id);
        return;
    }
    printf("\nThong tin hien tai:\n");
    printf("+------------+---------------------+\n");
    printf("|   ID       |   Ten               |\n");
    printf("+------------+---------------------+\n");
    printf("| %-10s | %-19s |\n", categories[flag].id, categories[flag].name);
    printf("+------------+---------------------+\n");
    while (1) {
        printf("Nhap ten moi: ");
        fgets(categories[flag].name, sizeof(categories[flag].name), stdin);
        categories[flag].name[strcspn(categories[flag].name, "\n")] = 0;
        if (strlen(categories[flag].name) == 0) {
            printf("\nTen khong hop le! Hay nhap lai.\n");
            continue;
        }
        break;
    }
    printf("\nDanh muc da duoc cap nhat thanh cong!\n");
    showSubMenu();
}

void deleteCategory() {
	system("cls");
    printf("\n**********XOA DANH MUC**********\n");
    char id[10];
    while (1) {
        printf("\nNhap ID danh muc can xoa: ");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = 0;
        if (strlen(id) == 0) {
            printf("\nID khong hop le! Hay nhap lai.\n");
            continue;
        }
        break;
    }
    int flag = -1;
    for (int i = 0; i < categoryCount; i++) {
        if (strcmp(categories[i].id, id) == 0) {
            flag = i;
            break;
        }
    }
    if (flag == -1) {
        printf("\nDanh muc voi ID \"%s\" khong ton tai.\n", id);
        return;
    }
    printf("\nThong tin hien tai:\n");
    printf("+------------+---------------------+\n");
    printf("|   ID       |   Ten               |\n");
    printf("+------------+---------------------+\n");
    printf("| %-10s | %-19s |\n", categories[flag].id, categories[flag].name);
    printf("+------------+---------------------+\n");
    printf("Ban co chac chan muon xoa danh muc voi ID \"%s\"? (y/n): ", id);
    char confirm;
    scanf(" %c", &confirm);
    getchar();
    if (confirm == 'y' || confirm == 'Y') {
        for (int i = flag; i < categoryCount - 1; i++) {
            categories[i] = categories[i + 1];
        }
        categoryCount--;
        printf("\nDanh muc da duoc xoa thanh cong!\n");
    } else {
        printf("\nHuy xoa danh muc.\n");
    }
    showSubMenu();
}

void searchCategoryByName() {
	system("cls");
    printf("\n********** TIM KIEM DANH MUC THEO TEN **********\n");
    char name[50];
    while (1) {
        printf("\nNhap ten danh muc can tim: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        if (strlen(name) == 0) {
            printf("Ten khong hop le! Hay nhap lai.\n");
            continue;
        }
        break;
    }

    printf("\nKet qua tim kiem:\n");
    printf("+------------+----------------------+\n");
    printf("|     ID     |      Ten danh muc    |\n");
    printf("+------------+----------------------+\n");
    int flag = -1;
    for (int i = 0; i < categoryCount; i++) {
        if (strstr(categories[i].name, name) != NULL) {
            printf("| %-10s | %-20s |\n", categories[i].id, categories[i].name);
            flag = 1;
        }
    }
    printf("+------------+----------------------+\n");
    if (flag==-1) {
        printf("\nKhong tim thay danh muc.\n");
    }
    showSubMenu();
}

void sortCategories() {
	system("cls");
    printf("\n**********SAP XEP DANH MUC**********\n");
    int choice;
    while (1) {
        printf("\nChon thu tu sap xep:\n");
        printf("1. A->Z\n");
        printf("2. Z->A\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar();
        if (choice == 1 || choice == 2) break;
        printf("Lua chon khong hop le! Hay nhap lai.\n");
    }
    for (int i = 0; i < categoryCount - 1; i++) {
        for (int j = i + 1; j < categoryCount; j++) {
            int compare = strcmp(categories[i].name, categories[j].name);
            if ((choice == 1 && compare > 0) || (choice == 2 && compare < 0)) {
                Category temp = categories[i];
                categories[i] = categories[j];
                categories[j] = temp;
            }
        }
	}
	printf("\nDa sap xep\n");
	printf("\n*********DANH SACH DANH MUC**********\n\n");
    printf("+------------+----------------------+\n");
    printf("|     ID     |      Ten danh muc    |\n");
    printf("+------------+----------------------+\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("| %-10s | %-20s |\n", categories[i].id, categories[i].name);
    }
    printf("+------------+----------------------+\n");
	showSubMenu();
}

int showSubMenu() {
    int choose;
    do {
        printf("\n1.Quay lai menu\n");
        printf("2.Thoat chuong trinh\n");
        printf("Lua chon cua ban la: ");
        scanf("%d", &choose);
        getchar();
        switch (choose) {
            case 1:
                return 1;
            case 2:
            	exit(0);
            default:
                printf("\nLua chon khong hop le\n");
        }
    } while (choose != 1||choose != 2);

    return 1;
}

void mainProduct() {
	loadProducts();
    int choice;
    do {
        showMenuProduct();
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                showProducts();
                break;
            case 2:
                addProduct();
                break;
            case 3:
                editProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                searchProduct();
                break;
            case 6:
                saveProducts();
                printf("Du lieu da duoc luu. Thoat...\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 6);
}
void loadProducts() {
    FILE *file = fopen("products.dat", "rb");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    fread(&productCount, sizeof(int), 1, file);
    fread(products, sizeof(Product), productCount, file);
    fclose(file);
}

void saveProducts() {
    FILE *file = fopen("products.dat", "wb");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    fwrite(&productCount, sizeof(int), 1, file);
    fwrite(products, sizeof(Product), productCount, file);
    fclose(file);
}

void showMenuProduct() {
	system("cls");
    printf("\n=== He Thong Quan Ly San Pham ===\n");
    printf("[1]. Hien thi danh sach san pham\n");
    printf("[2]. Them san pham\n");
    printf("[3]. Sua thong tin san pham\n");
    printf("[4]. Xoa san pham\n");
    printf("[5]. Tim kiem san pham theo ten\n");
    printf("[6]. Luu va thoat\n");
}

void showProducts() {
	system("cls");
    if (productCount == 0) {
        printf("Chua co san pham nao.\n");
        return;
    }
    printf("\n*****************************DANH SACH SAN PHAM********************************\n\n");
    printf("+--------------------+--------------------+-----------+---------+---------------+\n");
    printf("|        ID          |        Ten         |  So luong |   Gia   |  ID Danh muc  |\n");
    printf("+--------------------+--------------------+-----------+---------+---------------+\n");
    for (int i = 0; i < productCount; i++) {
        printf("| %-18s | %-18s | %-9d | %-7.0f | %-13s |\n",
               products[i].productID,
               products[i].productName,
               products[i].quantity,
               products[i].price,
               products[i].categoryID);
    }
    printf("+--------------------+--------------------+-----------+---------+---------------+\n");
    showSubMenu();
}

void addProduct() {
	system("cls");
	printf("\n**********THEM SAN PHAM**********\n");
	loadFile();
    if (productCount >= 50) {
        printf("Khong the them san pham.\n");
        return;
    }

    Product newProduct;
    while (1) {
        printf("Nhap ID san pham: ");
        fgets(newProduct.productID, sizeof(newProduct.productID), stdin);
        newProduct.productID[strcspn(newProduct.productID, "\n")] = 0;

        if (strlen(newProduct.productID) == 0) {
            printf("ID san pham khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }

        int flag = -1;
        for (int i = 0; i < productCount; i++) {
            if (strcmp(products[i].productID, newProduct.productID) == 0) {
                printf("ID san pham da ton tai. Vui long nhap ID khac.\n");
                flag = 1;
                break;
            }
        }
        if (flag==-1) break;
    }
    
    while (1) {
        printf("Nhap ID danh muc: ");
        fgets(newProduct.categoryID, sizeof(newProduct.categoryID), stdin);
        newProduct.categoryID[strcspn(newProduct.categoryID, "\n")] = 0;

        if (strlen(newProduct.categoryID) == 0) {
            printf("ID danh muc khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }

        int flag = -1;
        for (int i = 0; i < categoryCount; i++) {
            if (strcmp(categories[i].id, newProduct.categoryID) == 0) {
                flag = 1;
                break;
            }
        }

        if (flag == -1) {
            printf("ID danh muc khong ton tai. Vui long nhap lai.\n");
            continue;
        }
        break;
    }

    while (1) {
        printf("Nhap ten san pham: ");
        fgets(newProduct.productName, sizeof(newProduct.productName), stdin);
        newProduct.productName[strcspn(newProduct.productName, "\n")] = 0;
        if (strlen(newProduct.productName) == 0) {
            printf("Ten san pham khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }

        int flag = -1;
        for (int i = 0; i < productCount; i++) {
            if (strcmp(products[i].productName, newProduct.productName) == 0) {
                printf("Ten san pham da ton tai. Vui long nhap ten san pham khac.\n");
                flag = 1;
                break;
            }
        }
        if (flag==-1) break;
    }
    while (1) {
        printf("Nhap so luong san pham: ");
        char newQuantity[20];
        fgets(newQuantity, sizeof(newQuantity), stdin);
        if (strlen(newQuantity) == 1 && newQuantity[0] == '\n') {
            printf("So luong san pham khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }
        if (sscanf(newQuantity, "%d", &newProduct.quantity) != 1 || newProduct.quantity <= 0) {
            printf("So luong khong hop le. So luong phai la so nguyen duong. Vui long nhap lai.\n");
            continue;
        }
        break;
    }
    while (1) {
        printf("Nhap gia san pham: ");
        char newPrice[20];
        fgets(newPrice, sizeof(newPrice), stdin);
        if (strlen(newPrice) == 1 && newPrice[0] == '\n') {
            printf("Gia san pham khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }
        if (sscanf(newPrice, "%f", &newProduct.price) != 1 || newProduct.price <= 0) {
            printf("Gia khong hop le. Gia phai la so thuc duong. Vui long nhap lai.\n");
            continue;
        }
        break;
    }
    products[productCount++] = newProduct;
    printf("Them san pham thanh cong!\n");
    showSubMenu();
}

void editProduct() {
	system("cls");
	printf("\n********** SUA SAN PHAM **********\n");
    char id[20];
    int flag = -1;
    while (1) {
        printf("Nhap ID san pham can sua: ");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = 0;

        if (strlen(id) == 0) {
            printf("ID san pham khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }

        for (int i = 0; i < productCount; i++) {
            if (strcmp(products[i].productID, id) == 0) {
                flag = i;
                break;
            }
        }

        if (flag == -1) {
            printf("Khong tim thay san pham voi ID nay.\n");
            return;
        }
        break;
    }

    printf("\nThong tin san pham can sua (ID: %s):\n", products[flag].productID);
    printf("+--------------------+--------------------+-----------+---------+---------------+\n");
    printf("|        ID          |        Ten         |  So luong |   Gia   |  ID Danh muc  |\n");
    printf("+--------------------+--------------------+-----------+---------+---------------+\n");
    printf("| %-18s | %-18s | %-9d | %-7.0f | %-13s |\n", products[flag].productID, products[flag].productName, products[flag].quantity, products[flag].price,products[flag].categoryID);
    printf("+--------------------+--------------------+-----------+---------+---------------+\n");

    while (1) {
        printf("Nhap ten moi cho san pham: ");
        fgets(products[flag].productName, sizeof(products[flag].productName), stdin);
        products[flag].productName[strcspn(products[flag].productName, "\n")] = 0;

        if (strlen(products[flag].productName) == 0) {
            printf("Ten san pham khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }
        break;
    }

    while (1) {
        char newQuantity[20];
        printf("Nhap so luong moi: ");
        fgets(newQuantity, sizeof(newQuantity), stdin);

        if (strlen(newQuantity) == 1 && newQuantity[0] == '\n') {
            printf("So luong san pham khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }

        if (sscanf(newQuantity, "%d", &products[flag].quantity) != 1 || products[flag].quantity < 0) {
            printf("So luong khong hop le. So luong phai la so nguyen duong. Vui long nhap lai.\n");
            continue;
        }
        break;
    }

    while (1) {
        char newPrice[20];
        printf("Nhap gia moi: ");
        fgets(newPrice, sizeof(newPrice), stdin);

        if (strlen(newPrice) == 1 && newPrice[0] == '\n') {
            printf("Gia san pham khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }

        if (sscanf(newPrice, "%f", &products[flag].price) != 1 || products[flag].price < 0) {
            printf("Gia khong hop le. Gia phai la so thuc duong. Vui long nhap lai.\n");
            continue;
        }
        break;
    }
    printf("\nCap nhat thong tin thanh cong!\n");
    showSubMenu();
}

void deleteProduct() {
	system("cls");
	printf("\n**********XOA SAN PHAM**********\n");
    char id[20];
    int flag = -1;
    while (1) {
        printf("\nNhap ID san pham can xoa: ");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = 0;
        if (strlen(id) == 0) {
            printf("\nID san pham khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }
        for (int i = 0; i < productCount; i++) {
            if (strcmp(products[i].productID, id) == 0) {
                flag = i;
                break;
            }
        }
        if (flag == -1) {
            printf("\nKhong tim thay san pham voi ID nay.\n");
            return;
        }
        break;
    }
    printf("\nThong tin san pham can xoa:\n");
    printf("+--------------------+--------------------+-----------+---------+---------------+\n");
    printf("|        ID          |        Ten         |  So luong |   Gia   |  ID Danh muc  |\n");
    printf("+--------------------+--------------------+-----------+---------+---------------+\n");
    printf("| %-18s | %-18s | %-9d | %-7.0f | %-13s |\n", products[flag].productID, products[flag].productName, products[flag].quantity, products[flag].price,products[flag].categoryID);
    printf("+--------------------+--------------------+-----------+---------+---------------+\n");
    printf("\nBan co chac chan muon xoa danh muc voi ID \"%s\"? (y/n): ", id);
    char confirm;
    scanf(" %c", &confirm);
    getchar();
    if (confirm == 'y' || confirm == 'Y') {
        for (int i = flag; i < productCount - 1; i++) {
            products[i] = products[i + 1];
        }
        productCount--;
        printf("\nSan pham da duoc xoa thanh cong!\n");
    } else {
        printf("\nHuy xoa san pham.\n");
    }
    showSubMenu();
}

void searchProduct() {
	system("cls");
	printf("\n********** TIM KIEM SAN PHAM THEO TEN **********\n");
    char name[50];
    int flag = -1;

    while (1) {
        printf("\nNhap ten san pham can tim: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;

        if (strlen(name) == 0) {
            printf("\nTen san pham khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }
        break;
    }
    printf("\nDanh sach san pham tim duoc:\n");
    printf("+--------------------+--------------------+-----------+---------+---------------+\n");
    printf("|        ID          |        Ten         |  So luong |   Gia   |  ID Danh muc  |\n");
    printf("+--------------------+--------------------+-----------+---------+---------------+\n");
    for (int i = 0; i < productCount; i++) {
        if (strstr(products[i].productName, name)) { 
            printf("| %-18s | %-18s | %-9d | %-7.0f | %-13s |\n", products[i].productID, products[i].productName, products[i].quantity, products[i].price,products[i].categoryID);
            flag = 1;
        }
    }
	printf("+--------------------+--------------------+-----------+---------+---------------+\n");
    if (flag == -1) {
        printf("\nKhong tim thay san pham \n");
    }
    showSubMenu();
}
