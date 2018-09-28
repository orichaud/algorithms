#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;

bool check(const string& s) {
	static map<char, char> closings {
		{ '(', ')' },
		{ '[', ']' }
	};
	
	deque<char> stack;
	for(auto c: s) {
		if(!stack.empty() && closings[stack.front()] == c) {
			stack.pop_front();
		} else {
			stack.push_front(c);
		}
	}
    return stack.empty();
}

int main() {
    vector<string> strs = {
        "33",
		"[[[[[",
        "[)(]",
        "[()]",
        "()[]",
        "(()[])",
        "([)]",
        "((",
        "([])([][])",
        "(])()",
        "([[]()[]])([[]()[]])([[]()[]])([[]()[]])([[]()[]])"
    };
    for(auto s: strs) {
        cout << s << ":";
        cout << (check(s) ? "OK" : "KO") << endl;
    }
    return 0;
}

