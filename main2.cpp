#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

int binarySearch(int arr[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == value) {
            return mid;
        }
        if (arr[mid] > value) {
            return binarySearch(arr, value, start, mid - 1);
        }

        return binarySearch(arr, value, mid + 1, end);
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    constexpr int N = 100;
    int arr[N] = {};
    bool task = true;
    int choose = 0, idz = 0, idzChoose = -1;

    while (choose != -1) {
        cout << "\n\n\nИз данных заданий, выберете то, которое хотите выполнить: \n"
                "1.Создает массив размерности N = 100. Элементы массива принимают случайное значение в диапазоне от -99 до 99.\n"
                "2.Отсортировать 1 массив сортировкой (от меньшего к большему). Определить время,затраченное на сортировку.\n"
                "3.Найти максимальный и минимальный элемент массива. Подсчитать время поиска этих элементов в отсортированном и неотсортированном.\n"
                "4.Выводит среднее значение максимального и минимального значения в отсортированном и неотсортированном. Вывести индексы всех элементов и их количество. Подсчитать время поиска.\n"
                "5.Выводит количество элементов в отсортированном массиве, которые меньше числа a.\n"
                "6.Выводит количество элементов в отсортированном массиве, которые больше числа b.\n"
                "7.Выводит информацию о том, есть ли введенное пользователем число в отсортированном массиве.\n"
                "8.Меняет местами элементы массива, индексы которых вводит пользователь. Выведите скорость обмена.\n"
                "9.Идивидуальное домашнее задание.\n\n\n";

        cout << "Задание: ";
        cin >> choose;
        cout << "\n";

        if (choose != 1 and choose != 2 and choose != 3 and choose != 4 and choose != 5 and choose != 6 and choose != 7
            and choose != 8 and choose != 9 and choose != 0)
            cout << "Такого варианта ответа нет \n";

        else
            int arr[N];
        for (int i = 0; i < N; i++) {
            arr[i] = rand() % 199 - 99;
        }

        switch (choose) {

            case 0: {
                cout << "Пока \n\n";
                choose = -1;
            break;
            }

            case 1: {
                for (int i = 0; i < N; i++) {
                    cout << arr[i] << " ";
                }
                cout << '\n' << '\n';
                break;
            }

            case 2: {
                using fseconds = std::chrono::duration<float>;
                cout << '\n';
                const auto start = chrono::high_resolution_clock::now();
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N - 1 - i; j++) {
                        if (arr[j] > arr[j + 1]) {
                            int arr1 = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = arr1;
                        }
                    }
                }
                const auto end = chrono::high_resolution_clock::now();
                const std::chrono::duration<double> durationTime = end - start;
                cout << "Полученный массив: ";
                for (int i = 0; i < N; i++) {
                    cout << arr[i] << " ";
                }
                cout << '\n' << '\n' << "Затраченное время: " << durationTime.count() << " секунд" << '\n' << '\n';
                break;
            }

            case 3: {
                using fseconds = std::chrono::duration<float>;
                int max, min;
                max = arr[0];
                min = arr[0];
                const auto start = chrono::high_resolution_clock::now();
                for (int i = 1; i < N; ++i) {
                    if (arr[i] > max) {
                        max = arr[i];
                    }
                    if (arr[i] < min) {
                        min = arr[i];
                    }
                }
                const auto end = chrono::high_resolution_clock::now();
                const std::chrono::duration<double> durationTime = end - start;
                cout << '\n' << "Неотсортированный массив: " << '\n' << '\n' << "Минимальное значение: " \
                << min << '\n' << "Максимальное значение: " << max << '\n' \
                << "Время поиска: " << durationTime.count() << " секунд" << '\n';
                cout << "Полученный массив: ";
                for (int i = 0; i < N; i++) {
                    cout << arr[i] << " ";
                }
                cout << '\n' << '\n';
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            int arr2 = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = arr2;
                        }
                    }
                }
                const auto start1 = chrono::high_resolution_clock::now();
                max = arr[99];
                min = arr[0];
                const auto end1 = chrono::high_resolution_clock::now();
                const std::chrono::duration<double> durationTime1 = end - start;
                cout << "Отсортированный массив: " << '\n' << '\n' << "Минимальное значение: " \
                << min << '\n' << "Максимальное значение: " << max << '\n' \
                << "Время поиска: " << durationTime.count() << " секунд" << '\n';
                cout << "Полученный массив: ";
                for (int i = 0; i < N; i++) {
                    cout << arr[i] << " ";
                }
                cout << '\n' << '\n';
                break;
            }

            case 4: {
                using fseconds = std::chrono::duration<float>;
                int max, min, sum, sum01, sum02;
                sum = 0;
                int counter = 0;
                max = arr[0];
                min = arr[0];
                for(int i = 0; i < N; ++i){
                    if (arr[i] > max){
                        max = arr[i];
                    }
                    if (arr[i] < min){
                        min = arr[i];
                    }
                }
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            int arr3 = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = arr3;
                        }
                    }
                }
                sum = ( (max + min) / 2);
                for (int i = 0; i < N; i++) {
                    cout << arr[i] << " ";
                }
                cout << '\n' << "Среднее значение: " << sum << '\n';
                const auto start = chrono::high_resolution_clock::now();
                for(int i = 0; i < N; i++) {
                    if (arr[i] == sum) {
                        counter += 1;
                        cout << "Индекс элемента равного среднему значению: " << i << endl;
                    }
                }
                if (counter==0){
                    cout<<"Таких индесов нет"<<endl;
                }
                else
                    cout<<"Количество: "<<counter;
                const auto end = chrono::high_resolution_clock::now();
                const std::chrono::duration<double> durationTime = end - start;
                cout << '\n' <<"Затраченное время: " << durationTime.count() << " секунд" << '\n' << '\n';
                break;
            }

            case 5: {
                int a, number;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            int arr4 = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = arr4;
                        }
                    }
                }
                cout << '\n' << "Введите число: ";
                cin >> a;
                number = 0;
                while(arr[number] < a) {
                    number += 1;
                }
                cout << '\n' << "Количество элементов: " << number << '\n' << '\n';
                break;
            }

            case 6: {
                int b, number;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            int arr4 = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = arr4;
                        }
                    }
                }
                cout << '\n' << "Введите число: ";
                cin >> b;
                number = 99;
                while(arr[number] > b) {
                    number -= 1;
                }
                cout << '\n' << "Количество элементов: " << 99 - number << '\n' << '\n';
                break;
            }

            case 7: {
                int user_choice=0;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N - 1 - i; j++) {
                        if (arr[j] > arr[j + 1]) {
                            int arr1 = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = arr1;
                        }
                    }
                }
                for (int i = 0; i < N; i++) {
                    cout << arr[i] << " ";
                }
                cout<<'\n';
                cout << "Введите число: ";
                cin>>user_choice;

                //binary search
                const auto start = chrono::high_resolution_clock::now();
                int is_in_array=binarySearch(arr,user_choice,0,N);
                const auto end = chrono::high_resolution_clock::now();
                const std::chrono::duration<double> durationTime = end - start;
                cout << '\n' <<"Затраченное время: " << durationTime.count() << " секунд" << '\n';

                //perebor
                const auto start1 = chrono::high_resolution_clock::now();
                for (int i = 0; i < N; i++) {
                    if (user_choice==arr[i]||i==N-1)
                    {
                        const auto end1 = chrono::high_resolution_clock::now();
                        const std::chrono::duration<double> durationTime1 = end1 - start1;
                        cout << '\n' <<"Затраченное время1: " << durationTime1.count() << " секунд" << '\n' << '\n';
                        break;
                    }
                }
                if (is_in_array!=-1)
                    cout<<"Введённое число есть\n";
                else
                    cout<<"Введённого числа нет\n";
                break;
            }

            case 8: {
                int firstIndex, secondIndex;
                using fseconds = std::chrono::duration<float>;
                cout << '\n' << "Введите первый индекс: ";
                cin >> firstIndex;
                cout << '\n' << "Введите второй индекс: ";
                cin >> secondIndex;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            int arr4 = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = arr4;
                        }
                    }
                }
                const auto start = chrono::high_resolution_clock::now();
                swap(arr[firstIndex], arr[secondIndex]);
                const auto end = chrono::high_resolution_clock::now();
                const std::chrono::duration<double> durationTime = end - start;
                cout << '\n' << "Затраченное время: " << durationTime.count() << " секунд" << '\n';
                cout << '\n' << "Полученный массив: ";
                for(int i = 0; i < N; i++){
                    cout << arr[i] << " ";
                }
                cout << '\n';
                break;
            }

            case 9: {
                int zamenMinus;
                int k = 0;
                cout << '\n' << "Введите число: ";
                cin >> zamenMinus;
                cout << '\n';
                for(int i = 0; i < N; i++) {
                    if (arr[i] % 2 == 0) {
                        arr[i] = arr[i] - zamenMinus;
                        arr[i] = arr[i] * (rand() % 9 + 1);
                        k += 1;
                    }
                    cout << arr[i] << " ";
                }
                cout << '\n' << "Всего четных элементов: " << k << '\n' << "Всего нечетных элементов: " << 100-k << '\n';
                int kOf = 0;
                for (int j = 1; j < 10; ++j) {
                    for (int i = 0; i < N; ++i) {
                        if (arr[i] % j == 0) {
                            kOf++;
                        }
                    }
                    cout << kOf << " элементов, кратных " << j << '\n';
                    kOf = 0;
                }
                cout << '\n';
                break;
            }
        }
    }
    return 0;
}