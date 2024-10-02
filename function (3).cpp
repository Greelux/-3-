#include <iostream>
#include <cstdlib>  
#include <ctime>   
#include <Windows.h>

using namespace std;

const int MAX_SIZE = 20; 

void analyze(int arr[], int n, int& even, int& odd, int& negative, int& prime, int& negSum) {
    even = odd = negative = prime = negSum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) even++;
        else odd++;

        if (arr[i] < 0) {
            negative++;
            negSum += arr[i];
        }

        if (arr[i] > 1) {
            bool isPrime = true;
            for (int j = 2; j * j <= arr[i]; j++) {
                if (arr[i] % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) prime++;
        }
    }
}

int minPositive(int arr[], int n) {
    int minPos = 51;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0 && arr[i] < minPos) {
            minPos = arr[i];
        }
    }
    return (minPos == 51) ? -1 : minPos;
}

int sumEvenIndex(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i += 2) {
        sum += arr[i];
    }
    return sum;
}

int countUnique(int arr[], int n) {
    int unique = 0;
    for (int i = 0; i < n; i++) {
        bool isUnique = true;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j] && i != j) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) unique++;
    }
    return unique;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "");
    srand(time(0));

    int n;
    do {
        cout << "Введіть кількість елементів масиву (від 5 до 20): ";
        cin >> n;
    } while (n < 5 || n > 20);

    int arr[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101 - 50;
    }

    cout << "Масив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int even, odd, negative, prime, negSum;
    analyze(arr, n, even, odd, negative, prime, negSum);

    cout << "Парних: " << even << ", непарних: " << odd << endl;
    cout << "Від'ємних: " << negative << endl;
    cout << "Простих чисел: " << prime << endl;
    cout << "Сума від'ємних: " << negSum << endl;

    int minPos = minPositive(arr, n);
    if (minPos != -1) {
        cout << "Мінімальний додатний: " << minPos << endl;
    }
    else {
        cout << "Немає додатних чисел." << endl;
    }

    int evenIndexSum = sumEvenIndex(arr, n);
    cout << "Сума на парних індексах: " << evenIndexSum << endl;

    int unique = countUnique(arr, n);
    cout << "Унікальних елементів: " << unique << endl;

    return 0;
}

