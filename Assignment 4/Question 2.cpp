#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

void print_seat(int **seat, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << setw(2) << setfill('0') << seat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    const int SIZE = 10;

    int **seat = new int*[SIZE];
    int **backup = new int*[SIZE];

    for (int i = 0; i < SIZE; i++) {
        seat[i] = new int[SIZE];
        backup[i] = new int[SIZE];
    }

    for (int i = 0; i < SIZE; i++) {
        memset(seat[i], 0, SIZE * sizeof(int));
    }

    seat[0][0] = 11;
    seat[0][3] = 24;
    seat[1][1] = 35;
    seat[2][5] = 47;
    seat[3][3] = 58;
    seat[4][9] = 69;
    seat[5][0] = 70;
    seat[5][5] = 81;
    seat[5][9] = 92;
    seat[6][4] = 13;
    seat[7][7] = 26;
    seat[8][2] = 39;
    seat[9][9] = 44;

    for (int i = 0; i < SIZE; i++) {
        memcpy(backup[i], seat[i], SIZE * sizeof(int));
    }

    for (int j = 0; j < SIZE; j++) {
        seat[5][j] = 0;
    }

    cout << "[Original Seat Map After Clearing Row 5]" << endl;
    print_seat(seat, SIZE, SIZE);
    cout << endl;

    cout << "[Backup Seat Map After Original Was Modified]" << endl;
    print_seat(backup, SIZE, SIZE);

    int maxCount = -1;
    int bestRow = 0;

    for (int i = 0; i < SIZE; i++) {
        int count = 0;
        for (int j = 0; j < SIZE; j++) {
            if (backup[i][j] != 0) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            bestRow = i;
        }
    }

    cout << "\n[Row With Most Assigned Seats]" << endl;
    cout << "Row: " << bestRow << endl;
    cout << "Count: " << maxCount << endl;

    for (int i = 0; i < SIZE; i++) {
        delete[] seat[i];
        delete[] backup[i];
    }
    delete[] seat;
    delete[] backup;

    return 0;
}