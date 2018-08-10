//tip4 合并两有序数组，并且为排序数组 默认数组A有足够多的空间给B ,初始A元素m个，B元素n个
void mergeSortArray(int A[], int m, int B[], int n)
{
	int index = m + n - 1;
	while (m > 0 && n > 0)
	{
		if (A[m - 1] > B[n - 1])
		{
			A[index] = A[m - 1];
			--m;
		}
		else
		{
			A[index] = B[n - 1];
			--n;
		}
		--index;
	}
	while (n > 0)
	{
		A[index] = B[n - 1];
		--n;
		--index;
	}
}