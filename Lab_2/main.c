#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

extern void task_2();
//extern void check_input(double *value);



int mass_1, radius_1, speed_1;
int mass_2, radius_2, speed_2;
int mass_3, radius_3, speed_3;
double sp_1, sp_2, sp_3;
double LEN_1, LEN_2, LEN_3;


void start();
void check_in(int *value);
void input(int *mass, int *radius, int *speed);
double len_yr(int speed, int radius);
double calc_distance(int speed, int speed2, double LEN1, int radius, int radius2, double LEN2, int time);
double calc_speed(int speed, int radius);
double force(int mass1, int mass2, double r);
int checker();





int main(){

    int val, i;

    printf("1. Задание 2.1 (17)\n2. Задание 2.2 (6)\nВвод: ");

    while (scanf("%d", &val) != 1 || getchar() != '\n' || val < 1 || val > 2) {
        printf("Некоректный ввод !\nВвод: ");
        while (getchar() != '\n');
    }

    switch (val){
        case 1:
            start();
            break;
        case 2:
            for(i = 1; i <= 3; i++){
                printf("\n%d из 3\n", i);
                task_2();
            }
            break;
    }


    //task_2();
    //start();
    return 0;


}


void start(){

    while(1) {
        int value = 0;
        int time_5 = 0;
        int time_6 = 0;

        printf("\n1. Ввод параметров планеты 2G_1 (масса, радиус орбиты, скорость движения)\n");
        printf("\t\t(Целое значение)\n");
        printf("2. Ввод аналогичных параметров планеты 2G_2\n");
        printf("3. Ввод аналогичных параметров планеты 2G_3.\n");
        printf("4. Расчет продолжительности года на каждой из трех 3-х планет.\n");
        printf("5. Рассчитать, на каком расстоянии друг от друга будут\n"
               "   находиться планеты для заданного времени t, прошедшего с\n"
               "   момента появления звездолета в системе.\n");
        printf("6. Определить силу попарного гравитационного взаимодействия\n"
               "   3-х планет в заданное время t.\n");
        printf("7. Выход из программы.\n\n");

        printf("Ввод: ");

        while (scanf("%d", &value) != 1 || getchar() != '\n' || value < 1 || value > 7) {
            printf("Введите целое значение от 1 до 7: \n");
            while (getchar() != '\n');

        }


        switch (value) {

            case 1:

                input(&mass_1, &radius_1, &speed_1);
                sp_1 = calc_speed(speed_1, radius_1);
                LEN_1 = 2 * PI * radius_1;

                break;

            case 2:

                input(&mass_2, &radius_2, &speed_2);
                sp_2 = calc_speed(speed_2, radius_2);
                LEN_2 = 2 * PI * radius_2;

                break;

            case 3:

                input(&mass_3, &radius_3, &speed_3);
                sp_3 = calc_speed(speed_3, radius_3);
                LEN_3 = 2 * PI * radius_3;

                break;

            case 4:

                if (checker()) {
                    int val = 0;

                    printf("1. Продолижть\n2. Выйти\nВвод: ");
                    while (scanf("%d", &val) != 1 || getchar() != '\n' || val < 1 || val > 2) {
                        printf("Некоректный ввод !\n1. Продолижть\n2. Выйти\nВвод: ");
                        while (getchar() != '\n');

                    }

                    if (val == 1)
                        break;
                    else if (val == 2)
                        return;

                }


                printf("Продолжительность года на 1-ой планете: %lf\n", len_yr(speed_1, radius_1));
                printf("Продолжительность года на 1-ой планете: %lf\n", len_yr(speed_2, radius_2));
                printf("Продолжительность года на 1-ой планете: %lf\n", len_yr(speed_3, radius_3));

                break;

            case 5:

                if (checker()) {
                    int val = 0;

                    printf("1. Продолижть\n2. Выйти\nВвод: ");
                    while (scanf("%d", &val) != 1 || getchar() != '\n' || val < 1 || val > 2) {
                        printf("Некоректный ввод !\n1. Продолижть\n2. Выйти\nВвод: ");
                        while (getchar() != '\n');

                    }

                    if (val == 1)
                        break;
                    else if (val == 2)
                        return;

                }

                printf("Введите время: ");
                check_in(&time_5);
                printf("Расстояние между 1 и 2 планетой: %lf\n", calc_distance(speed_1, speed_2, LEN_1,
                                                                               radius_1, radius_2, LEN_2, time_5));

                printf("Расстояние между 1 и 3 планетой: %lf\n", calc_distance(speed_1, speed_3, LEN_1,
                                                                               radius_1, radius_3, LEN_3, time_5));

                printf("Расстояние между 2 и 3 планетой: %lf\n", calc_distance(speed_2, speed_3, LEN_2,
                                                                               radius_2, radius_3, LEN_3, time_5));

                break;

            case 6:

                if (checker()) {
                    int val = 0;

                    printf("1. Продолижть\n2. Выйти\nВвод: ");
                    while (scanf("%d", &val) != 1 || getchar() != '\n' || val < 1 || val > 2) {
                        printf("Некоректный ввод !\n1. Продолижть\n2. Выйти\nВвод: ");
                        while (getchar() != '\n');

                    }

                    if (val == 1)
                        break;
                    else if (val == 2)
                        return;

                }

                printf("Введите время: ");
                check_in(&time_6);

                double r_12 = calc_distance(speed_1, speed_2, LEN_1, radius_1, radius_2, LEN_2, time_6);
                double r_13 = calc_distance(speed_1, speed_3, LEN_1, radius_1, radius_3, LEN_3, time_6);
                double r_23 = calc_distance(speed_2, speed_3, LEN_2, radius_2, radius_3, LEN_3, time_6);

                printf("Сила взаимодействия 1 и 2: %lf * G\n", force(mass_1, mass_2, r_12));
                printf("Сила взаимодействия 1 и 3: %lf * G\n", force(mass_1, mass_3, r_13));
                printf("Сила взаимодействия 2 и 2: %lf * G\n", force(mass_2, mass_3, r_23));
                printf("Где  G - Гравитационная постоянная\n");
                break;
            case 7:
                printf("Выход из программы успешно выполнен !\n");
                return;

        }
    }

}


void input(int *mass, int *radius, int *speed){
    printf("Ввидите целые значения от 1 до 100\n");

    printf("Масса: ");
    check_in(mass);

    printf("Радиус: ");
    check_in(radius);
    printf("Скорость: ");
    check_in(speed);



}


double calc_speed(int speed, int radius){
    return speed * radius;
}


void check_in(int *value){
    while(scanf("%d", value) != 1 || getchar() != '\n' || *value < 1 || *value >= 100){
        printf("Введите целое значение от 1 до 100: \n");
        while (getchar() != '\n');

    }
}


double len_yr(int speed, int radius){
    return 2 * PI * radius / speed;
}


double calc_distance(int speed1, int speed2, double LEN1, int radius1, int radius2, double LEN2, int time){
    // int time = 0;
    double angle_1, angle_2, angle;
    // printf("Введите время: ");
    // check_in(time);

    angle_1 = speed1 * time * 360 / LEN1;
    angle_2 = speed2 * time * 360 / LEN2;
    angle = fabs(angle_1 - angle_2);
    if (angle > 180){
        angle = 360 - angle;
    }

    // Расстояние по теореме косинусов

    return sqrt(pow(radius1, 2) + pow(radius2, 2) - 2 * radius1 * radius2 * cos(angle * PI / 180));
}


double force(int mass1, int mass2, double r){
    // const double GI = 6.674 * pow(10, -11);
    return /* GI * */ mass1 * mass2 / pow(r, 2);
}

int checker(){
    if (mass_1 == 0 || mass_2 == 0 || mass_3 == 0){
        printf("\nВы не ввели данные о всех планетах !!!\n\n");
        printf("Масса: %d %d %d\n", mass_1, mass_2, mass_3);
        printf("Скорость: %d %d %d\n", speed_1, speed_2, speed_3);
        printf("Радиус: %d %d %d\n", radius_1, radius_2, radius_3);
        return 1;
    }
    return 0;
}