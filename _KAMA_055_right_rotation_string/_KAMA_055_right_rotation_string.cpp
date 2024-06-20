#include <iostream>
#include<string>

using namespace std;

string reverse_string(string s, int left, int right)
{
	while (left <= right)
	{
		char temp = s[left];
		s[left] = s[right];
		s[right] = temp;

		right--;
		left++;
	}

	return s;
}

int main()
{
	std::cout << "Hello World!\n";

	string s;
	int n;

	cout << "n = ";
	cin >> n;
	cout << "s = ";
	cin >> s;

	s = reverse_string(s, 0, s.size() - 1);
	s = reverse_string(s, 0, n - 1);
	s = reverse_string(s, n, s.size() - 1);

	cout << "NEW s = " << s << endl;

	return 0;
}
