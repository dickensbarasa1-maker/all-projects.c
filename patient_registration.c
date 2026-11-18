#include <stdio.h>

#define DAILY_RATE 2500

/* 1. Define the Patient structure */
struct Patient {
    int id;
    char name[50];
    int age;
    float temperature;
    int daysAdmitted;
};

int main(void) {
    
    struct Patient p;
    float cost;

    printf("Enter Patient ID: ");
    scanf("%d", &p.id);

    printf("Enter Patient Name: ");
    scanf(" %49[^\n]", p.name);   

    printf("Enter Age: ");
    scanf("%d", &p.age);

    printf("Enter Temperature (C): ");
    scanf("%f", &p.temperature);

    printf("Enter Number of Days Admitted: ");
    scanf("%d", &p.daysAdmitted);


    cost = p.daysAdmitted * DAILY_RATE;

    
    printf("\n----- PATIENT DETAILS -----\n");
    printf("Patient ID         : %d\n", p.id);
    printf("Name               : %s\n", p.name);
    printf("Age                : %d years\n", p.age);
    printf("Temperature        : %.1f C\n", p.temperature);
    printf("Days Admitted      : %d\n", p.daysAdmitted);
    printf("Accommodation Cost : KSh %.2f\n", cost);

    return 0;
}
