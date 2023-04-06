/*
 * Filename: GameOfLife.cpp
 *
 *  Authors Rick Mercer and Andrew Tapia
 *
 * This class models a society of cells growing according
 * to the rules of John Conway's Game of Life.
 *
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// This class allows a society of cells to grow according
// to the rules from John Conway's Game of Life
class GameOfLife {

// --Data Member
private:
    std::vector<std::vector<bool>> theSociety;

public:
    // Construct a board that is rows by cols size
    // with all elements set to false
    GameOfLife(unsigned rows, unsigned cols) {
        // TODO: Complete this method
        for (int i = 0; i < rows; i++) {
            vector<bool> row;
            for (int j = 0; j < cols; j++) {
                row.push_back(false);
            }
            theSociety.push_back(row);
        }
    }

    // Grow a cell at the given location
    void growCellAt(unsigned row, unsigned col) {
        theSociety.at(row).at(col) = true;
    }

    // Check to see if a cell is at the given location
    bool cellAt(unsigned row, unsigned col) const {
        return theSociety.at(row).at(col);
    }

    // Returns the colony as one big string
    string toString() const {
        string return_string = "";
        for (int i = 0; i < theSociety.size(); i++) {
            string row_str = "";
            for (int j = 0; j < theSociety.at(i).size(); j++) {
                if (theSociety.at(i).at(j)) {
                    row_str = row_str + "O";
                } else {
                    row_str = row_str + ".";
                }
            }
            return_string = return_string + row_str + "\n";
        }
        return return_string;
    }

    // Count the neighbors around the given location. Use wraparound. A cell in row 0
    // has neighbors in the last row if a cell is in the same column, or the column to
    // the left or right. In this example, cell 0,5 has two neighbors in the last row,
    // cell 2,8  has four neighbors, cell 2,0 has four neighbors, cell 1,0 has three
    // neighbors. The cell at 3,8 has 3 neighbors. The potential location for a cell
    // at 4,8 would have three neighbors.
    //
    // .....O..O
    // O........
    // O.......O
    // O.......O
    // ....O.O..
    //
    // The return values should always be in the range of 0 through 8.
    // Return the number of neighbors around any cell using wrap around.
    int neighborCount(int row, int col) const {
        // 00
        // 0
        // br b0 b1
        // 0r 00 01
        // 1r 10 11
        // 40
        vector<int> rowAdd = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> colAdd = {1, 0, -1, -1, -1, 0, 1, 1};
        int neighbor_count = 0;

        for (int i = 0; i < 8; i++) {
            int rowToCheck = row + rowAdd.at(i);
            int colToCheck = col + colAdd.at(i);
            // ensure row in bounds, if < 0 wrap to bottom row
            if (rowToCheck < 0) {
                rowToCheck = theSociety.size() - 1;
            }
                // ensure row in bounds, if row.size()  -1 then  wrap to top row
            else if (rowToCheck > theSociety.size() - 1) {
                rowToCheck = 0;
            }
            // ensure col in bounds, if colToCheck < 0 then  wrap to end of row whcih is theSociety.at(0).size()  - 1
            if (colToCheck < 0) {
                colToCheck = theSociety.at(0).size() - 1;
            }
                // ensure col in bounds, if colToCheck >  theSociety.at(0).size() - 1 then  wrap to beginning of row which is 0
            else if (colToCheck > theSociety.at(0).size() - 1) {
                colToCheck = 0;
            }
            if (cellAt(rowToCheck, colToCheck)) {
                neighbor_count++;
            }
        }

        return neighbor_count;
    }

    vector<vector<bool>> getSociety() {
        return theSociety;
    }

    // Change the state to the next society of cells
    void update() {
        int rows = theSociety.size();
        int cols = theSociety.at(0).size();
        GameOfLife newSociety(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbor_count = neighborCount(i, j);
                // 1 n = deathneighbor_count
                if (neighbor_count < 2) {
                    newSociety.getSociety().at(i).at(j) = false;
                } else if (neighbor_count == 3) {
                    newSociety.growCellAt(i, j);
                } else if (neighbor_count > 3) {
                    newSociety.getSociety().at(i).at(j) = false;
                } else if (neighbor_count == 2) {
                    if (cellAt(i, j)) {
                        newSociety.growCellAt(i, j);
                    }

                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                theSociety.at(i).at(j) = newSociety.getSociety().at(i).at(j);
            }
        }
    }

};
