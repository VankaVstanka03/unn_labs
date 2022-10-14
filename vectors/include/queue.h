#pragma once
#include <stack>

namespace why_my_console_is_broken {
	class my_queue {
	public:
		std::stack<int> put;
		std::stack<int> pull_out;


		void push(int k);
		void pop();
		int front();
		int back();
		int find_max();
		int find_min();
	};
}