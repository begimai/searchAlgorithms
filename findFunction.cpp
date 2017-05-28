#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main() {
	int a[] = {4, 1, 5, 3};
	auto p = find(begin(a), end(a), 1);
	if(p != end(a)) {
		cout << *p << " found" << endl;
	} 
	else {
		cout << 1 << " not found" << endl;
	}
	
	vector<int> b = {4, 1, 5, 3};
	auto q = find(begin(b), end(b), 3);
	
	if(q != end(b)) {
		cout << *q << " found" << endl;
	} 
	else {
		cout << 10 << " not found" << endl;
	}
	
	list<int> c = {4, 1, 5, 3};
	auto r = find(begin(c), end(c), 10);
	
	if(r != end(c)) {
		cout << *q << " found" << endl;
	} 
	else {
		cout << 10 << " not found" << endl;
	}
	return 0;
}
