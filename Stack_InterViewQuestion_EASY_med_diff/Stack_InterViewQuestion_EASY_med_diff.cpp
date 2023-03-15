// Stack_InterViewQuestion_EASY_med_diff.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include<stack>
using namespace std;


void balancingBrackets1()
{
    //  QUESTION TO CHECK WHETHER THE STRING IS VALID OR NOT.... (QUE 1:-BALANCING BRACKETS)
    string s;
    cin >> s;
    int i = 0, count = 0;



    while (i < s.length())
    {
        if (s[i] == '(')
            count++;

        else if (s[i] == ')')
            count--;


        if (count < 0)
        {
            cout << "invalid Sequence" << endl;
            return;
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



}


void balancingBrackets2() //balancing Brackets using Stack(by maintaing stack for every pair....)
{

    stack<char> st;
    string s;
    cin >> s;
    int i = 0; 
    while (i < s.length())
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(' || s[i] == '<')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                cout << "Invalid Sequence" << endl;
                return;
            }
            else if ((st.top() == '{' && s[i] == '}') ||
                (st.top() == '[' && s[i] == ']') ||
                (st.top() == '(' && s[i] == ')') ||
                (st.top() == '<' && s[i] == '>')
                )
            {
                st.pop();
            }
            else
            {
                cout << "Invalid Sequence" << endl;
                return;
            }
        }
        i++;

    }
    if (st.empty())
    {
        cout << "Valid Sequence" << endl;
    }
    else
    {
        cout << "Invalid Sequence" << endl;
    }

}




int main()
{
    
    balancingBrackets2();
    return 0;
}
