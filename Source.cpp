#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include "Timer.h"
#define MULTI
#include "Set.h"

int main()
{
	setlocale(0, "rus");
	{
		Timer timer(__FUNCTION__);
		Set<int> st;
		int root = 20;
		st.insert(root);

		for (int i = root - 1; i >= 0; i--)
		{
			st.insert(i);
		}
		for (size_t i = root + 1; i < 2 * root; i++)
		{
			st.insert(i);
		}

	}
	cout << endl;
	system("pause");
	return 0;
}

