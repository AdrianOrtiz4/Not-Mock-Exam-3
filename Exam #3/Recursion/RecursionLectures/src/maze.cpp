#include <iostream>
#include <string>

/*
 * A rat starts at a position and can only move in four directions:
    - Right
    - Down
    - Left
    - Up
    The goal is to find the cheese.
*/

using namespace std;

int maze[6][6] =
{
    {2, 2, 2, 0, 0, 0},
    {0, 0, 2, 0, 0, 0},
    {0, 0, 2, 2, 2, 0},
    {0, 0, 2, 0, 0, 0},
    {0, 0, 0, 0, 0, 3}
};

string findCheese(int row, int col)
{
    // Mouse Outside the maze
    if((row < 0 || row > 5) || (col < 0 || col > 5)) return "";
    // Mouse hit a wall
    if( maze[row][col] == 0) return "";
    // Mouse found the cheese
    if ( maze[row][col] == 3) return "[" + to_string(row) + "," + to_string(col) +"]";
    // Mouse revisited a space
    if ( maze[row][col] == -1) return "";

    maze[row][col] = -1;

    // Search Right
    string result = findCheese(row, col+1);
    if(result != "") return "[" + to_string(row) + "," + to_string(col) +"]" + result;
    // Search Down
    result = findCheese(row+1, col);
    if(result != "") return "[" + to_string(row) + "," + to_string(col) +"]" + result;
    // Search Left
    result = findCheese(row, col-1);
    if(result != "") return "[" + to_string(row) + "," + to_string(col) +"]" + result;
    // Search Up
    result = findCheese(row-1, col);
    if(result != "") return "[" + to_string(row) + "," + to_string(col) +"]" + result;

    return "";
}

int main(int argc, char const *argv[])
{
    cout << boolalpha;
    cout << findCheese(0, 0) << endl;
    return 0;
}
