#include <iostream>
#include <cstdlib>
#include <stack>

int polishNotation(std::string exp)
{

    std::stack<char> s;

    for (auto c : exp)
    {

        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            int temp2 = s.top();
            s.pop();
            int  temp1 = s.top();
            s.pop();
            int res ;
            switch (c)
            {
            case '+':
               res=temp1+temp2;
                break;
                case '-':
               res=temp1-temp2;
                break;
                case '*':
               res=temp1*temp2;
                break;
                case '/':
               res=temp1/temp2;
                break;
            
            default:
                break;
            }
            s.push(res);
        }

        else
        {

            s.push(c-'0');
        }
    }

    return s.top();
}

int main()
{

    std::string exp{"23*54*+9-"};
    std::cout << polishNotation(exp);

    return 0;
}