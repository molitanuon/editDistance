/*
How to compile and run the program:

1. unzip folder
2. open terminal at folder
3. type: g++ EditDistance.cpp
4. type:  ./a.out
5. follow prompt
*/




#include <iostream>
#include <string>
using namespace std;

int main()
{
  string first, second;
  cout << "\nWELCOME TO EDIT DISTANCE DEMONSTRATION.\n" << endl;
  cout << "This program will calculate the edit distance between two words.\n";
  cout << "It will output the distance and an alignment that support the result.\n\n";

  //get the user inputs
  cout <<"Please input two words for the edit distance as prompted:\n";
  cout << "The first word: ";
  cin >> first;
  cout <<"The second word: ";
  cin >> second;

  //create the matrix
  cout << "The matrix: \n" << endl;

  //print the first top column
  cout << "       ";
  for (int i = 0; i < second.size()+1;i++)
  {
    cout << i << "       ";
  }
  cout << endl;

  cout << "  ";
  for (int i = 0; i < second.size()+1;i++)
  {
    if (i < 10)
      cout << "________";
    else
      cout << "_________";
  }
  cout << endl;

  //calculate the edit distance and store it in the dArray
  int smallest = 0;
  int biggest =0;
  string str;
  string str2;

  int dArray[first.size()+1][second.size()+1];
  for (int i = 0; i < first.size()+1; i++)                //row
  {
    for (int j = 0; j < second.size()+1; j++)             //column
    {
      if(i == 0)
      {
        dArray[i][j] = j;
      }
      else if (j == 0)
      {
        dArray[i][j] = i;
      }
      else if (first[i-1] != second[j-1])
          {
            smallest = dArray[i-1][j];

            if(dArray[i-1][j-1] < smallest)
              smallest = dArray[i-1][j-1];

            if(dArray[i][j-1] < smallest)
              smallest = dArray[i][j-1];

            dArray[i][j] = smallest + 1;
          }
          else
            dArray[i][j] = dArray[i-1][j-1];

    }
  }

  //print the rest of the matrix

  for(int j = 0; j < first.size()+1; j++)
  {
    if (j < 10 )
      cout << j << "   |";
    else
      cout << j << "  |";

    for (int k = 0; k < second.size()+1; k++)
    {
      if (dArray[j][k] < 10)
        cout << " " << dArray[j][k] << "     |";
      else
        cout << " " << dArray[j][k] << "    |";
    }
    if (j == first.size())
    {
        cout << endl << "  ";
      for (int i = 0; i < second.size()+1;i++)
      {
        if (i < 10)
          cout << "________";
        else
          cout << "_________";
      }
    }
    cout << endl << endl;
  }

  //print edit distance

  cout << "The edit distance is: " << dArray[first.size()][second.size()] << endl ;

  int i = 0;
  int  j= 0;
  while(i < first.size()+1 || j < second.size()+1)
  {
      smallest = dArray[i+1][j+1];

      if(dArray[i][j+1] < smallest)
        smallest = dArray[i][j+1];

      if(dArray[i+1][j] < smallest)
        smallest = dArray[i+1][j];

      if(smallest == dArray[i+1][j+1])
      {
        str.push_back(first[i-1]);
        str2.push_back(second[j-1]);
        i = i+1;
        j = j+1;
      }
      else if(smallest == dArray[i][j+1])
      {
        str2.push_back(second[i-1]);
        str.push_back('_');
        i = i;
        j = j+1;
      }
      else
      {
        str2.push_back('_');
        str.push_back(first[i-1]);
        i = i+1;
      }

  }
cout << "\nAlignment is: \n";
cout << str << endl;
cout << str2 << endl << endl;

  return 0;
}
