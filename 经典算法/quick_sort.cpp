//快排序
void quickSort_(int a[], int left, int right, int size)
{
	if (left >= right)/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
	{
		return;
	}
	int i = left, j = right;
	int key = a[left];
	while (i < j)
	{
		while (a[j] >= key&&i < j) j--;
		while (a[i] <= key&&i < j) i++;
		swap(a[i], a[j]);
		for (int i = 0; i<size; i++)
			cout << a[i] << " ";
		cout << endl;
		cout << endl;
	}
	swap(a[left], a[j]);
	for (int i = 0; i<size; i++)
		cout << a[i] << " ";
	cout << endl;
	quickSort_(a, left,i-1 , size);
	quickSort_(a, i+1,right , size);
	
}
