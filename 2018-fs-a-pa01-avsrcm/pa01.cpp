/**
Implement the main here to match input and output.
If you want to add extra functions, you can do so above main.
**/

#include <iostream>
#include <iomanip>
#include "matrix_search.h"

using namespace std;

int main()
{
    int loop = 0;

    cin >> loop;

    for (int i = 0; i < loop; i++)
    {
        int numRow = 0;
        int numCols = 0;
        int sol[4];

        char **matrix = nullptr;

        string searchWord;

        cin >> numRow >> numCols;

        matrix = build_matrix(numRow, numCols);

        fill_matrix(numRow, numCols, matrix);

        print_matrix(numRow, numCols, matrix);

        matrix_search(sol, searchWord, numRow, numCols, matrix);

        cout << "Searching for \"" << searchWord << "\" in matrix " << i << "yields:\n";
        if(sol[0] != -1)
        {
            cout << "Start pos:(" << sol[0] << ", " << sol[1] << ") to End pos:(" << sol[2] << ", " << sol[3] << ")\n\n";
        }

        else
        {
            cout << "The pattern was not found.\n\n";
        }

        delete_matrix(numRow, matrix);
    }

    return 0;
}
