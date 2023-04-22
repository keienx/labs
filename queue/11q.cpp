#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct Point {
    string value;
    Point* next = nullptr;
};

struct Queue {
    int size = 0;
    Point* head = nullptr;
    Point* tail = nullptr;
};

void push(Queue& queue, string& value) {
    Point* new_Point = new Point;
    new_Point->value = value;
    queue.size++;
    if (queue.head != nullptr) {
        new_Point->next = nullptr;
        queue.tail->next = new_Point;
        queue.tail = new_Point;
    }
    else {
        queue.head = new_Point;
        queue.tail = new_Point;
    }
}

void full(Queue& queue, int size) {
    string value;
    for (int i = 1; i <= size; i++) {
        cout << "Введите значение " << i << " элемента: ";
        cin >> value;
        push(queue, value);
    }
}

void print(Queue& queue) {
    cout << "Очередь: =  ";
    Point* p = queue.head;
    while (p != nullptr) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << '\n';
}

void pop(Queue& queue) {
    Point* p = queue.head;
    queue.head = queue.head->next;
    queue.size--;
    delete p;
}

void insert(Queue& queue, int index) {
    int i = 1;
    while (i < index) {
        push(queue, queue.head->value);
        pop(queue);
        i++;
    }
    string value;
    cout << "Введите значение для вставки " << i << " элементом ";
    cin >> value;
    push(queue, value);
    for (i; i < queue.size; i++) {
        push(queue, queue.head->value);
        pop(queue);
    }
}

void addq(Queue & queue){
    ofstream out("file4.txt");
    Point* current = queue.head;
    while (current != nullptr) {
        out << current->value << " ";
        current = current->next;
    }
    out.close();
}

void fromq(Queue& queue, int size){
    string buf;
    ifstream in("file4.txt");
    getline(in, buf);
    push(queue, buf);
    in.close();
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Queue queue;
    int size, i;
    cout << "Введите размер очереди: ";
    cin >> size;
    full(queue, size);
    print(queue);
    cout << "номер\n";
    cin >> i;
    size++;
    insert(queue, i);
    print(queue);
    pop(queue);
    print(queue);
    addq(queue);
    return 0;
}
