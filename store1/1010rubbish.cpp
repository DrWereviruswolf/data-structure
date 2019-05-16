#include <iostream>

using namespace std;

int main(void) {
    char va[100] = "0";
    char vb[100] = "0";
    char vc[100] = "0";
    int i1 = 0;
    int i2 = 0;
    int i3 = 0;
    char item = 'a';
    int secondStr = -1;
    while (cin >> item) {
        if (item == ';') {
            secondStr++;
            continue;
        }
        if (secondStr < 0) {
            if (item == ',') {
                continue;
            } else {
                va[i1] = item;
            }
            i1++;
        } else if (secondStr == 0) {
            if (item == ',') {
                continue;
            } else {
                vb[i2] = item;
            }
            i2++;
        } else {
            if (item == ',') {
                continue;
            } else {
                vc[i3] = item;
            }
            i3++;
        }
    }
    int i = 0;
    while (vb[i] != 0) {
        for (int j = 0; j < 100 && vc[j] != 0; ++j) {
            if (vb[i] == vc[j]) {
                for (int l = 0; l < 100; ++l) {
                    if (va[l] == vb[i])
                        va[l] = 0;
                }
            }
        }
        i++;
    }
    int counter = 0;
    for (int m = 0; m < 100; ++m) {
        if (va[m] != 0)
            counter++;
    }
    for (int k = 0; k < 100; ++k) {
        if (va[k] != 0) {
            if (counter == 1) {
                cout << va[k];
            } else {
                cout << va[k] << ',';
                counter--;
            }
        }
    }
    return 0;
}