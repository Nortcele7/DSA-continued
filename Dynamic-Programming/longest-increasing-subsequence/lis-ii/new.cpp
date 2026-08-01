#include <iostream>
using namespace std;

#define MAX 100

// Function to display the list
void display(int arr[], int n) {
    if (n == 0) {
        cout << "List is empty" << endl;
        return;
    }
    cout << "List: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// a. Insert at the beginning
void insertBeginning(int arr[], int &n, int x) {
    if (n >= MAX) {
        cout << "List is full, cannot insert." << endl;
        return;
    }
    for (int i = n; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = x;
    n++;
}

// b. Insert at the end
void insertEnd(int arr[], int &n, int x) {
    if (n >= MAX) {
        cout << "List is full, cannot insert." << endl;
        return;
    }
    arr[n] = x;
    n++;
}

// c. Insert after a specific element
void insertAfter(int arr[], int &n, int x, int afterVal) {
    if (n >= MAX) {
        cout << "List is full, cannot insert." << endl;
        return;
    }
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == afterVal) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << afterVal << " not found in list." << endl;
        return;
    }
    for (int i = n; i > pos + 1; i--)
        arr[i] = arr[i - 1];
    arr[pos + 1] = x;
    n++;
}

// d. Delete from the beginning
void deleteBeginning(int arr[], int &n) {
    if (n == 0) {
        cout << "List is empty, cannot delete." << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

// e. Delete from the end
void deleteEnd(int arr[], int &n) {
    if (n == 0) {
        cout << "List is empty, cannot delete." << endl;
        return;
    }
    n--;
}

// f. Delete the element after a specific element
void deleteAfter(int arr[], int &n, int afterVal) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == afterVal) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << afterVal << " not found in list." << endl;
        return;
    }
    if (pos + 1 >= n) {
        cout << "No element exists after " << afterVal << " to delete." << endl;
        return;
    }
    for (int i = pos + 1; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

int main() {
    int arr[MAX];
    int n = 0;

    cout << "----- Initial List -----" << endl;
    display(arr, n);

    cout << "\n----- a. Insert at Beginning -----" << endl;
    insertEnd(arr, n, 20);
    insertEnd(arr, n, 30);
    insertEnd(arr, n, 40);
    display(arr, n); // build a base list first: 20 30 40
    insertBeginning(arr, n, 10);
    cout << "After inserting 10 at beginning:" << endl;
    display(arr, n);

    cout << "\n----- b. Insert at End -----" << endl;
    insertEnd(arr, n, 50);
    cout << "After inserting 50 at end:" << endl;
    display(arr, n);

    cout << "\n----- c. Insert After Specific Element -----" << endl;
    insertAfter(arr, n, 25, 20);
    cout << "After inserting 25 after 20:" << endl;
    display(arr, n);

    cout << "\n----- d. Delete from Beginning -----" << endl;
    deleteBeginning(arr, n);
    cout << "After deleting from beginning:" << endl;
    display(arr, n);

    cout << "\n----- e. Delete from End -----" << endl;
    deleteEnd(arr, n);
    cout << "After deleting from end:" << endl;
    display(arr, n);

    cout << "\n----- f. Delete After Specific Element -----" << endl;
    deleteAfter(arr, n, 20);
    cout << "After deleting element after 20:" << endl;
    display(arr, n);

    return 0;
}