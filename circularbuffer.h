#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H
#include <iostream>
#include <deque>
#include <exception>

template <typename T>
class CircularBuffer
{
private:
    typedef T value_type;
    typedef T* pointer;
    typedef const T * const_pointer;
    typedef T & reference;
    typedef const T & const_reference;
    typedef std::size_t size_type;

    std::deque<value_type> _buffer;
    size_type _size; //aktualnie przechowywana ilość elementów
    size_type _head; //indeks najstarszego elementu
    size_type _tail; //indeks najmłodszego elementu
    size_type _buffer_capacity; //maksymalna ilośc elementów

public:

    CircularBuffer(size_type buffer_capacity);
    CircularBuffer(const CircularBuffer<value_type> &rhs);
    void push_back(const value_type &elem);
    void clear();
    size_type size() const;
    size_type capacity() const;
    void pop_front();
    reference at(const size_type& index);
    reference operator[](const size_type& index);
    bool empty() const;
    typename std::deque<T>::iterator begin();
    typename std::deque<T>::iterator end();
    typename std::deque<T>::iterator rbegin();
    typename std::deque<T>::iterator rend();
};

template<typename T>
CircularBuffer<T>::CircularBuffer(size_type buffer_capacity){
    try{
        if(buffer_capacity>0){
        _buffer_capacity = buffer_capacity;
        _size = 0;
        _head = _tail = 0;
    }else{
        throw std::invalid_argument("Number of elements should be greater than 0");
    }
    }
    catch (const std::invalid_argument &arg){
        std::cout << arg.what() <<std::endl;
    }
}

template<typename T>
CircularBuffer<T>::CircularBuffer(const CircularBuffer<value_type> &rhs){
    _size = rhs._size;
    _head = rhs._head;
    _tail = rhs._tail;
    _buffer_capacity = rhs._buffer_capacity;
    _buffer = rhs._buffer;
}
template<typename T>
std::size_t CircularBuffer<T>::capacity() const{
    return _buffer_capacity;
}

template<typename T>
void CircularBuffer<T>::clear(){
    _buffer.clear();
}

template<typename T>
std::size_t CircularBuffer<T>::size() const{
    return _size;
}

template<typename T>
void CircularBuffer<T>::push_back(const value_type &elem){
    if(_size<_buffer_capacity){
        _buffer.push_back(elem);
        ++_size;
        ++_tail;
    } else if(_size == _buffer_capacity){
        _buffer.at(_head) = elem;
        ++_head;
        if(_head<=_buffer_capacity)
        _tail = _head-1;
        else if(_head==0)
        _tail = _buffer_capacity;
    }

}

template<typename T>
void CircularBuffer<T>::pop_front(){
    if(!_buffer.empty()){
        _buffer.at(_head) = T();
        ++_head;
        --_size;
    }
}

template<typename T>
T& CircularBuffer<T>::at(const size_t& index){
    size_t i = _head+index;
   if((i)<=_buffer_capacity)
       return _buffer.at(i);
   else
       return _buffer.at(i-_buffer_capacity);
}

template<typename T>
T& CircularBuffer<T>::operator[](const size_t& index){
    size_t i = _head+index;
   if((i)<=_buffer_capacity)
       return _buffer.at(i);
   else
       return _buffer.at(i-_buffer_capacity);
}

template<typename T>
bool CircularBuffer<T>::empty() const{
    if(_head==_tail)
        return true;
    return false;
}

template <typename T>
typename std::deque<T>::iterator CircularBuffer<T>::end(){
    return _buffer.end();
}

template <typename T>
typename std::deque<T>::iterator CircularBuffer<T>::begin(){

    return _buffer.begin();
}

template <typename T>
typename std::deque<T>::iterator CircularBuffer<T>::rend(){
    return _buffer.rend();
}


template <typename T>
typename std::deque<T>::iterator CircularBuffer<T>::rbegin(){
    return _buffer.rbegin();
}
#endif // CIRCULARBUFFER_H
