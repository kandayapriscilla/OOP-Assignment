#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char name[100];
    int studentID;
    int age;

public:
    void init(const char* n, int id, int a) {
        strcpy(name, n);
        studentID = id;
        age = a;
    }

    void printStudentInfo() {
        cout << "Name: " << name
             << ", ID: " << studentID
             << ", Age: " << age << endl;
    }
};

void personSwap(Person &p1, Person &p2) {
    Person temp = p1;
    p1 = p2;
    p2 = temp;
}

int main() {
    Person p1, p2;

    p1.init("Alice", 2026312345, 20);
    p2.init("Bob", 2019354321, 25);

    cout << "Before Swap:" << endl << endl;
    p1.printStudentInfo();
    cout << endl;
    p2.printStudentInfo();

    personSwap(p1, p2);

    cout << "\nAfter Swap:" << endl << endl;
    p1.printStudentInfo();
    cout << endl;
    p2.printStudentInfo();

    return 0;
}
