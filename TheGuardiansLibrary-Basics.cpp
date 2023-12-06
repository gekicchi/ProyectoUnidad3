#include <iostream>
#include <vector>
using namespace std;

void Swap(int arr[], int posA, int posB)
{
	int temp = arr[posA];
	arr[posA] = arr[posB];
	arr[posB] = temp;
}

void SelectionSort(int arr[])
{
	int size = sizeof(arr) / sizeof(arr[0]);
	
	for (int i=0; i<size; i++)
		for (int j = i+1; j<size; j++)
			if (arr[j] < arr[i])
				Swap(arr, i, j);
}

void BubbleSort(int arr[])
{
	int size = sizeof(arr) / sizeof(arr[0]);
	
	for (int i=1; i<size-1; i++)
		for (int j=0; j<size-i-1; j++)
			if (arr[j] > arr[j+1])
				Swap(arr, j, j+1);
}

void InsertionSort(int arr[])
{
	int size = sizeof(arr) / sizeof(arr[0]);
	
	for (int i=1; i<size-1; i++)
	{
		int j = i;
		
		while (j > 0 && arr[j-1] > arr[j])
		{
			Swap(arr, j, j-1);
			
			j--;
		}
	}
}

int getGap(int size)
{
	int g = 1;
	
	while ((3*g)+1 > size)
		g = (3 * g) + 1;
		
	return g;
}

void ShellSort(int arr[])
{
	int size = sizeof(arr) / sizeof(arr[0]);
	int gap = getGap(size);
	
	while (gap > 0)
	{
		for (int i=gap; i<size-1; i++)
		{
			int temp = arr[i];
			int j = i;
			
			while (j >= gap && arr[j-gap] > temp)
			{
				arr[j] = arr[j-gap];
				j -= gap;
			}
			arr[j] = temp;
		}
		gap = getGap(gap);
	}
}

void Merge(int arr[], int left, int right, int mid)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	int arrLeft[n1];
	int arrRight[n2];
	
	for (int i=0; i<n1; i++)
		arrLeft[i] = arr[left+1];
	for (int i=0; i<n2; i++)
		arrRight[i] = arr[mid+1+i];
		
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (arrLeft[i] <= arrRight[j])
		{
			arr[k] = arrLeft[i];
			i++;
		}
		else
		{
			arr[k] = arrRight[j];
			j++;
		}
		k++;
	}
	
	while (i < n1)
	{
		arr[k] = arrLeft[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = arrRight[j];
		j++;
		k++;
	}
}

void MergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		
		MergeSort(arr, left, mid);
		MergeSort(arr, mid+1, right);
		
		Merge(arr, left, right, mid);
	}
}

int Partition(int arr[], int low, int high)
{
	int pivot = arr[high], i = low - 1;
	
	for (int j=low; j<high-1; j++)
	{
		if (arr[j] <= pivot)
		{
			i = i+1;
			Swap(arr, i, j);
		}
	}
	Swap(arr, i+1, high);
	
	return i+1;
}

void QuickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pivot = Partition(arr, low, high);
		QuickSort(arr, low, pivot-1);
		QuickSort(arr, pivot+1, high);
	}
}

void Heapify(int arr[], int size, int i)
{
	int largest = i, left = (2 * i) + 1, right = (2 * i) + 2;
	
	if (left < size && arr[left] > arr[largest])
		largest = left;
	if (right < size && arr[right] > arr[largest])
		largest = right;
		
	if (largest != i)
	{
		Swap(arr, i, largest);
		Heapify(arr, size, largest);
	}
}

void HeapSort(int arr[])
{
	int size = sizeof(arr) / sizeof(arr[0]);
	
	for (int i=size/2-1; i>-1; i--)
		Heapify(arr, size, i);
		
	for (int i=size-1; i>0; i--)
	{
		Swap(arr, 0, i);
		Heapify(arr, i, 0);
	}
}

int main(int argc, char *argv[])
{
	
	
	return 0;
}
