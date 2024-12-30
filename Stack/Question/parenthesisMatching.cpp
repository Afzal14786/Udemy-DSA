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

int postfix_evaluation(string postfix) {
    // take a stack of integers //
    stack<int> st;
    int x1, x2, ans;

    for (auto num : postfix) {
        if (isOperand(num)) {
            st.push(num - '0');
        } else {
            x2 = st.top(); // right hand side number //
            st.pop();
            x1 = st.top(); // left hand side number //
            st.pop();

            switch(num) {
                case '+' : 
                    ans = x1 + x2;
                    break;
                case '-' :
                    ans = x1 - x2;
                    break;
                case '*' :
                    ans = x1 * x2;
                    break;
                case '/' :
                    ans = x1 / x2;
                    break;
            }
            st.push(ans);
        }
    }

    return st.top();
}


int main() {

    string expression =  "({(a+b)} * {(c-d))}";
    if (isParanthesis(expression)) {
        cout << "The Expression Is Paranthesis.\n";
    } else {
        cout << "The Expression Is Not Parenthesis.\n";
    }

    string ans = infix_postfix("3*5+6/2-4");
    cout << ans << endl;  // output : ab(c^d*+e)^(f-gh)*+i-

    cout << postfix_evaluation(ans) << endl;
    return 0;
}

/**
 * There is some minor mistakes in the above infix to postfix convirsion function
 * The function cannot ignore the opening and closing brackets, it must ignore the brackates and just convert operand and operators into the postfix .
 * 
 * Needs more correction and improvement in this code section 
 */