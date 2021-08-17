#ifndef EA214D1F_EA8A_44DA_9FB8_6D5913106A8B
#define EA214D1F_EA8A_44DA_9FB8_6D5913106A8B

#include <type_traits>
#include <new>

template <typename T>
struct Placement {
    void* Alloc() {
        return (void*)&u;
    }

    void Free() {
        GetObject()->~T();
    }

    const T* operator->() const {
        return GetObject();
    }

    T* operator->() {
        return GetObject();
    }

    const T& operator*() const {
        return GetRef();
    }

    T& operator*() {
        return GetRef();
    }

    const T* GetObject() const {
        return static_cast<const T*>(static_cast<const void*>(&u));
    }

    T* GetObject() {
        return static_cast<T*>(static_cast<void*>(&u));
    }

    const T& GetRef() const {
        return *GetObject();
    }

    T& GetRef() {
        return *GetObject();
    }

private:
    typename std::aligned_storage_t<sizeof(T), alignof(T)> u;
};

template <typename T>
struct DefaultPlacement : Placement<T> {
  T* init() {
    return new (Placement<T>::Alloc()) T();
  }
};

#endif /* EA214D1F_EA8A_44DA_9FB8_6D5913106A8B */
