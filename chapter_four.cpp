// Глава №4. Структуры
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void zadacha1();
void zadacha2();
void zadacha3();
void zadacha4();
void zadacha5();
void zadacha7();
void zadacha8();
void zadacha9();
void zadacha11();
void zadacha10();
void zadacha12();
void zadacha6();

int main()
{
    zadacha6();
    return 0;
}

void zadacha6()
{
    /*
    Как мы говорили, стандартные средства ввода/вывода C++ вместо значе-
    ний перечисляемых типов данных выводят их внутреннее представление
    в виде целых чисел. Для того чтобы преодолеть это ограничение, вы мо-
    жете использовать конструкцию switch, с помощью которой устанавлива-
    ется соответствие между значением переменной перечисляемого типа и ее
    внутренним представлением. Пусть, например, в программе определен пе-
    речисляемый тип данных etype, отражающий должность сотрудника:
    enum etype { laborer, secretary, manager, accountant, executive, researcher };
    Напишите программу, которая сначала по первой букве должности, введен-
    ной пользователем, определяет соответствующее значение переменной, по-
    мещает это значение в переменную типа etype, а затем выводит полностью
    название должности, первую букву которой ввел пользователь. Взаимодей-
    ствие программы с пользователем может выглядеть следующим образом:
    Введите первую букву должности
    (laborer, secretary, manager, accountant,
    executive, researcher); a
    полное название должности: accountant
    Возможно, вам понадобится два ветвления switch: одно — для ввода значе-
    ния, другое — для вывода.
    */

    enum etype { laborer = 0, secretary, manager, accountant, executive, researcher };

    char post;
    cout << "Введите первую букву поста работника "
            "laborer(l), secretary(s), manager(m), "
            "accountant(a), executive(e), researcher(r)\n";
    cin >> post;
    etype enum_post;

    switch (post)
    {
        case 'l': { enum_post = laborer; cout << "laborer\n"; break; }
        case 's': { enum_post = secretary; cout << "secretary\n"; break; }
        case 'm': { enum_post = manager; cout << "manager\n";   break; }
        case 'a': { enum_post = accountant; cout << "accountant\n"; break; }
        case 'e': { enum_post = executive; cout << "executive\n"; break; }
        case 'r': { enum_post = researcher; cout << "researcher\n"; break; }
    }//end of switch

    switch (enum_post)
    {
    case '0':     { cout << 'laborer\n';    break; }
    case '1':   { cout << "secretary\n";  break; }
    case '2':     { cout << "manager\n";    break; }
    case '3':  { cout << "accountant\n"; break; }
    case '4':   { cout << "executive\n";  break; }
    case '5':  { cout << "researcher\n"; break; }
    default:{break;}
    }


}

void zadacha12()
{
    /*
    Переработайте программу-калькулятор для дробей, описанную в упраж-
    нении 12 главы 3 так, чтобы каждая из дробей хранилась как значение пе-
    ременной типа struct fraction, по аналогии с упражнением 8 этой главы.
    */

    struct fraction
    {
        int numerator;   // числитель
        int denomirator; // знаменатель
    };



    char ch='\0';
    do
    {
        fraction first;
        fraction second;

        char slash ='/';
        char operation = '\0';

        cout << "Введите первую дробь, операцию и второй дробь: ";

        cin >> first.numerator              //a
            >> slash >> first.denomirator   //b
            >> operation
            >> second.numerator             //c
            >> slash >> second.denomirator; //d

        switch (operation)
        {
            case '+':
            {
                cout << "Результат равен: "
                     << first.numerator*second.denomirator
                        + first.denomirator*second.numerator
                     << '/' << first.denomirator*second.denomirator << endl;
                break;
            }
            case '-':
            {
                cout << "Результат равен: "
                     << first.numerator*second.denomirator
                        - first.denomirator*second.numerator
                     << '/' << first.denomirator*second.denomirator << endl;
                break;
            }
            case '*':
            {
                cout << "Результат равен: "
                     << first.numerator*second.numerator
                     << '/' << first.denomirator*second.denomirator << endl;
                break;
            }
            case '/':
            {
                cout << "Результат равен: "
                     << first.numerator*second.denomirator
                     << '/' << first.denomirator*second.numerator << endl;
                break;
            }
            default:
                break;
        } // end of switch

        cout << "Выполнить еще одну операцию (y/n)?\n";
        cin >> ch;
    }while(ch=='y');

}

void zadacha10()
{
    /*
    Создайте структуру с именем sterling, хранящую денежные суммы в старой
    английской системе, описанной в упражнениях 8 и 11 главы 3 «Циклы и
    ветвления». Поля структуры могут быть названы pounds, shillings и pence
    и иметь тип int. Программа должна запрашивать у пользователя значение
    денежной суммы в новых десятичных фунтах (значение должно хранить-
    ся в переменной типа double), затем переводить эту сумму в старую систе-
    му, сохранять переведенное значение в переменной типа sterling и выво-
    дить на экран полученную сумму в фунтах, шиллингах и пенсах.
    */

    struct sterling
    {
        int pounds;
        int shillings;
        int pence;
    };

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
}

void zadacha11()
{
    /*
    Используя структуру time из упражнения 9, напишите программу, кото-
    рая получает от пользователя два значения времени в формате 12:59:59,
    сохраняет их в переменных типа struct time, затем переводит оба значения
    в секунды, складывает их, переводит сумму в исходный формат, сохраня-
    ет его в переменной типа time и выводит полученный результат на экран
    в формате 12:59:59
    */

    struct time
    {
      int hours;
      int minutes;
      int seconds;
    };

    cout << "Введите 1 время в формате часы, минуты, секунды:\n";
    time t1;
    char ch = ':';
    cin >> t1.hours >> ch
        >> t1.minutes >> ch
        >> t1.seconds;
    long sum1 = 0;
    sum1 = (t1.hours)*3600 + (t1.minutes)*60 + t1.seconds;

    cout << "Введите 2 время в формате часы, минуты, секунды:\n";
    time t2;
    cin >> t2.hours >> ch
        >> t2.minutes >> ch
        >> t2.seconds;

    long sum2 = 0;
    sum2 = (t2.hours)*3600 + (t2.minutes)*60 + t2.seconds;

    time t3;
    float current_time;
    current_time = sum1 + sum2;

    current_time /= 3600; // перевод в часы с дробной частью
    float dec_hours; // дробная часть от часов
    t3.hours = static_cast<int>(current_time); // часы на вывод
    dec_hours = current_time - t3.hours; // дробная часть от часов

    // дробную часть от часов переведем в минуты
    dec_hours *= 60; //дробное значение количества минут
    float fract_minutes; // дробная часть от минут
    t3.minutes = static_cast<int>(dec_hours); // минуты на вывод
    fract_minutes = dec_hours - t3.minutes; // дробная часть от минут

    t3.seconds = fract_minutes * 60;
    t3.seconds = static_cast<int>(t3.seconds);

    cout << "Суммарное время: "
          << t3.hours << ":"
          << t3.minutes << ":"
          << t3.seconds << endl;
}

void zadacha9()
{
    /*
    Создайте структуру с именем time. Три ее поля, имеющие тип int, будут
    называться hours, minutes и seconds. Напишите программу, которая просит
    пользователя ввести время в формате часы, минуты, секунды. Можно
    запрашивать на ввод как три значения сразу, так и выводить для каж-
    дой величины отдельное приглашение. Программа должна хранить время
    в структурной переменной типа time и выводить количество секунд в вве-
    денном времени, определяемое следующим образом:
    long totalseсs = t1.hours*3600 + t1.minutes*60 + t1.seconds
    */

    struct time
    {
      int hours;
      int minutes;
      int seconds;
    };

    cout << "Введите время в формате часы, минуты, секунды:\n";
    time current_time;
    cin >> current_time.hours
        >> current_time.minutes
        >> current_time.seconds;
    long sum = 0;
    sum = (current_time.hours)*3600 + (current_time.minutes)*60 + current_time.seconds;
    cout << "\nКоличество секунд: " << sum;

}

void zadacha8()
{
/*
    Вернитесь к упражнению 9 главы 2 «Основы программирования на C++».
    В этом упражнении требуется написать программу, которая хранит значе-
    ния двух дробей в виде числителя и знаменателя, а затем складывает эти
    дроби согласно арифметическому правилу. Измените эту программу так,
    чтобы значения дробей хранились в структуре fraction, состоящей из двух
    полей типа int, предназначенных для хранения числителя и знаменателя.
    Все значения дробей должны храниться в переменных типа fraction.
    void zadacha7()
*/
    struct fraction
    {
        int numerator;   // числитель
        int denomirator; // знаменатель
    };

    fraction first;
    fraction second;

    char dummychar = '/';

    cout << "Введите первую дробь: ";
    cin >> first.numerator >> dummychar >> first.denomirator;
    cout << "Введите вторую дробь: ";
    cin >> second.numerator >> dummychar >> second.denomirator;
    cout << "Сумма равна "
         << first.numerator*second.denomirator + first.denomirator*second.numerator
         << "/" << first.denomirator*second.denomirator << endl;

}

void zadacha7()
{
    /*
       Добавьте поля типа enum etype (см. упражнение 6) и struct date (см. упраж-
       нение 5) в структуру employee из упражнения 4. Организуйте программу
       таким образом, чтобы пользователь вводил 4 пункта данных о каждом из
       трех сотрудников: его номер, величину зарплаты, его должность и дату
       принятия на работу. Программа должна хранить введенные значения в трех
       переменных типа employee и выводить их содержимое на экран.
    */

    enum etype { laborer = 0, secretary, manager, accountant, executive, researcher };

    struct date
    {
      int day;
      int month;
      int year;
    };

    struct employee
    {
      int number_of_worker;
      float money;
      etype post;
      date employ_date;
    };

    cout << "Введите номер, величину зарплаты, и дату"
            " принятия на работу\n";

    employee first_worker;
//    employee second_worker;
 //   employee third_worker;

    char ch = '/';

    cin >> first_worker.number_of_worker
        >> first_worker.money
        //>> first_worker.post
        >> first_worker.employ_date.day >> ch
        >> first_worker.employ_date.month >> ch
        >> first_worker.employ_date.year;

    cout << "\nВыберите должность:\n"
            "laborer(l), secretary(s), manager(m)"
            " accountant(a), executive(e), researcher(r)\n";

    char post_of_worker = first_worker.post;

    cin >> post_of_worker;

    cout << "№ сотрудника " << first_worker.number_of_worker << endl
         << "Величина зарплаты " << first_worker.money << endl
            //>> first_worker.post
         << "Дата принятия на работу "<< first_worker.employ_date.day << "/"
         << first_worker.employ_date.month << "/"
         << first_worker.employ_date.year << endl;

    switch (post_of_worker)
    {
        case 'l': { first_worker.post = laborer;    break; }
        case 's': { first_worker.post = secretary;  break; }
        case 'm': { first_worker.post = manager;    break; }
        case 'a': { first_worker.post = accountant; break; }
        case 'e': { first_worker.post = executive;  break; }
        case 'r': { first_worker.post = researcher; break; }

    }//end of switch


    if (first_worker.post == laborer)        cout << "laborer";
    else if (first_worker.post == secretary) cout << "secretary";
    else if (first_worker.post == manager)   cout << "manager";
    else if (first_worker.post == accountant)cout << "accountant";
    else if (first_worker.post == executive) cout << "executive";
    else if (first_worker.post == researcher)cout << "researcher";


}

void zadacha5()
{
    /*
     Создайте структуру типа date, содержащую три поля типа int: месяц,
     день и год. Попросите пользователя ввести день, месяц и год в формате
     31/12/2002, сохраните введенное значение в структурной переменной, а за-
     тем извлеките данные из этой переменной и выведите их на экран в том же
     формате, в каком они вводились.
   */

    struct date
    {
      int day;
      int month;
      int year;
    };

    cout << "Введите день месяц и год в формате 31/12/2002\n";
    date user_date;
    char ch = '/';
    cin >> user_date.day >> ch
        >> user_date.month >> ch
        >> user_date.year;

    cout << "\nВы ввели дату:\n"
         << user_date.day << ch
         << user_date.month << ch
         << user_date.year << endl;
}

void zadacha4()
{
    struct employee
    {
      int number_of_worker;
      float money;
    };

    cout << "Введите величину пособия 1 сотрудника\n";
    employee first_worker;
    first_worker.number_of_worker = 1;
    cin >> first_worker.money;

    cout << "Введите величину пособия 2 сотрудника\n";
    employee second_worker;
    second_worker.number_of_worker = 2;
    cin >> second_worker.money;

    cout << "Введите величину пособия 3 сотрудника\n";
    employee third_worker;
    third_worker.number_of_worker = 3;
    cin >> third_worker.money;

    cout << "Информация о сотрудниках: \n";

    cout << "№ сотрудника " << first_worker.number_of_worker
         << " Величина его пособия в долларах " << first_worker.money << endl;

    cout << "№ сотрудника " << second_worker.number_of_worker
         << " Величина его пособия в долларах " << second_worker.money << endl;

    cout << "№ сотрудника " << third_worker.number_of_worker
         << " Величина его пособия в долларах " << third_worker.money << endl;

    /*
    Создайте структуру с именем employee, содержащую два поля: номер со-
    трудника типа int и величину его пособия в долларах типа float. Запроси-
    те с клавиатуры данные о трех сотрудниках, сохраните их в трех струк-
    турных переменных типа employee и выведите информацию о каждом из
    сотрудников на экран
*/
}

void zadacha3()
{

    /*
Создайте структуру с именем Volume, содержащую три поля типа Distance
из примера englstrc, для хранения трех измерений помещения.
Определите переменную типа Volume, инициализируйте ее, вычислите объем,
занимаемый помещением, и выведите результат на экран. Для подсчета объема
переведите каждое из значений типа Distance в значение типа float, равное
соответствующей длине в футах и хранимое в отдельной переменной.
Затем для вычисления объема следует перемножить три полученные вещественные переменные
    */
    struct Distance // длина в английской системе
    {
     int feet; // футы
     float inches; // дюймы
    };
    //////////////////////////////////////////////////////////
    struct Volume // размеры прямоугольной комнаты
    {
     Distance length; // длина
     Distance width; // ширина
     Distance height; // высота
    };
    //////////////////////////////////////////////////////////

    Volume dining = {{13,6.5},{10,0.0},{8,1.75}}; // переменная dining типа Room

  /* dining.length.feet = 13; // задание параметров комнаты
     dining.length.inches = 6.5;
     dining.width.feet = 10;
     dining.width.inches = 0.0;
     dining.height.feet = 3;
     dining.height.inches = 0.0;
  */

     // преобразование длины и ширины в вещественный формат
     float l = dining.length.feet + dining.length.inches/12;
     float w = dining.width.feet + dining.width.inches/12;
     float h = dining.height.feet + dining.height.inches/12;


     // вычисление площади комнаты и вывод на экран
     cout << "Объем комнаты равен " << l * w * h
     << " кубичных футов\n";

}

void zadacha2()
{
    struct point
    {
      int x;
      int y;
    };

    cout << "Введите координаты точки p1: ";
    point p1;
    cin >> p1.x >> p1.y;
    cout << "Введите координаты точки p2: ";
    point p2;
    cin >> p2.x >> p2.y;

    point p3 = {p1.x + p2.x, p1.y + p2.y};
    cout << "Координаты точки p1+p2 равны "
         << p3.x << "." << p3.y
         << endl;

/*  Введите координаты точки p1: 3 4
    Введите координаты точки p2: 5 7
    Координаты точки p1+p2 равны 8.11
*/
}


void zadacha1()
{
    struct phone
    {
        int city_code;
        int station_number;
        int subscriber_number;
    };

    phone first_phone {212, 767, 8900};
    cout << "Введите код города, номер "
            "станции и номер абонента:" << endl;
    phone second_phone;
    cin >> second_phone.city_code >> second_phone.station_number
        >> second_phone.subscriber_number;

    cout << "Мой номер " << "(" << first_phone.city_code << ") "
                         << first_phone.station_number << "-"
                         << first_phone.subscriber_number << endl;

    cout << "Ваш номер " << "(" << second_phone.city_code << ") "
                         << second_phone.station_number << "-"
                         << second_phone.subscriber_number << endl;


    /* Введите код города, номер станции и номер абонента:
    415 555 1212
    Мой номер (212) 767-8900
    Ваш номер (415) 555-1212
    */
}
