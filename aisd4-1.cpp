#include "Tree.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
using namespace std;

int check()
{
    int number;
    while (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Некорректное значение. Попробуйте еще раз." << endl;
    }
    return number;
}

size_t lcg()
{
    static size_t x = 0;
    x = (1021 * x + 24631) % 116640;
    return x;
}

void add(Tree& obj)
{
    cout << "ВВОД ЭЛЕМЕНТА" << endl;
    cout << "Введите элемент" << endl;
    int node = check();
    obj.insert(node);
}

void add_and_delete_v(int size)
{
    clock_t start, end;
    double mean_time = 0;


    for (int i = 0; i < 100; i++)
    {
        vector<int> obj;
        for (int j = 0; j < size; j++)
            obj.push_back(int(lcg()));
        int key = int(lcg());
        while (find(obj.begin(), obj.end(), key) != obj.end())
            key = int(lcg());
        start = clock();
        obj.push_back(key);
        end = clock();
        mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
    }
    mean_time /= 100;
    cout << endl << "Время вставки элемента в вектор размером " << size << " элементов: " << mean_time << endl;
    mean_time = 0;
    for (int i = 0; i < 100; i++)
    {
        vector<int> obj;
        for (int j = 0; j < size; j++)
            obj.push_back(int(lcg()));
        int key = int(lcg());
        while (find(obj.begin(), obj.end(), key) == obj.end())
            key = int(lcg());
        start = clock();
        obj.erase(find(obj.begin(), obj.end(), key));
        end = clock();
        mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
    }
    mean_time /= 100;
    cout << endl << "Время удаления элемента из вектора размером " << size << " элементов: " << mean_time << endl;
    getchar();
}

void add_and_delete_time(int size)
{
    clock_t start, end;
    double mean_time = 0;


    for (int i = 0; i < 1000; i++)
    {
        Tree obj;
        for (int j = 0; j < size; j++)
            obj.insert(int(lcg()));
        int key = int(lcg());
        while (obj.contains(key) == true) key = int(lcg());
        start = clock();
        obj.insert(key);
        end = clock();
        mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
    }
    mean_time /= 1000;
    cout << endl << "Время вставки элемента в дерево размером " << size << " элементов: " << mean_time << endl;
    mean_time = 0;
    for (int i = 0; i < 1000; i++)
    {
        Tree obj;
        for (int j = 0; j < size; j++)
            obj.insert(int(lcg()));
        int key = int(lcg());
        while (obj.contains(key) == false) key = int(lcg());
        start = clock();
        obj.erase(key);
        end = clock();
        mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
    }
    mean_time /= 1000;
    cout << endl << "Время удаления элемента из дерева размером  " << size << " элементов: " << mean_time << endl;
    add_and_delete_v(size);
    getchar();
}

void check_node(Tree& obj)
{
    cout << "ПРОВЕРКА ЭЛЕМЕНТОВ НА НАЛИЧИЕ В ДЕРЕВЕ" << endl;
    cout << "Введите элемент" << endl;
    int node = check();
    if (obj.contains(node))
        cout << "Элемент существует";
    else
        cout << "Элемент не существует";
    getchar();
}

void create_v(int size)
{
    clock_t start, end;
    double mean_time = 0;
    for (int i = 0; i < 100; i += 1)
    {
        vector<int> tmp;
        start = clock();
        for (int j = 0; j < size; j++)
            tmp.push_back(int(lcg()));
        end = clock();
        mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
    }
    mean_time /= 100;
    cout << endl << "Время создания вектора с " << size << " элементов: " << mean_time << endl;
    getchar();
}

void create_time(int size)
{
    clock_t start, end;
    double mean_time = 0;
    for (int i = 0; i < 100; i += 1)
    {
        Tree tmp;
        start = clock();
        for (int j = 0; j < size; j++)
            tmp.insert(int(lcg()));
        end = clock();
        mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
    }
    mean_time /= 100;
    cout << endl << "Время создания дерева с " << size << " элементов: " << mean_time << endl;
    create_v(size);
    getchar();
}

void delete_node(Tree& obj)
{
    cout << "УДАЛЕНИЕ ЭЛЕМЕНТА" << endl;
    cout << "Введите элемент" << endl;
    int node = check();
    obj.erase(node);
    getchar();
}

void insert_dup(Node*& root, int data, vector<int>& duplicates) {
    if (root == nullptr) {
        root = new Node(data);
    }
    else if (data < root->_data) {
        insert_dup(root->_left, data, duplicates);
    }
    else if (data > root->_data) {
        insert_dup(root->_right, data, duplicates);
    }
    else {
        duplicates.push_back(data);
    }
}

void findDuplicates(vector<int>& nums) {
    Node* root = nullptr;
    std::vector<int> duplicates;

    for (int num : nums) {
        insert_dup(root, num, duplicates);
    }

    if (duplicates.size() > 0) {
        std::cout << "Найденные дубликаты: ";
        for (int dup : duplicates) {
            std::cout << dup << " ";
        }
        cout << endl;
    }
    else {
        cout << "Дубликаты не найденны" << endl;
    }
}

void exercise(Tree& obj) {
    vector<int> nums = { 3, 2, 2, 4, 4, 5, 5, 6, 8, 10, 3, 50, 20, 20, 15, 19, 11, 7 };
    findDuplicates(nums);
}


int muny()
{
    cout << "Выберите действие" << endl;
    cout << "1 - Добавить элемент" << endl;
    cout << "2 - Проверить элемент" << endl;
    cout << "3 - Удалить элемент" << endl;
    cout << "4 - Вывести дерево" << endl;
    cout << "5 - Задание" << endl;
    cout << "6 - Проверка на время" << endl;
    cout << "7 - Выход" << endl;
    cout << "Операция: ";
    int n = check();
    while (n > 7 || n <= 0)
    {
        cout << "Некорректное значение. Попробуйте еще раз." << endl << "Операция: ";
        n = check();
    }
    system("cls");
    return n;
}

void print_tree(Tree& obj)
{
    obj.print();
    getchar();
}

void search_v(int size)
{
    clock_t start, end;
    vector<int> obj;
    double mean_time = 0;

    for (int j = 0; j < size; j++)
        obj.push_back(int(lcg()));

    for (int i = 0; i < 1000; i++)
    {
        int key = int(lcg());
        while (find(obj.begin(), obj.end(), key) == obj.end())
            key = int(lcg());
        start = clock();
        find(obj.begin(), obj.end(), key);
        end = clock();
        mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
    }
    mean_time /= 1000;
    cout << endl << "Время поиска элемента в векторе размером  " << size << " элементов: " << mean_time << endl;
    getchar();
}

void search_time(int size)
{
    clock_t start, end;
    Tree obj;
    double mean_time = 0;

    for (int j = 0; j < size; j++)
        obj.insert(int(lcg()));

    for (int i = 0; i < 1000; i++)
    {
        int key = int(lcg());
        while (obj.contains(key) == false) key = int(lcg());
        start = clock();
        obj.contains(key);
        end = clock();
        mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
    }
    mean_time /= 1000;
    cout << endl << "Время поиска элемента в дереве размером " << size << " элементов: " << mean_time << endl;
    search_v(size);
    getchar();
}

void muny_time(Tree& obj)
{
    cout << "СРЕДНЕЕ ВРЕМЯ" << endl;
    cout << "Какое время рассчитать?" << endl;
    cout << "1 - Заполнение дерева" << endl;
    cout << "2 - Поиск числа" << endl;
    cout << "3 - Добавление и удаление" << endl;
    cout << "Операция: ";
    int n = check();
    while (n > 3 || n <= 0)
    {
        cout << "Некорректное значение. Попробуйте еще раз." << endl << "Операция: ";
        n = check();
    }

    cout << "Какого размера дерево?" << endl;
    cout << "1 - 1000" << endl;
    cout << "2 - 10000" << endl;
    cout << "3 - 100000" << endl;
    cout << "Операция: ";
    int size = check();
    while (size > 3 || size <= 0)
    {
        cout << "Некорректное значение. Попробуйте еще раз." << endl << "Операция: ";
        size = check();
    }
    system("cls");
    switch (size) {
    case 1:
        size = 1000;
        break;
    case 2:
        size = 10000;
        break;
    case 3:
        size = 100000;
        break;
    default:
        break;
    }
    void (*operatoin[3])(int size) = { create_time, search_time, add_and_delete_time };
    operatoin[n - 1](size);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    void (*operatoin[6])(Tree & obj) = { add, check_node, delete_node, print_tree, exercise, muny_time };
    Tree obj;
    int n = muny();
    getchar();
    while (n < 7)
    {
        operatoin[n - 1](obj);
        getchar();
        system("cls");
        cout << "Что дальше?" << endl;
        n = muny();
    }
}