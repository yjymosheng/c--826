#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack <int> s;
        int index = 0 ;

        for (auto ele : pushed) {
            s.push(ele);
            while (!s.empty()&& s.top() == popped[index]) {
                s.pop();
                index++;
            }
        }

        return s.empty() ;
    }
};

int main() {
    Solution sol;

    vector<pair<vector<int>, vector<int> > > tests = {
        {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}}, // 顺序输出
        {{1, 2, 3, 4, 5}, {2, 1, 4, 3, 5}}, // 合法混洗
        {{1, 2, 3, 4, 5}, {3, 1, 2, 5, 4}}, // 不合法混洗
        {{1}, {1}}, // 单元素
        {{}, {}}, // 空序列
        {{1, 2, 3}, {3, 1, 2}} ,// 最小禁形 312
        {{1,2,3,4,5}, {4,3,5,1,2}}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        auto &[pushed, popped] = tests[i];
        bool result = sol.validateStackSequences(pushed, popped);
        cout << "Test case " << i + 1 << ": " << (result ? "Valid" : "Invalid") << endl;
    }
}
