// Глава №5. Функции

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

void zadacha1();
float circarea(float);
void zadacha2();
double power(double n, int p = 2);
void zadacha3();
void zeroSmaller(int& a, int& b);
void zadacha4();
//void zadacha3glava3();
void zadacha5();
long hms_to_secs(int hs, int min, int sec);

void zadacha7();
int power(int n, int p);
long power(long n, int p);
float power(float n, int p);

void zadacha8();
void swap(int& a, int& b);

void zadacha9();

struct Time
{
  int hours;
  int minutes;
  int seconds;
};

void zadacha6();
long time_to_secs(Time);
Time secs_to_time(long time_sum);

struct Distance
// длина в английской системе
{
int feet;
float inches;
};
Distance retsrc(Distance first, Distance second);

struct Sterling
{
    int pounds;
    int shillings;
    int pence;
};

Sterling sum_of_money(Sterling first_sum, Sterling sec_sum);

void zadacha11();
Sterling get_sterling(int a,int b,int c);
void sterling_output(Sterling input);

void zadacha12();
struct Fraction
{
    int numerator;   // числитель
    int denomirator; // знаменатель
};
Fraction fadd(Fraction a_num,Fraction b_num);
Fraction fsub(Fraction a_num,Fraction b_num);
Fraction fmul(Fraction a_num,Fraction b_num);
Fraction fdiv(Fraction a_num,Fraction b_num);

void zadacha10();
void timeToCall();
int global_number;
void timeToCall2();

using namespace std;

int main()
{

    zadacha12();
    return 0;
}

void zadacha12()
{
    char ch='\0';
    Fraction result;
    do
    {
        Fraction first;
        Fraction second;


        char slash ='/';
        char operation = '\0';

        cout << "Введите первую дробь, операцию и вторую дробь: ";

        cin >> first.numerator              //a
            >> slash >> first.denomirator   //b
            >> operation
            >> second.numerator             //c
            >> slash >> second.denomirator; //d

        switch (operation)
        {
            case '+':
            {
                result = fadd(first,second);
                cout << "Результат равен: "
                     << result.numerator << "/" << result.denomirator
                     << endl;

                break;
            }
            case '-':
            {
                result = fsub(first,second);
                cout << "Результат равен: "
                     << result.numerator << "/" << result.denomirator
                     << endl;
                break;
            }
            case '*':
            {
                result = fmul(first,second);
                cout << "Результат равен: "
                     << result.numerator << "/" << result.denomirator
                     << endl;
                break;
            }
            case '/':
            {
                result = fdiv(first,second);
                cout << "Результат равен: "
                     << result.numerator << "/" << result.denomirator
                     << endl;
                break;
            }
            default:
                break;
        } // end of switch

        cout << "Выполнить еще одну операцию (y/n)?\n";
        cin >> ch;
    }while(ch=='y');

    /*
    Модифицируйте калькулятор, созданный в упражнении 12 главы 4, так,
    чтобы каждая арифметическая операция выполнялась с помощью функ-
    ции. Функции могут называться fadd(), fsub(), fmul() и fdiv(). Каждая из
    функций должна принимать два структурных аргумента типа fraction и воз-
    вращать значение того же типа.
    */
}

Fraction fdiv(Fraction a_num,Fraction b_num)
{
    Fraction c_num;
    c_num.numerator = a_num.numerator*b_num.denomirator;
    c_num.denomirator = a_num.denomirator*b_num.numerator;
    return c_num;
    /*
                cout << "Результат равен: "
                     << first.numerator*second.denomirator
                     << '/' << first.denomirator*second.numerator << endl;
    */
}

Fraction fmul(Fraction a_num,Fraction b_num)
{
    Fraction c_num;
    c_num.numerator = a_num.numerator*b_num.numerator;
    c_num.denomirator = a_num.denomirator*b_num.denomirator;
    return c_num;
/*
                cout << "Результат равен: "
                     << first.numerator*second.numerator
                     << '/' << first.denomirator*second.denomirator << endl;
*/
}

Fraction fsub(Fraction a_num,Fraction b_num)
{
    Fraction c_num;
    c_num.numerator = a_num.numerator*b_num.denomirator
                      - a_num.denomirator*b_num.numerator;

    c_num.denomirator = a_num.denomirator*b_num.denomirator;

    return c_num;
    /*
                cout << "Результат равен: "
                     << first.numerator*second.denomirator
                        - first.denomirator*second.numerator
                     << '/' << first.denomirator*second.denomirator << endl;
    */
}


Fraction fadd(Fraction a_num,Fraction b_num)
{
    Fraction c_num;
    c_num.numerator = a_num.numerator*b_num.denomirator
                      + a_num.denomirator*b_num.numerator;

    c_num.denomirator = a_num.denomirator*b_num.denomirator;

    return c_num;
    /*
    cout << "Результат равен: "
         << first.numerator*second.denomirator
            + first.denomirator*second.numerator
         << '/' << first.denomirator*second.denomirator << endl
    */
}


void zadacha11()
{
    /*
    Напишите программу, использующую структуру sterling, которая описана
    в упражнении 10 главы 4.

    Программа должна получать от пользователя
    значения двух денежных сумм, выраженных в фунтах, шиллингах и пен-
    сах, складывать эти значения и выводить результат на экран в том же
    формате.

    Необходимо разработать три функции.

    Первая из них должна
    получать от пользователя число фунтов, шиллингов и пенсов и возвра-
    щать соответствующее значение типа sterling.

    Вторая функция должна принимать в качестве аргументов два значения типа sterling,
    складывать их и возвращать значение, также имеющее тип sterling.

    Третья функция должна принимать аргумент типа sterling
    и выводить его значение на экран.
    */


    Sterling first_sum, second_sum, their_sum;
    int pounds_first, shillings_first, penny_first;
    int pounds_sec, shillings_sec, penny_sec;
    int pounds_end = 0, shillings_end = 0, penny_end = 0;
    char ch = '.';

    cout << "Введите первую сумму в формате фунты.шиллинги.пенсы:\n";
    cin >> pounds_first >> ch >> shillings_first >> ch >> penny_first;
    cout << "Введите вторую сумму в формате фунты.шиллинги.пенсы:\n";
    cin >> pounds_sec >> ch >> shillings_sec >> ch >> penny_sec;

    first_sum = get_sterling(pounds_first, shillings_first, penny_first);
    second_sum = get_sterling(pounds_sec, shillings_sec, penny_sec);

    their_sum = sum_of_money(first_sum,second_sum);

    sterling_output(their_sum);

}
void sterling_output(Sterling input)
{
    cout << "Сумма равняется:\n"
         << input.pounds << "."
         << input.shillings << "."
         << input.pence << endl;
}

Sterling sum_of_money(Sterling first_sum, Sterling sec_sum)
{
    Sterling result_sum;
    result_sum.pounds = 0, result_sum.shillings = 0, result_sum.pence = 0;
    result_sum.pence = first_sum.pence + sec_sum.pence;
    if (result_sum.pence >= 12)
    {
        ++result_sum.shillings;
        result_sum.pence = 0;
    }
        result_sum.shillings += first_sum.shillings + sec_sum.shillings;
    if (result_sum.shillings >= 20)
    {
        ++result_sum.pounds;
        result_sum.shillings = 0;
    }
    result_sum.pounds += first_sum.pounds + sec_sum.pounds;
    return result_sum;
}


Sterling get_sterling(int a,int b,int c)
{
    Sterling sum_1;
    sum_1.pounds = a;
    sum_1.shillings = b;
    sum_1.pence = c;
    return sum_1;
}


/*

 //упражнение 10 глава 4

cout << "Введите число десятичных фунтов: ";
double dec_pounds; // сумма в десятичных фунтах
cin >> dec_pounds;
sterling old_money;
//int pounds; // сумма в старых фунтах
double dec_frac; // десятичная дробная часть от новых фунтов
old_money.pounds = static_cast<int>(dec_pounds); // фунты на вывод
dec_frac = dec_pounds - old_money.pounds; // десятичная часть от фунтов

// перевод в старые шиллинги:
double dec_shillings = dec_frac*20; // шиллинги с дробной частью
//найдем целую часть от шиллингов
old_money.shillings = static_cast<int>(dec_shillings);
//найдем дробную часть от шиллингов
double dec_frac_shillings = dec_shillings - old_money.shillings;

//перевод в пенни:
double dec_penny = dec_frac_shillings*12; // пенни с дробной частью
old_money.pence = static_cast<int>(dec_penny);

cout << "Эквивалентная сумма записи: "
     << old_money.pounds << "."
     << old_money.shillings << "."
     << old_money.pence << endl;

*/

void zadacha10()
{
    /*
    Напишите функцию, которая при каждом вызове будет выводить на эк-
    ран количество раз, которое она вызывалась ранее. Напишите программу,
    которая будет вызывать данную функцию не менее 10 раз. Попробуйте
    реализовать данную функцию двумя различными способами: с использо-
    ванием глобальной переменной и статической локальной переменной для
    хранения числа вызовов функции. Какой из способов предпочтительней?
    Почему для решения задачи нельзя использовать обычную локальную пе-
    ременную?
    */
    for(int i=0;i<=10;++i)
        timeToCall();

    cout << endl;

    for(int j=0;j<=10;++j)
        timeToCall2();


}

void timeToCall2()
{
    ++global_number;
    cout << "Номер вызова " << global_number << endl;
}

void timeToCall()
{
    static int called = 0;
    ++called;
    cout << "Номер вызова " << called << endl;
}

void zadacha9()
{
    /*
    Переработайте программу из упражнения 8 так, чтобы функция swap()
    принимала в качестве аргументов значения типа time (см. упражнение 6)
    */

    cout << "Введите 1 время в формате часы, минуты, секунды:\n";
    Time t1;
    char ch = ':';
    cin >> t1.hours >> ch
        >> t1.minutes >> ch
        >> t1.seconds;

    cout << "\nВведите 2 время в формате часы, минуты, секунды:\n";
    Time t2;
    cin >> t2.hours >> ch
        >> t2.minutes >> ch
        >> t2.seconds;

    swap(t1,t2);

    cout << "\nМеняем местами, теперь 1 время:\n"
          << t1.hours << ":"
          << t1.minutes << ":"
          << t1.seconds << endl;

    cout << "\nВторое время:\n"
          << t2.hours << ":"
          << t2.minutes << ":"
          << t2.seconds << endl;


}
void swap(Time& first_time,Time& second_time)
{
    Time temp;
    temp = first_time;
    first_time = second_time;
    second_time = temp;
}


void zadacha8()
{
    /*
    Напишите функцию с именем swap(), обменивающую значениями два сво-
    их аргумента типа int (обратите внимание, что изменяться должны значе-
    ния переменных из вызывающей программы, а не локальных переменных
    функции). Выберите способ передачи аргументов. Напишите вызывающую
    программу main(), использующую данную функцию.
    */
    cout << "Введите 2 значения\n";
    int num1, num2;
    cin >> num1 >> num2;
    swap(num1, num2);
    cout << "Меняем их местами, результат:\n"
         << num1 << " " << num2 << endl;
}

void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void zadacha7()
{
    /*
    Взяв в качестве основы функцию power() из упражнения 2, работающую
    только со значением типа double, создайте перегруженные функции с этим
    же именем, принимающими в качестве аргумента значения типа char, int,
    long и float. Напишите программу, вызывающую функцию power() со все-
    ми возможными типами аргументов.
    */
   cout << "Введите значение типа int и степень (целое число)\n";
   int pow; //степень
   int num1;
   cin >> num1 >> pow;
   cout << num1 << " в степени " << pow << " = " << power(num1, pow);

   cout << "\nВведите значение типа long и степень (целое число)\n";
   long num2;
   cin >> num2 >> pow;
   cout << num2 << " в степени " << pow << " = " << power(num2, pow);

   cout << "\nВведите значение типа float и степень (целое число)\n";
   float num3;
   cin >> num3 >> pow;
   cout << num3 << " в степени " << pow << " = " << power(num3, pow);
}

int power(int n, int p)
{
    int result = n;
    for (int i=1;i<p;++i)
    result*=n;
    return result;
}
long power(long n, int p)
{
    long result = n;
    for (int i=1;i<p;++i)
    result*=n;
    return result;
}
float power(float n, int p)
{
    float result = n;
    for (int i=1;i<p;++i)
    result*=n;
    return result;
}

void zadacha6()
{
    cout << "Введите 1 время в формате часы, минуты, секунды:\n";
    Time t1;
    char ch = ':';
    cin >> t1.hours >> ch
        >> t1.minutes >> ch
        >> t1.seconds;
    long sum1 = 0;
    sum1 = time_to_secs(t1);

    cout << "Введите 2 время в формате часы, минуты, секунды:\n";
    Time t2;
    cin >> t2.hours >> ch
        >> t2.minutes >> ch
        >> t2.seconds;

    long sum2 = 0;
    sum2 = time_to_secs(t2);

    Time t3;
    long current_time;
    current_time = sum1 + sum2;
    cout << "Суммарное время в секундах:\n" << sum1;

    t3 = secs_to_time(current_time);

    cout << "\nОбратно в формат часы:минуты:секунды : \n"
          << t3.hours << ":"
          << t3.minutes << ":"
          << t3.seconds << endl;
    /*
    Модифицируйте программу, описанную в упражнении 11 главы 4 «Струк-
    туры», складывающую два структурных значения типа time. Теперь про-
    грамма должна включать в себя две функции. Первая, time_to_secs(), при-
    нимает в качестве аргумента значение типа time и возвращает эквивалентное
    значение в секундах типа long. Вторая, secs_to_time(), в качестве аргумента
    принимает число секунд, имеющее тип long, а возвращает эквивалентное
    значение типа time.
    */
}

Time secs_to_time(long time_sum)
{
    Time t4;
    t4.hours=time_sum/3600;//часы (странное конечно имя для часов....)
    time_sum%=3600; // отбросили часы
    t4.minutes=time_sum/60; // минуты
    time_sum%=60; // отбросили минуты
    t4.seconds=time_sum;
    return t4;
}

long time_to_secs(Time aa)
{
    int sum = aa.hours*3600 + aa.minutes*60 + aa.seconds;
    return sum;
}

void zadacha5()
{
    /*
    Напишите функцию с именем hms_to_secs(), имеющую три аргумента типа
    int: часы, минуты и секунды. Функция должна возвращать эквивалент пе-
    реданного ей временного значения в секундах (типа long). Создайте про-
    грамму, которая будет циклически запрашивать у пользователя ввод значе-
    ния часов, минут и секунд и выводить результат работы функции на экран.
    */
    char ch = '\0';
    do
    {
      cout << "Введите время (часы минуты секунды)\n";
      int hours_in, min_in, sec_in;
      cin >> hours_in >> min_in >> sec_in;

      cout << "Время в секундах:\n"
           << hms_to_secs(hours_in, min_in, sec_in)
           << endl;

      cout << "Повторить вычисление?(y/n)\n";
      cin >> ch;
    } while (ch == 'y');

}

long hms_to_secs(int hs, int min, int sec)
{
    int sec_out = hs*3600 + min*60 + sec;
    return sec_out;
}

//void zadacha3glava3()
//{
//    char ch;
//    unsigned long total = 0;
//    cout << "������� �����: ";
//    while ((ch = _getche()) != '\r')
//        total = total * 10 + ch - '0';
//    cout << "\n���������� �����: " << total << endl;
//}

void zadacha4()
{
    /*
    Напишите функцию, принимающую в качестве аргументов два значения
    типа Distance и возвращающую значение наибольшего из аргументов (не-
    обходимую информацию можно найти в примере RETSTRC)
    */

    Distance d1,d2,d3;
    cout << "Введите число футов: "; cin >> d1.feet;
    cout << "Введите число дюймов: "; cin >> d1.inches;

    cout << "Введите число футов: "; cin >> d2.feet;
    cout << "Введите число дюймов: "; cin >> d2.inches;
    d3 = retsrc(d1,d2);
    cout << "Наибольшее значение " << d3.feet << "\'-" << d3.inches << "\"\n";

}

Distance retsrc(Distance first, Distance second)
{
    if (first.feet>second.feet)
        return first;
    else return second;
}

void zadacha3()
{
    /*
    Напишите функцию с именем zeroSmaller(), в которую передаются с по-
    мощью ссылок два аргумента типа int, присваивающую меньшему из ар-
    гументов нулевое значение. Напишите программу для проверки работы
    функции.
    */
    int first, second;
    cout << "Введите два значения\n";
    cin >> first >> second;
    zeroSmaller(first,second);

}

void zeroSmaller(int& a, int& b)
{
    if (a<b)
    {
        cout << a << " меньшее";
        a = 0;
    }
    else
    {
        cout << b << " меньшее";
        b=0;
    }

}

void zadacha2()
{
    /*
     Возведение числа n в степень р — это умножение числа n на себя р раз.
    Напишите функцию с именем power(), которая в качестве аргументов при-
    нимает значение типа double для n и значение типа int для р и возвращает
    значение типа double. Для аргумента, соответствующего степени числа, за-
    дайте значение по умолчанию, равное 2, чтобы при отсутствии показателя
    степени при вызове функции число n возводилось в квадрат. Напишите
    функцию main(), которая запрашивает у пользователя ввод аргументов для
    функции power(), и отобразите на экране результаты ее работы.
    */
    double number;
    int pow;
    cout << "Введите число и степень\n";
    cin >> number >> pow;
    cout << number << " в степени "<< pow
         << " = " << power(number, pow) << endl;
}

double power(double n, int p)
{
    double result = n;
    for (int i=1;i<p;++i)
    result*=n;
    return result;
}

void zadacha1()
{
    /*
    Вернитесь к рассмотрению примера CIRCAREA главы 2 «Основы програм-
    мирования на C++». Напишите функцию с именем circarea(), которая ана-
    логичным образом вычисляет площадь круга. Функция должна принимать
    один аргумент типа float и возвращать значение типа float. Напишите функ-
    цию main(), которая просит пользователя ввести значение радиуса, вызы-
    вает функцию circarea(), а затем отображает результат вычисления на экране.
    */

    float rad;
    cout << "Введите радиус окружности: ";
    cin >> rad;
    float area = circarea(rad);
    cout << "Площадь круга равна " << area << endl;
}

float circarea(float rad)
{
    const float PI =3.14159F;
    return PI *rad *rad;
}

