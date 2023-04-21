#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Point{
    string value;
    Point* next = nullptr;
};

struct List{
    Point* head = nullptr;
    Point* tail = nullptr;
};

List list;

void popfirst(List& list){
    Point* new_point = list.head;
    list.head = new_point->next;
    delete new_point;
}

void poplast(List& list){
    Point* new_point = list.head;
    while (new_point->next != list.tail){
        new_point = new_point->next;
    }
    new_point->next = nullptr;
    delete list.tail;
    list.tail = new_point;
}

void pushfront(List& list, string& value){
    Point* new_point = new Point;
    new_point->value = value;
    if (list.head == nullptr){
        list.head = new_point;
        list.tail = new_point;
    }
    else{
        new_point -> next = list.head;
        list.head = new_point;
    }
}

void pushback(List& list, string& value){
    Point* new_point = new Point;
    new_point->value = value;
    if (list.head == nullptr){
       list.head = new_point;
       list.tail = new_point;
    }
    else{
       list.tail -> next = new_point;
       list.tail = new_point;
    }
}

void pushq(List& list, string value, int elem){
    Point* new_point = new Point;
    new_point->value = value;
    Point* p2 = list.head;
    Point* p3 = list.head;
    for(int i = 1; i <= elem - 2 ; i++){
        p2 = p2->next;
    }
    if (elem <= 1){
        pushfront(list, value);
    }
    else{
        for(int i = 1; i <= elem - 1 ; i++){
            p3 = p3->next;
        }
        p2->next = new_point;
        new_point->next = p3;
    }
}

void deleteq(List& list, int elem2){
    Point* new_point = list.head;
    Point* p2 = list.head;
    for(int i = 1; i <= elem2 - 3; i++){
        new_point = new_point->next;
    }
    if (elem2 <= 2){
        popfirst(list);
    }
    else{
        for(int i = 1; i <= elem2 - 1; i++){
            p2 = p2->next;
        }
        new_point->next = p2;
    }
}

void showmenu(){
    cout << "1. Создать список\n";
    cout << "2. Вывод списка на экран\n";
    cout << "3. Добавить элемент в начало\n";
    cout << "4. Добавить элемент в конец\n";
    cout << "5. Удалить начальный элемент\n";
    cout << "6. Удалить конечный элемент\n";
    cout << "7. Добавить несколько элементов\n";
    cout << "8. Удалить несколько элементов\n";
    cout << "9. Записать список в файл\n";
    cout << "10. Считать список из файла\n";
}

void printlist(List& list){
    Point* current = list.head;
    while (current != nullptr){
        cout << current->value << " \t ";
        current = current->next; 
    }
    cout << "\n";
}

void addlist(List & list){
    ofstream out("file.txt");
    Point* current = list.head;
    while (current != nullptr){
        out << current->value << "\n";
        current = current->next; 
    }
    out.close();
}

void createlist(int size){
    string str;
    cin.ignore();
    for (int i = 0; i < size; i++){
        getline(cin, str);
        pushback(list, str);
    }
}

void fromlist(List& list, int size){
    string buf;
    ifstream in("file.txt");
    for (int i = 0; i < size; i++){
        getline(in, buf);
        pushback(list, buf);
    }
    in.close();
}

void menu(){
    string str;
    int choice, size, quantity, index;
    while (choice != -1){
        system("pause");
        system("cls");
        showmenu();
        cin >> choice;
        switch(choice){
            case 1: {
                cout << "Введите количество элементов списка\n";
                cin >> size;
                createlist(size);
                break;
            }
            case 2: {
                printlist(list);
                break;
            }
            case 3: {
                cin.ignore();
                cout << "Введите добавляемый элемент\n";
                getline(cin, str);
                pushfront(list, str);
                break;
            }
            case 4: {
                cin.ignore();
                cout << "Введите добавляемый элемент\n";
                getline(cin, str);
                pushback(list, str);
                break;
            }
            case 5: {
                popfirst(list);
                break;
            }
            case 6: {
                poplast(list);
                break;
            }
            case 7: {
                cout << "Сколько элементов добавить?\n";
                cin >> quantity;
                cout << "Перед каким по счету?\n";
                cin >> index;
                cin.ignore();
                for (int i = 0; i < quantity; i++){
                    getline(cin, str);
                    pushq(list, str, index);
                    index++;
                }
                break;
            }
            case 8: {
                cout << "Сколько элементов удалить?\n";
                cin >> quantity;
                cout << "Перед каким по счету?\n";
                cin >> index;
                for (int i = 0; i < quantity; i++){
                    deleteq(list, index);
                    index--;
                }
                break;
            }
            case 9: {
                addlist(list);
                break;
            }
            case 10: {
                cout << "Введите количество символов списка\n";
                cin >> size;
                fromlist(list, size);
                break;
            }
            default: {
                cout << "??\n";
                break;
            }
        }
    }
}

int main(){
    system("chcp 1251 >> null");
    menu();
}

