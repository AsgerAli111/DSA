#include <iostream>
#include <stack>

bool isBalanced(std::string &str)
{

    std::stack<char> s;
    for (char c : str)
    {

        if (c == '(' || c == '[' || c == '{')
        {
            s.push(c);
        }

        else if (c == ')' || c == ']' || c == '}')
        {

            if (s.empty())
                return false;
            char top = s.top();
            s.pop();

            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))
                return false;
        }
    }
    return s.empty();
}

int main(){

    std::string str{"{(dfe)}"};
    std::cout<<isBalanced(str);
    return 0;
}