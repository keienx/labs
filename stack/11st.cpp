#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

struct Point {
    string value;
    Point* next = nullptr;
};

struct Stack {
    Point* head = nullptr;
};

void popfront(Stack& stack){
    if (stack.head == nullptr) return;
    Point* temp = stack.head;
    stack.head = stack.head->next;
    delete temp;
}

void printst(Stack& stack){
    for (Point* temp = stack.head; temp; temp = temp->next){
        cout << temp->value << "\n";
    }
    cout << '\n';
}

void pushfront(Stack& stack, string value) {
    Point* new_node = new Point;
    new_node->value = value;
    if (stack.head == nullptr)
        stack.head = new_node;
    else {
        new_node->next = stack.head;
        stack.head = new_node;
    }
}

void addstack(Stack& stack){
    ofstream out("file.txt");
    for (Point* temp = stack.head; temp; temp = temp->next){
        out << temp->value << "\n";
    }
    out << '\n';
    out.close();
}

void fromstack(Stack& stack, int size){
    string buf;
    ifstream in("file3.txt");
    for (int i = 0; i < size; i++){
        getline(in, buf);
        pushfront(stack, buf);
    }
    in.close();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Stack stack;
    int size;
    string str;
    cout << "Š®«¨ç¥áâ¢® í«¥¬¥­â®¢ áâ¥ª ? " << '\n';
    cin >> size;
    cin.ignore();
    for (int i = 0; i < size; i++) {
        cout << "¢¢¥¤¨â¥ " << i + 1 << " í«¥¬¥­â: ";
        getline(cin, str);
        pushfront(stack, str);
    }
    cout << "áâ¥ª" << '\n';
    printst(stack);
    getline(cin, str);
    pushfront(stack, str);
    printst(stack);
    popfront(stack);
    printst(stack);
    addstack(stack);
    return 0;
}
