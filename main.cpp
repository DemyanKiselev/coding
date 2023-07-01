#include    <iostream>
#include    <cstdint>
#include    <limits>
#include    <numbers>
#include    <cassert>

#include    <map>
#include    <set>
#include    <queue>
#include    <deque>
#include    <vector>
#include    <string>
#include    <cstring>

#include    <cmath>
#include    <bitset>
#include    <algorithm>

//other includes here

#define     int     long long
#define     pi      numbers::pi //type : double
#define     inf     numeric_limits<int>::max()

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //start coding here >.<
    int p, q, ai;
    cin >> p >> q;

    vector<int> answer;
    for (int i = 2; i <= q && p > 0; i++) {
        ai = p * i / q;
        assert(0 <= ai && ai < i);
        p = p * i % q;
        answer.push_back(ai);
    }

    cout << (int)answer.size() + 1 << '\n';

    for (auto ai : answer) {
        cout << ai << '\n';
    }

    return 0;
}