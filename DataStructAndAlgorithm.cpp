#define _CRT_SECURE_NO_WARNINGS
#include "DataStructAndAlgorithm.h"
#include <string>
using namespace std;

void bubble(int *arr, int n) {
	bool flag = false;
	for (int i = n; i > 0; i--)
	{
		for (int j = 1; j <  i; j++)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
				flag = true;
			}
		}
		if (!flag)
		{
			break;
		}
		flag = false;
	}
}


void insert_sort(int *arr, int n)
{
	int j;
	for (int i = 1; i < n; i++)
	{
		int temp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > temp; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}

void shell_sort(int *arr, int n)
{
	int j;
	for (int D = n / 2; D > 0; D /= 2)
	{
		for (int i = 1; i < n; i+=D)
		{
			int temp = arr[i];
			for (j = i; j > 0 && arr[j - D] > temp; j-= D)
			{
				arr[j] = arr[j - D];
			}
			arr[j] = temp;
		}
	}
}

void merge(int *arr, int *temp, int L, int R, int RightEnd)
{
	int length = RightEnd - L + 1;
	int Ti = L, LeftEnd = R - 1;
	while(L <= LeftEnd && R <= RightEnd)
	{
		if (arr[L] <= arr[R])
		{
 			temp[Ti++] = arr[L ++];
		}
		else
		{
			temp[Ti++] = arr[R ++];
		}
	}
	while (L <= LeftEnd)
	{
		temp[Ti++] = arr[L++];
	}
	while (R <= RightEnd)
	{
		temp[R++] = arr[R++];
	}
	for (int i = 0; i < length; i++ , RightEnd --)
	{
		arr[RightEnd] = temp[RightEnd];
	}
}


void merge_sort(int *arr , int *temp, int start, int end)
{
	if (start < end)
	{
		int center = (end + start) / 2;
		merge_sort(arr,temp, start, center);
		merge_sort(arr,temp,center + 1, end);
		merge(arr,temp, start, center + 1, end);
	} 
}

int median_three(int *arr,int left,int right)
{
	int center = (left + right) / 2;
	if (arr[left] > arr[center])
	{
		swap(arr[left], arr[center]);
	}
	if (arr[left] > arr[right])
	{
		swap(arr[left], arr[right]);
	}
	if (arr[center] > arr[right])
	{
		swap(arr[center], arr[right]);
	}
	swap(arr[center], arr[right - 1]);
	return arr[right - 1];
}

int cutoff = 3;

void quick_sort(int *arr,int left , int right)
{
	if (cutoff < right - left)
	{
		int pivot = median_three(arr,left,right);
		int i = left;
		int j = right - 1;
		while (arr[++i] <= pivot) {}
		while (arr[--j] >= pivot) {}
		if (i < j) {
			swap(arr[i], arr[j]);
		}
		swap(arr[i], arr[right - 1]);
		quick_sort(arr, left, i - 1);
		quick_sort(arr, i + 1, right);
	}
	else
	{
		insert_sort(arr + left,right - left + 1);
	}
}

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int n;
	cin >> n;
	int *arr = new int[n];
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr[i] = temp;
	}
	int *temp_arr = new int[n];
	quick_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	delete[] temp_arr;
	return 0;
}