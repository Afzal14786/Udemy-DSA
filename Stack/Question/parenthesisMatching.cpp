#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isOperand(char ch) {
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*') {
        return false;
    }

    return true;
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '^') {
        return 3;
    } else {
        return -1;
    }
}

bool isParanthesis(string &expression) {
    stack<char> st;
    int len = expression.length();
    for (int i = 0; i < len; ++i) {
        if (expression.at(i) == '(') {
            st.push(expression.at(i));
        } else if (expression.at(i) == '{') {
            st.push(expression.at(i));
        } else if (expression.at(i) == '[') {
            st.push(expression.at(i));
        } else if (expression.at(i) == ')') {
            if (st.empty()) {
                return false;
            }
            st.pop();
        } else if (expression.at(i) == '}') {
            if (st.empty()) {
                return false;
            }
            st.pop();
        } else if (expression.at(i) == ']') {
            if (st.empty()) {
                return false;
            }
            st.pop();
        }
    }

    if (st.empty()) {
        return true;
    }

    return false;
}

string infix_postfix(string exp) {
    stack <char> st;
    string ans = "";

    for (auto ch : exp) {
        // if the char is an operand //
        if (isOperand(ch)) {
            ans += ch;
        } else if (ch == '(') { // push closing bracket into stack //
            st.push(ch);
        } else if (ch == ')') {
            // pop the elements until st.top() == '(' //
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop(); // pop the '(' //
        } else {
            // if the character is an operator //
            while (!st.empty() && precedence(ch) <= precedence(st.top())) {
                // pop the character's from stack and add to answer //
                ans += st.top();
                st.pop();
            }

            // otherwise push the operator into stack //
            st.push(ch);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}


int main() {

    string expression =  "({(a+b)} * {(c-d))}";
    if (isParanthesis(expression)) {
        cout << "The Expression Is Paranthesis.\n";
    } else {
        cout << "The Expression Is Not Parenthesis.\n";
    }

    string ans = infix_postfix("a+b*(c^d-e)^(f+g*h)-i");
    cout << ans << endl;  // output : ab(c^d*+e)^(f-gh)*+i-
    return 0;
}