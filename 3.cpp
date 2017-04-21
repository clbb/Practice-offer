#include<iostream>
using namespace std;

void destroy(int** arr,int col)
{
	for(int i = 0; i<col; ++i)
		delete []arr[i];
	delete []arr;
}

bool findinMatrix(int** a,int key,int col,int row);
void innum()
{
	int col;
	int row;
	int tmp;
	cin>>col;
	if(col <= 0)
		return;
	cin>>row;
	if(row <= 0)
		return;
	int** arr= new int*[col];

	for(int i = 0 ;i<col; ++i)
	{
		arr[i] = new int[row];
		memset(arr[i],0,sizeof(int));
	}
	
	for(int i = 0; i<col; i++)
	{
		for(int j = 0; j<row; ++j)
		{
			cin>>tmp;
			*(*(arr+i)+j)  = tmp;
		}
	}

//	for(int i = 0; i<col; ++i)
//	{
//		for(int j = 0; j<row; ++j)
//			cout<<*(*(arr+i)+j)<<" ";
//		cout<<endl;
//	}

	int key;
	cout<<"key ";
	cin>>key;
	cout<<"find? "<<findinMatrix(arr,key,col,row)<<endl;
	destroy(arr,col);
}

bool findinMatrix(int** a,int key,int col,int row)
{
	int i = 0;
	int j = col-1;
	while(i < row && j >= 0)
	{
		if(key == *(*(a+i)+j))
			return true;
		if(key < *(*(a+i)+j))
			--i;
		if(key > *(*(a+i)+j))
			++j;
	}
	return false;
}



bool myFind(int *ar, int rows, int cols, int key)
{
	bool found = false;
	if (ar != NULL && rows > 0 && cols > 0)
	{
		int row = 0;
		int col = cols - 1;
		while (row < rows && col >= 0)
		{
			if (ar[row*cols + col] == key)
			{
				found = true;
				break;
			}
			else if (ar[row*cols + col] > key)
				--col;
			else
				++row;
		}
	}
	return found;
}
bool find(int *arr,int col,int row,int key)
{
	if(arr == NULL || col < 0 || row < 0)
		return false;

	int i = 0;
	int j = col -1;
	while(i < row && j >= 0)
	{
		if(key == arr[i*col+j])
			return true;
		else if(key < arr[i*col+j])
			--j;
		else
			++i;
	}
	
	return false;
}
int main()
{
	int a[] = {1,2,8,9,
				2,4,9,12,
				4,7,10,13,
				6,8,11,15}; 	
	cout<<find(a,4,4,7)<<endl;
	cout<<myFind(a,4,4,7)<<endl;
	innum();
	return 0;
}
