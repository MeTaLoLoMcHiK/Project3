#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h> 


double factorial(int n) {
    if (n == 0 || n == 1) return 1;
    double result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}


double calculate_series(double x, int terms) {
    double sum = 0.0;
    for (int n = 1; n <= terms; n++) {
        sum += sin(n * x) / factorial(n);
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "Russian"); 

    double x; 
    int terms = 10; 

  
    printf("Введите значение x (0 <= x <= 1): ");
    scanf("%lf", &x);

    if (x < 0 || x > 1) {
        printf("Ошибка: x должно быть в пределах [0, 1].\n");
        return 1;
    }

   
    double function_result = exp(sin(x)) * sin(cos(x));
    printf("Результат функции e^(sin(x)) * sin(cos(x)) для x = %.5lf: %.5lf\n", x, function_result);

 
    double series_result = calculate_series(x, terms);
    printf("Результат суммы ряда для x = %.5lf: %.5lf\n", x, series_result);

    return 0;
}