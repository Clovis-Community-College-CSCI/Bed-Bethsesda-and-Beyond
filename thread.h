#include "/public/read.h"
#include <iterator>
#include <vector>
#include <atomic>
#include <thread>
#include <mutex>
#include <queue>
#include <unistd.h>
using namespace std;

class ThreadSafe_Deque {
	mutex my_mutex;
	deque<string> my_deq;
public:
	ThreadSafe_Deque() {}
	ThreadSafe_Deque(const ThreadSafe_Deque &rh) = delete;
	void push(string s) {
		lock_guard lg(my_mutex);
		my_deq.push_back(s);
	}
	[[nodiscard]] string pop() {
		lock_guard lg(my_mutex);
		string retval = my_deq.front();
		my_deq.pop_front();
		return retval;
	}
	[[nodiscard]] size_t size() {
		lock_guard lg(my_mutex);
		return my_deq.size();
	}
};

inline ThreadSafe_Deque tsq;

class threads {

public:

	void mouser() {
		while(true) {
			usleep(uint32_t(rand()%10+1) * 1'000'000);
			tsq.push("MOUSE X: " + to_string(rand()%100) + " Y: " + to_string(rand()%100));
		}
	}
	void keyboard_commands() {
		while(true) {
			usleep(uint32_t(rand()%10+1) * 1'000'000);
			if (rand()%2) {
				tsq.push("Keyboard Command: Attack");
			}
			else {
				tsq.push("Keyboard Command: Defend");
			}
		}
	}
	void network_commands() {
		while(true) {
			usleep(uint32_t(rand()%10+1) * 1'000'000);
			tsq.push("Your life is now: " + to_string(rand()%100+1));
		}
	}

};
