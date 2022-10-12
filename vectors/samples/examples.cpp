#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <locale>
#include <Windows.h>

std::string Str_(std::string sentence);

std::string Str_(std::string sentence) {
	std::stack<char> res;
	int count_of_square = 0;
	int count_of_figure = 0;
	int count_of_round = 0;
	for (int i = 0; i < sentence.size(); i++) {
		if (sentence[i] == '(' || sentence[i] == ')' || sentence[i] == '{' || sentence[i] == '}' || sentence[i] == '[' || sentence[i] == ']') {
			res.push(sentence[i]);
		}
	}
	while (!res.empty()) {
		if (res.top() == '}') {
			count_of_figure++;
			res.pop();
			if (!res.empty()) {
				if (res.top() == '[' || res.top() == '(') {
					return "Wrong sentence";
				}
			}
			else {
				return "Wrong sentence";
			}
		}
		else if (res.top() == ')') {
			count_of_round++;
			res.pop();
			if (!res.empty()) {
				if (res.top() == '[' || res.top() == '{') {
					return "Wrong sentence";
				}
			}
			else {
				return "Wrong sentence";
			}
		}
		else if (res.top() == ']') {
			count_of_square++;
			res.pop();
			if (!res.empty()) {
				if (res.top() == '(' || res.top() == '{') {
					return "Wrong sentence";
				}
			}
			else {
				return "Wrong sentence";
			}
		}
		else if (res.top() == '(') {
			count_of_round--;
			res.pop();
		}
		else if (res.top() == '[') {
			count_of_square--;
			res.pop();
		}
		else if (res.top() == '{') {
			count_of_figure--;
			res.pop();
		}

	}
	if (count_of_square == 0 && count_of_round == 0 && count_of_figure == 0) {
		return "Correctly";
	}
	else {
		return "Wrong sentence";
	}
}

int main(int argc, char *argv) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string user_input;
	//user_input = argv;
	for (int i = 0; i < argc; i++) {
		user_input += argv[i];
		std::cout << "Argument " << i << " : " << argv[i] << std::endl;
		//std::cout << "\n";
		//std::cout << Str_(user_input) << std::endl;
	}
	//std::cin >> user_input;
	//std::cout << "\n" << user_input << std::endl;
	std::cout << Str_(user_input) << std::endl;

	return 0;
}