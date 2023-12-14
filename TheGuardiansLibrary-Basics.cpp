#include <cstdlib>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <random>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <chrono>
#include <unordered_map>
using namespace std;


vector<int> CreateArray(int size, int mode);
double GetTimeFromAlg(vector<int>& arr, int size, int option);
void Swap(int arr[], int posA, int posB);

void SelectionSort(vector<int>& arr);
void BubbleSort(vector<int>& arr);
void InsertionSort(vector<int>& arr);
int getGap(int size);
void ShellSort(vector<int>& arr);
void Merge(vector<int>& arr, int left, int right, int mid);
void MergeSort(vector<int>& arr, int left, int right);
int Partition(vector<int>& arr, int low, int high);
void QuickSort(vector<int>& arr, int low, int high);
void Heapify(vector<int>& arr, int size, int i);
void HeapSort(vector<int>& arr);

int main(int argc, char *argv[])
{
	srand(time(NULL));
	int electionA, electionB;
	int size;
	vector<int> OriginalArray;
	vector<int> SelectionArray, BubbleArray, InsertionArray, ShellArray, MergeArray, QuickArray, HeapArray;
	unordered_map<string, double> times;
	
	do{
		cout << "----- The Guardians Library-Basics -----" << endl;
		cout << "[1] Probar Colas de Espera" << endl << "[2] Probar Trazabilidad de Objetos" << endl << "[3] Probar Eventos" << endl << "[4] Salir" << endl;
		do{
			cout << "Eleccion: ";
			cin >> electionA;
		} while (electionA < 1 || electionA > 4);
		
		if (electionA != 4)
		{
			cout << endl << "[1] Aleatorio sin Repeticion" << endl << "[2] Aleatorio con Repeticion" << endl << "[3] Casi Ordenado" << endl << "[4] Inversamente Ordenado" << endl;
			do{
				cout << "Eleccion: ";
				cin >> electionB;
			} while (electionB < 1 || electionB > 4);
		}
		
		switch (electionA)
		{
			case 1: // colas de espera
				size = rand()%10000 + 100000;
				OriginalArray = CreateArray(size, electionB);
				break;
				
			case 2: // trazabilidad de objetos
				size = rand()%500 + 1000;
				size *= 15;
				OriginalArray = CreateArray(size, electionB);
				break;
				
			case 3: // eventos
				size = rand()%20000 + 60000;
				OriginalArray = CreateArray(size, electionB);
				break;
				
		}
		
		if (electionA != 4)
		{
			SelectionArray.assign(OriginalArray.begin(), OriginalArray.end());
			BubbleArray.assign(OriginalArray.begin(), OriginalArray.end());
			InsertionArray.assign(OriginalArray.begin(), OriginalArray.end());
			ShellArray.assign(OriginalArray.begin(), OriginalArray.end());
			MergeArray.assign(OriginalArray.begin(), OriginalArray.end());
			QuickArray.assign(OriginalArray.begin(), OriginalArray.end());
			HeapArray.assign(OriginalArray.begin(), OriginalArray.end());
			
			times["Selection Sort"] = GetTimeFromAlg(SelectionArray, size, 1);
			times["Bubble Sort"] = GetTimeFromAlg(BubbleArray, size, 2);
			times["Insertion Sort"] = GetTimeFromAlg(InsertionArray, size, 3);
			times["Shell Sort"] = GetTimeFromAlg(ShellArray, size, 4);
			times["Merge Sort"] = GetTimeFromAlg(MergeArray, size, 5);
			times["Quick Sort"] = GetTimeFromAlg(QuickArray, size, 6);
			times["Heap Sort"] = GetTimeFromAlg(HeapArray, size, 7);
			
			cout << endl;
			for (const auto& pair : times)
			{
				const string& key = pair.first;
				double value = pair.second;
				
				cout << key << ": " << fixed << value << setprecision(9) << endl;
			}
			cout << endl;
		}
		
	} while (electionA != 4);
	
	return 0;
}

vector<int> CreateArray(int size, int mode)
{
	vector<int> OriginalArray;
	int random;
	
	cout << "Tamano de Arreglos: " << size << endl;
	
	switch (mode)
	{
		case 1: // random sin repeticion
			for (int i=0; i<size; i++)
			{
			}
			break;
			
		case 2: // random con repeticion
			for (int i=0; i<size; i++)
			{
				random = rand()%size;
				
				OriginalArray.push_back(random);
			}
			break;
			
		case 3: // casi ordenado
			for (int i=0; i<size; i++)
			{
				random = rand()%(i+3) + i;
				
				OriginalArray.push_back(random);
			}
			break;
			
		case 4: // a la inversa
			random = size;
			for (int i=0; i<size; i++)
			{
				OriginalArray.push_back(random);
				random--;
			}
			break;
	}
	
	return OriginalArray;
}

// facilita el cambio de valores dentro de los arreglos
void Swap(vector<int>& arr, int posA, int posB)
{
	int temp = arr[posA];
	arr[posA] = arr[posB];
	arr[posB] = temp;
}

double GetTimeFromAlg(vector<int>& arr, int size, int option)
{
	time_t start, end;
	double timeTaken;
	
	time(&start);
	ios_base::sync_with_stdio(false);
	
	switch (option)
	{
		case 1:
			SelectionSort(arr);
			break;
			
		case 2:
			BubbleSort(arr);
			break;
			
		case 3:
			InsertionSort(arr);
			break;
			
		case 4:
			ShellSort(arr);
			break;
			
		case 5:
			MergeSort(arr, 0, size-1);
			break;
			
		case 6:
			QuickSort(arr, 0, size-1);
			break;
			
		case 7:
			HeapSort(arr);
			break;
	}
	
	time(&end);
	timeTaken = double(end - start);
	
	return timeTaken;
}

void SelectionSort(vector<int>& arr)
{
	int size = arr.size();
	
	for (int i=0; i<size; i++)
		for (int j = i+1; j<size; j++)
			if (arr[j] < arr[i])
				Swap(arr, i, j);
}

void BubbleSort(vector<int>& arr)
{
	int size = arr.size();
	
	for (int i=1; i<size-1; i++)
		for (int j=0; j<size-i-1; j++)
			if (arr[j] > arr[j+1])
				Swap(arr, j, j+1);
}

void InsertionSort(vector<int>& arr)
{
	int size = arr.size();
	
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
	
	while ((3*g)+1 < size)
		g = (3 * g) + 1;
		
	return g;
}

void ShellSort(vector<int>& arr)
{
	int size = arr.size();
	int gap = getGap(size);
	
	while (gap > 1)
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

void Merge(vector<int>& arr, int left, int right, int mid)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	vector<int> arrLeft(n1);
	vector<int> arrRight(n2);
	
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

void MergeSort(vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		
		MergeSort(arr, left, mid);
		MergeSort(arr, mid+1, right);
		
		Merge(arr, left, right, mid);
	}
}

int Partition(vector<int>& arr, int low, int high)
{
	int pivot = arr[high], i = low - 1;
	
	for (int j=low; j<=high-1; j++)
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

void QuickSort(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int pivot = Partition(arr, low, high);
		QuickSort(arr, low, pivot-1);
		QuickSort(arr, pivot+1, high);
	}
}

void Heapify(vector<int>& arr, int size, int i)
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

void HeapSort(vector<int>& arr)
{
	int size = arr.size();
	
	for (int i=size/2-1; i>-1; i--)
		Heapify(arr, size, i);
		
	for (int i=size-1; i>0; i--)
	{
		Swap(arr, 0, i);
		Heapify(arr, i, 0);
	}
}
