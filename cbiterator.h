/*#ifndef CBITERATOR_H
#define CBITERATOR_H

#include <iterator>

template <typename T>
class CBiterator : public std::iterator<std::forward_iterator_tag, T>
{
private:
    typedef CBiterator<T> iterator;
    typedef T* pointer;

    pointer _pos;

public:
    CBiterator() : _pos(nullptr)
    CBiterator(T* rhs): _pos(rhs)
    ~CBiterator() {};
    iterator operator ++(int) {return ++_pos;}
    iterator & operator ++(int) {++_pos; return *this;}
    iterator & operator *() {return *_pos;}
    pointer operator -> () {return _pos;}
    iterator operator + (T* rhs) {return _pos+rhs;}
    bool operator ==(const iterator &rhs) {return _pos == rhs._pos;}
    bool operator !=(const iterator &rhs) {return _pos != rhs._pos;}
};

template <typename T>
CBiterator begin(T *val) {
    return CBiterator<T>(val);
}

template <typename T, typename T_Size>
CBiterator end(T*val, T_Size size){
    return CBiterator<T>(val) + size);
}

#endif // CBITERATOR_H
*/
