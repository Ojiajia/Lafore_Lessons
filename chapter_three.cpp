// Глава №3. Циклы и ветвления.
using namespace std;
#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

void zadacha1();
//void zadacha2();
void zadacha7();
void zadacha10();
void zadacha8();
void zadacha11();
void zadacha12(float& dec_pounds);
void zadacha4();
void zadacha12();
void zadacha6();
void zadacha2();


int main()
{
    zadacha2();

    return 0;
}

/*
Напишите программу, предлагающую пользователю осуществить перевод
температуры из шкалы Цельсия в шкалу Фаренгейта или наоборот, а затем
осуществите преобразование. Используйте в программе переменные вещественного типа.
Взаимодействие программы с пользователем может выглядеть следующим образом:
Нажмите 1 для перевода шкалы Цельсия в шкалу Фаренгейта,
2 для перевода шкалы Фаренгейта в шкалу Цельсия: 2
Введите температуру по Фаренгейту: 70
Значение по Цельсию: 21.111111
*/
void zadacha2()
{
    int response;
    double temper;
    cout << "Нажмите 1 для перевода из Фаренгейта в Цельсии,"
         << "\n2 для обратного переводa: ";
    cin >> response;
    if (response == 2)
    {
        cout << "Введите температуру (в Фаренгейтах): ";
        cin >> temper;
        cout << "В Цельсиях будет " << 5.0/9.0*(temper - 32.0) << endl;
    } // end of if
    else if (response == 1)
    {
        cout << "Введите температуру в Цельсиях: ";
        cin >> temper;
        cout << "В Фаренгейтах будет: " << 9.0/5.0*temper + 32.0 << endl;
    } //end of else if


}

/*
Измените программу factor, приведенную в этой главе, таким образом,
чтобы она циклически запрашивала ввод пользователем числа и вычисляла его факториал,
пока пользователь не введет 0. В этом случае программа должна завершиться.
При необходимости вы можете использовать соответствующие операторы
программы factor в цикле do или while.
*/
void zadacha6()
{
    char ch = '\0';

    do
    {
        unsigned int numb = 0;
        unsigned long fact = 1;
        cout << "Введите челое число: ";
        cin >> numb;
        for (int j=numb; j>0; j--)
            fact *=j;
        cout << "Факториал числа равен " << fact << endl;
        cout << "Чтобы выйти, нажмите 0, чтобы повторить счет - любой другой символ ";
        cin >> ch;
    }while(ch != '0');
}


/*
Создайте калькулятор, выполняющий четыре арифметических действия
над дробями (см. упражнение 9 главы 2 и упражнение 4 этой главы).
Формулы, демонстрирующие выполнение арифметических операций над
дробями, приведены ниже.

Сложение: a/b + c/d = (a*d + b*c)/(b*d)
Вычитание: a/b - c/d = (a*d - b*c)/(b*d)
Умножение: a/b*c/d = (a*c)/(b*d)
Деление: a/b/c/d = (a*d)/(b*c)

Пользователь должен сначала ввести первый операнд,
затем знак операции и второй операнд.
После вычисления результата программа должна
отобразить его на экране и запросить пользователя
о его желании произвести еще одну операцию.
*/
void zadacha12()
{
    char ch='\0';
    do
    {
        double a = 0, b = 0, c = 0, d = 0;
        char operation = '\0';
        char slash ='/';

        cout << "Введите первый операнд, операцию и второй операнд: ";
        cin >> a >> slash >> b >> operation >> c >> slash >> d;
        switch (operation)
        {
            case '+':
            {
                cout << "Результат равен: "
                     << a*d + b*c << '/' << b*d << endl;
                break;
            }
            case '-':
            {
                cout << "Результат равен: "
                     << a*d - b*c << '/' << b*d << endl;
                break;
            }
            case '*':
            {
                cout << "Результат равен: "
                     << a*c << '/' << b*d << endl;
                break;
            }
            case '/':
            {
                cout << "Результат равен: "
                     << a*d << '/' << b*c << endl;
                break;
            }
            default:
                break;
        } // end of switch

        cout << "Выполнить еще одну операцию (y/n)? ";
        cin >> ch;
    }while(ch=='y');

}

/*
Создайте эквивалент калькулятора, выполняющего четыре основных арифметических операции.
Программа должна запрашивать ввод пользователем первого операнда,
знака операции и второго операнда. Для хранения
операндов следует использовать переменные вещественного типа. Выбрать
операцию можно при помощи оператора switch. В конце программа
должна отображать результат на экране. Результат работы программы с пользователем
может выглядеть следующим образом:

Введите первый операнд, операцию и второй операнд: 10 / 3
Результат равен 3.333333
Выполнить еще одну операцию (y/n)? y
Введите первый операнд, операцию и второй операнд: 12 + 100
Результат равен 112
Выполнить еще одну операцию (y/n)? n
*/
void zadacha4()
{
    char ch2 = '\0';
    do
    {
    cout << "Введите первый операнд, операцию и второй операнд: ";
    double a=0, b=0;
    char ch='\0';
    cin >> a >> ch >> b;

    switch (ch)
    {
        case '+':
        {
            cout << "Результат равен: "
                 << a+b << endl;
            break;
        }
        case '-':
        {
            cout << "Результат равен: "
                 << a-b << endl;
            break;
        }
        case '*':
        {
            cout << "Результат равен: "
                 << a*b << endl;
            break;
        }
        case '/':
        {
            cout << "Результат равен: "
                 << a/b << endl;
            break;
        }
        default:
            break;
    } // end of switch
    cout << "Выполнить еще одну операцию (y/n)? ";
    cin >> ch2;
    }while(ch2=='y'); // end of do while
}

/*
Создайте калькулятор, выполняющий действия над денежными суммами,
выраженными в фунтах, шиллингах и пенсах (см. упражнения 10 и 12
главы 2). Калькулятор должен складывать и вычитать вводимые значения,
а также производить умножение денежной суммы на вещественное
число (операция умножения двух денежных сумм не имеет смысла,
поскольку квадратных денежных единиц не существует.
Деление одной денежной суммы на другую мы тоже не будем рассматривать).
Организация взаимодействия с калькулятором описана в упражнении 4 этой главы.
*/
void zadacha11()
{
    char ch = '\0';
    float pounds_first, shillings_first, penny_first;
    int pounds_sec, shillings_sec, penny_sec;
    int pounds_end = 0, shillings_end = 0, penny_end = 0;
    float pounds_dec; // для подстановки в функцию
    float first_pounds, second_pounds; // для умножения и вычитания
    do
    {
        char ch2 = '\0';
        cout << "Сложить или вычесть два числа(+,-),"
                 "или умножить на вещественное число(*)" << endl;
        cin >> ch2;
        switch(ch2)
        {
        case '+':
        {
            cout << "Введите первую сумму: ";

            cin >> pounds_first >> shillings_first >> penny_first;
            cout << "Введите вторую сумму: ";

            cin >> pounds_sec >> shillings_sec >> penny_sec;

            int pounds_end = 0, shillings_end = 0, penny_end = 0;
            penny_end = penny_first + penny_sec;
            if (penny_end >= 12)
            {
                ++shillings_end;
                penny_end = 0;
            }
                shillings_end += shillings_first + shillings_sec;
            if (shillings_end >= 20)
            {
                ++pounds_end;
                shillings_end = 0;
            }
            pounds_end += pounds_first + pounds_sec;
            cout << "Всего " << pounds_end << " " << shillings_end << " " << penny_end << endl;
            pounds_end = 0;
            shillings_end = 0;
            penny_end = 0;
            break;
        }
        case '-':
        {
            cout << "Введите первую сумму: ";
            cin >> pounds_first >> shillings_first >> penny_first;
            cout << "Введите вторую сумму: ";
            cin >> pounds_sec >> shillings_sec >> penny_sec;

// не очень точный вариант
//            first_pounds = pounds_first*240 + shillings_first*12 + penny_first;

//            second_pounds = pounds_sec*240 + shillings_sec*12 + penny_sec;
//            pounds_dec = (first_pounds - second_pounds)/240;
//            cout << "фунты десятичные: " << pounds_dec;
//            zadacha12(pounds_dec);
//            pounds_dec = 0;

// длинный вариант:
            if (penny_first < penny_sec)
            {
                --shillings_first;
                penny_first += 12;
                penny_end = penny_first - penny_sec;
            }
            penny_end = penny_first - penny_sec;

            if (shillings_first < shillings_sec)
            {
                --pounds_first;
                shillings_first += 20;
                shillings_end = shillings_first - shillings_sec;
             }

            shillings_end = shillings_end = shillings_first - shillings_sec;

            pounds_end = pounds_first - pounds_sec;
            cout << "Всего " << pounds_end << " " << shillings_end << " " << penny_end << endl;
            pounds_end = 0;
            shillings_end = 0;
            penny_end = 0;
            break;
        }
        case '*':
        {
            cout << "Введите денежную сумму: ";
            cin >> pounds_first >> shillings_first >> penny_first;
            cout << "Введите множитель: ";
            float number;
            cin >> number;
            pounds_dec = pounds_first*240 + shillings_first*12 + penny_first;
            pounds_dec /= 240;
            pounds_dec *= number;
            // cout << "sum of pounds = " << pounds_dec << endl;
            zadacha12(pounds_dec);
            pounds_dec = 0;
        } // end of case
        } // end of switch
        cout << "Продолжить(y)? ";
        cin >> ch;
    }while (ch=='y');
}

/*
 Создайте калькулятор, выполняющий четыре арифметических действия
над дробями (см. упражнение 9 главы 2 и упражнение 4 этой главы).
Формулы, демонстрирующие выполнение арифметических операций над
дробями, приведены ниже.

Сложение: a/b + c/d = (a*d + b*c)/(b*d)
Вычитание: a/b - c/d = (a*d - b*c)/(b*d)
Умножение: a/b*c/d = (a*c)/(b*d)
Деление: a/b/c/d = (a*d)/(b*c)

Пользователь должен сначала ввести первый операнд,
затем знак операции и второй операнд.
После вычисления результата программа должна
отобразить его на экране и запросить пользователя о
его желании произвести еще одну операцию.
*/
void zadacha12(float& dec_pounds)
{
    //cout << "переданные фунты: " << dec_pounds << endl;
    int pounds = 0; // сумма в старых фунтах
    float dec_frac = 0; // десятичная дробная часть от новых фунтов
    pounds = static_cast<int>(dec_pounds); // фунты на вывод
    dec_frac = dec_pounds - pounds; // десятичная часть от фунтов
    //cout << "десятичная часть от них: " << dec_frac << endl;

    // перевод в старые шиллинги:
    float dec_shillings = dec_frac*20; // шиллинги с дробной частью
    //cout << "десятичные шиллинги: " << dec_shillings << endl;
    //найдем целую часть от шиллингов
    int shillings = static_cast<int>(dec_shillings);
    //найдем дробную часть от шиллингов
    float dec_frac_shillings = dec_shillings - shillings;

    //перевод в пенни:
    float dec_penny = dec_frac_shillings*12; // пенни с дробной частью
    int penny = static_cast<int>(dec_penny);

    cout << "Результат: "
         << pounds << "." << shillings << "." << penny << endl;
}

/*
Напишите программу, которая циклически будет запрашивать ввод
пользователем двух денежных сумм, выраженных в фунтах, шиллингах
и пенсах (см. упражнения 10 и 12 главы 2). Программа должна складывать
введенные суммы и выводить на экран результат, также выраженный в
фунтах, шиллингах и пенсах. После каждой итерации программа должна
спрашивать пользователя, желает ли он продолжать работу программы.
При этом рекомендуется использовать цикл do. Естественной формой
взаимодействия программы с пользователем была бы следующая:

Введите первую сумму £5 10 6
Введите первую сумму £3 2 6
Всего £8 13 0
Продолжить(y/n) ?

Для того чтобы сложить две суммы, вам необходимо учесть заем одного
шиллинга в том случае, если число пенсов окажется больше 11, и одного
фунта, если число шиллингов окажется больше 19.
*/
void zadacha8()
{
    char ch = '\0';
    do
    {
        cout << "Введите первую сумму: ";
        int pounds_first, shillings_first, penny_first;
        cin >> pounds_first >> shillings_first >> penny_first;
        cout << "Введите вторую сумму: ";
        int pounds_sec, shillings_sec, penny_sec;
        cin >> pounds_sec >> shillings_sec >> penny_sec;

        int pounds_end = 0, shillings_end = 0, penny_end = 0;
        penny_end = penny_first + penny_sec;
        if (penny_end >= 12)
        {
            ++shillings_end;
            penny_end = 0;
        }
            shillings_end += shillings_first + shillings_sec;
        if (shillings_end >= 20)
        {
            ++pounds_end;
            shillings_end = 0;
        }
        pounds_end += pounds_first + pounds_sec;
        cout << "Всего " << pounds_end << " " << shillings_end << " " << penny_end << endl;
        cout << "Продолжить(y/n)? ";
        cin >> ch;
    }while(ch=='y');

}

/*
Предположим, вы хотите создать таблицу умножения на заданное число.
Напишите программу, которая позволяет пользователю ввести это число,
а затем генерирует таблицу размером 20 строк на 10 столбцов. Первые
строки результата работы программы должны выглядеть примерно следующим образом:
Введите число: 7
7142128354249566370
77849198105112119126133140
147154161168175182189196203210
*/
void zadacha1()
{
    cout << "Введите число: ";
    int n;
    cin >> n;
    for (int i=1;i<=30;++i)
    {
//        if((i%10)!= 0)
//            cout << n*i;
//        else
//        {
//            cout << n*i;
//            cout << endl;
//        }
    // из ответов:
    cout << i*n;
    if(i%10==0)
        cout << endl;
    }
}

//void zadacha2()
//{
//  getch();
//}

/*
Напишите программу, рассчитывающую сумму денег,
которые вы получите при вложении начальной суммы с
фиксированной процентной ставкой
дохода через определенное количество лет.
Пользователь должен вводить
с клавиатуры начальный вклад, число лет и процентную ставку.
Примером результата работы программы может быть следующий:

Введите начальный вклад: 3000
Введите число лет: 10
Введите процентную ставку: 5.5
Через 10 лет вы получите 5124.43 доллара.

В конце первого года вы получите 3 000 + (3 000*0.055) = 3165 долларов.
В конце следующего года вы получите 3 165 + (3 165*0.055) = 3339.08 долларов.
Подобные вычисления удобно производить с помощью цикла for.
*/
void zadacha7()
{
    cout << "Введите начальный вклад: ";
    float first_sum;
    cin >> first_sum;
    cout << "Введите число лет: ";
    int n_let;
    cin >> n_let;
    cout << "Введите процентную ставку: ";
    float percent;
    cin >> percent;
    percent*=0.01;
    float end_sum = 0;
    for (int i=1; i<=n_let; ++i)
    {
        end_sum = first_sum+ first_sum*percent;
        first_sum = end_sum;
        if (i==n_let)
            cout << end_sum;
    }
}
/*
Модифицируйте программу, описанную в упражнении 7, так, чтобы вместо вычисления текущей суммы на вашем счете она вычисляла, сколько
лет потребуется для того, чтобы при заданной процентной ставке и величине начального вклада сумма на вашем счете достигла запрашиваемого
вами значения. Для хранения найденного числа лет используйте переменную целого типа (можно отбросить дробную часть значения, полученного
в результате расчета). Самостоятельно выберите тип цикла, подходящий
для решения задачи
*/
void zadacha10()
{
    cout << "Введите процентную ставку: ";
    float percent;
    cin >> percent;
    cout << "Введите величину начального вклада: ";
    float first_sum;
    cin >> first_sum;
    cout << "Введите конечную сумму: ";
    float end_sum;
    cin >> end_sum;
    float sum = 0;
    int i = 0;
    while (sum <= end_sum)
    {
        sum = first_sum + first_sum*percent*0.01;
        first_sum = sum;
        ++i;
    }
    cout << "Количество лет: " << i << endl;
}

