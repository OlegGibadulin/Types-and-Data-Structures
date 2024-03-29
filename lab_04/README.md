# Лабораторная работа #4

## Условие задачи

Реализовать операции работы со стеком, который представлен в виде массива (статического или динамического) и в виде односвязного линейного списка; оценить преимущества и недостатки каждой реализации: получить представление о механизмах выделения и освобождения памяти при работе со стеком. Элементами стека являются адреса памяти. При реализации массивами - их вводить, при реализации списком – брать адрес выделенной памяти под элемент.

## Описание ТЗ

Создать программу работы со стеком, выполняющую операции добавления, удаления элементов и вывод текущего состояния стека. Реализовать стек: а) массивом; б) списком. Все стандартные операции со стеком должны быть оформлены подпрограммами. При реализации стека списком в вывод текущего состояния стека добавить просмотр адресов элементов стека и создать свой список или массив свободных областей (адресов освобождаемых элементов) с выводом его на экран.

### Исходные данные

При реализации массивами адреса считываются со стандартного потока ввода, при реализации списком – берётся адрес выделенной памяти под элемент.

### Результаты

Результатом является текущее состояние стека и массив свободных областей (адресов освобождаемых элементов).

### Способ обращения к программе

Обращение к программе происходит через исполняемый файл. Исходные данные вводятся через окно терминала, вывод результатов производится в окно терминала.

### Аварийные ситуации и ошибки пользователя

* Некорректный ввод.
* Пустой ввод.
* Переполнение стека при реализации массивом.
* Вывод пустого стека.
* Удаление несуществующего элемента.

Во всех перечисленных случаях программа выдаёт сообщение об ошибке.

## Описание СД

Односвязный линейный список.

```
typedef struct node node_t;struct node{    void *ptr;						// Указатель на адрес    node_t *next;					// Указатель на следующий элемент};
```

Массив содержащий указатели на адреса.

```
void **ptr = NULL;
```

## Тесты

**Время add**

|Количество действий|Массив|Список|
|:-:|:-:|:-:|
|1|132|408|
|10|440|2684|
|100|4551|131316|

**Время pop**

|Количество действий|Массив|Список|
|:-:|:-:|:-:|
|1|100|8848|
|10|364|4768|
|100|4173|232257|

**Время show**

|Количество действий|Массив|Список|
|:-:|:-:|:-:|
|1|27965|18624|
|10|46032|36378|
|100|725425|508972|

**Объём памяти**

|Количество действий|Массив|Список|
|:-:|:-:|:-:|
|1|1|16|
|10|10|160|
|100|100|1600|

## Выводы

В ходе данной лабораторной работы были реализованы операции работы со стеком, который представлен в виде статического массива и в виде односвязного линейного списка, была произведена оценка преимуществ и недостатк каждой реализации.

Реализация стеком массивом даёт преимущество по времени, но ограничивает количество элементов заданным значением, тогда как в реализации списком стек ограничен допустимой в программе оперативной памятью.

## Вопросы

**1. Что такое стек?**

Стек – это последовательный список с переменной длиной, в котором включение и исключение элементов происходит только с одной стороны – с его вершины. Стек функционирует по принципу: последним пришел – первым ушел, Last In – First Out (LIFO).

**2. Каким образом и сколько памяти выделяется под хранение стека при различной его реализации?**

Если стек реализован в виде статического или динамического массива (вектора), то для его хранения обычно отводится непрерывная область памяти ограниченного размера, имеющая нижнюю и верхнюю границу.

При физической реализации стека в виде односвязного линейного списка дескриптор будет отличаться отсутствием верхней границы стека. В этом случае объем стека ограничивается только объемом доступной оперативной памяти.

**3. Каким образом освобождается память при удалении элемента стека при различной реализации стека?**

При исключении элемента из стека, реализованного массивом, сначала считываются данные, а затем происходит перемещение указателя PS к предыдущему элементу. Если указатель стека выходит за нижнюю границу массива, то стек пуст.

При исключении элемента по указателю стека, реализованного списком, сначала считывается информация об исключаемом элементе, а затем указатель смещается к предыдущему элементу. После чего освобождается память, выделенная под элемент. Если указатель имеет значение нулевого адреса, то стек пуст.

**4. Что происходит с элементами стека при его просмотре?**

При работе со стеком доступен только его верхний элемент, который адресуется специальным указателем стека PS (Pointer Stack). При просмотре элемент удаляется, а указатель смещается.

**5. Каким образом эффективнее реализовывать стек? От чего это зависит?**

Реализовывать стек эффективнее массивом, что даёт преимущество по врмени и если заранее известно количество элементов стека, то и по памяти. Это обусловлено тем, что в отличие от массива, где память выделяется единожды, при реализации списком требуется каждый раз выделять и освобождать память.