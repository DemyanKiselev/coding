/*
    Продавец предоставляет покупателю, делающему большую закупку,
    скидку по следующим правилам:
        — на каждый второй товар стоимостью больше 100 рублей
            предоставляется скидка 30%;
        — общая стоимость покупки со скидкой округляется вверх
            до целого числа рублей;
        — порядок товаров в списке определяет продавец и делает
            это так, чтобы общая сумма скидки была наименьшей.

    По известной стоимости каждого товара в покупке необходимо
    определить общую стоимость покупки с учётом скидки и стоимость
    самого дорогого товара, на который будет предоставлена скидка.

    Первая строка входного файла содержит число N  — общее количество
    купленных товаров. Каждая из следующих N строк содержит одно целое
    число  — стоимость товара в рублях.

    В ответе запишите два целых числа: сначала общую стоимость
    покупки с учётом скидки, затем стоимость самого дорогого товара,
    на который будет предоставлена скидка.
*/

ifstream f("task 3.txt");

int n, max = 0;
double sum = 0;

vector<int> v;
f >> n;

for (int i = 0; i < n; i++) {
    int cost;
    f >> cost;

    if (cost <= 100) {
        sum += cost;
    } else {
        v.push_back(cost);
    }

    sort(v.begin(), v.end());
    int length = (int)v.size();
    for (int i = 0; i < length; i++) {
        if (i < length / 2) {
            sum += v[i] * 0.7;
            max = v[i];
        } else {
            sum += v[i];
        }
    }

    cout << ceil(sum) << " " << max << '\n';
}