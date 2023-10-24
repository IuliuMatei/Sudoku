// sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

#define ROW 9
#define COL 9

vector<vector<int> > matrice;
vector<vector<int> > perechi = { {0,0},{0,3}, {0,4},{0,5},{0,6},{0,8},{1,0},{1,2},{1,3},{1,4},{1,6},{1,7},{1,8},{2,0},{2,1},{2,2},{2,3},
    {2,5},{3,0},{3,1},{3,2},{3,3},{3,4},
    {3,5},{3,6},{3,7},{3,8},{4,0},{4,1},{4,2},{4,3},{4,4},{4,5}, {4,7},{5,0}};

void creare_matrice(vector<vector<int> > &matrice) {
    for (int i = 0; i < ROW; i++) {
        vector<int> v1;

        for (int j = 0; j < COL; j++) {
            v1.push_back(0);
        }

        matrice.push_back(v1);
    }
}

void afisare(vector<vector<int> > &matrice) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0)
                cout << " " << matrice[i][j] << " ";
            else cout << matrice[i][j] << " ";
        }
        if (i % 3 == 2)
            cout << endl;
        cout << endl;
    }

}

bool check_full(vector<vector<int> > &matrice) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (matrice[i][j] == 0)
                return false;
        }
    }
    return true;
}

bool check_row(vector<vector<int> >& matrice,int row,int col) {
    for (int j = 0; j < COL; j++) {
        if (j != col) {
            if (matrice[row][col] == matrice[row][j])
                return false;
        }
    }

    return true;
}

bool check_col(vector<vector<int> >& matrice, int row, int col) {
    for (int i = 0; i < ROW; i++)
        if (i != row) {
            if (matrice[row][col] == matrice[i][col])
                return false;
        }

    return true;
}

bool check_matrix(vector<vector<int> >& matrice, int row, int col) {
    if (row >= 0 && row <= 2) {
        if (col >= 0 && col <= 2)
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++) {
                    if (i != row && j != col)
                        if (matrice[row][col] == matrice[i][j])
                            return false;
                }
    }
    if (row >= 0 && row <= 2) {
        if (col >= 3 && col <= 5)
            for (int i = 0; i < 3; i++)
                for (int j = 3; j < 6; j++) {
                    if (i != row && j != col)
                        if (matrice[row][col] == matrice[i][j])
                            return false;
                }
    }
    if (row >= 0 && row <= 2) {
        if (col >= 6 && col <= 8)
            for (int i = 0; i < 3; i++)
                for (int j = 6; j < 9; j++) {
                    if (i != row && j != col)
                        if (matrice[row][col] == matrice[i][j])
                            return false;
                }
    }
    if (row >= 3 && row <= 5) {
        if (col >= 0 && col <= 2)
            for (int i = 3; i < 6; i++)
                for (int j = 0; j < 3; j++) {
                    if (i != row && j != col)
                        if (matrice[row][col] == matrice[i][j])
                            return false;
                }
    }
    if (row >= 3 && row <= 5) {
        if (col >= 3 && col <= 5)
            for (int i = 3; i < 6; i++)
                for (int j = 3; j < 6; j++) {
                    if (i != row && j != col)
                        if (matrice[row][col] == matrice[i][j])
                            return false;
                }
    }
    if (row >= 3 && row <= 5) {
        if (col >= 6 && col <= 8)
            for (int i = 3; i < 6; i++)
                for (int j = 6; j < 9; j++) {
                    if (i != row && j != col)
                        if (matrice[row][col] == matrice[i][j])
                            return false;
                }
    }
    if (row >= 6 && row <= 8) {
        if (col >= 0 && col <= 2)
            for (int i = 6; i < 9; i++)
                for (int j = 0; j < 3; j++) {
                    if (i != row && j != col)
                        if (matrice[row][col] == matrice[i][j])
                            return false;
                }
    }
    if (row >= 6 && row <= 8) {
        if (col >= 3 && col <= 5)
            for (int i = 6; i < 9; i++)
                for (int j = 3; j < 6; j++) {
                    if (i != row && j != col)
                        if (matrice[row][col] == matrice[i][j])
                            return false;
                }
    }
    if (row >= 6 && row <= 8) {
        if (col >= 6 && col <= 8)
            for (int i = 6; i < 9; i++)
                for (int j = 6; j < 9; j++) {
                    if (i != row && j != col)
                        if (matrice[row][col] == matrice[i][j])
                            return false;
                }
    }
    return true;
}

bool check(int row, int col) {
    vector<int> pereche;
    pereche.push_back(row);
    pereche.push_back(col);
    for (int i = 0; i < perechi.size(); i++) {
        if (pereche == perechi[i])
            return true;
    }

    return false;
}

int main()
{
    int i = 0, j = 0, prev = 0, choice, rand, coloana, numar, choice2;

    creare_matrice(matrice);
    matrice[0][0] = 5;
    matrice[0][3] = 4;
    matrice[0][4] = 6;
    matrice[0][5] = 7;
    matrice[0][6] = 3;
    matrice[0][8] = 9;
    matrice[1][0] = 9;
    matrice[1][2] = 3;
    matrice[1][3] = 8;
    matrice[1][4] = 1;
    matrice[1][6] = 4;
    matrice[1][7] = 2;
    matrice[1][8] = 7;
    matrice[2][0] = 1;
    matrice[2][1] = 7;
    matrice[2][2] = 4;
    matrice[2][3] = 2;
    matrice[2][5] = 3;
    matrice[3][0] = 2;
    matrice[3][1] = 3;
    matrice[3][2] = 1;
    matrice[3][3] = 9;
    matrice[3][4] = 7;
    matrice[3][5] = 6;
    matrice[3][6] = 8;
    matrice[3][7] = 5;
    matrice[3][8] = 4;
    matrice[4][0] = 8;
    matrice[4][1] = 5;
    matrice[4][2] = 7;
    matrice[4][3] = 1;
    matrice[4][4] = 2;
    matrice[4][5] = 4;
    matrice[4][7] = 9;
    matrice[5][0] = 4;


    afisare(matrice);
    cout << endl << endl;
    cout << "1. Resolve the sudoku" << endl;
    cout << "2. Just let the computer resolve it" << endl;
    cout << "3. Exit" << endl << endl;
    cout << "Your choice: ";
    cin >> choice;
    system("cls");
    do {
        if (choice == 1) {
            do {
                afisare(matrice);
                cout << "You want to put the number: ";
                cin >> numar;
                cout << "On the row: ";
                cin >> rand;
                cout << "On the coloumn: ";
                cin >> coloana;
                if (check(rand, coloana)) {
                    cout << "You can not change the number there!" << endl;
                    do {
                        cout << "Press 1 if you got it" << endl;
                        cin >> choice2;
                    } while (choice2 == 0);
                }
                else {
                    matrice[rand][coloana] = numar;
                    afisare(matrice);
                }
                system("cls");
            } while (check_full(matrice) == false);
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (check_matrix(matrice, i, j) == true && check_row(matrice, i, j) == true && check_col(matrice, i, j) == true)
                        cout << "You won! :)";
                    else cout << "You lost! :(";
                }
            }
        }

        if (choice == 2) {
            while (i < ROW) {
                while (j < COL) {
                    if (check(i, j) == false) {
                        for (int k = 1; k <= 9; k++) {
                            matrice[i][j] = k;
                            if (check_matrix(matrice, i, j) == true && check_row(matrice, i, j) == true && check_col(matrice, i, j) == true && matrice[i][j] > prev) {
                                if (j == 8) {
                                    j = 0;
                                    i++;
                                    if (i == 9)
                                        goto end;
                                }
                                else j++;
                                prev = 0;
                                break;
                            }
                            else {
                                if (k == 9) {
                                    matrice[i][j] = 0;
                                    if (j == 0) {
                                        j = 8;
                                        i--;
                                    }
                                    else j--;

                                    while (check(i, j) == true) {
                                        if (j == 0) {
                                            j = 8;
                                            i--;
                                        }
                                        else j--;

                                    }
                                    prev = matrice[i][j];

                                }
                            }
                        }
                    }
                    else {
                        if (j == 8) {
                            j = 0;
                            i++;
                            if (i == 9)
                                goto end;
                        }
                        else j++;
                    }
                }
            }
        end:
            afisare(matrice);
            cout << "There is your sudoku!";
        }
    } while (choice == 3);


















   
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
