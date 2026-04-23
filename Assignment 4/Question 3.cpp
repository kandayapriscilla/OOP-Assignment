#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 5;

void printDict(char **list, int n, const char *title) {
    cout << title << endl;
    for (int i = 0; i < n; i++) {
        cout << "[" << i << "] " << list[i] << endl;
    }
}

int main() {

    char **list = new char*[SIZE];

    const char *words[SIZE] = {
        "alpha",
        "bravo",
        "charlie",
        "delta",
        "echo"
    };

    for (int i = 0; i < SIZE; i++) {
        list[i] = new char[strlen(words[i]) + 1];
        strcpy(list[i], words[i]);
    }

    printDict(list, SIZE, "[Initial Dictionary]");

    int foundIndex = -1;

    for (int i = 0; i < SIZE; i++) {
        if (strcmp(list[i], "delta") == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        cout << "\n[Search Result]" << endl;
        cout << "delta found at index " << foundIndex << endl;
    }

    delete[] list[1];  

    list[1] = new char[strlen("blueberry") + 1];
    strcpy(list[1], "blueberry");

    printDict(list, SIZE, "\n[After Update]");

    int delIndex = -1;

    for (int i = 0; i < SIZE; i++) {
        if (strcmp(list[i], "charlie") == 0) {
            delIndex = i;
            break;
        }
    }

    if (delIndex != -1) {

        delete[] list[delIndex];

        for (int i = delIndex; i < SIZE - 1; i++) {
            list[i] = list[i + 1];
        }

        list[SIZE - 1] = nullptr; 

        printDict(list, SIZE - 1, "\n[After Delete]");
    }

    for (int i = 0; i < SIZE - 1; i++) {
        delete[] list[i];
    }

    delete[] list;

    return 0;
}