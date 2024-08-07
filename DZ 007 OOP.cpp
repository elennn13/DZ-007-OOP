#include <iostream>

template <typename T>
class Matrix {
private:
    int rows; // количество строк
    int cols; // количество столбцов
    T** data; // указатель на двумерный массив

public:
    // Конструкторы
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        data = new T * [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
        }
    }

    // Деструктор
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Методы
    void fillFromKeyboard() { // Метод fillFromKeyboard() позволяет заполнить матрицу с клавиатуры
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cin >> data[i][j];
            }
        }
    }

    void fillRandom() { // позволяет заполнить матрицу случайными значениями
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = rand() % 100;
            }
        }
    }

    void display() { //  выводит матрицу на экран
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    T getMax() { // находят максимальный элементы матрицы.
        T max = data[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] > max) {
                    max = data[i][j];
                }
            }
        }
        return max;
    }

    T getMin() { // находят минимальный элементы матрицы.
        T min = data[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] < min) {
                    min = data[i][j];
                }
            }
        }
        return min;
    }

    // Перегрузка операторов
    Matrix operator+(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
};