#include <iostream>

template <typename T>
class Vector {
private:
    T* elements;
    size_t size_;
    size_t cap_;


public:
    Vector()
    : elements(nullptr), size_(0), cap_(8) {
        elements = new T[cap_];

    }

    Vector(size_t size)
    : elements(nullptr), size_(size), cap_(8 + size) {
        elements = new T[cap_];

    }

    Vector(size_t size, T element)
    : elements(nullptr), size_(size), cap_(8 + size) {
        elements = new T[cap_];
        for(size_t i = 0; i < size_; i++)
            elements[i] = element;

    } 
    
    ~Vector() {delete[] elements;}

    size_t capacity() {
        return cap_;
    }

    size_t size() {
        return size_;
    }
    
    bool empty() {
        if(size() == 0)
            return true;
        else {
            return false;
        }
    }

    void clear() {
        size_ = 0;
    }

    void erase(size_t index) {
        T* temp = new T[cap_];
        for(size_t i=0; i < size(); i++) 
            temp[i] = elements[i];
        
        elements = new T[cap_];
        for(size_t i=0; i < index; i++)
            elements[i] = temp[i];
        for(size_t i= index; i < size()-1; i++) {
            elements[i] = temp[i+1];
        }
        size_ -= 1;
        delete[] temp;
    }

    T* insert(size_t index, T& element) {
        if(size_ >= cap_)
            cap_ = cap_*2;
        
        T* temp = new T[cap_];
        for(size_t i=0; i < size(); i++) 
            temp[i] = elements[i];
        
        elements = new T[cap_];
        for(size_t i =0; i < index ; i++)
            elements[i] = temp[i];
        elements[index] = element;
        for(size_t i = index+1; i < size()+1; i++)
            elements[i] = temp[i-1];
        
        size_++;
        delete[] temp;
        return elements + index;
    }

    void push_back(const T& element) {
        if(size_ >= cap_) {
            cap_ *= 2;
            T* temp = new T[cap_];
            for(size_t i=0; i < size(); i++) 
                temp[i] = elements[i];
            
            elements = new T[cap_];
            
            for(size_t i=0; i < size(); i++) 
                elements[i] = temp[i];
            elements[size_] = element;
            
            delete[] temp;
        }

        else{
            elements[size_] = element;
        }

        size_ += 1;
    }

    void pop_back() {
        size_ -= 1;
        
    }

    void resize(size_t resize_num) {
        if(resize_num > size_) {
            size_ = 0;
        }
        else {
            size_ = resize_num;
        }
    }

    void assign(size_t size_num, const T& element) {
        if(size_num >= cap_) {
            cap_ = size_num*2;
        }
        elements = new T[cap_];
        for(size_t i = 0;  i < size_num ; i++)
            elements[i] = element;
        
        size_ = size_num;
    }

    T* begin() {
        return elements;
    }

    const T* cbegin() {
        return elements;
    }

    T* end() {
        return elements + size_;
    }

    const T* cend() {
        return elements + size_;;
    }

    T* rbegin() {return elements + size_ -1;}
    T* rend() {return elements - 1;}
    const T* crbegin() {return elements + size_ -1;}
    const T* crend() {return elements - 1;}
    
    T& front() {
        return elements[0];
    }

    T& back() {
        return elements[size_ -1];
    }
    
    T& operator[](size_t index) {
     
        return elements[index];
    }

    Vector& operator=(const Vector &rhs) {
        cap_ = rhs.cap_;
        size_ = rhs.size_;

        elements = new T[cap_];
        for(size_t i = 0; i < size_ ; i++) {
            elements[i] = rhs.elements[i];
        }
        
        return *this;
    } 
    //값만 복사, type 같아야 함
    template <typename F>
    friend std::ostream& operator<<(std::ostream& out, Vector<F>& vector);
    template <typename F>
    friend std::istream& operator>>(std::istream& in, Vector<F>& vector);
    

};
template<typename F>
std::ostream& operator<<(std::ostream& out, Vector<F>& vector) {
    // for(size_t i =0 ; i< vector.size();i++)
    //     std::cout << vector[i] << ", ";
    // std::cout << std::endl;

    for(size_t i =0 ; i< vector.size();i++)
        out << vector[i] << ",";
    out << std::endl;

    return out;
}

template<typename F>
std::istream& operator>>(std::istream& in, Vector<F>& vector) {
    F temp;
    in >> temp;
    vector.push_back(temp);
    return in;
}
