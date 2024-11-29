include <iostream>
using namespace std;

struct Matrix {
  // двумерный массив с данными.
  int** data_ = nullptr;
  // количество столбцов
  size_t n_ = 0u;
  // количество строк
  size_t m_ = 0u;
};

// Создает заполненную нулями матрицу n x m.
void Construct(Matrix& out, size_t n, size_t m)
{
    out.n_ = n;
    out.m_ = m;
    out.data_ = new int*[n];
    for(int i = 0; i < n; ++i)
    {
        out.data_[i] = new int[m];
        for(int j = 0; j < m; ++j)
        {
            out.data_[j][i] = 0;
        }
    }
}
// Освобождает выделенную память.
void Destruct(Matrix& in)
{
    for(int i = 0; i < in.n_; ++i) delete[] in.data_[i];
    delete[] in.data_;
}

// Создает копию матрицы |matrix|.
Matrix Copy(const Matrix& matrix)
{
    Matrix m;
    Construct(m, matrix.n_, matrix.m_);
    for(int j = 0; j < m.n_; ++j)
    {
        for(int i = 0; i < m.m_; ++i)
        {
            m.data_[i][j] = matrix.data_[i][j];
        }
    }
    return m;
}
// Возвращает сумму двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Add(const Matrix& a, const Matrix& b)
{
    Matrix x;
    Construct(x, a.n_, a.m_);
    if(a.m_ != b.m_ or a.n_ != b.n_) return x;
    for(int j = 0; j < x.n_; ++j)
    {
        for(int i = 0; i < x.m_; ++i)
        {
            x.data_[i][j] = a.data_[i][j] + b.data_[i][j];
        }
    }
    return x;
}
// Возвращает разницу двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Sub(const Matrix& a, const Matrix& b)
{
    Matrix x;
    Construct(x, a.n_, a.m_);
    if(a.m_ != b.m_ or a.n_ != b.n_) return x;
    for(int j = 0; j < x.n_; ++j)
    {
        for(int i = 0; i < x.m_; ++i)
        {
            x.data_[i][j] = a.data_[i][j] - b.data_[i][j];
        }
    }
    return x;
}
// Возвращает произведение двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Mult(const Matrix& a, const Matrix& b)
{
    Matrix x;
    Construct(x, b.n_, a.m_);
    if(a.n_ != b.m_) return x;
    for(int i = 0; i < x.m_; ++i)
    {
        for(int j = 0; j < x.n_; ++j)
        {
            for(int k = 0; k < a.n_; ++k)
                x.data_[i][j] += a.data_[i][k] * b.data_[k][j];
        }
    }
    return x;
}

// Транспонирование матрицы.
void Transposition(Matrix& matrix)
{
    Matrix x = Copy(matrix);
    Destruct(matrix);
    Construct(matrix, x.m_, x.n_);
    for(int i = 0; i < matrix.m_; ++i)
    {
        for(int j = 0; j < matrix.n_; ++j)
        {
            matrix.data_[i][j] = x.data_[j][i];
        }
    }
    Destruct(x);
}

// Сравнение двух матриц.
bool operator==(const Matrix& a, const Matrix& b)
{
    if(a.m_ != b.m_ or a.n_ != b.n_) return 0;
    for(int i = 0; i < a.m_; ++i)
    {
        for(int j = 0; j < a.n_; ++j)
        {
            if(a.data_[i][j] != b.data_[i][j]) return 0;
        }
    }
    return 1;
}
