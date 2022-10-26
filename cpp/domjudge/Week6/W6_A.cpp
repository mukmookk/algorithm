#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> stack1;      // 막대 1
stack<int> stack2;      // 막대 2
stack<int> stack3;      // 막대 3
int N, K;
int result;
int initial;
int cnt = 0;
int ext;

int TowerOfHanoi(int num, stack<int> *from, stack<int> *by, stack<int> *to)
{
	int ret;

	if (ext == 1)
		return 1;
	if (num == 1 && ext == 0)
	{
		to->push(from->top());
		from->pop();
		cnt++;
		if (cnt == K)
		{
			ext = 1;
			if (stack2.size() == 0)
			{
				printf("0\n");
				return 1;
			}
			while (stack2.size() != 0)
			{
				printf("%d ", stack2.top());
				stack2.pop();
			}
			printf("\n");
			return 1;
		}
		return 0;
	}
	TowerOfHanoi(num - 1, from, to, by);
	if (ext == 1)
		return 1;

	to->push(from->top());
	from->pop();
	cnt++;

	if (cnt == K)
	{			
		ext = 1;
		if (stack2.size() == 0)
		{
			printf("0\n");
			return 1;
		}
		while (stack2.size() != 0)
		{
			printf("%d ", stack2.top());
			stack2.pop();
		}
		printf("\n");
		return 1;
	}
	TowerOfHanoi(num - 1, by, from, to);
	return 0;
}

int main()
{
	int T, temp;
	cin >> T;

	while (T)
	{
		cin >> N >> K;

		stack1 = stack<int>();
		stack2 = stack<int>();
		stack3 = stack<int>();
		cnt = 0;
		ext = 0;
		temp = N;
		while (temp)
		{
			stack1.push(temp);
			temp--;
		}

		TowerOfHanoi(N, &stack1, &stack2, &stack3);
		T--;
	}
}