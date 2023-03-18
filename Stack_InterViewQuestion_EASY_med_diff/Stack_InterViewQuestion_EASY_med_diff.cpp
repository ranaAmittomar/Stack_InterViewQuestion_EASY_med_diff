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


//Remove adjacent duplicates from the string..

void removeDuplicate()
{
    string s;
    cin >> s;
    stack<char> st;
    int i = 0;
    while (i < s.length())
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else
        {
            if (st.top() == s[i])
            {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }

        i++;
    }
    s = "";
    while (!st.empty())
    {
        s = st.top() + s;   //string CONCATINATION....
        st.pop();
    }
    cout << s << endl;
}

//Remove K number of adjacent chars from a string ...Which means ,if K=3, then remove 3 same adjacent chars from a string.

void removeKDuplicates()
{
    string s;
    cin >> s;
    int k;
    cin >> k;

    stack<pair<char, int>> st;
    pair<char, int> t;
    int i = 0;

    while (i<s.length())
    {
        if (st.empty())
        {
            st.push({ s[i],1 });
        }
        else
        {
            if (st.top().first == s[i])
            {
                if (st.top().second == (k - 1))
                {
                    //code here
                    for (int j = 0; j < k - 1; j++)
                        st.pop();
                }
                else {
                    //code here
                    st.push({ s[i],st.top().second + 1 });
                }

            }
            else {
                st.push({ s[i],1 });
            }
        }

        i++;
    }

    s = "";
    while (!st.empty())
    {
        s = st.top().first + s;
        st.pop();
    }
    cout << s;
 }

//Find the Previous smallest element from array

void previousSmaller(int* prev, int* num, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && num[st.top()] >= num[i])
            st.pop();

        prev[i] = (st.empty() ? -1 : st.top()); //using TERNARY OPERATOR FOR IF/ELSE STATEMENT,...
        st.push(i);
    }
}

//Find the next smaller element...

void nextSmaller(int* next, int* num, int n)
{
    stack<int> st;
    for (int i = n-1; i >=0; i--)
    {
        while (!st.empty() && num[st.top()] >= num[i])
            st.pop();

        next[i] = (st.empty() ? -1 : st.top()); //using TERNARY OPERATOR FOR IF/ELSE STATEMENT,...
        st.push(i);
    }
}

//Find the previous greater number....


void previousGreater(int* prev, int* num, int n)
{

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && num[st.top()] <= num[i])
            st.pop();

        prev[i] = (st.empty() ? -1 : st.top()); //using TERNARY OPERATOR FOR IF/ELSE STATEMENT,...
        st.push(i);
    }
}


int main()


{
    int n;
    cout << "Please Enter a value less than 50" << endl;
    cin >> n;
    int num[50];
    for (int i = 0; i < n; i++)
        cin >> num[i]; 

    int prev[50],next[50];


    previousSmaller(prev, num, n);
    nextSmaller(next, num, n);


    
    for (int i = 0; i < n; i++)
        if (prev[i] == -1)
            cout << "-1"<<" ";
        else
            cout << num[prev[i]] << " ";
    

    cout << endl;
    for (int i = 0; i < n; i++)
        if (next[i] == -1)
            cout << "-1" << " ";
        else
            cout << num[next[i]] << " ";

    //removeKDuplicates();
    //removeDuplicate();
   // balancingBrackets2();
    return 0;
}
