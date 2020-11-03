#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>
#include <type_traits>
#include <iostream>

template <typename T = float>
struct vector2
{
    /* ONLY float or double */
    static_assert(std::is_same<T, float>::value || std::is_same<T, double>::value,
        "template class vector2 typename T must be foating point (float or double)");

    T x;
    T y;

    /* ctors */
    vector2();
    vector2(T x_, T y_);
    vector2(T a);

    vector2<T>& operator=(const vector2<T>& v);

    /* Initialization */
    void init();        // Initialize to zero

    T* ptr() const;

    void zero();
    bool is_zero() const;
    bool is_almost_zero(const T tolerance = 0.01f) const;
    bool is_any_zero() const;

    /* Equality operators */

    bool operator==(const vector2<T>& v) const;
    bool operator!=(const vector2<T>& v) const;

    /* Compound arithmetic operators */

    vector2<T>& operator+=(const vector2<T>& v);
    vector2<T>& operator+=(const T a);
    vector2<T>& operator-=(const vector2<T>& v);
    vector2<T>& operator-=(const T a);
    vector2<T>& operator*=(const vector2<T>& v);
    vector2<T>& operator*=(const T a);
    vector2<T>& operator/=(const vector2<T>& v);
    vector2<T>& operator/=(const T a);

    /* Unary arithmetic operators */

    vector2<T> operator-(void) const;

    /* Binary arithmetic operators */

    vector2<T> operator+(const vector2<T>& v) const;
    vector2<T> operator-(const vector2<T>& v) const;
    vector2<T> operator*(const vector2<T>& v) const;    // Element wise multiplication
    vector2<T> operator*(T a) const;
    vector2<T> operator/(const vector2<T>& v) const;
    vector2<T> operator/(T a) const;                    // Division by scalar

    /* Other operations */

    T           lengthsqr() const;      // Squared Magnitude of a vector
    T           length() const;         // Magnitude of a vector
    void        normalize_this();       // Unit Vector
    vector2<T>  normalize() const;
    T           distance(const vector2<T>& v) const;    // Distance to another vector
    T           dot(const vector2<T>& v) const;         // Dot product

    bool        is_perpendicular(const vector2<T>& v) const;    // Check ortogonality between two vectors
    bool        is_opposite(const vector2<T>& v) const;
    void        opposite_this();
    vector2<T>  opposite() const;
    bool        is_collinear(const vector2<T>& v) const;
    void        collinear_this(T a);
    vector2<T>  collinear(T a) const;
    bool        is_anticollinear(const vector2<T>& v) const;
    void        anticollinear_this(T a);
    vector2<T>  anticollinear(T a) const;

};

/* Non-member functions */
template <typename T>
vector2<T> operator*(T a, const vector2<T>& v);       // Symmetric multiplication by scalar

/* I/O operators */
template <typename T>
std::ostream& operator<<(std::ostream& out, const vector2<T>& v);

template <typename T>
std::istream& operator>>(std::istream& in, vector2<T>& v);

/* Canonical implementations */

template <typename T>
T distance(const vector2<T>& lv, const vector2<T>& rv);

template <typename T>
T dot(const vector2<T>& lv, const vector2<T>& rv);              // Dot product

/* ctors */

template <typename T>
vector2<T>::vector2() {}

template <typename T>
vector2<T>::vector2(T x_, T y_)
{
    x = x_;
    y = y_;
}

template <typename T>
vector2<T>::vector2(T a)
{
    x = a;
    y = a;
}

/* Initialization */
template <>
inline void vector2<float>::init()
{
    x = 0.0f;
    y = 0.0f;
}

template <>
inline void vector2<double>::init()
{
    x = 0.0;
    y = 0.0;
}

template <typename T>
inline vector2<T>& vector2<T>::operator=(const vector2<T>& v)    // Assigment constructor
{
    x = v.x; y = v.y; return *this;
}

template <typename T>
inline T* vector2<T>::ptr() const   // Base pointer to the vector
{
    return (T*)this;
}

/* I/O operators */
template <typename T>
std::ostream& operator<<(std::ostream& out, const vector2<T>& v)
{
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, vector2<T>& v)
{
    std::cout << "x = ";
    in >> v.x;
    std::cout << "y = ";
    in >> v.y;

    return in;
}

/* Equality operators */
template <typename T>
inline bool vector2<T>::operator==(const vector2<T>& v) const
{
    return (x == v.x) && (y == v.y);
}

template <typename T>
inline bool vector2<T>::operator!=(const vector2<T>& v) const
{
    return !((*this) == v);
}

/* Compound arithmetic operators */
template <typename T>
inline vector2<T>& vector2<T>::operator+=(const vector2<T>& v)
{
    x += v.x; y += v.y; return *this;
}

template <typename T>
inline vector2<T>& vector2<T>::operator+=(T a)
{
    x += a; y += a; return *this;
}

template <typename T>
inline vector2<T>& vector2<T>::operator-=(const vector2<T>& v)
{
    x -= v.x; y -= v.y; return *this;
}

template <typename T>
inline vector2<T>& vector2<T>::operator-=(T a)
{
    x -= a; y -= a; return *this;
}

template <typename T>
inline vector2<T>& vector2<T>::operator*=(const vector2<T>& v)
{
    x *= v.x; y *= v.y; return *this;
}

template <typename T>
inline vector2<T>& vector2<T>::operator*=(T a)
{
    x *= a; y *= a; return *this;
}

template <typename T>
inline vector2<T>& vector2<T>::operator/=(const vector2<T>& v)
{
    x /= v.x; y /= v.y; return *this;
}

template <typename T>
inline vector2<T>& vector2<T>::operator/=(T a)
{
    x /= a; y /= a; return *this;
}

/* Unary arithmetic operators */
template <typename T>
inline vector2<T> vector2<T>::operator-(void) const
{
    return vector2<T>(-x, -y);
}

/* Binary arithmetic operators */
template <typename T>
inline vector2<T> vector2<T>::operator+(const vector2<T>& v) const
{
    return vector2<T>(x + v.x, y + v.y);
}

template <typename T>
inline vector2<T> vector2<T>::operator-(const vector2<T>& v) const
{
    return vector2<T>(x - v.x, y - v.y);
}

template <typename T>
inline vector2<T> vector2<T>::operator*(const vector2<T>& v) const   // Element wise multiplication
{
    return vector2<T>(x * v.x, y * v.y);
}

template <typename T>
inline vector2<T> vector2<T>::operator*(T a) const
{
    return vector2<T>(x * a, y * a);
}

template <typename T>
inline vector2<T> operator*(T a, const vector2<T>& v)
{
    return v * a;
}

template <typename T>
inline vector2<T> vector2<T>::operator/(const vector2<T>& v) const   // Element wise division
{
    return vector2<T>(x / v.x, y / v.y);
}

template <typename T>
inline vector2<T> vector2<T>::operator/(T a) const
{
    return vector2<T>(x / a, y / a);
}

/* Other operations */
template <>
inline void vector2<float>::zero()
{
    x = 0.0f; y = 0.0f;
}

template <>
inline void vector2<double>::zero()
{
    x = 0.0; y = 0.0;
}

template <>
inline bool vector2<float>::is_zero() const
{
    return (x == 0.0f) && (y == 0.0f);
}

template <>
inline bool vector2<double>::is_zero() const
{
    return (x == 0.0) && (y == 0.0);
}

template <>
inline bool vector2<float>::is_any_zero() const
{
    return (x == 0.0f) || (y == 0.0f);
}

template <>
inline bool vector2<double>::is_any_zero() const
{
    return (x == 0.0) || (y == 0.0);
}

template <typename T>
inline bool vector2<T>::is_almost_zero(T tolerance) const
{
    return x > -tolerance && x < tolerance &&
           y > -tolerance && y < tolerance;
}

template <typename T>
inline T vector2<T>::lengthsqr() const
{
    return x * x + y * y;
}

template <typename T>
inline T vector2<T>::length() const
{
    return std::sqrt(lengthsqr());
}

template <typename T>
inline void vector2<T>::normalize_this()
{
    (*this) /= length();
}

template <typename T>
inline vector2<T> vector2<T>::normalize() const
{
    return (*this) / length();
}

template <typename T>
inline T distance(const vector2<T>& lv, const vector2<T>& rv)	// Distance between two vectors
{
    vector2<T> v;
    v = lv - rv;
    return v.length();
}

template <typename T>
inline T vector2<T>::distance(const vector2<T>& v) const        // Distance between two vectors
{
    return ::distance(*this, v);
}

template <typename T>
inline T dot(const vector2<T>& lv, const vector2<T>& rv)        // Canonical Dot product
{
    return lv.x * rv.x + lv.y * rv.y;
}

template <typename T>
inline T vector2<T>::dot(const vector2<T>& v) const             // Dot product
{
    return ::dot(*this, v);
}

template <>
inline bool vector2<float>::is_perpendicular(const vector2<float>& v) const     // Check orthogonality between two vectors
{
    return dot(v) == 0.0f;
}

template <>
inline bool vector2<double>::is_perpendicular(const vector2<double>& v) const   // Check orthogonality between two vectors
{
    return dot(v) == 0.0;
}

template <typename T>
inline bool vector2<T>::is_opposite(const vector2<T>& v) const
{
    return x == -v.x && y == -v.y;
}

template <typename T>
inline void vector2<T>::opposite_this()
{
    x = -x; y = -y;
}

template <typename T>
inline vector2<T> vector2<T>::opposite() const
{
    vector2<T> v;
    v.x = -x; v.y = -y;
    return v;
}

template <typename T>
inline bool vector2<T>::is_collinear(const vector2<T>& v) const
{
    return x * v.y == y * v.x;
}

template <typename T>
inline void vector2<T>::collinear_this(T a)         // With a negative a you make it anticollinear
{
    (*this) *= a;
}

template <typename T>
inline vector2<T> vector2<T>::collinear(T a) const  // With a negative a you make it anticollinear
{
    return (*this) * a;
}

template <typename T>
inline bool vector2<T>::is_anticollinear(const vector2<T>& v) const
{
    return x * v.y == y * v.x &&
           std::signbit(x) != std::signbit(v.x) &&
           std::signbit(y) != std::signbit(v.y);
}

template <typename T>
inline void vector2<T>::anticollinear_this(T a)         // With a negative a you make it collinear
{
    (*this) *= -a;
}

template <typename T>
inline vector2<T> vector2<T>::anticollinear(T a) const  // With a negative a you make it collinear
{
    return (*this) * -a;
}

#endif
