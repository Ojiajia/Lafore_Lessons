// Глава 2. Основы программирования на C++

#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <CTYPE.h>
#include <QChar>

using namespace std;

void zadacha1();
void zadacha2();
void zadacha3();
void zadacha4();
void zadacha5();
void zadacha6();
void zadacha7();
void zadacha8();  // у меня не работали манипуляторы для форматирования
void zadacha9(); 
void zadacha10();
void zadacha11(); // у меня не работали манипуляторы для форматирования
void zadacha12();

int main()
{
    zadacha7();
    return 0;
}

/* Задача №1
 * Считая, что кубический фут равен 7,481 галлона, написать программу,
 * запрашивающую у пользователя число галлонов и выводящую на экран
 * эквивалентный объем в кубических футах.
 */ 
void zadacha1()
{
    cout << "input the number of gallons" << endl;
    int N_Gallon;
    cin >> N_Gallon;
    cout << "in foots = " << N_Gallon/7.481 << endl;
}

/* Задача №2
 * Напишите программу, выводящую следующую таблицу:
 * 1990 135
 * 1991 7290
 * 1992 11300
 * 1993 16200
 * В программе использовать только один оператор с cout.
 */
void zadacha2()
{
    cout << 1990 << setfill('.') << setw(7) << 135 << endl
         << 1991 << setw(7) << 7290 << endl
         << 1992 << setw(7) << 11300 << endl
         << 1993 << setw(7) << 16200 << endl;
}

/* Задача №3
 *Напишите программу, генерирующую следующий вывод:
 * 10
 * 20
 * 19
 * Используйте представление числа 10 в виде целой константы.
 * Для вывода числа 20 воспользуйтесь одной из арифметических
 * операций с присваиванием, а для вывода числа 19 — операцией
 * декремента.
 */
void zadacha3()
{
    const int a = 10;
    int b = a*2;
    int c = --b;
    cout << 10 << endl << a*2 << endl << c << endl;
}

/* Задача №4
 * Напишите программу, выводящую на экран ваше любимое стихотворение.
 * Для разбиения на строчки используйте подходящую управляющую
 * последовательность.
 */

void zadacha4()
{
    cout << "One is for envy and one just for spite\n"
            "The cuts in my heart, they show me your eyes\n"
            "Don't make it better by twisting knife\n"
            "Turns all by itself, on to someone else";
}

/* Задача №5
 * Библиотечная функция islower() принимает
 * в качестве аргумента один символ (букву)
 * и возвращает ненулевое целое значение в том случае,
 * если буква является строчной, и нулевое,
 * если буква является заглавной.
 * Описание функции хранится в файле CTYPE.H.
 * Напишите программу, которая принимает букву от пользователя,
 * а затем выводит нулевое или ненулевое значение
 * в зависимости от того, является ли буква строчной или нет
 */
void zadacha5()
{
    char x;
    cin >> x;
    cout << islower(x);
}

/* Задача №6
 * На биржевых торгах за 1 фунт стерлингов
 * давали $1.487, за франк — $0.172,
 * за немецкую марку — $0.584,
 * а за японскую йену — $0.00955. Напишите
 * программу, которая запрашивает денежную
 * сумму в долларах, а затем выводит эквивалентные суммы в других валютах
 */
void zadacha6()
{
    double dollar;
    cout << "input the sum in $: ";
    cin >> dollar;
    cout << "in pounds = " << (1000*dollar)/1487 << endl;
    cout << "in franc = " << (1000*dollar)/172 << endl;
    cout << "in marks = " << (1000*dollar)/584 << endl;
    cout << "in Japanese yen = " << (100000*dollar)/955 << endl;
}

/* Задача №7
 * Температуру, измеренную в градусах по Цельсию,
 * можно перевести в градусы по Фаренгейту путем
 * умножения на 9/5 и сложения с числом 32.
 * Напишите программу, запрашивающую температуру
 * в градусах по Цельсию и отображающую ее эквивалент по Фаренгейту
 */
void zadacha7()
{
    cout << "enter temperature in celsius: ";
    float celsius;
    cin >> celsius;
    cout << "in fahrenheit = " << celsius*9/5 + 32;

}

void zadacha8()
{
      /*
      Когда размер величины, выводимой на экран с помощью манипулятора
      setw(), оказывается меньше размера зарезервированного поля, по умолчанию незаполненные поля заполняются пробелами. Манипулятор setfill()
      принимает в качестве аргумента один символ, который замещает все пробелы на незаполненных позициях поля. Модифицируйте пример WIDTH
      так, чтобы символы, разделяющие пары значений из столбцов, были не
      пробелами, а точками, например
      Москва .... 8425785
      */
      
      // у меня не работал манипулятор для форматирования
}

/* Задача №9
 * Две дроби а/b и c/d можно сложить следующим образом:
 * a/b + c/d = (a*d + b*c)/(b*d)
 * Например, 1/4 + 2/3 = (1*3 + 4*2)/4*3 = 11/12
 * Напишите программу, запрашивающую у пользователя значения двух
 * дробей, а затем выводящую результат, также записанный в форме дроби.
 * Взаимодействие программы с пользователем может выглядеть, например,
 * следующим образом:

 * Введите первую дробь: 1/2
 * Введите вторую дробь: 2/5
 * Сумма равна 9/10

 * Вы можете использовать тот факт, что операция извлечения >>может
 * считывать более одного значения за раз:
 * cin >> а >> dummychar >> b;
 */
void zadacha9()
{
    char dummychar = '\0';
    int a,b,c,d;

    cout << "input first fraction (numerator/denominator != 0)" << endl;
    cin >> a >> dummychar >> b;
    
    cout << "input second fraction (numerator/denominator != 0)" << endl;
    cin >> c >> dummychar >> d;
  
      int num = a*d + b*c;
      int denum = b*d;
      cout << "sum =" << num << "/" << denum;
    
}

/* Задача №10
 * Устаревшая денежная система Великобритании состояла из фунтов, шиллингов и пенсов.
 * 1 фунт был равен 20 шиллингам, а 1 шиллинг — 12 пенсам. Для записи использовалась
 * система, состоящая из знака £ и трех деся -
 * тичных значений, разделенных точками. Например, запись £5.2.8 обозна -
 * чала 5 фунтов, 2 шиллинга и 8 пенсов (пенс — множественное число от
 * пенни). Современная денежная система, принятая в 50-е годы XX века,
 * состоит только из фунтов и пенсов, причем один фунт равен 100 пенсам.
 * Такой фунт называют десятичным. Таким образом, в новой денежной
 * системе указанная сумма будет обозначаться как £5.13 (если быть точнее,
 * £5.1333333). Напишите программу, которая будет преобразовывать сумму,
 * записанную в старом формате (фунты, шиллинги, пенсы), в новый
 * формат (фунты, пенсы). Форматом взаимодействия программы с
 * пользователем может являться следующий:

 * Введите количество фунтов: 7
 * Заедите количество шиллингов: 17
 * Введите количество пенсов: 9
 * Десятичных фунтов: £7.89

 * В большинстве компиляторов для представления знака £ используется
 * десятичный код 156. Некоторые компиляторы позволяют скопировать
 * знак фунта прямо из таблицы символов Windows.
 */

void zadacha10()
{
    cout << "Введите количество фунтов: ";
    int pounds_old;
    cin >> pounds_old;
    cout << "Введите количество шилингов: ";
    int shillings_old;
    cin >> shillings_old;
    cout << "введите количество пенсов: ";
    int penny_old;
    cin >> penny_old;
    cout << "Десятичных фунтов: "
         << setprecision(3)
         << pounds_old + shillings_old*0.05 + penny_old/240.1
         << endl;
}

void zadacha11()
{
      /*
      По умолчанию форматирование вывода производится по правому краю
      поля. Можно изменить форматирование текста на левостороннее путем
      использования манипулятора setiosflags(ios::left) (не беспокойтесь о смысле
      новой формы записи, встретившейся в манипуляторе). Используйте этот
      манипулятор вместе с setw() для того, чтобы произвести следующий вывод:

      Фамилия  Имя      Адрес         Город
      ------------------------------------------------
      Петров   Василий  Кленовая 16   Санкт-Петербург
      Иванов   Сергей   Осиновая 3    Находка
      Сидоров  Иван     Березовая 21  Калининград
      */
      
      // у меня не работали манипуляторы для форматирования
}

/* Задача №12
 * Напишите программу, выполняющую действия, обратные тем, которые
 * описаны в упражнении 10, то есть запрашивающую у пользователя сумму,
 * указанную в десятичных фунтах, и переводящую ее в старую систему
 * фунтов, шиллингов и пенсов. Пример взаимодействия программы с
 * пользователем может выглядеть так:

 * Введите число десятичных фунтов: 3.51
 * Эквивалентная сумма в старой форме записи: £3.10.2

 * Обратите внимание на то, что если вам придется присваивать
 * вещественное значение (например, 12,34) переменной целого типа, то его дробная
 * часть (0,34) будет потеряна, а целая переменная получит значение 12.
 * Чтобы избежать предупреждения со стороны компилятора, используйте
 * явное преобразование типов. Можно использовать операторы, подобные
 * приведенным ниже:

 * float decpounds;                        // сумма в десятичных фунтах
 * int pounds;                             // сумма в старых фунтах
 * float decfrac;                          // десятичная дробная часть
 * pounds = static_cast<int>(decpounds);   //отбрасывание
                                        //дробной части
 * decfrac = decpounds - pounds;           //прибавление дробной части

 * Чтобы получить число шиллингов, следует умножить на 20 значение
 * переменной decfrac. Аналогичным образом можно получить число пенсов.
 */

void zadacha12()
{
    cout << "new Введите число десятичных фунтов: ";
    float dec_pounds; // сумма в десятичных фунтах
    cin >> dec_pounds;
    int pounds; // сумма в старых фунтах
    float dec_frac; // десятичная дробная часть от новых фунтов
    pounds = static_cast<int>(dec_pounds);
    dec_frac = dec_pounds - pounds;
    // перевод в старые шиллинги:
    float shillins_old;
    shillins_old = dec_frac/0.05;
//    int dec_shilling; // отбрасывание дробной части
//    dec_shilling = static_cast<int>(shillins_old);
//    float penny_old;
//    penny_old = shillins_old - dec_shilling;


    cout << "2 Эквивалентная сумма записи: "
         << pounds << "." << shillins_old << endl;
}
