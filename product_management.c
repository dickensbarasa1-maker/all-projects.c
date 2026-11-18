#include <stdio.h>

/* 1. Define the Product structure */
struct Product {
    int code;
    char name[50];
    float unitPrice;
    int quantity;
};

int main(void) {
    /* 2. Declare a structure variable and input product details */
    struct Product p;
    float totalValue;

    printf("Enter Product Code: ");
    scanf("%d", &p.code);

    printf("Enter Product Name: ");
    scanf(" %49[^\n]", p.name);   /* reads names with spaces, prevents overflow */

    printf("Enter Unit Price (KSh): ");
    scanf("%f", &p.unitPrice);

    printf("Enter Quantity in Stock: ");
    scanf("%d", &p.quantity);

    /* 3. Calculate total value of the available stock */
    totalValue = p.unitPrice * p.quantity;

    /* 4. Display product details and total stock value */
    printf("\n----- PRODUCT DETAILS -----\n");
    printf("Product Code      : %d\n", p.code);
    printf("Product Name      : %s\n", p.name);
    printf("Unit Price        : KSh %.2f\n", p.unitPrice);
    printf("Quantity in Stock : %d\n", p.quantity);
    printf("Total Stock Value : KSh %.2f\n", totalValue);

    return 0;
}
