/*****************************************************
 * Title: hw6_2.cpp
 * Name: Ricardo Barbosa
 * Date: December 17, 2020
 * id: 3639
 * Abstract: collects the maximum number of coins on 
 *             a board that is 25 x 25
 * **************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int row_max = 25;
const int col_max = 25;
const int MAX = 250;
int main()
{
   int row, col;
   int collected[row_max][col_max];
   int counter[row_max][col_max];
   string storage[MAX];
   cin>>col>>row;
   for(int i=0; i<row;i++)
   {
      for (int j=0; j<col; j++)
      {
         cin>>collected[i][j];   
      }
   }

   counter[0][0] = collected[0][0];
   for (int j = 1; j < col; j++)
   {
      if(collected[0][j] == 2)
      {
         counter[0][j] = -1;
      }
   else
   {  
      counter[0][j] = counter[0][j - 1] + collected[0][j];
   }
   }
      for (int i = 1; i <= row; i++)
      {
         if(collected[i][0] == 2)
         {
            counter[i][0] = -1;
         }
   else
   {
      counter[i][0] = counter[i - 1][0] + collected[i][0];
   }
   for (int j = 1; j < col; j++)
   {
      if(collected[i][j] == 2)
      {
         counter[i][j] = -1;
      }
   else
   {
      counter[i][j] = max(counter[i - 1][j], counter[i][j - 1]) + collected[i][j];
   }
   }
   }
   cout << "Max coins: " << counter[row - 1][col - 1] << endl;
   int row2 = row - 1;
   int col2 = col - 1;
   int count = 0;
   cout << "Path: ";
   stringstream first, second;
   string firstRes, secondRes;
   first << row;
   first >> firstRes;
   second << col;
   second >> secondRes;
   storage[count] = secondRes + "," + firstRes;
   count++;
   while (row2 > 0 || col2 > 0)
   {
      if (row2 < 0 || col2 < 0)
   {
   break;
   }
   if (row2 != 0 && counter[row2 - 1][col2] >= counter[row2][col2 - 1])
   {
      row2--;
      stringstream converter, converter2;
      string result, result2;
      converter << row2 + 1;
      converter >> result;
      converter2 << col2 + 1;
      converter2 >> result2;
      storage[count] = result2 + "," + result;
   }
   else if(col2 != 0)
   {
      col2--;
      stringstream converter, converter2;
      string result, result2;
      converter << row2 + 1;
      converter >> result;
      converter2 << col2 + 1;
      converter2 >> result2;
      storage[count] = result2 + "," + result;
   }
   else
   {
      break;
   }
      count++;
}
for (int i = count - 1; i >= 0; i--)
{
   cout << "(" << storage[i] << ")";
if (i > 0)
{
cout << "->";
}
}
cout << endl;
return 0;
}