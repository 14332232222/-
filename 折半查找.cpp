#include<iostream>
#include<stdio.h>
using namespace std;

void zb(int key, int a[], int n)//key表示要找的数，a表示数组，n表示数组元素个数 
{
	int i, high, low, mid;
	int count1 = 0, count = 0;
	low = 0;
	high = n - 1;
	while (high >= low)//保证右下标不小于左下标 
	{
		count++;
		mid = (high + low) / 2;//总的来说变得是中间位置相当于把中间位置移到了key那个数那里，所以mid应该处于循环里面 
		if (key < a[mid])//说明key在a【mid】的左半边 ,那么最右边的high下标就可以在下标mid基础上往左进一个单位了
			high = mid - 1;
		else if (key > a[mid])//说明key在a【mid】的右半边 ,那么最左边的low下标就可以在下标mid基础上往右进一个单位了 
			low = mid + 1;
		if (key == a[mid])
		{
			printf("元素找到了！！！\n一共查找了%d次\n它处于a[%d]位置上\na[%d]=%d\n", count, mid, mid, key);
			count1++;
			break;
		}
	}
	if (count1 == 0)
		printf("元素不存在！！！\n");
}
int main()
{
	int key, n, a[100];
	int i;
	void zb(int key, int a[], int n);//声明定义函数 
	printf("请输入数组元素个数：\n");
	cin >> n;
	printf("请输入（从小到大）所有数组元素：\n");
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	printf("请输入要查找的数：\n");
	cin >> key;
	zb(key, a, n);
	printf("\n");
	return 0;
}