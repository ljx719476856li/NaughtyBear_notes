#include <iostream>
using namespace std;
/*
ÍøÒ×»¥Óé´óÅ£´ğ°¸£º https://www.nowcoder.com/discuss/221108?type=all&order=time&pos=&page=1
*/


int main()
{
	int T;
	cin >> T;
	bool* res = new bool[33];
	for (; T; --T) 
	{
		int N;
		cin >> N;
		int* arr = new int[N];
		for (int i = 0; i < 33; ++i)
			res[i] = 0;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
			int sum = 0;
			while (arr[i] != 0) 
			{
				sum += arr[i] & 1;
				arr[i] = arr[i] >> 1;
			}
			res[sum] = 1;
		}
		int sum = 0;
		for (int i = 0; i < 33; ++i)
			sum += res[i];
		cout << sum << endl;
	}
	delete[] res;
}