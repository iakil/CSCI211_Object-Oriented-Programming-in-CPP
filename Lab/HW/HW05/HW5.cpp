/*
akil bhuiyan
prof. cong chen
cs211-HW5
*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void backtrack();
void dumb();
bool isAttacked(int arr[], int c);

int main()
{
  cout << "solutions will be printed to \"outputBacktrack.txt\" and \"outputDumb.txt\" \n";
	backtrack();
  dumb();
  return 0;
}

/*
*generates a solution using backtracking on a 2D array
*
*/
void backtrack()
{
  ofstream fout = ofstream("outputBacktrack.txt");
  int b[8][8] = { 0 };
	int c = 0, r = 0;
	int numSolutions = 1; //number of solutions currently found
		int numQueens = 1; //number of queens on the board
		b[r][c] = 1;
	nc:c++;
		r--;
	nr:r++;
		if (r == 8)
			goto backtrack;
		for (int i = 0; i < c; i++)
			if (b[r][i] == 1)
				goto nr;
		for (int i = 1; (r - i) > -1 && (c - i) > -1; i++)
			if (b[r - i][c - i] == 1)
				goto nr;
		for (int i = 1; (r + i) < 8 && (c - i) > -1; i++)
			if (b[r + i][c - i] == 1)
				goto nr;
		b[r][c] = 1;
		r = 0;
		numQueens++;

		//check if a solution has been found aka there is 8 queens on the board that do not threaten each other since the program will not place a queen unless it is not being attacked
		if (numQueens == 8)
		{
			fout << endl << "Solution using backtracking number " << numSolutions << endl;

			//prints how the board looks when a solution is reached
			for (int r = 0; r < 8; r++)
			{
				for (int c = 0; c < 8; c++)
				{
					fout << b[r][c] << "  ";
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
		goto nc;
	backtrack:c--;
		numQueens--;
		r = 0;
		while (b[r][c] != 1)
			r++;
		b[r][c] = 0;
		goto nr;
}

/*
*generates a solution using the "dumb" algorithm on a 1D array and outputs it to a
*file 
*/
void dumb()
{
  int b[8] = {0};
  ofstream fout = ofstream("outputDumb.txt");
  int numSolutions = 1;
 
 for(int i = 0; i < 8; i++)
 {
   b[0] = i;
   if(isAttacked(b, 0))
      continue; //using keyword continue will allow the computer to move on to the next iteration of the loop, so if a certain position does not work, it will try the next available row for that collumn 
   for(int j = 0; j < 8; j++)
   {
     b[1] = j;
     if(isAttacked(b, 1))
        continue;
     for(int k = 0; k < 8; k++)
     {
       b[2] = k;
       if(isAttacked(b, 2))
        continue;
      for(int l = 0; l < 8; l++)
      {
        b[3] = l;
        if(isAttacked(b, 3))
          continue;
        for(int m = 0; m < 8; m++)
        {
           b[4] = m;
           if(isAttacked(b, 4))
              continue;
          for(int n = 0; n < 8; n++)
          {
             b[5] = n;
             if(isAttacked(b, 5))
                continue;
            for(int p = 0; p < 8; p++)
            {
               b[6] = p;
               if(isAttacked(b, 6))
                continue;
              for(int q = 0; q < 8; q++)
              {
                 b[7] = q;
                 if(isAttacked(b, 7))
                  continue;
                  //if the computer has reached a solution then print the output to the file
                 fout << "solution number " << numSolutions << endl;
                 for(int y = 0; y < 8; y++)
                 {
                   for(int z = 0; z < 8; z++)
                   {
                     if(b[y] == z)
                      fout << "1  ";
                     else
                      fout << "0  ";
                   }
                   fout << endl;
                 }
                 fout << endl;
                 numSolutions++;
              }
            }
          }
        }
      }
     }
   }
 } 
  fout.close();
}

/*
* checks if a queen in a 1D array is being attacked if so return true *else return false
*/
bool isAttacked(int arr[], int c)
{
  for(int i = 0; i < c; i++)
    if((arr[i] == arr[c]) || (c - i) == abs(arr[c] - arr[i]))
      return true;
  return false;
}   