#include <stack>
#include <stdio.h>
#include <cstring>
bool paren(const char exp[], int lo, int hi) {
    std::stack<char> S;
    char top;

    for (int i = lo; i <= hi; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') S.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (S.empty()) return false;
            top = S.top();
            S.pop();
            switch (top) {
                case '(': if (exp[i] != ')') return false; break;
                case '{': if (exp[i] != '}') return false; break;
                case '[': if (exp[i] != ']') return false; break;
                default: return false;
            }
        }
    }
    return S.empty();
}

int main() {
    const char* tests[] = {
        "()",          // true
        "([]{})",      // true
        "([)]",        // false
        "((()))",      // true
        "({[)]})",     // false
        "",            // true (empty)
        "((()[]){})"   // true
    };

    int n = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < n; i++) {
        printf("Test %d: %s -> %s\n", i+1, tests[i],
               paren(tests[i], 0, (int)strlen(tests[i])-1) ? "matched" : "not matched");
    }
}
