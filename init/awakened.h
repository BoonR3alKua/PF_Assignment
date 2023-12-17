/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Winter 2023
* Author: Tran Huy
* Date: 07.11.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef awakened_h
#define awakened_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
///                         Support Function                         ///
///                                                                  ///
////////////////////////////////////////////////////////////////////////

int stringToInt(const string& str) {
    int num = 0;
    int sign = 1;
    size_t i = 0;
    if (!str.empty() && str[0] == '-') {
        sign = -1;
        i = 1;
    }
    for (; i < str.length(); i++) {
        char ch = str[i];
        if (ch >= '0' && ch <= '9') {
            int digit = ch - '0';
            if (num > 100000 / 10 || (num == 100000 / 10 && digit > 100000 % 10)) {
                return sign == 1 ? 100000 : -100000;
            }
            num = num * 10 + digit;
        } else {
            break;
        }
    }
    return num * sign;
};

bool checkDateValidity(string DDMM1, string DDMM2) {
    return 1;
};

bool checkTimeValidity(string hhmm1, string hhmm2) {
    return 1;
};

void countRowsCols(const std::string& input, int& rows, int& cols) {
    istringstream iss(input);
    string line;
    rows = 0;
    cols = 0;
    while (getline(iss, line)) {
        istringstream lineStream(line);
        int count = 0;
        int number;
        while (lineStream >> number) {
            count++;
        }
        if (count > cols) {
            cols = count;
        }
        rows++;
    }
}

int** createMatrix(const std::string& input, int rows, int cols){
    int** matrix = new int*[rows];
    for(int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols]();
    }
    istringstream iss(input);
    string line;
    int row = 0;
    while (getline(iss, line)) {
        istringstream lineStream(line);
        int col = 0;
        int number;
        while (lineStream >> number) {
            matrix[row][col++] = number;
        }
        row++;
    }
    return 0;
}

void reverseString(string& s) {
    int n = s.length();
    for (int i = 0; i < n / 2; ++i) {
        std::swap(s[i], s[n - i - 1]);
    }
}

////////////////////////////////////////////////////////////////////////
///                         Main Function                            ///
///                                                                  ///
////////////////////////////////////////////////////////////////////////


int invalidTime(const string& schedule) {
    // Complete this function to gain point
    int validShip = 0;
    ifstream newFile(schedule);
    string ship_num;
    if(newFile.is_open()) {
        for(int i = 0; i < 4; i++) {
            newFile >> ship_num;
        }
        for (int i = 0; i < 3; i++) {
            if (ship_num[i] < '0' || ship_num[i] > '9') return -1;
        }
        int num = stringToInt(ship_num);
        while(num > 0) {
            string ship_name;
            string dm1, hm1, dm2, hm2;
            char dummy;
            newFile >> ship_name >> dm1 >> hm1 >> dummy >> dm2 >> hm2;
            if (!ship_name.empty() && ship_name.back() == ',') {
                ship_name.pop_back();
            }
            if(checkDateValidity(dm1, dm2) && checkTimeValidity(hm1, hm2)) validShip++;
            num--;
        }
    }
    return validShip;
}

string longestDuration(const string& schedule) {
    // Complete this function to gain point
    return "";
}

bool investigateTemple(const string& map, const string& moveStyle, int stamina, int& outTime, string& outPath) {
    // Complete this function to gain point
    return 1;
    int rows, cols;
    countRowsCols(map, rows, cols);
    int** matrix = createMatrix(map, rows, cols);
    int x_pos, next_x;
    int y_pos, next_y;
    int n = 0;
    int doorT[4];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] == 'S') {
                x_pos = i;
                y_pos = j;
            }
            if(matrix[i][j] == 'T') {
                doorT[n] = i;
                doorT[n + 1] = j;
                n += 2;
            }
        }
    }
    string tempMoveStyle = moveStyle;
    outTime = 0;
    n = stamina;
    int index = 0;
    int i = moveStyle.length();
    int potion = 0;
    bool potionFound;
    bool found = false;
    bool end = 0;

    while(n > 0) {
        switch (tempMoveStyle[index])
        {
        case 'L':
            if(y_pos == 0) next_y = 9;
            else next_y = y_pos - 1;
            next_x = x_pos;
            if(!(matrix[next_x][next_y] == 'X')){
                x_pos = next_x;
                y_pos = next_y;
            }
            if(potionFound) {
                if(potion) potion--;
                else {
                    potion = 1;
                    n--;
                }
            } else{
                n--;
            }
            break;
        case 'R':
            if(y_pos == 9) next_y = 0;
            else next_y = y_pos + 1;
            next_x = x_pos;
            if(!(matrix[next_x][next_y] == 'X')){
                x_pos = next_x;
                y_pos = next_y;
            }
            if(potionFound) {
                if(potion) potion--;
                else {
                    potion = 1;
                    n--;
                }
            } else{
                n--;
            }
            break;
        case 'U':
            if(x_pos == 0) next_y = 9;
            else next_x = x_pos - 1;
            next_y = y_pos;
            if(!(matrix[next_x][next_y] == 'X')){
                x_pos = next_x;
                y_pos = next_y;
            }
            if(potionFound) {
                if(potion) potion--;
                else {
                    potion = 1;
                    n--;
                }
            } else{
                n--;
            }
            break;
        case 'D':
            if(x_pos == 9) next_y = 0;
            else next_x = x_pos + 1;
            next_y = y_pos;
            if(!(matrix[next_x][next_y] == 'X')){
                x_pos = next_x;
                y_pos = next_y;
            }
            if(potionFound) {
                if(potion) potion--;
                else {
                    potion = 1;
                    n--;
                }
            } else{
                n--;
            }
            break;
        default:
            break;
        }
        
        outTime++;
        outPath += tempMoveStyle[index];
        if(index == (i - 1)) index = 0;
        n--;
        index++;

        switch (matrix[x_pos][y_pos])
        {
        case 0:
        case 1:
        case 2:
            matrix[x_pos][y_pos]++;
            break;
        case 3:
            end = 1;
            break;
        case 'R':
            reverseString(tempMoveStyle);
            break;
        case 'A':
            found = 1;
            end = 1;
            break;
        case 'T':
            if (x_pos == doorT[0] && y_pos == doorT[1]){
                x_pos = doorT[2];
                y_pos = doorT[3];
            } else {
                x_pos = doorT[0];
                y_pos = doorT[1];
            }
            break;
        case 'H':
            /* code */
            break;
        case 'P':
            potionFound = 1;
            break;
        case 'C':
            for (int i = 0; i < (rows / 2); ++i) {
                for (int j = 0; j < cols; ++j) {
                    swap(matrix[i][j], matrix[rows - 1 - i][cols - 1 - j]);
                }
            }
            break;
        case 'L':
            int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
            int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

            for (int i = 0; i < 8; i++) {
                int newX = x_pos + dx[i];
                int newY = y_pos + dy[i];
                if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10) {
                    if (matrix[newX][newY] == 'A') {
                        found = 1;
                        end = 1;
                        break;
                    }
                } else {
                    if (newX < 0) newX = 9;
                    if (newX >= 10) newX = 0;
                    if (newY < 0) newY = 9;
                    if (newY >= 10) newY = 0;

                    if (matrix[newX][newY] == 'A') {
                        found = 1;
                        end = 1;
                        break;
                    }
                }
            }
            break;
        case 'M':
            end = 1;
            break;
        default:
            break;
        }
        if(end) break;
    }
    if(found) return true;
    else return false;
}

int solveCrate(int* arr, int size, int k) {
    // Complete this function to gain point
    if (k <= 0 || k > size) return 0;
    if (k == 1) {
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += arr[i];
            sum %= 1000;
        }
        return sum;
    }
    int temp1[size], temp2[size];
    for (int i = 0; i < size; ++i) {
        temp1[i] = arr[i];
    }
    for (int row = 2; row <= k; ++row) {
        for (int i = 0; i < size - row + 1; ++i) {
            temp2[i] = temp1[i] + temp1[i + 1];
            temp2[i] %= 1000;
        }
        for (int i = 0; i < size - row + 1; ++i) {
            temp1[i] = temp2[i];
        }
    }
    int sum = 0;
    for (int i = 0; i < size - k + 1; ++i) {
        sum += temp1[i];
        sum %= 1000;
    }
    return sum;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* awakened_h */
