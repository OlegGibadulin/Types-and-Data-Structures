# Лабораторная работа #5

## Условие задачи

Реализовать операции работы с очередью, которая представлена в виде одномерного массива и односвязного линейного списка, провести сравнительный анализ реализации алгоритмов включения и исключения элементов из очереди при использовании указанных структур данных, оценить эффективности программы по времени и по используемому объему памяти.

## Описание ТЗ

Смоделировать процесс обслуживания первых 1000 заявок 1-го типа, выдавая после обслуживания каждых 100 заявок информацию о текущей и средней длине каждой очереди, а в конце процесса - общее время моделирования и количество вошедших в систему и вышедших из нее заявок обоих типов. По требованию пользователя выдать на экран адреса элементов
очереди при удалении и добавлении элементов. Проследить, возникает ли при этом фрагментация памяти.

Заявки 1-го и 2-го типов поступают в "хвосты" своих очередей по случайному закону с интервалами времени Т1 и Т2, равномерно распределенными от 1 до 5 и от 0 до 3 единиц времени (е.в.) соответственно. В ОА они поступают из "головы" очереди по одной и обслуживаются также равновероятно за времена Т3 и Т4, распределенные от 0 до 4 е.в. и от 0 до 1 е.в. соответственно, после чего покидают систему. (Все времена – вещественного типа) В начале процесса в системе заявок нет.
Заявка любого типа может войти в ОА, если:

а) она вошла в пустую систему;

б) перед ней обслуживалась заявка ее же типа;

в) перед ней из ОА вышла заявка другого типа, оставив за собой
пустую очередь (система с чередующимся приоритетом).

### Исходные данные

Временные значения генерируются случайным образом в пределах границ, которые пользователь может изменить.

### Результаты

Результатом является общее время моделирования системы, время простоя, количество вошедших и вышедших элементов, общее количество прошедших через ОА элементов, общее время работы ОА, процент расхождения практических данных с теоретическими.

### Способ обращения к программе

Обращение к программе происходит через исполняемый файл. Исходные данные генерируются случайным образом, вывод результатов производится в окно терминала.

### Аварийные ситуации и ошибки пользователя

* Некорректный ввод.
* Пустой ввод.
* Переполнение очереди при реализации массивом.

Во всех перечисленных случаях программа выдаёт сообщение об ошибке.

## Описание СД

Реализация очереди односвязным линейным списком.

```
typedef float type;
typedef struct list list;typedef struct element element;

struct element{    type data;			// Данные    element *next;		// Указатель на следующий элемент};struct list{    element *start;    element *ptr;};
```

Реализация очереди массивом.

```
typedef float type;
typedef struct array array;

struct array{    type buf[SZ_BUF];	// Данные    int head;				// Голова    int tail;				// Хвост    int len;				// Количество хранящихся элементов};
```

## Тесты

```
T1 1..5 T2 0..3 T3 0..4 T4 0..1

Array

100 ELEMENTSCount of including applications T1: 100Count of including applications T2: 199Count of released applications T1: 100Count of released applications T2: 187Lenth T1: 0Lenth T2: 12200 ELEMENTSCount of including applications T1: 201Count of including applications T2: 395Count of released applications T1: 200Count of released applications T2: 393Lenth T1: 1Lenth T2: 2300 ELEMENTSCount of including applications T1: 301Count of including applications T2: 572Count of released applications T1: 300Count of released applications T2: 566Lenth T1: 1Lenth T2: 6400 ELEMENTSCount of including applications T1: 401Count of including applications T2: 775Count of released applications T1: 400Count of released applications T2: 772Lenth T1: 1Lenth T2: 3500 ELEMENTSCount of including applications T1: 502Count of including applications T2: 968Count of released applications T1: 500Count of released applications T2: 965Lenth T1: 2Lenth T2: 3600 ELEMENTSCount of including applications T1: 600Count of including applications T2: 1148Count of released applications T1: 600Count of released applications T2: 1145Lenth T1: 0Lenth T2: 3700 ELEMENTSCount of including applications T1: 701Count of including applications T2: 1342Count of released applications T1: 700Count of released applications T2: 1335Lenth T1: 1Lenth T2: 7800 ELEMENTSCount of including applications T1: 802Count of including applications T2: 1538Count of released applications T1: 800Count of released applications T2: 1538Lenth T1: 2Lenth T2: 0900 ELEMENTSCount of including applications T1: 900Count of including applications T2: 1715Count of released applications T1: 900Count of released applications T2: 1713Lenth T1: 0Lenth T2: 2Simulation time: 3236.94				// Общее время симуляцииDowntime: 267.39							// Время простояCount of including applications T1: 1001Count of including applications T2: 1895Count of released applications T1: 1000Count of released applications T2: 1893Amount of work performed of OA: 2893Time of working of OA: 2893 units of timeSystem check by inclusion: 0.65%			// Проверка по входуSystem check by conclusion: 2.36%			// Проверка по выходу

List

100 ELEMENTSCount of including applications T1: 102Count of including applications T2: 174Count of released applications T1: 100Count of released applications T2: 173Lenth T1: 2Lenth T2: 1200 ELEMENTSCount of including applications T1: 200Count of including applications T2: 380Count of released applications T1: 200Count of released applications T2: 380Lenth T1: 0Lenth T2: 0300 ELEMENTSCount of including applications T1: 302Count of including applications T2: 570Count of released applications T1: 300Count of released applications T2: 566Lenth T1: 2Lenth T2: 4400 ELEMENTSCount of including applications T1: 400Count of including applications T2: 745Count of released applications T1: 400Count of released applications T2: 742Lenth T1: 0Lenth T2: 3500 ELEMENTSCount of including applications T1: 500Count of including applications T2: 943Count of released applications T1: 500Count of released applications T2: 943Lenth T1: 0Lenth T2: 0600 ELEMENTSCount of including applications T1: 601Count of including applications T2: 1146Count of released applications T1: 600Count of released applications T2: 1142Lenth T1: 1Lenth T2: 4700 ELEMENTSCount of including applications T1: 700Count of including applications T2: 1340Count of released applications T1: 700Count of released applications T2: 1338Lenth T1: 0Lenth T2: 2800 ELEMENTSCount of including applications T1: 801Count of including applications T2: 1553Count of released applications T1: 800Count of released applications T2: 1543Lenth T1: 1Lenth T2: 10900 ELEMENTSCount of including applications T1: 902Count of including applications T2: 1740Count of released applications T1: 900Count of released applications T2: 1739Lenth T1: 2Lenth T2: 1Simulation time: 3284.45				// Общее время симуляцииDowntime: 319.33							// Время простояCount of including applications T1: 1001Count of including applications T2: 1955Count of released applications T1: 1000Count of released applications T2: 1951Amount of work performed of OA: 2951Time of working of OA: 2951 units of timeSystem check by inclusion: 1.25%			// Проверка по входуSystem check by conclusion: 0.43%			// Проверка по выходуArray 60294					// Время работы при реализации массивомList  90834					// Время работы при реализации списком
Array 4012 b				// Выделенная память при реализации массивом
List 20 b					// Выделенная память при реализации списком для 1 элемента, оставшегося в очереди
```

## Выводы

В ходе данной лабораторной работы были реализованы операции работы с очередью, который представлен в виде статического массива и в виде односвязного линейного списка, была произведена оценка преимуществ и недостатк каждой реализации.

Реализация очереди массивом даёт преимущество по времени, но ограничивает количество элементов заданным значением, тогда как в реализации списком стек работает медленнее, но ограничен только допустимой оперативной памятью. Таким образом, если заранее известно максимальное количество элементов, хранящихся в очереди, эффективнее использовать реализацию массивом, иначе используем список.

## Вопросы

**1. Что такое очередь?**

Очередь – это последовательный список переменной длины, включение элементов в который идет с одной стороны (с «хвоста»), а исключение – с другой стороны (с «головы»). Принцип работы очереди: первым пришел – первым вышел, т. е. First In – First Out (FIFO).

**2. Каким образом, и какой объем памяти выделяется под хранение очереди при различной ее реализации?**

При моделировании линейной очереди на основе массива выделяется последовательная область памяти из m мест по L байт, где L – размер поля данных для одного элемента размещаемого типа. В каждый текущий момент времени выделенная память может быть вся свободна, занята частично или занята полностью.

При моделировании линейной очереди на основе линейного списка каждый элемент содержит информационное поле и поле с указателем на следующий элемент. В этом случае в статической памяти можно либо хранить адрес начала и конца очереди, либо – адрес начала очереди и количество элементов.

**3. Каким образом освобождается память при удалении элемента из очереди при ее различной реализации?**

При реализации очереди на основе массива происходит считывание данных головы, остальные элементы смещаются (смещение можно избежать, если использовать кольцевой массив), длина массива уменьшается на один.

При реализации очереди на основе линейного списка происходит считывание данных головы, перенос головы на следующий элемент, освобождение данных.

**4. Что происходит с элементами очереди при ее просмотре?**

При просмотре очереди головной элемент удаляется. Остальные элменты смещаются в массиве, или голова перемещается на следующий элемент в списке.

**5. Каким образом эффективнее реализовывать очередь. От чего это зависит?**

Реализация массивом даёт преимущество по времени, по сравнению с реализацией списком. Но массив ограничен по объёму используемой памяти заданным значением, тогда как список - оперативной памятью. Если заранее известно максимальное количество элементов, хранящихся в очереди, тогда эффективнее использовать реализацию массивом, иначе используем список.

**6. В каком случае лучше реализовать очередь посредством указателей, а в
каком – массивом?**

Если заранее известно максимальное количество элементов, хранящихся в очереди, тогда эффективнее использовать реализацию массивом, иначе используем список.

**7. Каковы достоинства и недостатки различных реализаций очереди в
зависимости от выполняемых над ней операций?**

При реализации очереди на основе массива отсутствует фрагментация памяти, может возникнуть переполнение очереди и при нециклическом массиве приходится тратить время на сдвиг элементов. При реализации очереди на основе линейного списка может присутствовать фрагментация памяти, а также список медленне массива.

**8. Что такое фрагментация памяти?**

Фрагментация памяти - это выделение непоследовательных адресов памяти при работе с памятью.

**9. На что необходимо обратить внимание при тестировании программы?**

При тестировании программы необходимо проверить правильность работы программы при различном заполнении очередей, т.е., когда время моделирования определяется временем обработки заявок и когда определяется временем прихода заявок, отследить переполнение очереди, если очередь в программе ограничена, и отследить наличие фрагментации памяти.

**10. Каким образом физически выделяется и освобождается память при
динамических запросах?**

При динамических запросах для выделения памяти программа посылает запрос ОС для нахождение блока данного размера. Если таковой имеется, то ОС записывает его адрес и размер в таблицу адресов и посылает его программе. Для освобождения памяти программа снова посылает запрос ОС, которая удаляет его из таблицы.