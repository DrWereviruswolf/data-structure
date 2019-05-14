#include <iostream>

using namespace std;


int main() {
    int va[1000];
    int i = 0, temp =0, temp2 = 0;
    while (cin >> va[i]) {
        i++;
    }
    int k;
    for (k = 0; k < i - 1; ++k) {
        if (va[i - 1] <= va[k]) {
            temp = va[k];
            va[k] = va[i-1];
            break;
        }
    }
    for (int l = k+1; l < i; ++l) {
        temp2 = va[l];
        va[l] = temp;
        temp = temp2;
    }
    for (int j = 0; j < i - 1; ++j) {
        cout << va[j] << " ";
    }
    cout << va[i - 1];
    return 0;
}