// Stack_InterViewQuestion_EASY_med_diff.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include<stack>
using namespace std;





int main()
{
    //  QUESTION TO CHECK WHETHER THE STRING IS VALID OR NOT....
    string s;
    cin >> s;
    int i=0, count = 0;



    while (i < s.length())
    {
        if (s[i] == '(')
            count++;

        else if(s[i] == ')')
            count--;


        if (count < 0)
        {
            cout << "invalid Sequence"<<endl;
            return 0  ;
        }

        i++;
    }


    if (count == 0)
    {
        cout << "Valid Sequence" << endl;

    }
    else
    {
        cout << "Invalid Sequence" << endl;
    }


    return 0;
}
