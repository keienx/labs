#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

string names[10] = { "Андрей", "Иван", "Петр", "Дмитрий", "Евгений", "Антон", "Олег", "Артем", "Глеб", "Максим" };
string patronymic[10] = { "Андреевич", "Иванович", "Петрович","Дмитриевич", "Евгеньевич", "Антонович", "Олегович", "Артемович", "Глебович", "Максимович" };
string surnames[10] = { "Смирнов", "Маслов", "Сафронов", "Кузнецов", "Горбачёв", "Вариков", "Филатов", "Аксенов", "Боженов", "Лужков" };
string phones[10] = { "88422352177", "84959631102", "84953245489", "84953584156", "84959524920", "89226593865", "89347681002", "893456781187", "89349850335", "89348790476" };
string ID[10] = { "4759 969117", "4481 920688", "4340 756756", "4340 756756", "4793 464759", "5717 729432", "5717 726552", "5718 707432", "5718 723419", "5717 734532" };
string dates[10] = { "15.11.1969", "27.01.1996", "23.10.1972", "13.04.1993", "20.07.1985", "01.04.1988", "13.07.1999", "19.09.1964", "26.11.1987", "30.12.1982" };
int collisions_count = 0;

struct Human {
	Human()
	{
		full_name = "NULL";
		ID_number = "NULL";
		phone_number = "NULL";
		date_of_birth = "NULL";
	}
	string full_name;
	string ID_number;
	string phone_number;
	string date_of_birth;
};

struct hash_table {
	Human* array;
	hash_table(int size)
	{
		array = new Human[size];
	}
	~hash_table()
	{
		delete[] array;
	}
	void add(Human temp, const int size);
	void pop(string date_to_delete, const int size);
	void find_index(string date_of_birth, const int size);
};

void fill_array_random_humans(Human* array, const int count);
Human create_random_human();
string get_random_name();
string get_random_ID();
string get_random_phone();
string get_random_date();
int get_random_number();
int get_sum_of_date(string str);
int hash_function(string str, const int size);
void show_hash_table(hash_table& table, const int size);


void fill_array_random_humans(Human* array, const int count) {
	for (int i = 0; i < count; i++)
		array[i] = create_random_human();
}

Human create_random_human() {
	Human temp;
	temp.full_name = get_random_name();
	temp.ID_number = get_random_ID();
	temp.phone_number = get_random_phone();
	temp.date_of_birth = get_random_date();
	return temp;
}

string get_random_name() {
	return (surnames[get_random_number()] + " " + names[get_random_number()] + " " + patronymic[get_random_number()]);
}

string get_random_ID() {
	return ID[get_random_number()];
}

string get_random_phone() {
	return phones[get_random_number()];
}

string get_random_date() {
	return dates[get_random_number()];
}

int get_random_number() {
	return rand() % 10;
}

void hash_table::add(Human temp, const int size) {
	int hash = hash_function(temp.date_of_birth, size);	//hash функция возвращает ключ, по которому программа будет пытаться добавить элемент
	int index = hash;
	if (array[index].full_name == "NULL") {
		array[index] = temp;
		return;
	}
	else {
		++index;
		while (index < size) {
			if (array[index].full_name == "NULL") {
				array[index] = temp;
				return;
			}
			++index;
			++collisions_count;
		}
		if (index == size) {
			index = 0;
			++collisions_count;
			while (index < hash) {
				if (array[index].full_name == "NULL") {
					array[index] = temp;
					return;
				}
				++index;
				++collisions_count;
			}
		}
	}
}

void hash_table::find_index(string date_of_birth, const int size) {
	int hash = hash_function(date_of_birth, size);
	int index = hash;
	while (array[index].date_of_birth != date_of_birth && index < size) {
		++index;
	}
	if (index == size) {
		index = 0;
		while (array[index].date_of_birth != date_of_birth && index < hash) {
			++index;
		}
		if (index == hash) {
			cout << "Человека с датой рождения \"" << date_of_birth << "\" нет.\n\n";
		}
		else {
			cout << "Человек с датой рождения \"" << date_of_birth << "\" содержится по индексу " << index << '\n' << '\n';
		}
	}
	else {
		cout << "Человек с датой рождения \"" << date_of_birth << "\" содержится по индексу " << index << '\n' << '\n';
	}
}

void hash_table::pop(string date_to_delete, const int size) {
	int hash = hash_function(date_to_delete, size);
	int index = hash;
	if (array[index].date_of_birth == date_to_delete) {
		array[index] = Human();
		return;
	}
	else {
		++index;
		while (index < size) {
			if (array[index].date_of_birth == date_to_delete) {
				array[index] = Human();
				return;
			}
			++index;
		}
		if (index == size) {
			index = 0;
			while (index < hash) {
				if (array[index].date_of_birth == date_to_delete) {
					array[index] = Human();
					return;
				}
				++index;
			}
		}
	}
}

int hash_function(string str, const int size) {
	double a = ((sqrt(2) - 1)) * get_sum_of_date(str);	// a = 0.414 * 2019 == 835.866
	double c = size * (a - int(a));	// с = 10 * (835.866 - 835) == 8.66
	return int(c);	// с == 8
}

int get_sum_of_date(string str) {
	return stoi(str.substr(0, 2)) + stoi(str.substr(3, 2)) + stoi(str.substr(6, 4));
}

void show_hash_table(hash_table& table, const int size) {
	for (int i = 0; i < size; ++i)
	{
		cout << "ФИО: " << table.array[i].full_name
			<< "\nДата рождения: " << table.array[i].date_of_birth
			<< "\nНомер телефона: " << table.array[i].phone_number
			<< "\nСерия и номер паспорта: " << table.array[i].ID_number << '\n' << '\n';
	}
}

int main() {
	srand(time(0));
	int size;
	cout << "Введите количество элементов в массиве: ";
	cin >> size;
	cout << '\n';
	Human* array = new Human[size];
	hash_table table(size);
	fill_array_random_humans(array, size);
	for (int i = 0; i < size; ++i) {
		table.add(array[i], size);
	}
	show_hash_table(table, size);
	table.find_index("23.10.1972", size);
	table.pop("23.10.1972", size);
	cout << "=================================================" << '\n' << '\n';
	show_hash_table(table, size);
	cout << '\n' << "Количество коллизий для " << size << " записей: " << collisions_count << '\n';
	delete[] array;
	return 0;
}