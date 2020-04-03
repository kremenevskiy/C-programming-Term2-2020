#include <stdio.h>
#include <math.h>

#define PI 3.14


void check_input(double *value);
void formula(double x);
unsigned long long int factorial(int num);


void task_2(){

    double x;
    double sin_x;

    printf("\nВведите (в градусах) x: ");
    check_input(&x);

    x = x * PI / 180;

    sin_x = sin(x);
    printf("sin(%.2lf) = %lf\n", x, sin_x);

    formula(x);

}


void formula(double x){

    double sum = 0;
    const int accuracy = 10;
    double ep;
    double sin_x = sin(x);
    int n = 0;

    printf("Введите погрешность ε : ");
    check_input(&ep);

    int i;
    for (i = 1; i < accuracy; i++){

        sum += pow(-1, i - 1) * powf( (float) x, (float) (2 * i - 1)) / (double) factorial(2 * i - 1);

        if (fabs(sin_x - sum) < ep && n == 0){
            n = i;
        }

    }
    printf("\nЗначение по формуле sin(%.2lf) = %lf\n", x, sum);

    if (n) {
        printf("\nИсследуемое выражение отличается от sin(%.2lf) менее,\n"
               "чем на заданную погрешность ε = %lf\n"
               "на шаге n = %d\n\n", x, ep, n);
    }
    else{
        printf("Погрешность ε = %lf не достигается\n\n", ep);
    }

}


unsigned long long int factorial(int num){

    if (num == 1)
        return 1;

    else
        return n
        um * factorial(num - 1);
}


void check_input(double *value){

    while(scanf("%lf", value) != 1 || getchar() != '\n'){

        printf("Некорректный ввод!\nВвод: ");
        while(getchar() != '\n');
    }
}
