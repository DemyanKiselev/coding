/*
    Напишите программу, которая ищет среди целых чисел, принадлежащих
    числовому отрезку [95632; 95650], числа, имеющие ровно шесть различных
    нечётных натуральных делителей (при этом количество четных делителей может
   быть любым).

    Для каждого найденного числа запишите эти шесть делителей в шесть соседних
    столбцов на экране с новой строки. Делители в строке должны следовать в
    порядке возрастания.

    Например, в диапазоне [2; 48] ровно шесть нечётных различных натуральных
    делителей имеет число 45, поэтому для этого диапазона вывод на экране должна
    содержать следующие значения: 1 3 5 9 15 45;
    в диапазоне [480; 489] ровно шесть нечётных различных натуральных делителей
    имеет число 486, поэтому для этого диапазона вывод на экране должна
   содержать следующие значения: 1 3 9 27 81 243.
*/

vector<int> d;

for (int i{95632}; i <= 95650; i++) {
    d = {};

    for (int j{1}; j < sqrt(i); j++) {
        if (i % j == 0) {
            if (j % 2 == 1) d.push_back(j);

            if (i != j * j && (i / j) % 2 != 0) d.push_back(i / j);
        }
    }

    if ((int)d.size() == 6) {
        sort(d.begin(), d.end());

        cout << i << ": ";
        for (auto el : d) cout << el << " ";
        cout << '\n';
    }
}