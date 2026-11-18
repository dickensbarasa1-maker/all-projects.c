#include <stdio.h>

double calculateElectricBill(int units) {
    if (units <= 100) return units * 10;
    if (units <= 200) return 1000 + (units - 100) * 15;
    return 2500 + (units - 200) * 20;
}

double calculateFare(double km) {
    return km * 50;
}

double convertToCelsius(double f) {
    return (f - 32) * 5 / 9;
}

int main() {
    int units;
    double km, f;

    printf("Units: ");
    scanf("%d", &units);
    printf("Bill: KSh %.2f\n", calculateElectricBill(units));

    printf("Distance (km): ");
    scanf("%lf", &km);
    printf("Fare: KSh %.2f\n", calculateFare(km));

    printf("Fahrenheit: ");
    scanf("%lf", &f);
    printf("Celsius: %.2f\n", convertToCelsius(f));
    return 0;
}
