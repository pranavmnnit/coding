#include <iostream>
using namespace std;

int a = 1;
void permute(string str, int size, int level=0)
{
	if (level == size-1) {
		cout << a++ << ":" << str << endl;
	}
	for (int i=level; i<size; i++) {
		str[level] = str[i];
		permute(str, size, level+1);
	}
}

int main()
{
	string str("abcd");
	permute(str, str.size());
	return 0;
}
