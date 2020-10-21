#include <iostream>
#include <algorithm>
using namespace std;

int binSearch(int v[100], int lowerBound, int upperBound, int element, bool first = true) {
    int mid, result = -1;
    while (lowerBound <= upperBound) {
        mid = (upperBound + lowerBound) >> 1;
        if (v[mid] == element) {
            if (first == true) {
                upperBound = mid - 1;
            }
            else {
                lowerBound = mid + 1;
            }
            result = mid;
        }
        else {
            if (v[mid] > element) {
                upperBound = mid - 1;
            }
            else {
                lowerBound = mid + 1;
            }
        }
    }
    return result;
}

void test(void);
void solve(void);
void printArr(int* v, int arrSize) {
    for (int index = 0; index < arrSize; index++) {
        std::cout << v[index] << " ";
    }
    std::cout << "\n";
}
int main()
{
    //test();
    /*
        Given an array of n elements, find the majority element.
        A majority element occurs at least n/2 + 1 times.
        If if doesn't exist print -1
    */
    solve();
    return 0;
}
void test(void) {
    int v[] = { 7, 1, 8, 6, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1 };
    int n = sizeof(v) / sizeof(int);
    int l = (n >> 1) + 1;
    sort(v, v + n);
    //printArr(v, n);
    std::cout << "v[" << l << "]= " << v[l] << "\n";
    int first = binSearch(v, 0, n - 1, v[l]);
    int last = binSearch(v, 0, n - 1, v[l], false);
    std::cout << v[l] << " occurs " << last - first + 1 << " times.\n";
}
void solve(void) {
    int n;
    std::cout << "n= ";
    std::cin >> n;
    int* v = new int[n];
    for (int index = 0; index < n; index++) {
        std::cin >> v[index];
    }

    int l = (n >> 1) + 1, first, last; // n/2 + 1

    std::sort(v, v + n);
    first = binSearch(v, 0, n - 1, v[l]);
    last = binSearch(v, 0, n - 1, v[l], false);
    if (last - first + 1 < l) {
        std::cout << "There isn't a majority element in the array!\n";
    }
    else {
        std::cout << v[l] << " occurs " << last - first + 1 << " times.\n";
    }
}
