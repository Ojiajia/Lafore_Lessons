// Глава №6. Объекты и классы

#include <iostream>
#include <curses.h>
#include <iomanip>
using namespace std;

class Fraction_12
{
private:
    int num; // числитель
    int den; // знаменатель

public:
    Fraction_12():num(0),den(0)
    {}
    void input()
    {
        char ch2 = '/';
        cout << "Введите числитель и знаменатель через пробел:\n";
        cin >> num >> ch2 >> den;
    }

    void output()
    {
        cout << num << "/" << den << " ";
    }

    void sum(Fraction_12 a,Fraction_12 b) //сложение
    {
        num = a.num * b.den + a.den * b.num;
        den = a.den * b.den;
    }
    void substract(Fraction_12 a,Fraction_12 b) //вычитание
    {
        num = a.num * b.den - a.den * b.num;
        den = a.den * b.den;
    }
    void multiply(Fraction_12 a,Fraction_12 b)
    {

        num = a.num * b.num;
        den = a.den * b.den;

    }
    void division(Fraction_12 a,Fraction_12 b)
    {
        num = a.num * b.den;
        den = a.den * b.num;
    }
    void lowterms()
    // сокращение дроби
    {
    long tnum, tden, temp, gcd;
    tnum = labs(num);
    // используем неотрицательные
    tden = labs(den);
    // значения (нужен cmath)
    if( tden == 0 )
    // проверка знаменателя на 0
    { cout << "Недопустимый знаменатель!"; exit(1); }
    else if( tnum == 0 )
    // проверка числителя на 0
    { num=0; den = 1; return; }
    // нахождение наибольшего общего делителя
    while(tnum !=0)
    {
    if( tnum < tden )
    // если числитель больше знаменателя,
    { temp=tnum; tnum=tden; tden=temp; } //меняем их местами
    tnum = tnum - tden;
    // вычитание
    }
    gcd = tden;
    // делим числитель и знаменатель на
    num = num / gcd;
    // полученный наибольший общий делитель
    den = den / gcd;
    }
    Fraction_12 get_division(int n, int denu)
    {
        Fraction_12 a;
        a.num = n-1;
        a.den = denu;
        a.lowterms();

        return a;
    }
};

void zadacha12();

void zadacha11();

class Fraction
{
private:
    int num;   // числитель
    int den; // знаменатель
public:
    void set_number()
    {
        cout << "Введите первую дробь: \n";
        char ch = '/';
        cin >> num >> ch >> den;
    }
    void get_number()
    {
        cout << num << "/" << den << endl;
    }
    void sum_fract(Fraction sec)
    {
        cout << "Сумма равна: "
             << num*sec.den + sec.num*den
             << "/" << den*sec.den << endl;
    }
};

/*
На основе структуры fraction из упражнения 8 главы 4 создайте класс
fraction. Данные класса должны быть представлены двумя полями:
числителем и знаменателем. Методы класса должны получать от пользователя
значения числителя и знаменателя дроби в форме 3/5 и выводить
 значение дроби в этом же формате. Кроме того, должен быть разработан метод,
складывающий значения двух дробей. Напишите функцию main(), которая
циклически запрашивает у пользователя ввод пары дробей, затем
складывает их и выводит результат на экран. После каждой такой операции
программа должна спрашивать пользователя, следует ли продолжать цикл.
*/
void zadacha9();

class Date
{
private:
    int day;
    int month;
    int year;
public:
    void set_date()
    {
        cout << "Введите день месяц и год в формате 31/12/2002\n";
        char ch = '/';
        cin >> day >> ch >> month >> ch >> year;
    }
    void get_date()
    {
        cout << "Вы ввели дату:\n";
        cout << day << "/" << month << "/" << year << endl;
    }

};

void zadacha5();

class Employee
{
private:
    int number;
    float money;
    enum etype { laborer = 0, secretary, manager, accountant, executive, researcher };
    etype enum_post;
    char post;
    int day;
    int month;
    int year;

public:
    void set_data()
    {

        cout << "Введите номер сотрудника и оклад\n";
        cin >> number >> money;
        cout << "Введите первую букву поста работника "
                "laborer(l), secretary(s), manager(m), "
                "accountant(a), executive(e), researcher(r)\n";
        cin >> post;
        switch (post)
        {
            case 'l': { enum_post = laborer;    break; }
            case 's': { enum_post = secretary;  break; }
            case 'm': { enum_post = manager;    break; }
            case 'a': { enum_post = accountant; break; }
            case 'e': { enum_post = executive;  break; }
            case 'r': { enum_post = researcher; break; }
        }//end of switch
        cout << "Введите дату приема сотрудника на работу\n";
        char ch = '/';
        cin >> day >> ch >> month >> ch >> year;
    }
    void get_data()
    {
        cout << "Номер сотрудника: " << number
             << "\nоклад: " << money << endl;

        if (enum_post == laborer)
            cout << "Должность: laborer\n";
         else if (enum_post == secretary)
            cout << "Должность: secretary\n";
         else if (enum_post == manager)
            cout << "Должность: manager\n";
         else if (enum_post == accountant)
            cout << "Должность: accountant\n";
         else if (enum_post == executive)
            cout << "Должность: executive\n";
         else if (enum_post == researcher)
            cout << "Должность: researcher\n";

        cout << "Дата приема на работу: " << day << "/"
             << month << "/" << year << endl;
    }

};

void zadacha4();

class Time
{
private:
    int hs;
    int min;
    int sec;
public:
    Time():hs(0),min(0),sec(0)
    {}
    Time(int hours,int minutes,int seconds):
        hs(hours),min(minutes),sec(seconds)
    {}
    void get_time() const
    {
        cout << "Вывод времени: "<< hs << "." << min << "." << sec << endl;
    }
    void sum_time(const Time time1,const Time time2)
    {
        int sum_1 = time1.hs*3600 + time1.min*60 + time1.sec;
        int sum_2 = time2.hs*3600 + time2.min*60 + time2.sec;
        int sum_3 = sum_1 + sum_2;
        hs = sum_3/3600;//часы (странное конечно имя для часов....)
        sum_3%=3600; // отбросили часы
        min=sum_3/60; // минуты
        sum_3%=60; // отбросили минуты
        sec=sum_3;
    }
};

void zadacha3();

class foo
{
private:
    static int count; // общее поле для всех объектов
    // (в смысле "объявления")
    int number;
public:
    foo() // инкрементирование при создании объекта
    {
        ++count;
        number = count;
    }
    int getcount() // возвращает значение count
    {
        return number;
    }
};

int foo::count = 0; // *определение* count

void zadacha8_glava6();

class Int
{
  private:
    int number;
  public:
    Int():number(0){}
    void set_number(int n)
    { number = n; }
    void get_number()
    { cout << "Значение поля равно " << number << endl; }
    void add_numbers(Int a, Int b)
    { number = a.number + b.number; }
};
void zadacha1();

class tollBoth
{
private:
    unsigned int passed_cars;
    double cash;

public:
    tollBoth():passed_cars(0), cash(0)
    {}
    void payingCar()
    {
        ++passed_cars;
        cash += 0.5;
    }
    void noPayCar()
    {
        ++passed_cars;
    }
    void display()
    {
        cout << "cash = " << cash;
        cout << "\nnumber of cars = " << passed_cars;
    }


};

void zadacha2();
//************************************************************************************************************
int main()
{
    zadacha12();
    return 0;
}
//************************************************************************************************************

/*
Используйте преимущество ООП, заключающееся в том, что однажды
созданный класс можно помещать в другие программы. Создайте новую
программу, которая будет включать класс fraction, созданный в упражнении 11.
Программа должна выводить аналог целочисленной таблицы
умножения для дробей. Пользователь вводит знаменатель, а программа
должна подобрать всевозможные целые значения числителя так, чтобы
значения получаемых дробей находились между 0 и 1. Дроби из получившегося
таким образом набора перемножаются друг с другом во всевозможных комбинациях,
в результате чего получается таблица следующего
вида (для знаменателя, равного 6):

    1/6  1/3  1/2 2/3  5/6
-----------------------------------------
1/6 1/36 1/18 1/12 1/9 5/36
1/3 1/18 1/9  1/6  2/9 5/18
1/2 1/12 1/6  1/4  1/3 5/12
2/3 1/9  2/9  1/3  4/9 5/9
5/6 5/36 5/18 5/12 5/9 25/36
*/
void zadacha12()
{
    cout << "Введите знаменатель:\n";
    int denum;
    cin >> denum;
    cout << "Вывод первой строки таблицы:\n";

    for (int i=1; i <= denum; ++i)
    {
        if (i==1)
            cout << "    ";// можно сделать setfill
                          // в зависимости от ++denum

        else
        {
        Fraction_12 a,b;
        b = a.get_division(i,denum);
        b.output();
        }
    }
    cout << endl;

    for (int j=2; j <= denum; ++j)
    {
        for (int k = 1; k <= denum; ++k)
        {
            if (k == 1)
            {
                Fraction_12 c,d;
                c = d.get_division(j,denum);
                c.output();

            }
            else
            {
                Fraction_12 e,f,g,h,s,z;
                e = f.get_division(j,denum);
                g = h.get_division(k,denum);
                s.multiply(e,g);
                s.lowterms();
                s.output();

            }

        }
        cout << endl;
    }

}


/*
Модифицируйте калькулятор, созданный в упражнении 12 главы 5 так,
чтобы вместо структуры fraction использовался одноименный класс. Класс
должен содержать методы для ввода и вывода данных объектов, а также
для выполнения арифметических операций. Кроме того, необходимо
включить в состав класса функцию, приводящую дробь к несократимому виду.
Функция должна находить наибольший общий делитель числителя и
знаменателя и делить числитель и знаменатель на это значение.
Код функции, названной lowterms(), приведен ниже:

void fraction::lowterms() // сокращение дроби
{
long tnum, tden, temp, gcd;
tnum = labs(num); // используем неотрицательные
tden = labs(den); // значения (нужен cmath)
if( tden == 0 ) // проверка знаменателя на 0
 { cout << "Недопустимый знаменатель!"; exit(1); }
else if( tnum == 0 ) // проверка числителя на 0
 { num=0; den = 1; return; }
// нахождение наибольшего общего делителя
while(tnum !=0)
{
 if( tnum < tden ) // если числитель больше знаменателя,
 { temp=tnum; tnum=tden; tden=temp; } //меняем их местами
 tnum = tnum - tden; // вычитание
}
gcd = tden; // делим числитель и знаменатель на
num = num / gcd; // полученный наибольший общий делитель
den = den / gcd;
}

Можно вызывать данную функцию в конце каждого метода,
выполняющего арифметическую операцию, либо непосредственно перед выводом
на экран результата. Кроме перечисленных методов,
вы можете включить в класс конструктор с двумя аргументами, что также будет полезно.
*/
void zadacha11()
{
    char ch = '\0';
    do
    {
    Fraction_12 one,two,three;
    one.input();
    cout << "Введите операцию:\n";
    char operation = '\0';
    cin >> operation;
    two.input();

    switch (operation)
    {
    case '+':
    {
        three.sum(one,two);
        three.output();
        three.lowterms();
        three.output();
        break;
    }
    case '-':
    {
        three.substract(one,two);
        three.output();
        three.lowterms();
        three.output();
        break;
    }
    case '*':
    {
        three.multiply(one,two);
        three.output();
        three.lowterms();
        three.output();
        break;
    }
    case '/':
    {
        three.division(one,two);
        three.output();
        three.lowterms();
        three.output();
        break;
    }
    }//end of switch

    cout << "Повторить вычисления?\n";
    cin >> ch;
    }while(ch == 'y');
}

void zadacha9()
{
    char ch = '\0';
    do
    {
        Fraction first, second, third;
        first.set_number();
        second.set_number();

        cout << "Первая дробь:\n";
        first.get_number();
        cout << "Вторая дробь:\n";
        second.get_number();

        first.sum_fract(second);
        first.get_number();
        cout << "Повторить вычисление?(y/n)\n";
        cin >> ch;
    }while (ch == 'y');
    /*
    На основе структуры fraction из упражнения 8 главы 4 создайте класс
    fraction. Данные класса должны быть представлены двумя полями: числи-
    телем и знаменателем. Методы класса должны получать от пользователя
    значения числителя и знаменателя дроби в форме 3/5 и выводить значе-
    ние дроби в этом же формате. Кроме того, должен быть разработан метод,
    складывающий значения двух дробей. Напишите функцию main(), которая
    циклически запрашивает у пользователя ввод пары дробей, затем склады-
    вает их и выводит результат на экран. После каждой такой операции про-
    грамма должна спрашивать пользователя, следует ли продолжать цикл.
    */
}

void zadacha5()
{
    Date date1;
    date1.set_date();
    date1.get_date();

    /*
    Взяв в качестве основы структуру из упражнения 5 главы 4, создайте
    класс date. Его данные должны размещаться в трех полях типа int: month,
    day и year. Метод класса getdate() должен принимать значение для объекта
    в формате 12/31/02, а метод showdate() — выводить данные на экран.
    */
}

void zadacha4()
{
    Employee worker1, worker2, worker3;
    worker1.set_data();
    worker2.set_data();
    worker3.set_data();
    worker1.get_data();
    worker2.get_data();
    worker3.get_data();
    /*
    Создайте класс employee, используя упражнение 4 главы 4. Класс должен
    включать поле типа int для хранения номера сотрудника и поле типа float
    для хранения величины его оклада. Методы класса должны позволять
    пользователю вводить и отображать данные класса. Напишите функцию
    main(), которая запросит пользователя ввести данные для трех сотрудни-
    ков и выведет полученную информацию на экран.
    */
}
void zadacha3()
{
    const Time Time1(6,03,44);
    const Time Time2(11,59,59);
    Time Time3;
    cout << "first time: \n";
    Time1.get_time();
    cout << "second time: \n";
    Time2.get_time();
    Time3.sum_time(Time1, Time2);
    cout << "third time: \n";
    Time3.get_time();

    /*
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
    */
    /*
    Создайте класс с именем time, содержащий три поля типа int, предназна-
    ченные для хранения часов, минут и секунд. Один из конструкторов клас-
    са должен инициализировать поля нулевыми значениями, а другой конст-
    руктор — заданным набором значений. Создайте метод класса, который
    будет выводить значения полей на экран в формате 11:59:59, и метод,
    складывающий значения двух объектов типа time, передаваемых в качест-
    ве аргументов.
    В функции main() следует создать два инициализированных объекта (по-
    думайте, должны ли они быть константными) и один неинициализиро-
    ванный объект. Затем сложите два инициализированных значения, а ре-
    зультат присвойте третьему объекту и выведите его значение на экран.
    Где возможно, сделайте методы константными.
    */
}

void zadacha2()
{

//    initscr();
//  //  cbreak();
//    noecho();
//    addstr("hit a key:");
//    char ch = getch();
//    endwin();
//    cout << "u pressed" << ch << endl;


   // noecho();
    tollBoth Both;
    char ch;
    cout << "Введите 'y' для проезда с оплатой "
        "'n' для проезда без оплаты"
        "'Esc' для выдачи текущих значений количества машин "
        "и выручки и завершения программы" << endl;

    //cbreak();
    initscr();
    // noecho();
    while ((ch = getch()) != 27)
    {
        switch (ch)
        {
        case 'y' :
            {
                Both.payingCar(); break;
            }
        case 'n' :
            {
            Both.noPayCar(); break;
            }

        }

    }
    endwin();
    Both.display();

    // или сделать через getchar();

    /*
    Представьте пункт для взимания платежей за проезд по автостраде. Каж-
    дая проезжающая машина должна заплатить за проезд 50 центов, однако
    часть машин платит за проезд, а часть проезжает бесплатно. В кассе ведет-
    ся учет числа проехавших машин и суммарная выручка от платы за проезд.
    Создайте модель такой кассы с помощью класса tollBooth.

    Класс должен
    содержать два поля. Одно из них, типа unsigned int, предназначено для
    учета количества проехавших автомобилей, а второе, имеющее тип double,
    будет содержать суммарную выручку от оплаты проезда.

    Конструктор дол-
    жен инициализировать оба поля нулевыми значениями.

    Метод payingCar()
    инкрементирует число машин и увеличивает на 0,50 суммарную выручку.

    Другой метод, nopayCar(), увеличивает на единицу число автомобилей, но
    оставляет без изменения выручку.

    Метод display() выводит оба значения
    на экран. Там, где это возможно, сделайте методы константными.
    Создайте программу, которая продемонстрирует работу класса. Програм-
    ма должна предложить пользователю нажать одну клавишу для того, что-
    бы сымитировать заплатившего автолюбителя, и другую клавишу, чтобы
    сымитировать недобросовестного водителя. Нажатие клавиши Esc должно
    привести к выдаче текущих значений количества машин и выручки и за-
    вершению программы.
    */
}

/*
Создайте класс, одно из полей которого хранит «порядковый номер» объекта,
то есть для первого созданного объекта значение этого поля равно 1,
для второго созданного объекта значение равно 2 и т. д.
Для того чтобы создать такое поле, вам необходимо иметь еще одно поле,
в которое будет записываться количество созданных объектов класса (это
означает, что последнее поле должно относиться не к отдельным объектам класса,
а ко всему классу в целом. Вспомните, какое ключевое слово
необходимо при описании такого поля.). Каждый раз при создании нового
объекта конструктор может получить значение этого поля и в соответствии
с ним назначить объекту индивидуальный порядковый номер.
В класс следует включить метод, который будет выводить на экран порядковый
номер объекта. Создайте функцию main(), в которой будут созданы три объекта,
и каждый объект выведет на экран свой порядковый
номер, например: Мой порядковый номер: 2 и т. п.
*/
void zadacha8_glava6()
{
            foo f1, f2, f3; // создание трех объектов
        // каждый объект видит одно и то же значение
        cout << "Порядковый номер " << f1.getcount() << endl;
        cout << "Порядковый номер " << f2.getcount() << endl;
        cout << "Порядковый номер " << f3.getcount() << endl;
}

void zadacha1()
{
    /*
    Создайте класс Int, имитирующий стандартный тип int. Единственное
    поле этого класса должно иметь тип int. Создайте методы, которые будут
    устанавливать значение поля, равным нулю, инициализировать его целым
    значением, выводить значение поля на экран и складывать два значения
    типа Int.
    Напишите программу, в которой будут созданы три объекта класса Int,
    два из которых будут инициализированы. Сложите два инициализирован-
    ных объекта, присвойте результат третьему, а затем отобразите результат
    на экране.
    */

    Int first, sec, third;
    first.set_number(1);
    sec.set_number(2);

    first.get_number();
    sec.get_number();

    third.add_numbers(first,sec);

    third.get_number();


}
