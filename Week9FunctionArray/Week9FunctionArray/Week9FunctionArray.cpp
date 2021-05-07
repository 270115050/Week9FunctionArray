// Week9Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <Windows.h>
#include <string>
#include <iomanip>
using namespace std;

void sortArray(int rndNum[], int arrSize) {
    int temp = 0;
    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            if (rndNum[i] < rndNum[j]) {
                temp = rndNum[i];
                rndNum[i] = rndNum[j];
                rndNum[j] = temp;
            }
        }
    }
    for (int i = 0; i < arrSize; i++) {
        cout << rndNum[i] << endl;
    }
}

void printMatrix1(int matrix[2][2], int maxRow, int maxCol) {

    cout << "MATRIX A TABLE" << endl;
    for (int i = 0; i < maxRow; i++) {
        for (int k = 0; k < maxCol; k++) {
            cout << matrix[i][k] << "\t";
        }
        cout << endl;
    }
    cout << endl << endl;
}

void printMatrix2(int matrix[2][2], int maxRow, int maxCol) {
    cout << "MATRIX B TABLE" << endl;
    for (int i = 0; i < maxRow; i++) {
        for (int k = 0; k < maxCol; k++) {
            cout << matrix[i][k] << "\t";
        }
        cout << endl;
    }
    cout << endl << endl;
}

void printMatrix3(int matrix[2][2], int maxRow, int maxCol) {
    cout << "MATRIX C TABLE" << endl;
    for (int i = 0; i < maxRow; i++) {
        for (int k = 0; k < maxCol; k++) {
            cout << matrix[i][k] << "\t";
        }
        cout << endl;
    }
    cout << endl << endl;
}

void AddMatrixAB(int matrixA[2][2], int matrixB[2][2], int maxRow, int maxCol, char opt) {
    int matrixC[2][2];

    for (int i = 0; i < maxRow; i++) {
        for (int k = 0; k < 2; k++) {
            if (opt == '+') {
                matrixC[i][k] = matrixA[i][k] + matrixB[i][k];
            }
            else
                matrixC[i][k] = matrixA[i][k] - matrixB[i][k];
        }
    }

    cout << endl << endl;
    printMatrix3(matrixC, maxRow, maxCol);
}

void printItemStock(string supermarket[5][10]) {
    cout << endl << endl
        << "Item _code\t Item_name\t Cost Price\t Selling Price\t Stock\t\t Re Ordered" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            cout << supermarket[i][j] << "\t         ";
        }
        cout << endl;
    }

    cout << endl << endl
        << "Item _code\t Item_name\t Cost Price\t Selling Price\t Stock\t\t Re Ordered\t Profit" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            if (j == 6) {
                cout << "$" << supermarket[i][j] << "\t";
            }
            else
                cout << supermarket[i][j] << "\t         ";
        }
        cout << endl;
    }
}

int main()
{
    const int MAX = 10, MAX_ROW = 2, MAX_COL = 2;
    int randNum[MAX], choice = 0, matrixA[MAX_ROW][MAX_COL], matrixB[MAX_ROW][MAX_COL], matrixC[MAX_ROW][MAX_COL];
    string superMarket[5][10];
    srand(time(0));
    int c = 0;
    char opt;
    bool isTrue = true;

    string item_code;
    string item_name;
    string cost_price, selling_price;
    string stock;
    string re_ordered;

again:

    cout << "WEEK 9 Function Array" << endl
        << "Press 1 to run Random number sort acending order function" << endl
        << "Press 2 to run Maxtrix function" << endl
        << "Press 3 to run SuperMarket function" << endl
        << "Press any key to exit.. " << endl
        << "Press a number: ";
    cin >> choice;
    cout << endl << endl << endl;

    switch (choice) {
    case 1:
        for (int i = 0; i < MAX; i++) {
            do {
                isTrue = false;
                randNum[i] = rand() % 10 + 1;
                for (int j = 0; j < i; j++) {
                    if (randNum[i] == randNum[j]) {
                        isTrue = true;
                        break;
                    }
                }
            } while (isTrue);
        }
        sortArray(randNum, MAX);
        break;
    case 2:
        for (int i = 0; i < MAX_ROW; i++) {
            for (int j = 0; j < MAX_COL; j++) {
                cout << "Enter matrix A num: ";
                cin >> matrixA[i][j];
            }
        }

        for (int i = 0; i < MAX_ROW; i++) {
            for (int j = 0; j < MAX_COL; j++) {
                cout << "Enter matrix B num: ";
                cin >> matrixB[i][j];
            }
        }

        printMatrix1(matrixA, MAX_ROW, MAX_COL);
        printMatrix2(matrixB, MAX_ROW, MAX_COL);


        cout << "Press 1 to do Addition" << endl
            << "Press 2 to run Subtractioin" << endl;
        cin >> c;

        if (c == 1) {
            opt = '+';
            AddMatrixAB(matrixA, matrixB, MAX_ROW, MAX_COL, opt);
        }
        else {
            opt = '-';
            AddMatrixAB(matrixA, matrixB, MAX_ROW, MAX_COL, opt);
        }
        break;
    case 3:
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 6; j++) {
                if (j == 0) {
                    cout << "Enter item code: ";
                    cin >> item_code;
                    superMarket[i][j] = item_code;
                }
                else if (j == 1) {
                    cout << "Enter item name: ";
                    cin >> item_name;
                    superMarket[i][j] = item_name;
                }
                else if (j == 2) {
                    cout << "Enter cost price: ";
                    cin >> cost_price;
                    superMarket[i][j] = cost_price;
                }
                else if (j == 3) {
                    do {
                        cout << "Enter selling price: ";
                        cin >> selling_price;
                        if (selling_price > cost_price) {
                            superMarket[i][j] = selling_price;
                            break;
                        }
                        else
                            cout << "Invalid selling price must be higher than cost price... " << endl;
                    } while (true);
                }
                else if (j == 4) {
                    cout << "Enter number of stock: ";
                    cin >> stock;
                    superMarket[i][j] = stock;
                }
                else if (j == 5) {
                    do {
                        cout << "Enter re oredered: ";
                        cin >> re_ordered;
                        if (re_ordered < stock) {
                            superMarket[i][j] = re_ordered;
                            float profit = stof(selling_price) - stof(cost_price);
                            superMarket[i][6] = to_string(round(profit));
                            break;
                        }
                        else
                            cout << "Invalid re ordered must be lower than cost stock... " << endl;
                    } while (true);

                }
            }
        }
        printItemStock(superMarket);
        break;
    default:
        return 0;
        break;
    }

    system("pause");
    system("cls");
    goto again;
}
