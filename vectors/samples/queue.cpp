#include "queue.h"

	void why_my_console_is_broken::my_queue::push(int k){
		if (this->put.empty()) {
			this->put.push(k);
			this->Max.push(k);
			this->Min.push(k);
		}
		else {
			if (k >= this->Max.top()) {
				this->Max.push(k);
				this->put.push(k);
			}
			else if(k <= this->Min.top()){
				this->Min.push(k);
				this->put.push(k);

			}
			else {
				this->put.push(k);
			}
		}
	}

	void why_my_console_is_broken::my_queue::pop(){
		if (this->pull_out.empty() && this->put.empty()) {
			throw std::exception("Empty queue");
		}
		if (this->pull_out.empty()) {
			while (!this->put.empty()) {
				this->pull_out.push(this->put.top());
				this->put.pop();
			}
			if (this->pull_out.top() == this->Max.top()) {
				this->Max.pop();
			}
			else if(this->pull_out.top() == this->Min.top()){
				this->Min.pop();
			}
			this->pull_out.pop();
		}
		else {
			if (this->pull_out.top() == this->Max.top()) {
				this->Max.pop();
			}
			else if (this->pull_out.top() == this->Min.top()) {
				this->Min.pop();
			}
			this->pull_out.pop();
		}
		

	}

	int why_my_console_is_broken::my_queue::front(){
		int res;
		if (this->pull_out.empty() && this->put.empty()) {
			throw std::exception("Empty queue");
		}
		if (!this->pull_out.empty()) {
			res = this->pull_out.top();
			return res;
		}
		else {
			while (!this->put.empty()) {
				this->pull_out.push(this->put.top());
				this->put.pop();
			}
			res = this->pull_out.top();
			return res;
		}
	}

	int why_my_console_is_broken::my_queue::back(){
		if (this->pull_out.empty() && this->put.empty()) {
			throw std::exception("Empty queue");
		}
		if(!this->put.empty()){
			return this->put.top();
		}
		else {
			while (!this->pull_out.empty()) {
				this->put.push(this->pull_out.top());
				this->pull_out.pop();
			}
			return this->put.top();
		}
	}

	int why_my_console_is_broken::my_queue::find_max() {
		return this->Max.top();
		//if (!this->put.empty()) {
		//	std::stack<int> tmp = this->put;
		//	int max_ = tmp.top();
		//	if (tmp.empty()) {
		//		return max_;
		//	}
		//	while (!tmp.empty()) {
		//		if (max_ < tmp.top()) {
		//			this->pull_out.push(max_);
		//			max_ = tmp.top();
		//			tmp.pop();
		//
		//		}
		//		else {
		//			this->pull_out.push(tmp.top());
		//			tmp.pop();
		//		}
		//	}
		//	while (!this->pull_out.empty()) {
		//		this->pull_out.pop();
		//	}
		//	return max_;
		//}
		//else {
		//	throw std::exception("empty queue doesn't have max");
		//}
	}

	int why_my_console_is_broken::my_queue::find_min(){
		return this->Min.top();
		//if (!this->put.empty()) {
		//	std::stack<int> tmp = this->put;
		//	int min_ = tmp.top();
		//	if (tmp.empty()) {
		//		return min_;
		//	}
		//	while (!tmp.empty()) {
		//		if (min_ > tmp.top()) {
		//			this->pull_out.push(min_);
		//			min_ = tmp.top();
		//			tmp.pop();
		//
		//		}
		//		else {
		//			this->pull_out.push(tmp.top());
		//			tmp.pop();
		//		}
		//	}
		//	while (!this->pull_out.empty()) {
		//		this->pull_out.pop();
		//	}
		//	return min_;
		//}
		//else {
		//	throw std::exception("empty queue doesn't have min");
		//}
	}


