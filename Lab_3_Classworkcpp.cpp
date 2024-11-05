#include <iostream>
#include <cmath>
using namespace std;

// Binary search functions for first and last occurrence
int binarySearchFirst(int arr[], int size, int target) {
    int low = 0, high = size - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int binarySearchLast(int arr[], int size, int target) {
    int low = 0, high = size - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid;
            low = mid + 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int countOccurrences(int arr[], int size, int target) {
    int first = binarySearchFirst(arr, size, target);
    if (first == -1) return 0;
    int last = binarySearchLast(arr, size, target);
    return last - first + 1;
}

// Jump Search
int jump_Search(int arr[], int size, int target) {
    int i = 0;
    int m = sqrt(size);

    // Jump in blocks of sqrt(size) to find the correct block
    while (m < size && arr[m] < target) {
        i = m;
        m += sqrt(size);
    }

    // Linear search within the identified block
    for (int x = i; x < min(m, size); x++) {
        if (arr[x] == target) {
            return x;
        }
    }

    return -1;
}

// Interpolation Search
int interpolationsearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right && target >= arr[left] && target <= arr[right]) {
        int probe = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);
        if (arr[probe] == target) {
            return probe;
        } else if (arr[probe] < target) {
            left = probe + 1;
        } else {
            right = probe - 1;
        }
    }
    return -1;
}

// Missing Number Search
int Missingnumber(int arr[], int size) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == mid) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

// Linear Search
void linearSearch(int arr[], int size, int target, int &comparisons) {
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == target) {
            cout << "Linear Search: Found at " << i + 1 << " position" << endl;
            return;
        }
    }
    cout << "Not found" << endl;
}

// Binary Search with comparisons count
void binarySearch(int arr[], int size, int target, int &comparisons) {
    int low = 0, high = size - 1;
    while (low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            cout << "Binary Search: Found at " << mid + 1 << " position" << endl;
            return;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Not found" << endl;
}

// Jump Search with comparisons count
void jump_Search(int a[], int n, int target, int &jumpComparisons) {
    int i = 0;
    int m = sqrt(n);
    while (i < n && a[min(m, n) - 1] < target) {
        jumpComparisons++;
        i = m;
        m += sqrt(n);
    }
    for (int x = i; x < min(m, n); x++) {
        jumpComparisons++;
        if (a[x] == target) {
            cout << "Jump Search: Found at " << x + 1 << " position" << endl;
            return;
        }
    }
    cout << "Not found" << endl;
}

// Bidirectional Binary Search
int BidirectionalBinarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        if (arr[low] == target) return low;
        if (arr[high] == target) return high;
        low++;
        high--;
    }
    return -1;
}

// Quickselect for kth smallest element
int quickSelect(int arr[], int low, int high, int k);
int partition(int arr[], int low, int high);
void swap(int &a, int &b);

int kthSmallest(int arr[], int size, int k) {
    return quickSelect(arr, 0, size - 1, k - 1);
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);
        if (pi == k) return arr[pi];
        else if (pi < k) return quickSelect(arr, pi + 1, high, k);
        else return quickSelect(arr, low, pi - 1, k);
    }
    return -1;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Menu function
void menu() {
    int choice;
    do {
        cout << "\nSelect an Algorithm:\n";
        cout << "1. Binary Search \n";
        cout << "2. Jump Search\n";
        cout << "3. Interpolation Search\n";
        cout << "4. Missing Number Search\n";
        cout << "5. Linear, Binary, and Jump Search Comparison\n";
        cout << "6. Bidirectional Binary Search\n";
        cout << "7. Kth Smallest Element (Quickselect)\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int size, target, k;
        int arr[100];

        switch(choice) {
            case 1: {
        cout << "Enter the size of the array: ";
        cin >> size;
        cout << "Enter array: ";
        for (int i = 0; i < size; i++) 
        cin >> arr[i];
        cout << "Enter target: ";
        cin >> target;
        int count = countOccurrences(arr, size, target);
        cout << "The number " << target << " appears " << count <<" times."<<endl;

                break;
            }
            case 2: {
        cout << "Enter size of the array: ";
        cin >> size;
        cout << "Enter sorted array elements: ";
        for (int i = 0; i < size; i++) {
        cin >> arr[i];
        }
        cout << "Enter target: ";
        cin >> target;
        int result = jump_Search(arr, size, target);
        if (result != -1) {
        cout << "Found at position: " << result + 1 << endl;
        } else {
        cout << "Not found" << endl;
        }
        break;
}


            case 3: {
                cout << "Enter size of the array: ";
                cin >> size;
                cout << "Enter sorted array elements: ";
                for (int i = 0; i < size; i++) cin >> arr[i];
                cout << "Enter target: ";
                cin >> target;
                int position = interpolationsearch(arr, size, target);
                if (position != -1) cout << "Found at position: " << position + 1 << endl;
                else cout << "Not found" << endl;
                break;
            }

            case 4: {
                cout << "Enter size of the array: ";
                cin >> size;
                cout << "Enter array elements: ";
                for (int i = 0; i < size; i++) cin >> arr[i];
                cout << "Missing number is: " << Missingnumber(arr, size) << endl;
                break;
            }

            case 5: {
                cout << "Enter size of the array: ";
                cin >> size;
                cout << "Enter sorted array elements: ";
                for (int i = 0; i < size; i++) cin >> arr[i];
                cout << "Enter target: ";
                cin >> target;
                int linearComparisons = 0, binaryComparisons = 0, jumpComparisons = 0;
                linearSearch(arr, size, target, linearComparisons);
                binarySearch(arr, size, target, binaryComparisons);
                jump_Search(arr, size, target, jumpComparisons);
                cout << "Linear Search Comparisons: " << linearComparisons << endl;
                cout << "Binary Search Comparisons: " << binaryComparisons << endl;
                cout << "Jump Search Comparisons: " << jumpComparisons << endl;
                break;
            }

            case 6: {
                cout << "Enter size of the array: ";
                cin >> size;
                cout << "Enter array elements: ";
                for (int i = 0; i < size; i++) cin >> arr[i];
                cout << "Enter target: ";
                cin >> target;
                int index = BidirectionalBinarySearch(arr, size, target);
                if (index != -1) cout << "Found at position: " << index + 1 << endl;
                else cout << "Not found" << endl;
                break;
            }

            case 7: {
                cout << "Enter size of the array: ";
                cin >> size;
                cout << "Enter array elements: ";
                for (int i = 0; i < size; i++) cin >> arr[i];
                cout << "Enter k to find the kth smallest element: ";
                cin >> k;
                if (k > 0 && k <= size) {
                    cout << "The " << k << "th smallest element is: " << kthSmallest(arr, size, k) << endl;
                } else {
                    cout << "Invalid k" << endl;
                }
                break;
            }

            case 8:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);
}

int main() {
    menu();
    return 0;
}