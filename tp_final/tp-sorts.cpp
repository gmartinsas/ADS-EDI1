#include <iostream>
using namespace std;

void print(int t, int *a) {
	cout << "----------------------" << endl;
	for(int i=0; i<t; ++i) {
		cout << "Elemento: " << i << " = " << a[i] << endl;
	}
	cout << "----------------------" << endl;
}

void bubbleSort(int t, int *a) {
	int aux;
	for(int i=t-1; i>0; --i) {
		for(int j=0; j<i; ++j) {
			cout << "[" << j << "]: " << a[j] << 
			        ", [" << j+1 << "]:  " << a[j+1];
			if (a[j] > a[j+1]) {
				aux = a[j];
				a[j] = a[j+1];
				a[j+1] = aux;
				cout << " - Trocou!!!";
			}
			cout << endl;
		}
	}
}

void insertionSort(int a, int *v) {
	for (int i = 1; i < a; i++) { 
		
		int j = i;
	
		while (j > 0 && v[j] < v[j-1]) {
			int aux = v[j];
			v[j] = v[j - 1];
			v[j - 1] = aux;
			j -= 1;
		}
	
	}	
}

void quickSort(int *v, int l, int r) {
    int i = l, j = r;
    int aux;
    int p = v[(l + r) / 2];

    while (i <= j) {
        while (v[i] < p)
            i++;
        while (v[j] > p)
            j--;
        if (i <= j) {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    };

    if (l < j)
        quickSort(v, l, j);
    if (i < r)
        quickSort(v, i, r);
}

void selectionSort(int *v, int n) {
   int i, j, min_i;

   for (i = 0; i < n-1; i++) {
      min_i = i;
      for (j = i+1; j < n; j++) {
         if (v[j] < v[min_i])
            min_i = j;
	  }
	swap(v[min_i], v[i]);
   }
}

void merge(int *v, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        }
        else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *v, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);

        merge(v, l, m, r);
    }
}

void shellSort(int *v, int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = v[i];
            int j;
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap)
                v[j] = v[j - gap];
            	v[j] = temp;
        }
    }
}

int main(int argc, char** argv)
{
	int v[8] = {49, 38, 58, 87, 34, 93, 26, 13};
	int n = sizeof(v) / sizeof(v[0]);
	print(8, v);
	
    v = {49, 38, 58, 87, 34, 93, 26, 13};

	bubbleSort(8, v);
	print(8, v);
	
    v = {49, 38, 58, 87, 34, 93, 26, 13};

	insertionSort(8, v);
	print(8, v);
	
	v = {49, 38, 58, 87, 34, 93, 26, 13};

	quickSort(v, 0, n-1);
	print(8, v);
	
    v = {49, 38, 58, 87, 34, 93, 26, 13};

	selectionSort(v, n);
	print(8, v);
	
    v = {49, 38, 58, 87, 34, 93, 26, 13};

	mergeSort(v, 0, n-1);
	print(8, v);

    v = {49, 38, 58, 87, 34, 93, 26, 13};
	
	shellSort(v, n);
	print(8, v);
	
	return 0;
}