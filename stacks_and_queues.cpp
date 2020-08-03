#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

template <class Tc, typename Uc = int>
struct Stack
{
        int top;
        Tc stk[MAX];
        Stack() { top = -1; }
        ~Stack() {}
        void push(Tc value)
        {
                if (top >= (MAX - 1))
                {
                        cout << "Stack overflow" << endl;
                        return;
                }
                stk[++top] = value;
                return;
        }

        Tc peek()
        {
                if (top < 0)
                {
                        cout << "Stack is empty" << endl;
                        Tc c;
                        return c;
                }
                Tc value = stk[top];
                return value;
        }

        void pop()
        {
                if (top < 0)
                {
                        cout << "Stack underflow" << endl;
                }
                Tc _ = stk[top--];
        }
        bool isEmpty()
        {
                return top < 0;
        }
};

string isBalanced(string s)
{
        stack<char> stk;
        for (auto c : s)
        {
                switch (c)
                {
                case '{':
                case '(':
                case '[':
                        stk.push(c);
                        break;
                case ')':
                        if (stk.empty() || (stk.top() != '('))
                        {
                                return "NO";
                        }
                        stk.pop();
                        break;

                case '}':
                        if (stk.empty() || (stk.top() != '{'))
                        {
                                return "NO";
                        }
                        stk.pop();
                        break;

                case ']':
                        if (stk.empty() || (stk.top() != '['))
                        {
                                return "NO";
                        }
                        stk.pop();
                        break;
                }
        }

        return stk.empty() ? "YES" : "NO";
}

int main(int argc, const char **argv)
{
        string v = "}][}}(}][))]";
        string i = isBalanced(v);
        cout << i << endl;
        return 0;
}