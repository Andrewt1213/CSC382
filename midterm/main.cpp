#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class Matrix {
private:
    vector<vector<T>> table;
    int rows, cols;

public:
    Matrix(vector<vector<T>> const &initTable) {
        this->table = initTable;
        rows = table.size();
        cols = table[0].size();
    }

    void print() {
        for (int r = 0; r < table.size(); r++) {
            for (int c = 0; c < table[0].size(); c++) {
                cout.width(4);
                cout << table[r][c];
            }
            cout << endl;
        }
    }

    void transpose(){
        vector<vector<T>> t_table;
        for(int i = 0; i < cols; i++)
        {
            vector<T> row;
            for(int j = 0; j < rows; j++)
            {
                row.push_back(table[j][i]);
            }
            t_table.push_back(row);
        }
        int temp = rows;
        rows = cols;
        cols = temp;
        table  = t_table;
    }
};

int main() {
    vector<vector<int>> one{{{1, 2, 3}, {4, 5, 6}}};
    Matrix<int> a{one};
    a.print();
    a.transpose();
    a.print();
    a.transpose();
    a.print();

    return 0;
}