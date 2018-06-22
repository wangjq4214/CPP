#include "iStack.h"

template<typename element>
iStack<element>::iStack() {
	count = 0;
}

template<typename element>
bool iStack<element>::empty() {
	if (count == 0) {
		return true;
	} else {
		return false;
	}
}

template<typename element>
bool iStack<element>::full() {
	if (count == maxLen) {
		return true;
	} else {
		return false;
	}
}

template<typename element>
bool iStack<element>::get_top(element &x) {
	if (!empty()) {
		x = data[count - 1];
		return true;
	} else {
		return false;
	}
}

template<typename element>
bool iStack<element>::push(element x) {
	if (!full()) {
		data[count++] = x;
		return true;
	} else {
		return false;
	}
}

template <typename element>
bool iStack<element>::pop() {
	if (!empty()) {
		--count;
		return true;
	} else {
		return false;
	}
}
