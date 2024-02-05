template<class T>
class Matrix {
    std::array<int, 2>dim;
    T* elem;
    
    Matrix(int d1, int d2) : dim{d1, d2}, elem{new T[d1*d2]} {}
    int size() const { return dim[0]*dim[1];}

    Matrix(const Matrix&);
    Matrix(Matrix&&);

    Matrix& operator=(const Matrix&); // copy assignment
    Matrix& operator=(Matrix&&); // move assignment

    Matrix operator+(const Matrix& a, const Matrix&b);
};

template<class T>
Matrix<T>::Matrix(Matrix&& a) //move constructor 
    : dim{a.dim}, elem{a.elem} {
        a.dim = {0,0};
        a.elem = nullptr;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix&& a) { // move assignment
    swap(dim, a.dim);
    swap(elem, a.elem);
    return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix& a, const Matrix& b) {
    if (a.dim[0] != b.dim[0] || a.dim[1] != b.dim[1])
        throw std::runtime_error("Unequal matrix sizes");
    
    Matrix<T> res{a.dim[0], a.dim[1]};
    constexpr auto n = a.size();
    for(int i = 0; i!= n;++i) {
        res.elem[i] = a.elem[i] + b.elem[i];
    }

    return res;
}