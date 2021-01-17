#include <iostream>
#include <vector>

using namespace std;

void shell_sort(vector<int>& v);

void shell_sort(vector<int>& v) {
    int i, j, temp;
    bool swap;

    int h = v.size() / 2;
    while (h > 0) {
        i = h;
	while (i < v.size()) {
	    swap = false;
	    temp = v[i];
	    j = i - h;
	    while (j >= 0 && v[j] > temp) {
	        v[j+h] = v[j];
		swap = true;
		j -= h;
	    }

	    if (swap) 
	        v[j+h] = temp;
			
	    i += 1;

	}

	h = h / 2;
    }

}

int main() {

    vector<int> v = {98, 31, 1, 44, 55, 10, 5, 6, 7, 8, 1999, 3131, 9, 0};

    shell_sort(v);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

}
