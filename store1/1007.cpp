#include <iostream>

using namespace std;

int main(void) {
    char va[1000];
    char vb[1000];
    int i1 = 0;
    int i2 = 0;
    char item = 'a';
    int secondStr = -1;
    while (cin >> item) {
        if (item == ';') {
            secondStr = 1;
            continue;
        }
        if (secondStr < 0) {
            if (item == ',') {
                continue;
            } else {
                va[i1] = item;
            }
            i1++;
        } else {
            if (item == ',') {
                continue;
            } else {
                vb[i2] = item;
            }
            i2++;
        }
    }
    int len = (i1 < i2) ? i1 : i2;
    int who = i1 == i2? 0:
              i1 < i2? 1:2;
    int i, result;
    for (i = 0; i < len; ++i) {
        if (va[i] != vb[i])
            break;
    }
    if (i == len)
        result = who;
    else
        result = (va[i] < vb[i])? 1:2;
    cout << result;
    return 0;
}