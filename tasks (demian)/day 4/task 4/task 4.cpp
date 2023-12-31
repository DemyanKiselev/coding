/*
    Для перевозки партии грузов различной массы выделен грузовик,
    но его грузоподъёмность ограничена, поэтому перевезти сразу
    все грузы не удастся.
    Грузы массой от 210 до 220 кг грузят в первую очередь,
    гарантируется, что все такие грузы поместятся.

    На оставшееся после этого место стараются взять как можно
    больше грузов. Если это можно сделать несколькими способами,
    выбирают тот способ, при котором самый большой из выбранных
    грузов имеет наибольшую массу. Если и при этом условии возможно
    несколько вариантов, выбирается тот, при котором наибольшую массу
    имеет второй по величине груз, и т. д.

    Известны количество грузов, масса каждого из них и грузоподъёмность
   грузовика. Необходимо определить количество и общую массу грузов, которые
    будут вывезены при погрузке по вышеописанным правилам.
*/

ifstream f("task 4.txt");

int n, m, count;
f >> n >> m;

int car = 0, x = 0;
vector<int> weights;
for (int i = 0; i < n; i++) {
    int w;
    f >> w;

    if (w >= 210 && w <= 220) {
        x += w;
        count++;
    } else {
        weights.push_back(w);
    }
}

int s = m - x;
sort(weights.begin(), weights.end());

int index = 0;
for (int i = 0; i < n; i++) {
    if (car + weights[i] <= s) {
        car += weights[i];
        index = i;
        count++;
    }
}

int acar = car;
car = car - weights[index];
for (int i = index + 1; i < n; i++) {
    if (car + weights[i] <= s) {
        car += weights[i];
    }
}

car = max(acar, car);

cout << car + x << " " << count << '\n';