 #include <iostream>
#include <fstream> 
using namespace std;

#define MAX 5   // Maximum size of the stack

// Log actions to a text file
void logToFile(string message) {
    ofstream file("stack.txt", ios::app);
    file << message << endl;
    file.close();
}

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Check if stack is full
    bool isFull() {
        return (top == MAX - 1);
    }

    // Check if stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Push element
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            logToFile("Push failed (Stack Full): " + to_string(value));
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into the stack." << endl;
        logToFile("Pushed: " + to_string(value));
    }

    // Pop element
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
            logToFile("Pop failed (Stack Empty)");
            return;
        }
        cout << arr[top] << " popped from the stack." << endl;
        logToFile("Popped: " + to_string(arr[top]));
        top--;
    }

    // Display stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            logToFile("Display: Stack Empty");
            return;
        }

        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;

        logToFile("Displayed stack");
    }
};

int main() {
    Stack s;
    int choice, value;

    cout << "---- STACK USING ARRAY ----" << endl;

    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.display();
            break;

        case 4:
            cout << "Exiting program..." << endl;
            logToFile("Program Exited");
            return 0;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }
}