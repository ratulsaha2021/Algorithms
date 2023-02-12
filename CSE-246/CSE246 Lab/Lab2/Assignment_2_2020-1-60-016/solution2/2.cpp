#include <bits/stdc++.h>
using namespace std;

struct Item {
    int benefit, weight;
};

struct Temp {
    int temB, temW;
};

int partition(Item item[], int Ratio[], int low, int high) {
    Temp t;
    int temp;
    int pivot = Ratio[(low+high)/2];

    while(low<=high) {
        while(Ratio[low]>pivot) {
            low++;
        }
        while(Ratio[high]<pivot) {
            high--;
        }
        if(low<=high) {
            temp = Ratio[low];
            t.temB = item[low].benefit;
            t.temW = item[low].weight;
            Ratio[low] = Ratio[high];
            item[low].benefit = item[high].benefit;
            item[low].weight = item[high].weight;
            Ratio[high] = temp;
            item[high].benefit = t.temB;
            item[high].weight = t.temW;
            low++;
            high--;
        }
    }
    return low;
}

void quick_Sort(Item item[], int Ratio[], int low, int high) {
    int pi = partition(item, Ratio, low, high);

    if(low<pi-1) {
        quick_Sort(item, Ratio, low, pi-1);
    }
    if(pi<high) {
        quick_Sort(item, Ratio, pi, high);
    }
}

int main() {
    int N,i,j;
    double W,temp_Weight=0,temp_Benefit=0;

    while(1) {
        cin >> N;
        cin >> W;
        int Ratio[N];
        Item item[N];

        for(i=0; i<N; i++) {
            j=i;
            cin >> Ratio[i];
        }

        for(i=0; i<N; i++) {
            cin >> item[i].weight;
            item[i].benefit = Ratio[i]*item[i].weight;
        }

        quick_Sort(item, Ratio, 0, N-1);

        for(i=0; i<N-1; i++) {
            if(W>item[i].weight) {
                temp_Weight = temp_Weight+item[i].weight;
                W = W-item[i].weight;
                temp_Benefit = temp_Benefit+item[i].benefit;
            }
            else {
                temp_Weight = temp_Weight+W;
                temp_Benefit = temp_Benefit+Ratio[i]*W;
                i=N;
            }
        }
        cout << endl;
        cout << temp_Benefit;
        cout << endl;
        cout << endl;
        cout << endl;
        temp_Weight=0;
        temp_Benefit=0;
    }


    return 0;
}
