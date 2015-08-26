#pragma once

template <class InputIterator, class Function>
Function my_generate(InputIterator first, InputIterator last, Function fn) {
	while (first != last) {
		*first = fn();
		++first;
	}
	return fn;
}

template <class InputIterator, class Function>
Function my_for_each(InputIterator first, InputIterator last, Function fn) {
	while (first != last) {
		fn(*first);
		++first;
	}
	return fn;
}

template <class InputIterator, class Data>
int my_count(InputIterator first, InputIterator last, Data d) {
	int counter = 0;
	while (first != last) {
		if (*first == d)
			counter++;
		++first;
	}
	return counter;
}

template <class InputIterator>
void my_reverse(InputIterator first, InputIterator last) {
	int counter = 0;
	last--;
	while (first <= last) {
		auto tmp = *first;
		*first = *last;
		*last = tmp;
		++first;
		--last;
	}
}

template <class InputIterator, class Function>
void my_sort(InputIterator left, InputIterator right, Function comparator) {
	InputIterator i = left, j = right;
	int diff = ((int)right - (int)left) / sizeof(*left);
	int midPoint = diff / 2;
	//cout << "diff: " << diff << endl;
	InputIterator pivot = (InputIterator)((int)left + midPoint*sizeof(*left));
	//cout << "left: " << (int)left << " right: " << (int)right << " pivot: " << (int)pivot << endl;
	//cout << "left: " << *left << " right: " << *right << " pivot: " << *pivot << endl;
	//return;
	auto tmp = *i;

	/* partition */
	while (i <= j) {
		while (!comparator(*pivot, *i))
			i++;
		while (!comparator(*j, *pivot))
			j--;
		if (i <= j) {
			tmp = *i;
			*i = *j;
			*j = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		my_sort(left, j, comparator);
	if (i < right)
		my_sort(i, right, comparator);
}