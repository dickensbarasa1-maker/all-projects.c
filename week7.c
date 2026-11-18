#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    char regNo[20];
    float marks;
};

void borrowedBooks() {
    char title[100];
    FILE *fp = fopen("borrowed_books.txt", "a");   /* append keeps old records */
    getchar();
    printf("Enter book title: ");
    fgets(title, sizeof title, stdin);
    fputs(title, fp);
    fclose(fp);
    printf("Title stored successfully.\n");
}

void readResults() {
    struct Student s;
    FILE *fp = fopen("results.dat", "rb");
    if (!fp) { printf("results.dat not found\n"); return; }
    while (fread(&s, sizeof s, 1, fp) == 1)
        printf("%s - %.2f\n", s.name, s.marks);
    fclose(fp);
}

void salesTotal() {
    double amt, total = 0;
    FILE *fp = fopen("sales.txt", "r");
    if (!fp) { printf("sales.txt not found\n"); return; }
    while (fscanf(fp, "%lf", &amt) == 1)
        total += amt;
    fclose(fp);
    printf("Total sales: KSh %.2f\n", total);
}

int main() {
    int c;
    printf("1.Books 2.Results 3.Sales: ");
    scanf("%d", &c);
    if (c == 1) borrowedBooks();
    else if (c == 2) readResults();
    else if (c == 3) salesTotal();
    return 0;
}
