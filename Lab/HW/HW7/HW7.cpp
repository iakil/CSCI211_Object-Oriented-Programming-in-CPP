/*
akil bhuiyan
prof. cong chen
cs211-HW6&7
*/

#include <iostream>
#include <fstream>
using namespace std;

/*
*variables and mathods used for lab 7
*/
int r = 0;
int col = 0;
int b[8][8] = { 0 };
int numQueens = 1; //number of queens on the board
void lab6();
void lab7();
void backtrack();
bool isOk();

int main()
{
  cout << "Solutions for lab6 and 7 will be printed to their respective text files" << endl;
  lab6();
  lab7();
}

/*
*creates the 92 solutions using the 1 dimensional array representation and backtracking
*
*/

void lab6()
{
  int numSol = 0;
  ofstream fout = ofstream("Lab6.txt");
  int q[8] = {0}, c = 0;
  q[0] = 0;
  nc: c++;
  if(c == 8)
    goto print;
  q[c] = -1;
  nr: q[c]++;
  if(q[c] == 8)
    goto backtrack;
  for(int i = 0; i < c; i++)
    if((q[i] == q[c]) || ((c - i) == abs(q[c] - q[i])))
      goto nr;

  goto nc;

  print:
  numSol++;
  fout << "solution number " << numSol << endl;
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(q[i] == j)
        fout << "1  ";
      else 
        fout << "0  ";
    }
    fout << endl;
  }
  fout << endl;

  backtrack: c--;
  if(c == -1) 
  {
    fout.close();
    return;
  }
  goto nr;
}

/*
*creates the 92 solutions using the 2 dimensional array representation and the use of methods
*/
void lab7()
{
  ofstream fout = ofstream("Lab7.txt");
	int numSolutions = 1; //number of solutions currently found
		
		b[r][col] = 1;
    col++;
    r--;
  while(true)
  {
  //this is repalced and put at the end of the while loop so that it will only be reached when a proper spot for a queen has been found
  //nc:col++; 
  //r--;
  r++;
		if (r >= 8)
    {
      backtrack();
      continue;
    }

    //if there is a conflict with 2 queens, the computer will move on to the next row until it reaches row 8
		if(!isOk()) 
      continue;
		b[r][col] = 1;
		r = 0;
		numQueens++;

		//check if a solution has been found aka there is 8 queens on the board that do not threaten each other since the program will not place a queen unless it is not being attacked
		if (numQueens == 8)
		{
			fout << endl << "Solution using backtracking number " << numSolutions << endl;

			//prints how the board looks when a solution is reached
			for (int rows = 0; rows < 8; rows++)
			{
				for (int columns = 0; columns < 8; columns++)
				{
					fout << b[rows][columns] << "  ";
				}

				//start a new line when going to next row for neater output
				fout << endl;

			}

			//checks if the 92 solutions have been found and if so finish the method
			if (numSolutions == 92) 
      {
        fout.close();
				return;
      }
      //increase the number of solutions found by the computer
			numSolutions++;
		}
    //goto nc;
		col++;
    r--;//nextCol();
    //goto nr;
 }
}

//backtracks/removes a queen from the board
void backtrack()
{
    col--;
		numQueens--;
		r = 0;
		while (b[r][col] != 1)
			r++;
		b[r][col] = 0;
}

//checks if there is conflict between 2 queens in the board and if so returns false, otherwise retunrs true
bool isOk()
{
  for (int i = 0; i < col; i++)
			if (b[r][i] == 1)
				return false;
		for (int i = 1; (r - i) > -1 && (col - i) > -1; i++)
			if (b[r - i][col - i] == 1)
				return false;
		for (int i = 1; (r + i) < 8 && (col - i) > -1; i++)
			if (b[r + i][col - i] == 1)
				return false;
    return true;
}