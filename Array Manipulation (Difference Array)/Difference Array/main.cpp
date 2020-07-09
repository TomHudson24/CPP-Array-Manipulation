#include <vector>
#include <iostream>

int main() {
	long int N, K, p, q, sum, i, j, max = 0, x = 0;

	std::cin >> N >> K;
	long int* a = new long int[N + 1]();

	for (i = 0; i < K; i++)
	{
		std::cin >> p >> q >> sum;
		a[p] += sum;
		if ((q + 1) <= N) a[q + 1] -= sum;
	}

	for (i = 1; i <= N; i++)
	{
		x = x + a[i];
		if (max < x) max = x;

	}

	std::cout << max;
	return 0;
}

/*
The below solution works, had to convert all ints to long ints to deal with larger numbers in hackerrank tests. 
Logic taken from https://www.geeksforgeeks.org/difference-array-range-update-query-o1/
I personally added the get largest function.
*/
#if 0
// Creates a diff array D[] for A[] and returns 
// it after filling initial values. 
std::vector<long int> initializeDiffArray(std::vector<long int>& A)
{
	long int n = A.size();

	// We use one extra space because 
	// update(l, r, x) updates D[r+1] 
	std::vector<long int> D(n + 1);

	D[0] = A[0], D[n] = 0;
	for (long int i = 1; i < n; i++)
		D[i] = A[i] - A[i - 1];
	return D;
}

// Does range update 
void update(std::vector<long int>& D, long int l, long int r, long int x)
{
	D[l] += x;
	D[r + 1] -= x;
}

// Prints updated Array 
void printArray(std::vector<long int>& A, std::vector<long int>& D)
{
	for (long int i = 0; i < A.size(); i++) {
		if (i == 0)
			A[i] = D[i];

		// Note that A[0] or D[0] decides 
		// values of rest of the elements. 
		else
			A[i] = D[i] + A[i - 1];

		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
}
void printLargest(std::vector<long int>& arrA, std::vector<long int>& arrD)
{
	for (long int i = 0; i < arrA.size(); i++) {
		if (i == 0)
			arrA[i] = arrD[i];

		// Note that A[0] or D[0] decides 
		// values of rest of the elements. 
		else
			arrA[i] = arrD[i] + arrA[i - 1];
	}
	long int large = arrA[0];
	for (long int i = 0; i < arrA.size(); i++)
	{
		if (arrA[i] > large) {
			large = arrA[i];
		}
	}
	std::cout << large;
}
// Driver Code 
int main()
{
	//how big is the array and the amount of updates
	long int n, m;
	std::cin >> n >> m;

	// Array to be updated 
	std::vector<long int> A(n);

	// Create and fill difference Array 
	std::vector<long int> D = initializeDiffArray(A);

	for (long int i = 0; i < m; i++) {
		long int a, b, k;
		std::cin >> a >> b >> k;
		update(D, (a - 1), (b - 1), k);
	}
	//printArray(A, D);
	printLargest(A, D);
	
	
	return 0;
}
#endif
#if 0
int main()
{
	// Array to be updated 
	std::vector<int> A{ 10, 5, 20, 40 };

	// Create and fill difference Array 
	std::vector<int> D = initializeDiffArray(A);

	// After below update(l, r, x), the 
	// elements should become 20, 15, 20, 40 
	update(D, 0, 1, 10);
	printArray(A, D);

	// After below updates, the 
	// array should become 30, 35, 70, 60 
	update(D, 1, 3, 20);
	update(D, 2, 2, 30);
	printArray(A, D);

	return 0;
}
#endif