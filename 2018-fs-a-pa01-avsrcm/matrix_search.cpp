/**
Here in the .cpp you should define and implement the functions that are declared in the .h file, and optionally any you declared, but not defined, above main.
**/

#include <iostream>
#include <iomanip>
#include "matrix_search.h"

using namespace std;

// We're giving you this one the first time, and you should copy it into all future assignments.
// Change the information to your own.
void get_identity(string my_id[])
{
    my_id[0] = "avsrcm";
    my_id[1] = "12449123";
}


char** build_matrix(int rows, int cols)
{
    char **arrPtr = nullptr;

	arrPtr = new char *[rows];

	for (int i = 0; i < rows; i++)
	{
		arrPtr[i] = new char [cols];
	}

    return arrPtr;
}


void fill_matrix(int rows, int cols, char **matrix)
{
	for (int r = 0; r < rows; r++)
    	{
        	for (int c = 0; c < cols; c++)
        	{
			cin >> matrix[r][c];
        	}
    	}
}


void print_matrix(int rows, int cols, char **matrix)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			cout << matrix[r][c];
		}
		cout << endl;
	}
}


void delete_matrix(int rows, char **matrix)
{
    for(int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
    matrix = nullptr;
}


void matrix_search(int sol[], string word, int rows, int cols, char **matrix)
{
    bool found  = false;

    sol[0] = {-1};
    sol[1] = {-1};
    sol[2] = {-1};
    sol[3] = {-1};

  // linear search
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if(word[0] == matrix[rows][cols])
            {
                int numCount = 0;

                // Search Right
                if((cols - c) >= word.length())
                {
                    for(int i = 0; i < word.length(); i++)
                    {
                        if(word[i] == matrix[r][c + i])
                        {
                            numCount++;
                        }
                        if(numCount == word.length())
                        {
                            found = true;
                            sol[0] = r;
                            sol[1] = c;
                            sol[2] = r;
                            sol[3] = c + 1;
                        }
                    }
                }
                //Search Left
                if(found == false && c >= (word.length() - 1))
                {
                    numCount = 0;

                    for(int i = 0; i < word.length(); i++)
                    {
                        if(word[i] == matrix[r + i][c - i])
                        {
                            numCount++;
                        }
                        if(numCount == word.length())
                        {
                            found = true;
                            sol[0] = r;
                            sol[1] = c;
                            sol[2] = r;
                            sol[3] = c - i;
                        }
                    }
                }
                //Search Up
                if(found == false && r >= (word.length() - 1))
                {
                    numCount = 0;

                    for(int i = 0; i < word.length(); i++)
                    {
                        if(word[i] == matrix[r - i][c])
                        {
                            numCount++;
                        }
                        if(numCount == word.length())
                        {
                            found = true;
                            sol[0] = r;
                            sol[1] = c;
                            sol[2] = r - i;
                            sol[3] = c;
                        }
                    }
                }
                //Search Down
                 if(found == false && r >= (word.length() - 1))
                {
                    numCount = 0;

                    for(int i = 0; i < word.length(); i++)
                    {
                        if(word[i] == matrix[r + i][c])
                        {
                            numCount++;
                        }
                        if(numCount == word.length())
                        {
                            found = true;
                            sol[0] = r;
                            sol[1] = c;
                            sol[2] = r + i;
                            sol[3] = c;
                        }
                    }
                }
                 //Search Up,Right
                 if(found == false && r >= (word.length() - 1))
                {
                    numCount = 0;

                    for(int i = 0; i < word.length(); i++)
                    {
                        if(word[i] == matrix[r - i][c + i])
                        {
                            numCount++;
                        }
                        if(numCount == word.length())
                        {
                            found = true;
                            sol[0] = r;
                            sol[1] = c;
                            sol[2] = r - i;
                            sol[3] = c + i;
                        }
                    }
                }
                //Search Down,Right
               if(found == false && r >= (word.length() - 1))
                {
                    numCount = 0;

                    for(int i = 0; i < word.length(); i++)
                    {
                        if(word[i] == matrix[r + i][c + i])
                        {
                            numCount++;
                        }
                        if(numCount == word.length())
                        {
                            found = true;
                            sol[0] = r;
                            sol[1] = c;
                            sol[2] = r + i;
                            sol[3] = c + i;
                        }
                    }
                }
                //Search Down,Left
                if(found == false && r >= (word.length() - 1))
                {
                    numCount = 0;

                    for(int i = 0; i < word.length(); i++)
                    {
                        if(word[i] == matrix[r - i][c - i])
                        {
                            numCount++;
                        }
                        if(numCount == word.length())
                        {
                            found = true;
                            sol[0] = r;
                            sol[1] = c;
                            sol[2] = r + i;
                            sol[3] = c - i;
                        }
                    }
                }
                //Search Up,Left
                if(found == false && r >= (word.length() - 1))
                {
                    numCount = 0;

                    for(int i = 0; i < word.length(); i++)
                    {
                        if(word[i] == matrix[r - i][c - i])
                        {
                            numCount++;
                        }
                        if(numCount == word.length())
                        {
                            found = true;
                            sol[0] = r;
                            sol[1] = c;
                            sol[2] = r - i;
                            sol[3] = c - i;
                        }
                    }
                }
            }
        }
    }
}
