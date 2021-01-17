#include <iostream>
#include <vector>

using namespace std;

void quicksort(vector<int>& v, int p, int r);
int partition(vector<int>& v, int p, int r);

void quicksort(vector<int>& v, int p, int r) {
    int q;

    if (p < r) {
        q = partition(v, p, r);
        quicksort(v, p, q - 1);
        quicksort(v, q + 1, r);	
    }

}

int partition(vector<int>& v, int p, int r) {

    int x = v[p];
    int i = p;
    int j = p + 1;

    while (j <= r) {
        
        if (v[j] < x) {
            i += 1;
    	    swap(v[i], v[j]);
    	}

        j += 1;

    }    
	
    swap(v[i], v[p]);
    return i;
}

int main() {
    
   vector<int> v = {98, 31, 1, 44, 55, 10, 5, 6, 7, 8, 1999, 3131, 9, 0};

   quicksort(v, 0, v.size() - 1);

   for (int i = 0; i < v.size(); i++) {
       cout << v[i] << endl;
   }

    return 0;
}
