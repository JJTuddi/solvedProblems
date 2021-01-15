#include <iostream>
#include <vector>
using namespace std;
int nBits(int n) {
    int count = 0;
    do {
        count++;
        n >>= 1;
    } while(n);
    return count;
}
vector<int> toBitVector(int n, int size = 32) {
    vector<int> result(size);
    for(int i = 0; n > 0; i++, n >>= 1) {
        result[i] = n & 1;
    }
    return result;
}
void printBinNumber(vector<int> bits) {
    for (int i = 0; i < bits.size(); i++) {
        cout << bits[i];
    }
    cout << "\n";
}
vector<int> binSum(vector<int> a, vector<int> b) {
    vector<int> result(a.size() + 1);
    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
        result[i] = a[i] ^ b[i] ^ carry;
        carry = ((a[i] ^ b[i]) & carry) | (a[i] & b[i]);
    }
    result[result.size() - 1] = carry;
    return result;
}

int toNumber(vector<int> v) {
    int result = 0;
    for (int i = 0; i < v.size(); i++) {
        result += v[i] << i;
    }
    return result;
}
int main()
{
    int a, b;
    cin >> a >> b;
    int maxBits = nBits(max(a, b));
    printBinNumber(toBitVector(a, maxBits));
    printBinNumber(toBitVector(b, maxBits));
    cout << toNumber(binSum(toBitVector(a, maxBits), toBitVector(b, maxBits)));
    return 0;
}
