#include <iostream> // для ввода/вывода
#include <vector> // для использования векторов
#include <deque> //для использования деков
#include <list> // для использования списков
#include <fstream> // для работы с файлами
#include <iterator> //  для использования итераторов
#include <algorithm> //  для алгоритмов
#include <string> //  для работы со строками
#include <limits> // для работы с границами потоков
#include <cctype> // для работы с символами
// Объявляем функции, представляющие задачи
void zadacha1(); 
void zadacha2(); 
void zadacha3(); 
void zadacha4(); 
void zadacha5(); 
void zadacha6(); 
// Функция для проверки, является ли строка числом
bool isNumber(const std::string& str) {
    // Проверка, что строка не пустая и первый символ - это цифра или знак (+ или -)
    if (str.empty() || (!isdigit(str[0]) && str[0] != '-' && str[0] != '+')) return false;
    
    char* p; // Указатель для хранения результата преобразования
    strtol(str.c_str(), &p, 10); // Преобразование строки в долгий целый тип
    return (*p == 0); // Если преобразование успешно, указатель p должен указывать на конец строки
}
// Функция для показа меню пользователю
void menu() {
    int choice; // Переменная для хранения выбора пользователя
    do {
        // Выводим доступные задания
        std::cout << "Выберите задачу (1-6) или 0 для выхода:\n"; 
        std::cout << "1 - Задача 1\n";
        std::cout << "2 - Задача 2\n";
        std::cout << "3 - Задача 3\n"; 
        std::cout << "4 - Задача 4\n"; 
        std::cout << "5 - Задача 5\n";
        std::cout << "6 - Задача 6\n"; 
        std::cout << "Ваш выбор: "; 
        std::cin >> choice; // Читаем выбор пользователя
        switch (choice) { // Проверяем выбор пользователя
            case 1: zadacha1(); break; // Если 1, вызываем задачу 1
            case 2: zadacha2(); break; // Если 2, вызываем задачу 2
            case 3: zadacha3(); break; // Если 3, вызываем задачу 3
            case 4: zadacha4(); break; // Если 4, вызываем задачу 4
            case 5: zadacha5(); break; // Если 5, вызываем задачу 5
            case 6: zadacha6(); break; // Если 6, вызываем задачу 6
            case 0: break; // Если 0, выходим из меню
            default: std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n"; // Сообщение об ошибке
        }
        
    } while (choice != 0); // Повторяем, пока пользователь не выберет 0 для выхода
}
// Задача 1: Чтение чисел из файла и вывод на экран
void zadacha1() {
    std::string filename; // Имя файла для чтения
    std::cout << "Введите имя файла: "; // Запрос имени файла
    std::cin >> filename; // Чтение имени файла
    std::ifstream file(filename); // Открываем файл для чтения
    if (!file.is_open()) { // Проверяем, успешно ли открылся файл
        std::cerr << "Ошибка открытия файла!\n"; // Выводим сообщение об ошибке
        return; // Выходим из функции
    }
    std::vector<int> V; // Создаем вектор для хранения чисел
    int num; // Переменная для чтения числа
    while (file >> num) { // Читаем числа из файла
        V.push_back(num); // Добавляем число в вектор
    }
    file.close(); // Закрываем файл
    std::cout << "Элементы вектора:\n"; 
    for (int n : V) { // Перебираем элементы вектора
        std::cout << n << " "; // Выводим элементы на экран
    }
    std::cout << std::endl; // Печатаем новую строку
}
// Задача 2: Ввод элементов вектора и дека и изменение их
void zadacha2() {
    std::vector<int> V; // Вектор для хранения чисел
    std::deque<int> D; // Дек для хранения чисел
    std::string input; // Переменная для ввода
    std::cout << "Введите элементы вектора V (введите -1 для завершения ввода): \n"; 
    while (std::cin >> input && input != "-1") { // Читаем элементы вектора пока не введен -1
        if (isNumber(input)) { // Проверяем, является ли ввод числом
            V.push_back(std::stoi(input)); // Добавляем число в вектор
        } else {
            std::cout << "Некорректный ввод. Попробуйте снова.\n"; // Сообщение об ошибке
        }
    }
    std::cout << "Введите элементы дека D (введите -1 для завершения ввода): \n"; 
    while (std::cin >> input && input != "-1") { // Читаем элементы дека
        if (isNumber(input)) { // Проверяем, является ли ввод числом
            D.push_back(std::stoi(input)); // Добавляем число в дек
        } else {
            std::cout << "Некорректный ввод. Попробуйте снова.\n"; // Сообщение об ошибке
        }
    }
    size_t half_d_size = D.size() / 2; // Вычисляем половину размера дека
    V.insert(V.end(), D.begin(), D.begin() + half_d_size); // Добавляем первую половину дека в вектор
    D.insert(D.begin(), V.rbegin(), V.rbegin() + (V.size() / 2)); // Добавляем половину вектора в начало дека
    std::cout << "Вектор V после изменений:\n"; 
    for (int n : V) { // Перебираем элементы вектора
        std::cout << n << " "; // Выводим элементы на экран
    }
    std::cout << "\nДек D после изменений:\n"; 
    for (int n : D) { // Перебираем элементы дека
        std::cout << n << " "; // Выводим элементы на экран
    }
    std::cout << std::endl; // Печатаем новую строку
}
// Задача 3: Удаление всех элементов из вектора
void zadacha3() {
    std::vector<int> V; // Вектор для хранения чисел
    std::string input; // Переменная для ввода
    std::cout << "Введите элементы вектора V (введите -1 для завершения ввода): \n"; 
    while (std::cin >> input && input != "-1") { // Читаем элементы вектора пока не введен -1
        if (isNumber(input)) { // Проверяем, является ли ввод числом
            V.push_back(std::stoi(input)); // Добавляем число в вектор
        } else {
            std::cout << "Некорректный ввод. Попробуйте снова.\n"; // Сообщение об ошибке
        }
    }
    std::cout << "Исходный вектор V:\n"; 
    for (int n : V) { // Перебираем элементы вектора
        std::cout << n << " "; // Выводим элементы на экран
    }
    std::cout << std::endl; // Печатаем новую строку
    auto it = V.begin(); // Итератор для вектора
    while (it != V.end()) { // Проходим по вектору
        it = V.erase(it); // Удаляем элемент и получаем новый итератор
        if (it != V.end()) ++it; // Если не достигли конца, переходим к следующему элементу
    }
    std::cout << "Вектор V после удаления:\n"; 
    for (int n : V) { // Перебираем элементы вектора
        std::cout << n << " "; // Выводим элементы на экран
    }
    std::cout << std::endl; // Печатаем новую строку
}
// Задача 4: Чтение чисел из файла и вывод чисел с нечетными порядковыми номерами
void zadacha4() {
    std::string filename; // Имя файла для чтения
    std::cout << "Введите имя файла: "; // Запрос имени файла
    std::cin >> filename; // Чтение имени файла
    std::ifstream file(filename); // Открываем файл для чтения
    if (!file.is_open()) { // Проверяем, успешно ли открылся файл
        std::cerr << "Ошибка открытия файла!\n"; // Выводим сообщение об ошибке
        return; // Выходим из функции
    }
    // Чтение чисел из файла с помощью итераторов
    std::istream_iterator<int> start(file), end; 
    std::vector<int> V(start, end); // Создаем вектор из считанных чисел
    std::cout << "Числа с нечетными порядковыми номерами:\n"; 
    for (size_t i = 0; i < V.size(); ++i) { // Перебираем все элементы вектора
        if (i % 2 == 0) { // Проверяем, является ли индекс нечетным
            std::cout << V[i] << " "; // Выводим элемент на экран
        }
    }
    std::cout << std::endl; // Печатаем новую строку
}
// Задача 5: Вставка элементов в вектор на основе размера
void zadacha5() {
    int K; // Переменная для хранения значения K
    std::cout << "Введите K (больше 0): "; 
    while (!(std::cin >> K) || K <= 0) { // Проверка, что K корректно введено
        std::cout << "Некорректный ввод. Попробуйте снова: "; 
        std::cin.clear(); // Очищаем состояние потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем до конца строки
    }
    std::vector<int> V; // Вектор для хранения чисел
    std::string input; // Переменная для ввода
    std::cout << "Введите элементы вектора V (введите -1 для завершения ввода): \n"; 
    while (std::cin >> input && input != "-1") { // Читаем элементы вектора пока не введен -1
        if (isNumber(input)) { // Проверяем, является ли ввод числом
            V.push_back(std::stoi(input)); // Добавляем число в вектор
        } else {
            std::cout << "Некорректный ввод. Попробуйте снова.\n"; // Сообщение об ошибке
        }
    }
    // Поиск последовательности из K положительных элементов в векторе
    auto it = std::search_n(V.begin(), V.end(), K, 1, [](int n, int) { return n > 0; });
    if (it != V.end()) { // Если нашли последовательность
        std::vector<int> new_elements(it, it + K); // Создаем новый вектор из найденной последовательности
        V.insert(it + K, new_elements.begin(), new_elements.end()); // Вставляем новый вектор в оригинал
    }
    std::cout << "Вектор V после модификаций:\n"; 
    for (int n : V) { // Перебираем элементы вектора
        std::cout << n << " "; // Выводим элементы на экран
    }
    std::cout << std::endl; // Печатаем новую строку 
}
// Задача 6: Работа со списками и изменение их
void zadacha6() {
    std::list<int> L1, L2; // Списки L1 и L2
    int value; // Переменная для считывания значений
    std::cout << "Введите элементы списка L1 (введите -1 для завершения ввода): \n"; 
    while (std::cin >> value && value != -1) { // Читаем элементы списка L1
        L1.push_back(value); // Добавляем значение в список L1
    }
    std::cout << "Введите элементы списка L2 (введите -1 для завершения ввода): \n";
    while (std::cin >> value && value != -1) { // Читаем элементы списка L2
        L2.push_back(value); // Добавляем значение в список L2
    }
    int half_size_L1 = L1.size() / 2; // Вычисляем половину размера списка L1
    std::list<int> first_half_L1(L1.begin(), std::next(L1.begin(), half_size_L1)); // Получаем первую половину списка L1
    std::reverse_copy(first_half_L1.begin(), first_half_L1.end(), std::back_inserter(L1)); // Обратная копия первой половины в конец списка L1
    std::cout << "Список L1 после изменений:\n"; 
    for (int n : L1) { // Перебираем элементы списка L1
        std::cout << n << " "; // Выводим элементы на экран
    }
    std::cout << std::endl; // Печатаем новую строку
    int half_size_L2 = L2.size() / 2; // Вычисляем половину размера списка L2
    auto it_half_L2 = std::next(L2.begin(), half_size_L2); // Итератор для половины L2
    // Вставляем в конце списка L2 первую половину в `итератор`
    L2.insert(L2.end(), std::make_move_iterator(L2.begin()), std::make_move_iterator(it_half_L2));
    // Вставляем вторую половину в список L2
    L2.insert(L2.end(), std::make_move_iterator(--it_half_L2), std::make_move_iterator(L2.begin()));
    std::cout << "Список L2 после изменений:\n"; 
    for (int n : L2) { // Перебираем элементы списка L2
        std::cout << n << " "; // Выводим элементы на экран
    }
    std::cout << std::endl; // Печатаем новую строку 
}
// Главная функция программы
int main() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем локаль для вывода на русском
    menu(); // Вызываем меню
    return 0; // Возвращаем 0 для успешного завершения программы
}
