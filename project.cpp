using namespace std;
#include <iostream>
#include <vector>
#include<queue>
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    TreeNode* root;
    TreeNode* insertIntoBST(TreeNode* root, int d) {
        if (root == NULL) {
            root = new TreeNode(d);
            return root;
        }
        if (d > root->data) {
            root->right = insertIntoBST(root->right, d);
        } else {
            root->left = insertIntoBST(root->left, d);
        }
        return root;
    }
    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }
    void takeInput(TreeNode* &root) {
        int data;
        cout << "Enter data for the BST (Enter -1 to stop): ";
        cin >> data;
        while (data != -1) {
            root = insertIntoBST(root, data);
            cout << "Enter data for the BST (Enter -1 to stop): ";
            cin >> data;
        }
    }
};
class BinaryTree {
public:
    TreeNode* root;

public:
    //BinaryTree() : root(nullptr) {}

    void insert() {
        queue<TreeNode*> q;

        cout << "Enter data for root: ";
        int data;
        cin >> data;
        root = new TreeNode(data);

        q.push(root);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            cout << "Enter left node for " << temp->data << ": ";
            int leftData;
            cin >> leftData;

            if (leftData != -1) {
                temp->left = new TreeNode(leftData);
                q.push(temp->left);
            }

            cout << "Enter right node for " << temp->data << ": ";
            int rightData;
            cin >> rightData;

            if (rightData != -1) {
                temp->right = new TreeNode(rightData);
                q.push(temp->right);
            }
        }
    }
    void levelOrderTraversal(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);

        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();

            if (temp == nullptr) {
                cout << endl;
                if (!q.empty()) {

                    q.push(nullptr);
                }
            } else {
                cout << temp->data << " ";
                if (temp->left) {
                    q.push(temp->left);
                }

                if (temp->right) {
                    q.push(temp->right);
                }
            }
        }
    }
};
struct SinglyNode {
    int data;
    SinglyNode* next;

    SinglyNode(int value) : data(value), next(nullptr) {}
};
class SinglyLinkedList {
private:
    SinglyNode* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void append(int value) {
        SinglyNode* newNode = new SinglyNode(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            SinglyNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void displayList() {
        SinglyNode* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

struct DoublyNode {
    int data;
    DoublyNode* prev;
    DoublyNode* next;

    DoublyNode(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    DoublyNode* head;
    DoublyNode* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {
    }
    void append(int value) {
        DoublyNode* newNode = new DoublyNode(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void displayList() {
        DoublyNode* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " <-> ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

struct CircularNode {
    int data;
    CircularNode* next;

    CircularNode(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    CircularNode* head;

public:
    //CircularLinkedList() : head(nullptr) {}

    void append(int value) {
        CircularNode* newNode = new CircularNode(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // make it circular
        } else {
            CircularNode* current = head;
            while (current->next != head) {
                current = current->next;
            }
            newNode->next = head; // new node point to head
            current->next = newNode;
        }
    }

    void displayList() {
        if (head == nullptr) {
            cout << "Circular Linked List is empty." << endl;
            return;
        }

        CircularNode* current = head;
        do {
            cout << current->data;
            if (current->next != head) {
                cout << " -> ";
            }
            current = current->next;
        } while (current != head);
        cout <<"->"<<endl;
    }
};
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        cout << "Linear Search Step " << i + 1 << ": Searching in [";
        for (int j = 0; j <= i; j++) {
            cout << arr[j];
            if (j < i) {
                cout << ", ";
            }
        }
        cout << "]" << endl;

        cout << "Linear Search Step " << i + 1 << ": Comparing element at index " << i << " with the target..." << endl;

        if (arr[i] == target) {
            cout << "Linear Search Step " << i + 1 << ": Element found at index " << i << endl;
            return i;
        }
    }

    cout << "Linear Search: Element not found in the array." << endl;
    return -1;
}

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        cout << "Binary Search Step " << left << " - " << right << ": Searching in [";
        for (int i = left; i <= right; i++) {
            cout << arr[i];
            if (i < right) {
                cout << ", ";
            }
        }
        cout << "]" << endl;

        cout << "Binary Search Step " << left << " - " << right << ": Comparing element at index " << mid << " with the target..." << endl;

        if (arr[mid] == target) {
            cout << "Binary Search Step " << left << " - " << right << ": Element found at index " << mid << endl;
            return mid; // Element found at index mid
        } else if (arr[mid] < target) {
            cout << "Binary Search Step " << left << " - " << right << ": Target is in the right half. Updating left pointer." << endl;
            left = mid + 1;
        } else {
            cout << "Binary Search Step " << left << " - " << right << ": Target is in the left half. Updating right pointer." << endl;
            right = mid - 1;
        }
    }

    cout << "Binary Search: Element not found in the array." << endl;
    return -1;
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n ; i++) {
        bool swapped = false;
        for (int j = 0; j < n  -1; j++) {
            cout << "Bubble Sort Step " << i  << ": Comparing elements at index " << j << " and " << (j + 1) << "..." << endl;
            if (arr[j] > arr[j + 1]) {
                cout << "Bubble Sort Step " << i  << ": Swapping elements at index " << j << " and " << (j + 1) << endl;
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }

        cout << "Bubble Sort Step " << i + 1 << ": Current array state (bars): ";
        for (int num : arr) {
            for (int k = 0; k < num; k++) {
                cout << "|";
            }
            cout << " ";
        }
        cout <<endl;
    }
}
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            cout << "Selection Sort Step " << i + 1 << ": Swapping elements at index " << i << " and " << minIndex << endl;
            swap(arr[i], arr[minIndex]);
        }

        cout << "Selection Sort Step " << i + 1 << ": Current array state (bars): ";
        for (int num : arr) {
            for (int k = 0; k < num; k++) {
                cout << "|";
            }
            cout << " ";
        }
        cout << endl;
    }
}
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    cout << "Merge Sort Step: ";
    for (int num : arr) {
        for (int k = 0; k < num; k++) {
            cout << "|";
        }
        cout << " ";
    }
    cout << endl;
}
void printArrayBars(const vector<int>& arr) {
    cout << "Merge Sort Step: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << " (bars): ";
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << "|";
        }
        cout << " ";
    }
    cout << endl;
}
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);

        printArrayBars(arr);
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        cout << "Insertion Sort Step " << i << ": Before Insertion - ";

        for (int num : arr) {
            for (int k = 0; k < num; k++) {
                cout << "|";
            }
            cout << " ";
        }
        cout << endl;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];

            cout << "Insertion Sort Step " << i << ": Swapping " << arr[j] << " with " << key << " - ";
            for (int num : arr) {
                for (int k = 0; k < num; k++) {
                    cout << "|";
                }
                cout << " ";
            }
            cout << endl;

            j = j - 1;
        }
        arr[j + 1] = key;

        cout << "Insertion Sort Step " << i << ": After Insertion - ";
        for (int num : arr) {
            for (int k = 0; k < num; k++) {
                cout << "|";
            }
            cout << " ";
        }
        cout << endl;
    }
}
int main() {
    cout << "********************************************" << endl;
    cout << "*        Welcome to Algo Visualizer        *" << endl;
    cout << "*                 Made by:                 *" << endl;
    cout << "*            Yogesh Choudhary              *" << endl;
    cout << "*               E22CSEU0804                *" << endl;
    cout << "********************************************" << endl;
    while (true) {
        int operationChoice;
        cout << "Choose the ALGO you want to perform:\n";
        cout << "1. Search\n";
        cout << "2. Sort\n";
        cout << "3. Linked List\n";
        cout << "4. Binary Tree\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1/2/3/4/5): ";
        cin >> operationChoice;

        if (operationChoice == 1 || operationChoice == 2) {
            vector<int> arr;
            int size;

            cout << "Enter the number of elements in the array: ";
            cin >> size;

            cout << "Enter " << size << " elements separated by spaces: ";
            for (int i = 0; i < size; i++) {
                int element;
                cin >> element;
                arr.push_back(element);
            }

            if (operationChoice == 1) {
                int searchChoice;
                cout << "Choose the type of search:\n";
                cout << "1. Linear Search\n";
                cout << "2. Binary Search\n";
                cout << "Enter your choice (1/2): ";
                cin >> searchChoice;

                if (searchChoice == 1) {
                    int target;
                    cout << "Enter the target element to search: ";
                    cin >> target;
                    int result = linearSearch(arr, target);
                    if (result != -1) {
                        cout << "Linear Search: Element found at index " << result << endl;
                    } else {
                        cout << "Linear Search: Element not found in the array." << endl;
                    }
                } else if (searchChoice == 2) {
                    int target;
                    cout << "Enter the target element to search: ";
                    cin >> target;
                    bubbleSort(arr);
                    int result = binarySearch(arr, target);
                    if (result != -1) {
                        cout << "Binary Search: Element found at index " << result << endl;
                    } else {
                        cout << "Binary Search: Element not found in the array." << endl;
                    }
                } else {
                    cout << "Invalid search choice. Please select a valid option (1/2)." << endl;
                }
            } else if (operationChoice == 2) {
                int sortChoice;
                cout << "Choose the type of sort:\n";
                cout << "1. Bubble Sort\n";
                cout << "2. Selection Sort\n";
                cout << "3. Merge Sort\n";
                cout << "4. Insertion Sort\n";
                cout << "Enter your choice (1/2/3/4): ";
                cin >> sortChoice;

                if (sortChoice == 1) {
                    cout << "Unsorted Array (bars): ";
                    for (int num: arr) {
                        for (int k = 0; k < num; k++) {
                            cout << "|";
                        }
                        cout << " ";
                    }
                    cout << endl;

                    bubbleSort(arr);

                    cout << "Bubble Sort: Sorted Array (bars): ";
                    for (int num: arr) {
                        for (int k = 0; k < num; k++) {
                            cout << "|";
                        }
                        cout << " ";
                    }
                    cout << endl;
                }else if (sortChoice == 2) {
                    cout << "Unsorted Array (bars): ";
                    for (int num: arr) {
                        for (int k = 0; k < num; k++) {
                            cout << "|";
                        }
                        cout << " ";
                    }
                    cout << endl;

                    selectionSort(arr);

                    cout << "Bubble Sort: Sorted Array (bars): ";
                    for (int num: arr) {
                        for (int k = 0; k < num; k++) {
                            cout << "|";
                        }
                        cout << " ";
                    }
                    cout << endl;
                }else if (sortChoice == 3) {
                    cout << "Unsorted Array (bars): ";
                    for (int num: arr) {
                        for (int k = 0; k < num; k++) {
                            cout << "|";
                        }
                        cout << " ";
                    }
                    cout << endl;

                    mergeSort(arr, 0, size - 1);

                    cout << "Merge Sort: Sorted Array (bars): ";
                    for (int num: arr) {
                        for (int k = 0; k < num; k++) {
                            cout << "|";
                        }
                        cout << " ";
                    }
                    cout << endl;
                }else if (sortChoice == 4) {
                    cout << "Unsorted Array (bars): ";
                    for (int num: arr) {
                        for (int k = 0; k < num; k++) {
                            cout << "|";
                        }
                        cout << " ";
                    }
                    cout << endl;

                    insertionSort(arr);

                    cout << "Merge Sort: Sorted Array (bars): ";
                    for (int num: arr) {
                        for (int k = 0; k < num; k++) {
                            cout << "|";
                        }
                        cout << " ";
                    }
                    cout << endl;
                } else {
                    cout << "Invalid sort choice. Please select a valid option (1/3)." << endl;
                }
            }
        } else if (operationChoice == 3) {  // Linked List operations
            int linkedListChoice;
            cout << "Choose the type of linked list:\n";
            cout << "1. Singly Linked List\n";
            cout << "2. Doubly Linked List\n";
            cout << "3. Circular Linked List\n";
            cout << "4. Back to Main Menu\n";
            cout << "Enter your choice (1/2/3/4): ";
            cin >> linkedListChoice;

            if (linkedListChoice == 1) {
                SinglyLinkedList singlyLinkedList;

                while (true) {
                    int singlyListOperation;
                    cout << "Choose the operation for Singly Linked List:\n";
                    cout << "1. Append\n";
                    cout << "2. Display\n";
                    cout << "3. Back to Linked List Menu\n";
                    cout << "Enter your choice (1/2/3): ";
                    cin >> singlyListOperation;

                    if (singlyListOperation == 1) {
                        int value;
                        cout << "Enter the value to append to the singly linked list: ";
                        cin >> value;
                        singlyLinkedList.append(value);
                        cout << "Value " << value << " appended to the singly linked list." << endl;
                    } else if (singlyListOperation == 2) {
                        cout << "Singly Linked List Contents: ";
                        singlyLinkedList.displayList();
                    } else if (singlyListOperation == 3) {
                        break;
                    } else {
                        cout << "Invalid choice. Please select a valid option (1/2/3)." << endl;
                    }
                }
            } else if (linkedListChoice == 2) {
                DoublyLinkedList doublyLinkedList;

                while (true) {
                    int doublyListOperation;
                    cout << "Choose the operation for Doubly Linked List:\n";
                    cout << "1. Append\n";
                    cout << "2. Display\n";
                    cout << "3. Back to Linked List Menu\n";
                    cout << "Enter your choice (1/2/3): ";
                    cin >> doublyListOperation;

                    if (doublyListOperation == 1) {
                        int value;
                        cout << "Enter the value to append to the doubly linked list: ";
                        cin >> value;
                        doublyLinkedList.append(value);
                        cout << "Value " << value << " appended to the doubly linked list." << endl;
                    } else if (doublyListOperation == 2) {
                        cout << "Doubly Linked List Contents: ";
                        doublyLinkedList.displayList();
                    } else if (doublyListOperation == 3) {
                        break;
                    } else {
                        cout << "Invalid choice. Please select a valid option (1/2/3)." << endl;
                    }
                }
            } else if (linkedListChoice == 3) {
                CircularLinkedList circularLinkedList;

                while (true) {
                    int circularListOperation;
                    cout << "Choose the operation for Circular Linked List:\n";
                    cout << "1. Append\n";
                    cout << "2. Display\n";
                    cout << "3. Back to Linked List Menu\n";
                    cout << "Enter your choice (1/2/3): ";
                    cin >> circularListOperation;

                    if (circularListOperation == 1) {
                        int value;
                        cout << "Enter the value to append to the circular linked list: ";
                        cin >> value;
                        circularLinkedList.append(value);
                        cout << "Value " << value << " appended to the circular linked list." << endl;
                    } else if (circularListOperation == 2) {
                        cout << "Circular Linked List Contents: ";
                        circularLinkedList.displayList();
                    } else if (circularListOperation == 3) {
                        break;
                    } else {
                        cout << "Invalid choice. Please select a valid option (1/2/3)." << endl;
                    }
                }
            } else if (linkedListChoice == 4) {
                break;
            } else {
                cout << "Invalid choice. Please select a valid option (1/2/3/4)." << endl;
            }
        }else if (operationChoice == 4) {
            int binaryTreeChoice;
            cout << "Binary Tree Operations:\n";
            cout << "1. Binary Tree\n";
            cout << "2. Binary Search Tree (BST)\n";
            cout << "3. Back to Main Menu\n";
            cout << "Enter your choice (1/2/3): ";
            cin >> binaryTreeChoice;

            if (binaryTreeChoice == 1) {
                BinaryTree binaryTree;
                int treeChoice;

                while (true) {
                    cout << "Binary Tree Operations:\n";
                    cout << "1. Insert into Binary Tree\n";
                    cout << "2. Display Binary Tree (Level Order)\n";
                    cout << "3. Back to Binary Tree Menu\n";
                    cout << "Enter your choice (1/2/3): ";
                    cin >> treeChoice;

                    if (treeChoice == 1) {
                        binaryTree.insert();
                        cout << "Binary Tree built from Level Order input." << endl;
                    } else if (treeChoice == 2) {
                        cout << "Binary Tree Contents (Level Order Traversal):\n";
                        binaryTree.levelOrderTraversal(binaryTree.root);
                        cout << endl;
                    } else if (treeChoice == 3) {
                        break;
                    } else {
                        cout << "Invalid choice. Please select a valid option (1/2/3)." << endl;
                    }
                }
            } else if (binaryTreeChoice == 2) {
                BinarySearchTree bst;
                BinaryTree binaryTree;

                int choice;
                do {
                    cout << "Binary Search Tree (BST) Operations:\n";
                    cout << "1. Insert into BST\n";
                    cout << "2. Inorder Traversal\n";
                    cout << "3. Exit\n";
                    cout << "Enter your choice (1/2/3): ";
                    cin >> choice;

                    if (choice == 1) {
                        int value;
                        cout << "Enter the value to insert into the BST: ";
                        cin >> value;
                        //bst.insert(value);
                        bst.takeInput(bst.root);
                        cout << "Value " << value << " inserted into the BST." << endl;
                    } else if (choice == 2) {
                        cout << "Inorder Traversal of the BST: ";
                        bst.inorderTraversal(bst.root);
                        cout << endl;
                    } else if (choice == 3) {
                        cout << "Exiting the BST operations. Goodbye!" << endl;
                    } else {
                        cout << "Invalid choice. Please select a valid option (1/2/3)." << endl;
                    }
                } while (choice != 3);
            }
        } else if (operationChoice == 5) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid operation choice. Please select a valid option (1/2/3/4)." << endl;
        }

        char another;
        cout << "Do you want to perform another operation? (y/n): ";
        cin >> another;

        if (another != 'y' && another != 'Y') {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
    }
    return 0;
}
