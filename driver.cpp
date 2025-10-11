#include "ArrayStack.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {


    // -----------------------------------
    // 1. PUSH & EMPTY CHECK
    // -----------------------------------
    cout << "\n[1] PUSH / EMPTY TEST\n";
    ArrayStack<string> travelStack(5);

    cout << "Starting state: " 
         << (travelStack.isEmpty() ? "Stack is empty" : "Stack has items") << endl;

    cout << "Adding destinations...\n";
    travelStack.push("Santa");
    travelStack.push("Monica");
    cout << "After a few pushes: " 
         << (travelStack.isEmpty() ? "Empty" : "Not empty") << endl;
    cout << "Current contents (top to bottom): " << travelStack << endl;

    // -----------------------------------
    // 2. POP / PEEK
    // -----------------------------------
    cout << "\n[2] POP & PEEK\n";
    cout << "Top element before pop: " << travelStack.peek() << endl;
    travelStack.pop();
    cout << "After first pop, new top: " << travelStack.peek() << endl;
    travelStack.pop();
    cout << "Stack should now be empty -> " 
         << (travelStack.isEmpty() ? "Yes" : "No") << endl;

    // -----------------------------------
    // 3. OVERFLOW
    // -----------------------------------
    cout << "\n[3] OVERFLOW HANDLING\n";
    try {
        string stops[] = {"LA", "LAX", "Burbank", "Glendale", "Pasadena"};
        for (auto &city : stops) {
            travelStack.push(city);
            cout << "Pushed: " << city << endl;
        }
        cout << "Attempting to add one more (should throw)...\n";
        travelStack.push("Hollywood");
    } 
    catch (string &err) {
        cerr << "Error caught: " << err << endl;
    }
    cout << "Stack contents now: " << travelStack << endl;

    // -----------------------------------
    // 4. ROTATE TEST
    // -----------------------------------
    cout << "\n[4] ROTATE OPERATION\n";
    try {
        cout << "Rotate RIGHT once:\n";
        travelStack.rotate(Stack<string>::RIGHT);
        cout << travelStack << endl;

        cout << "Rotate LEFT twice:\n";
        travelStack.rotate(Stack<string>::LEFT);
        travelStack.rotate(Stack<string>::LEFT);
        cout << travelStack << endl;
    } 
    catch (string &err) {
        cerr << "Rotation error: " << err << endl;
    }

    // -----------------------------------
    // 5. CLEAR STACK
    // -----------------------------------
    cout << "\n[5] CLEARING STACK\n";
    travelStack.clear();
    cout << "Stack cleared. Empty now? " 
         << (travelStack.isEmpty() ? "Yes" : "No") << endl;

    // -----------------------------------
    // 6. DOUBLE DATA TYPE
    // -----------------------------------
    cout << "\n[6] DOUBLE TYPE TEST\n";
    ArrayStack<double> priceStack(3);

    priceStack.push(4.99);
    priceStack.push(7.50);
    priceStack.push(9.75);
    cout << "Top price: " << priceStack.peek() << endl;
    priceStack.pop();
    cout << "After pop -> " << priceStack << endl;
    priceStack.clear();
    cout << "After clear -> " 
         << (priceStack.isEmpty() ? "Empty" : "Not empty") << endl;

    // -----------------------------------
    // 7. UNDERFLOW TEST
    // -----------------------------------
    cout << "\n[7] UNDERFLOW CHECK\n";
    try {
        cout << "Attempting to pop from an empty stack...\n";
        travelStack.pop();
    } 
    catch (string &err) {
        cerr << "Error: " << err << endl;
    }


    return 0;
}
