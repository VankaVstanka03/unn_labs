#pragma once
#include <stack>

namespace why_my_console_is_broken {
	class my_queue {
	public:
		std::stack<int> put;
		std::stack<int> pull_out;
		std::stack<int> Max;
		std::stack<int> Min;

	
		void push(int k);
		void pop();
		int front();
		int back();
		int find_max();
		int find_min();
	};
}