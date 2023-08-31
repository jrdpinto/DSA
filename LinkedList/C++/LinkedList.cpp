#include "LinkedList.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;

	{
		LinkedList<int> testList(1);
		testList.append(2);
		testList.append(3);
		testList.append(4);
		testList.append(5);
	}

	return 0;
}
