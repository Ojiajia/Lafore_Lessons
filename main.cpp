// Глава №7. Массивы и строки

#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

void zadacha1();
char* reverseit(char a[]);
void zadacha2();
class Employee
{
private:
    string name;
    long number;
public:
    void getdata()
    {
        cout << "Введите имя сотрудника\n";
        cin >> name;
        cout << "Введите номер сотрудника\n";
        cin >> number;
    }
    void putdata()
    {
        cout << "Имя сотрудника " << name << " № сотрудника " << number << endl;
    }

};

class Employee2
{
private:
    enum {MAX = 80};
    char name[3][MAX];
    long number[3];
public:
    void getdata()
    {
        for (int i=0;i<=2;++i)
        {
            cout << "Введите имя сотрудника\n";
            cin >> name[i];
            cout << "Введите номер сотрудника\n";
            cin >> number[i];
        }
    }
    void putdata()
    {
        for (int i=0;i<=2;++i)
        {
            cout << "Имя сотрудника: " << name[i]
                 << "Номер сотрудника: " << number[i];
            cout << endl;
        }
    }
};

class Distance
{
private:
    int feet;
    float inches;
public:
    void getdist ( ) // получение информации
    {
        cout << "\n Введите футы: "; cin >> feet;
        cout << " Введите дюймы: "; cin >> inches;
    }
    void showdist ( ) const // показ информации
    { cout << feet << "\'-" << inches << '\"'; }
    void add_dist(Distance dd1, Distance dd2)
    {
        inches = dd1.inches + dd2.inches; // сложение дюймов
        feet = 0;                         // с возможным заемом
        if(inches >= 12.0)                // если число дюймов больше 12.0,
        {                                 // то уменьшаем число дюймов
            inches -= 12.0;               // на 12.0 и увеличиваем
            feet++;                       // число футов на 1
        }
    feet += dd1.feet + dd2.feet;          // сложение футов
    }
// выделение целой части из значения Distance
    void div_dist ( Distance d2, int divisor )
    {
        float fltfeet = d2.feet + d2.inches / 12.0;
        fltfeet /= divisor;
        feet = int ( fltfeet );
        inches = ( fltfeet - feet ) * 12.0;
    }
};
void zadacha3();

enum {MAX = 5};

struct Array
{
    int ar_struct;
    int ar_id;
};
Array maxint(int arr[MAX]);
void zadacha4();

//*************************************************************************************************
int main()
{
    cout << "Введите число:\n";
    char a[5];
    cin >> a;
    long double b;

    //zadacha4();
    return 0;
}
//*************************************************************************************************

 /* Задача №4
    Начните с программы, которая позволяет пользователю вводить целые чис-
    ла, а затем сохранять их в массиве типа int. Напишите функцию maxint(),
    которая, обрабатывая элементы массива один за другим, находит наиболь-
    ший. Функция должна принимать в качестве аргумента адрес массива и
    количество элементов в нем, а возвращать индекс наибольшего элемента.
    Программа должна вызвать эту функцию, а затем вывести наибольший
    элемент и его индекс. (Смотрите программу SALES этой главы.)
 */
void zadacha4()
{

    int array[MAX];

    cout << "Введите 5 элементов массива:";
    for (int i = 0; i < MAX; ++i)
        cin >> array[i];
    Array b;

    b = maxint(array);

    cout << "Наибольший элемент = " << b.ar_struct
         << "\n Его индекс = " << b.ar_id;


    
}

Array maxint(int arr[MAX])
{
    Array a;
    a.ar_struct = arr[0];
    a.ar_id = 0;
    for (int i = 1; i < MAX; ++i)
    {
        if (a.ar_struct < arr[i])
        {
            a.ar_struct = arr[i];
            a.ar_id = i;
        }

    }
    return a;
}

/* Задача №3 
Операции ввода, такие, как cin, должны уметь преобразовывать последовательность символов в число.
Напишите программу, которая позволяет
пользователю ввести шесть цифр, а затем выводит результат типа long на
экране. Каждая цифра должна считываться отдельно при помощи функции getche().
Вычисление значения переменной производится путем умножения текущего ее
значения на 10 и сложения с последней введенной
цифрой (для того, чтобы из кода символа получить цифру, вычтите из него 48 или '0').
Примером результата работы программы может служить
следующий:

Введите число: 123456
Вы ввели число 123456 
*/
void zadacha3()
{
    Distance dist [ 100 ], total; // массив переменных
    int n = 0;
    // счетчик данных
    char ans;
    // ответ пользователя (y/n)
    cout << endl;
    do
    {
        cout << "Введите длину номер " << n + 1;
        dist [ n++ ].getdist ( );
        // получаем и сохраняем длину
        cout << "Продолжить ввод (y/n)?: ";    // !!здесь n-1 - количество элементов для
                                               // среднего арифметического
        cin >> ans;
    }
    while ( ans != 'n' );
    // продолжать, пока не будет введено 'n'

    for (int i = 0; i < n; ++i)
    total.add_dist(total,dist[i]);

    total.div_dist(total,n);


    cout << "Среднее арифметическое равно: ";
    total.showdist();

    // показываем все введенное
    for ( int j = 0; j < n; j++ )
        {
            cout << "\nДлина номер " << j + 1 << " : ";
            dist [ j ].showdist ( );
        }
    cout << endl;
}

/*  Задача №2
    Создайте класс employee, который содержит имя (объект класса string)
    и номер (типа long) служащего. Включите в него метод getdata(),
    предназначенный для получения данных от пользователя и помещения их в объект,
    и метод putdata(), для вывода данных. Предполагаем, что имя не может иметь
    внутренних пробелов.
    Напишите функцию main(), использующую этот класс. Вам нужно будет
    создать массив типа employee, а затем предложить пользователю ввести
    данные до 100 служащих. Наконец, вам нужно будет вывести данные всех
    служащих.
    */
void zadacha2()
{
    Employee2 workers;
    workers.getdata();
    workers.putdata();
    /*Employee workers[3];
    for(int i = 0;i <= 2; ++i)
        workers[i].getdata();
    for (int i = 0;i <= 2; ++i)
        workers[i].putdata();
    */
}

/*  Задача №1
    Напишите функцию reversit(), которая переворачивает строку (массив типа
    char). Используйте цикл for, который меняет местами первый и последний
    символы, затем следующие и т. д. до предпоследнего. Строка должна
    передаваться в функцию reversit() как аргумент.
    Напишите программу для выполнения функции reversit().
    Программа должна принимать строку от пользователя,
    вызывать функцию reversit(), а затем выводить полученный результат.
    Используйте метод ввода, который
    позволяет использовать внутренние пробелы. Протестируйте программу
    на примере фразы «Аргентина манит негра»
    */
void zadacha1()
{
    cout << "Введите строку:\n";
    enum { SZ = 80 }; // максимальный размер строки
    char str [ SZ ];
    cin.get(str,SZ);

    cout << "Перевернутая строка:\n" << reverseit(str) << endl;    
}

char* reverseit(char a[])
{
    int N = strlen(a);
    for(int i=0; i <= (N-1); ++i)
    {
        if((N-1) != i)
        {
        char temp = a[i];
        a[i] = a[N-1];
        a[N-1] = temp;
        N = N-1;
        }
    }
    return a;
}

