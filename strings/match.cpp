#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

// Validate nested  opening and closing sequences of brackets and parenthesis. 
// The point of the algorithm is in the introduction of a stack to avoid any form of exponential reccursion.
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

    std::for_each(
        strs.begin(), 
        strs.end(), 
        [](const auto& s) { cout << s << ":" << (check(s) ? "OK" : "KO") << endl; }
    );
    return 0;
}

