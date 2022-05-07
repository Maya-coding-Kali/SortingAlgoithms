// SortingAlgoithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<algorithm>
#include<array>
#include<vector>
#include<map>
void MainMenu();
void InsertionSort(int* arr, int n);
int* RandomGeno();
void BubbleSort(int* arr, int n);
void tag_sort(int collection[], int tag[], int size);
int shellSort(int arr[], int N);
void IndexSort(int* arr, int N);
void BucketSort(int arr[], int N);
int main()
{

	std::cout << "\nWelcome to the sorting algorithm exraveganze\n";
	MainMenu();
}
void MainMenu()
{
	int choice = 0;
	std::string menu = "1. Insertion sort \n2. Bubble sort \n3. Tag sort \n4. Shell sort with distance of 3	\n5. Index sort	\n6. Bucket sort(Radix sort) \n7. Quick sort \n8. Merge sort \n9. Heap sort\n";
	std::string yC = "You chose ";
	std::cout << menu;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		std::cout << yC << "Insertion sort\n";
		InsertionSort(RandomGeno(), 20);
		break;
	case 2:
		std::cout << yC << "Bubble sort\n";
		BubbleSort(RandomGeno(), 20);
		break;
	case 3:
		std::cout << yC << "Tag sort\n";
		int tagArray[20];
		for (int i = 0; i < 20; ++i)
		{
			tagArray[i] = i;
		}
		tag_sort(RandomGeno(), tagArray, 20);
		break;
	case 4:
		std::cout << yC << "Shell sort with distance of 3\n";
		shellSort(RandomGeno(), 20);
		break;
	case 5:
		std::cout << yC << "Index sort\n";
		IndexSort(RandomGeno(), 20);
		break;
	case 6:
		std::cout << yC << "Bucket sort(Radix sort)\n";
		BucketSort(RandomGeno(), 20);
		break;
	case 7:
		std::cout << yC << "Quick sort\n";
		
		break;
	case 8:
		std::cout << yC << "Merge sort\n";

		break;
	case 9:
		std::cout << yC << "Heap sort\n";

		break;
	}
}
int* RandomGeno()
{
	static int randNumbers[] = { 99,5,1,44,20, 15,88,77,41,25, 36,42,81,96,12, 8,66,2,11,432 };
	for (auto i : randNumbers)
	{
		std::cout << i << ", ";
	}
	std::cout << "\n";
	return randNumbers;
}
void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << ", ";

	}
	std::cout << '\n';
}
void InsertionSort(int* arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	print(arr, n);

}
void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	print(arr, n);
}
void tag_sort(int collection[], int tag[], int size)
{
	//Loop controlling variables
	int i = 0;
	int j = 0;
	//used to swap tag value
	int temp = 0;
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (collection[tag[i]] > collection[tag[j]])
			{
				//When need to swap the value of tag element
				temp = tag[i];
				tag[i] = tag[j];
				tag[j] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		printf("  %d", collection[tag[i]]);
	}
}
int shellSort(int arr[], int N)
{
	for (int gap = 3; gap > 0; gap /= 2)
	{
		for (int i = gap; i < N; i += 1)
		{
			//sort sub lists created by applying gap 
			int temp = arr[i];

			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			arr[j] = temp;
		}
	}
	print(arr, N);
	return 0;
}
void IndexSort(int* arr, int N)
{
	int newArr[445];
	for (int i = 0; i < 445; i++)
	{
		newArr[i] = -1;
	}
	for (int i = 0; i < N; i++)
	{
		newArr[arr[i]] = arr[i];
	}


	for (int i = 0; i < 445; i++)
	{
		if (newArr[i] != -1)
		{
			std::cout << newArr[i] << "\n";

		}
	}
	std::cout << "\n";
}
void BucketSort(int arr[], int N)
{
	int newArray[20];
	int Bucket[10][10];
	int counter = 0;
	int digit = 1;
	
	for (int i = 0; i < 20; i++)
	{
		newArray[i] = arr[i];

	}
	while (counter < 3)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				Bucket[i][j] = -1;
			}
		}
		for (int i = 0; i < 20; i++)
		{
			int bucketIndex = (newArray[i] / digit) % 10;
			Bucket[bucketIndex][(newArray[i] / (digit * 10)) % 10] = newArray[i];
		}
		int newCount = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (Bucket[j][i] != -1)
				{
					newArray[newCount++] = Bucket[j][i];
					
				}
			}
		}
		digit *= 10;
		++counter;
	}
	std::cout << "\n";
	for (int i = 0; i < 20; i++)
	{
		std::cout << newArray[i] << ", ";
	}
	////i want to find the ones position and sort the array based on that
	/*int newArray[20];
	int NewNewArray[20];
	int digit = 1;
	for (int i = 0; i < N; i++)
	{
		newArray[i] = arr[i];
		NewNewArray[i] = newArray[i];
	}
	int Bucket[10][20];
	int cont = 0;
	while (cont < 3)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < N; j++)
			{

				Bucket[i][j] = -1;
			}
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if ((newArray[j]/digit) % 10 == i)
				{
					Bucket[i][j] = newArray[j];
				}
			}
		}
		int counter = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < N; j++)
			{

				if (Bucket[i][j] != -1)
				{
					newArray[counter] = Bucket[i][j];
					++counter;
				}
			}
		}
		++cont;
		digit *= 10;
	}
		for (int i = 0; i < N; i++)
		{
			std::cout<<newArray[i]<<'\n';
		}
*/

}
void QuickSort(int arr[], int leftmost, int rightmost)
{
	std::vector<int> myVect;
	for (int i = 0; i < 20; i++)
	{
		myVect[i] = arr[i];
	}
	if (myVect.size() < 1)
	{
		return;
	}

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
