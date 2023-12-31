/*
    Вам дана десятичная запись целого неотрицательного числа без ведущих нулей.

    С ней можно делать следующие операции:
        '1'      - умножить число на 2 (например, 12 преобразуется в 24);
        '2'      - разделить число на 2, если оно четное (например, 12
   преобразуется в 6); '3', '4' - поделить запись числа на две половины равной
   длины и оставить только одну из половин ('3' - первую половину, '4' - вторую
   половину), если в записи числа четное число знаков (например, 12 можно
   преобразовать в 1 или 2); '5', '6' - поделить запись числа на две половины
   равной длины и заменить одну из половин другой ('5' - используется первая
   половина, '6' - используется вторая половину), если в записи числа четное
   число знаков (например, 12 можно преобразовать в 11 или 22);

    Если в результате операции получаются ведущие нули, их надо отбросить.

    Требуется за по возможности минимальное количество операций из заданного
   числа получить 1.
*/

int digits(int n) {
    if (n == 0) return 1;
    return (int)log10(n) + 1;
}

pair<int, int> split(int n) {
    return {n / (int)(pow(10, digits(n) / 2)),
            n % (int)(pow(10, digits(n) / 2))};
}

int n;
cin >> n;

int operations = 0;
string answer = "";

while (n != 1) {
    int d = digits(n);
    int d2 = digits(n / 2), d4 = digits(n / 4);

    if (!(d & 1)) {
        int l = split(n).first;
        int r = split(n).second;

        if (l < r || r == 0) {
            n = l;
            answer += '3';
        } else {
            n = r;
            answer += '4';
        }
    } else {
        if (!(d2 & 1) && !(n & 1) || n == 2) {
            n /= 2;
            answer += '2';
        } else if (!(d4 & 1) && (!(n & 1) && !((n / 2) & 1)) || n == 4) {
            n /= 4;
            answer += "22";
        } else {
            n *= 2;
            answer += '1';
        }
    }

    operations++;
}

cout << operations << '\n';
cout << answer << '\n';