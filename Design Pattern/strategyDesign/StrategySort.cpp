#include <iostream>
#include <vector>
using namespace std;

class SortStrategy {
public:
    virtual void sort(int arr[], int size) = 0;
    virtual ~SortStrategy() {}
};

class BubbbleSort :  public SortStrategy {
public:
    void sort(int arr[],int size) override{
        for(int i=0;i<size-1;i++){
            for(int j=0;j<size-i-1;j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }

        cout << "Array Sorted using Bubble Sort: ";
        for(int i=0;i<size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


class SelectionSort : public SortStrategy {
public:
    void sort(int arr[],int size)override{
        for(int i=0;i<size-1;i++){
            int minIndex = i;
            for(int j=i+1;j<size;j++){
                if(arr[j] < arr[minIndex]){
                    minIndex = j;
                }
                swap(arr[i],arr[minIndex]);

            }
           
        }
         cout << "Array Sorted using Selection Sort: ";
        for(int i=0;i<size;i++){
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

class InsertionSort : public SortStrategy {
public:
    void sort(int arr[],int size)override{
        for(int i=1;i<size;i++){
            int key = arr[i];
            int j = i-1;
            while(j >= 0 && arr[j] > key){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
        cout << "Array Sorted using Insertion Sort: ";

        for(int i=0;i<size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class MergeSort : public SortStrategy {
private:
    void merge(int arr[],int low,int mid,int high){
        vector<int>temp;
        int left = low,right = mid+1;

        // mege two sorted subarrays

        while(left <= mid && right <= high){
            if(arr[left]<= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        // copy remaining elements of left subarray
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        // copy remaining elements of right subarray
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        // copy temp array to original array
        for(int i=low;i<=high;i++){
            arr[i] = temp[i - low];
        }

    }
    void mergeSort(int arr[],int low,int high){
        if(low < high){
            int mid = low + (high - low)/2;
            mergeSort(arr,low,mid);
            mergeSort(arr,mid+1,high);
            merge(arr,low,mid,high);
        }
    }
    public:
    void sort(int arr[],int size)override{
        mergeSort(arr,0,size-1);
        cout << "Array Sorted using Merge Sort: ";
        for(int i=0;i<size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// quick sort strategy
class QuickSort : public SortStrategy {
private:
    int partition(int arr[],int low,int high){
        int pivot = arr[high];
        int i = low - 1;
        for(int j=low;j<high;j++){
            if(arr[j] < pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[high]);
        return i+1;
    }
    void quickSort(int arr[],int low,int high){
        if(low < high){
            int pi = partition(arr,low,high);
            quickSort(arr,low,pi-1);
            quickSort(arr,pi+1,high);
        }
    }
public:
    void sort(int arr[],int size)override{
        quickSort(arr,0,size-1);
        cout << "Array Sorted using Quick Sort: ";
        for(int i=0;i<size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class SortContext {
private:
    SortStrategy* strategy;
public:
    SortContext(SortStrategy* strategy) : strategy(strategy) {}
    void setStrategy(SortStrategy* strategy) {
        this->strategy = strategy;
    }
    void sortArray(int arr[],int size) {
        strategy->sort(arr,size);
    }
};

int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << "Original Array: ";
    for(int i=0;i<size1;i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    SortStrategy* bubbleSort = new BubbbleSort();
    SortStrategy* selectionSort = new SelectionSort();
    SortStrategy* insertionSort = new InsertionSort();
    SortStrategy* mergeSort = new MergeSort();
    SortStrategy* quickSort = new QuickSort();

    SortContext context(bubbleSort);
    context.sortArray(arr1,size1);

    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    context.setStrategy(selectionSort);
    context.sortArray(arr2,size2);

    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    int size3 = sizeof(arr3)/sizeof(arr3[0]);
    context.setStrategy(insertionSort);
    context.sortArray(arr3,size3);

    int arr4[] = {64, 34, 25, 12, 22, 11, 90};
    int size4 = sizeof(arr4)/sizeof(arr4[0]);
    context.setStrategy(mergeSort);
    context.sortArray(arr4,size4);

    int arr5[] = {64, 34, 25, 12, 22, 11, 90};
    int size5 = sizeof(arr5)/sizeof(arr5[0]);
    context.setStrategy(quickSort);
    context.sortArray(arr5,size5);

    delete bubbleSort;
    delete selectionSort;
    delete insertionSort;
    delete mergeSort;
    delete quickSort;

    return 0;
}