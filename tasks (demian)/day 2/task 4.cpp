/*
    Выходя на пробежку Рита берёт с собой телефон для прослушивания
    музыки и беспроводные наушники.  Перед каждой пробежкой Рита заряжает
    наушники, и этой зарядки хватает на A минут прослушивания музыки.

    Рита решила, что каждый день она будет тренироваться на минуту дольше,
    чем в предыдущий день. То есть если в первый день Рита бегала и слушала
    музыку в течение B минут, во второй день она будет бегать B + 1 минуту,
    в третий день — B + 2 минуты и т.д.

    Если заряда наушников хватает на большее время, чем продолжительность
   пробежки, то неиспользованный заряд накапливается и может быть использован в
   последующие дни. Емкость аккумулятора наушников можно считать неограниченной.

    Определите, в какой день Рите впервые не хватит заряда для прослушивания
   музыки во время всей пробежки.

    Первая строка входных данных содержит целое число A (1<=A<=10^9) — величина
   ежедневного заряда аккумулятора (в минутах прослушивания музыки). Вторая
   строка входных данных содержит целое число B (1<=B<=10^9) — продолжительность
   пробежки в первый день.

    Программа должна вывести одно целое число — номер дня, на который Рите
   впервые не хватит заряда наушников на всю пробежку.

    Ввод:
        42 40
    Вывод:
        6
*/

int a, b;
cin >> a >> b;

int l = 1, r = a;
while (r >= b) {
    l++;
    r += (a - b);
    b++;
}

cout << l << '\n';
