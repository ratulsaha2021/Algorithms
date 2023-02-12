#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

struct Temp {
    int temps, tempe;
};

int partition(Activity act[], int low, int high) {
    Temp t;
    int pivot = act[(low+high)/2].finish;

    while(low<=high) {
        while(act[low].finish<pivot) {
            low++;
        }
        while(act[high].finish>pivot) {
            high--;
        }
        if(low<=high) {
            t.tempe = act[low].finish;
            t.temps = act[low].start;
            act[low].finish = act[high].finish;
            act[low].start = act[high].start;
            act[high].finish = t.tempe;
            act[high].start = t.temps;
            low++;
            high--;
        }
    }
    return low;
}

void quick_Sort(Activity act[], int low, int high) {
    int pi = partition(act, low, high);

    if(low<pi-1) {
        quick_Sort(act, low, pi-1);
    }
    if(pi<high) {
        quick_Sort(act, pi, high);
    }
}

void maxActivities(Activity act[], int N) {
    int i,j,count;

    i=0;
    count=1;
    for (j=1; j<N; j++) {
      if (act[j].start>act[i].finish) {
        count++;
        i=j;
      }
    }
    cout << endl;
    cout << count;
    cout << endl;
    cout << endl;

}

int main() {
    int N,i,j;

    while(1) {
        cin >> N;
        Activity act[N];

        for(i=0; i<N; i++) {
            j=i;
            cin >> act[i].start;
            cin >> act[j].finish;
        }

        quick_Sort(act, 0, N-1);
        maxActivities(act, N);
    }
}
