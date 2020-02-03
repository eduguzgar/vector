#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <type_traits>
#include <iostream>

template <typename T = float>
struct vector3
{
    /* ONLY float or double */
    static_assert(std::is_same<T, float>::value || std::is_same<T, double>::value, 
        "template class vector3 typename T must be foating point (float or double)");

    T x;
    T y;
    T z;

    /* ctors */
    vector3();
    vector3(T x_, T y_, T z_);
    vector3(T a);

    vector3<T>& operator=(const vector3<T>& v);

    /* Initialization */
    void init();        // Initialize to zero

    T* ptr() const;

    void zero();
    bool is_zero() const;
    bool is_almost_zero(const T tolerance = 0.01f) const;
    bool is_any_zero() const;

    /* Equality operators */

    bool operator==(const vector3<T>& v) const;
    bool operator!=(const vector3<T>& v) const;

    /* Compound arithmetic operators */

    vector3<T>& operator+=(const vector3<T>& v);
    vector3<T>& operator+=(const T a);
    vector3<T>& operator-=(const vector3<T>& v);
    vector3<T>& operator-=(const T a);
    vector3<T>& operator*=(const vector3<T>& v);
    vector3<T>& operator*=(const T a);
    vector3<T>& operator/=(const vector3<T>& v);
    vector3<T>& operator/=(const T a);

    /* Unary arithmetic operators */

    vector3<T> operator-(void) const;

    /* Binary arithmetic operators */

    vector3<T> operator+(const vector3<T>& v) const;
    vector3<T> operator-(const vector3<T>& v) const;
    vector3<T> operator*(const vector3<T>& v) const;    // Element wise multiplication
    vector3<T> operator*(T a) const;
    vector3<T> operator/(const vector3<T>& v) const;
    vector3<T> operator/(T a) const;                    // Division by scalar

    /* Other operations */

    T           lengthsqr() const;      // Squared Magnitude of a vector
    T           length() const;         // Magnitude of a vector
    T           lengthsqr_xy() const;
    T           lengthsqr_xz() const;
    T           lengthsqr_yz() const;
    T           length_xy() const;
    T           length_xz() const;
    T           length_yz() const;
    void        normalize_this();       // Unit Vector
    vector3<T>  normalize() const;
    T           distance_to(const vector3<T>& v) const; // Distance to another vector
    T           dot(const vector3<T>& v) const;         // Dot product
    vector3<T>  cross(const vector3<T>& v) const;       // Cross product
    
    bool        is_perpendicular(const vector3<T>& v) const;    // Check ortogonality between two vectors
    void        perpendicular_this(const vector3<T>& v);
    vector3<T>  perpendicular(const vector3<T>& v); 
    bool        is_opposite(const vector3<T>& v) const;
    void        opposite_this();
    vector3<T>  opposite() const;
    bool        is_collinear(const vector3<T>& v) const;
    void        collinear_this(T a);
    vector3<T>  collinear(T a) const;
    bool        is_anticollinear(const vector3<T>& v) const;
    void        anticollinear_this(T a);
    vector3<T>  anticollinear(T a) const;

};

/* Non-member functions */
template <typename T>
vector3<T> operator*(T a, const vector3<T>& v);       // Symmetric multiplication by scalar

/* I/O operators */
template <typename T>
std::ostream& operator<<(std::ostream& out, const vector3<T>& v);

template <typename T>
std::istream& operator>>(std::istream& in,  vector3<T>& v);

/* Canonical implementations */
template <typename T>
T dot(const vector3<T>& lv, const vector3<T>& rv);              // Dot product

template <typename T>
vector3<T> cross(const vector3<T>& lv, const vector3<T>& rv);   // cross product

template <typename T>
vector3<T>::vector3() {}

/* ctor */
template <typename T>
vector3<T>::vector3(T x_, T y_, T z_) 
{
    x = x_;
    y = y_;
    z = z_;
}

template <typename T>
vector3<T>::vector3(T a) 
{
    x = a;
    y = a;
    z = a;
}

/* Initialization */
template <>
inline void vector3<float>::init() 
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

template <>
inline void vector3<double>::init() 
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

template <typename T>
inline vector3<T>& vector3<T>::operator=(const vector3<T>& v)    // Assigment constructor
{
    x = v.x; y = v.y; z = v.z; return *this;
}

template <typename T>
inline T* vector3<T>::ptr() const   // Base pointer to the vector
{
    return (T*)this;
}

/* I/O operators */
template <typename T>
std::ostream& operator<<(std::ostream& out, const vector3<T>& v)
{
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in,  vector3<T>& v)
{
    std::cout << "x = ";
    in >> v.x;
    std::cout << "y = ";
    in >> v.y;
    std::cout << "z = ";
    in >> v.z;

    return in;
}

/* Equality operators */
template <typename T>
inline bool vector3<T>::operator==(const vector3<T>& v) const 
{ 
    return (x == v.x) && (y == v.y) && (z == v.z); 
}

template <typename T>
inline bool vector3<T>::operator!=(const vector3<T>& v) const
{
    return !((*this) == v); 
}

/* Compound arithmetic operators */
template <typename T>
inline vector3<T>& vector3<T>::operator+=(const vector3<T>& v)
{
    x += v.x; y += v.y; z += v.z; return *this;
}

template <typename T>
inline vector3<T>& vector3<T>::operator+=(T a)
{
    x += a; y += a; z += a; return *this;
}

template <typename T>
inline vector3<T>& vector3<T>::operator-=(const vector3<T>& v)
{
    x -= v.x; y -= v.y; z -= v.z; return *this;
}

template <typename T>
inline vector3<T>& vector3<T>::operator-=(T a)
{
    x -= a; y -= a; z -= a; return *this;
}

template <typename T>
inline vector3<T>& vector3<T>::operator*=(const vector3<T>& v)
{
    x *= v.x; y *= v.y; z *= v.z; return *this;
}

template <typename T>
inline vector3<T>& vector3<T>::operator*=(T a)
{
    x *= a; y *= a; z *= a; return *this;
}

template <typename T>
inline vector3<T>& vector3<T>::operator/=(const vector3<T>& v)
{
    x /= v.x; y /= v.y; z /= v.z; return *this;
}

template <typename T>
inline vector3<T>& vector3<T>::operator/=(T a)
{
    x /= a; y /= a; z /= a; return *this;
}

/* Unary arithmetic operators */
template <typename T>
inline vector3<T> vector3<T>::operator-(void) const
{
    return vector3<T>(-x,-y,-z);
}

/* Binary arithmetic operators */
template <typename T>
inline vector3<T> vector3<T>::operator+(const vector3<T>& v) const
{
    return vector3<T>(x + v.x, y + v.y, z + v.z);
}

template <typename T>
inline vector3<T> vector3<T>::operator-(const vector3<T>& v) const
{
    return vector3<T>(x - v.x, y - v.y, z - v.z);
}

template <typename T>
inline vector3<T> vector3<T>::operator*(const vector3<T>& v) const   // Element wise multiplication
{
    return vector3<T>(x * v.x, y * v.y, z * v.z);
}

template <typename T>
inline vector3<T> vector3<T>::operator*(T a) const
{
    return vector3<T>(x * a, y * a , z * a);
}

template <typename T>
inline vector3<T> operator*(T a, const vector3<T>& v)
{
    return v * a;
}

template <typename T>
inline vector3<T> vector3<T>::operator/(const vector3<T>& v) const   // Element wise division
{
    return vector3<T>(x / v.x, y / v.y, z / v.z);
}

template <typename T>
inline vector3<T> vector3<T>::operator/(T a) const
{
    return vector3<T>(x / a, y / a, z / a);
}

/* Other operations */
template <>
inline void vector3<float>::zero()
{
    x = 0.0f; y = 0.0f; z = 0.0f;
}

template <>
inline void vector3<double>::zero()
{
    x = 0.0; y = 0.0; z = 0.0;
}

template <>
inline bool vector3<float>::is_zero() const
{
    return (x == 0.0f) && (y == 0.0f) && (z == 0.0f);
}

template <>
inline bool vector3<double>::is_zero() const
{
    return (x == 0.0) && (y == 0.0) && (z == 0.0);
}

template <>
inline bool vector3<float>::is_any_zero() const
{
    return (x == 0.0f) || (y == 0.0f) || (z == 0.0f);
}

template <>
inline bool vector3<double>::is_any_zero() const
{
    return (x == 0.0) || (y == 0.0) || (z == 0.0);
}

template <typename T>
inline bool vector3<T>::is_almost_zero(T tolerance) const
{
    return x > -tolerance && x < tolerance &&
           y > -tolerance && y < tolerance &&
           z > -tolerance && z < tolerance;
}

template <typename T>
inline T vector3<T>::lengthsqr() const
{
    return x * x + y * y + z * z;
}

template <typename T>
inline T vector3<T>::length() const
{
    return std::sqrt(lengthsqr());
}

template <typename T>
inline T vector3<T>::lengthsqr_xy() const
{
    return x * x + y * y;
}

template <typename T>
inline T vector3<T>::lengthsqr_xz() const
{
    return x * x + z * z;
}

template <typename T>
inline T vector3<T>::lengthsqr_yz() const
{
    return y * y + z * z;
}

template <typename T>
inline T vector3<T>::length_xy() const
{
    return std::sqrt(lengthsqr_xy());
}

template <typename T>
inline T vector3<T>::length_xz() const
{
    return std::sqrt(lengthsqr_xz());
}

template <typename T>
inline T vector3<T>::length_yz() const
{
    return std::sqrt(lengthsqr_yz());
}

template <typename T>
inline void vector3<T>::normalize_this()
{
    (*this) /= length();
}

template <typename T>
inline vector3<T> vector3<T>::normalize() const
{
    return (*this) / length();
}

template <typename T>
inline T vector3<T>::distance_to(const vector3<T>& v) const
{
    return ((*this) - v).length();
}

template <typename T>
inline T dot(const vector3<T>& lv, const vector3<T>& rv)          // External Dot product
{
    return lv.x * rv.x + lv.y * rv.y + lv.z * rv.z;
}

template <typename T>
inline T vector3<T>::dot(const vector3<T>& v) const               // Dot product
{
    return x * v.x + y * v.y + z * v.z;
}

template <typename T>
inline vector3<T> cross_product(const vector3<T>& lv, const vector3<T>& rv)  // Cross product
{
    vector3<T> v;
    v.x = lv.y * rv.z - lv.z * rv.y;
    v.y = lv.z * rv.x - lv.x * rv.z;
    v.z = lv.x * rv.y - lv.y * rv.x;
    return v;
}

template <typename T>
inline vector3<T> vector3<T>::cross(const vector3<T>& v) const           // Cross product
{
    vector3<T> va;
    va.x = y * v.z - z * v.y;
    va.y = z * v.x - x * v.z;
    va.z = x * v.y - y * v.x;
    return va;
}

template <>
inline bool vector3<float>::is_perpendicular(const vector3<float>& v) const     // Check orthogonality between two vectors
{
    return dot(v) == 0.0f;
}

template <>
inline bool vector3<double>::is_perpendicular(const vector3<double>& v) const   // Check orthogonality between two vectors
{
    return dot(v) == 0.0;
}

template <typename T>
inline void vector3<T>::perpendicular_this(const vector3<T>& v)       // Make this vector perpendicular to itself
{
    (*this) = cross_product(*this, v);
}

template <typename T>
inline vector3<T> vector3<T>::perpendicular(const vector3<T>& v)         // Perpendicular vector
{
    vector3<T> v_aux;
    v_aux = cross_product(*this, v);
    return v_aux;
}

template <typename T>
inline bool vector3<T>::is_opposite(const vector3<T>& v) const
{
    return x == -v.x && y == -v.y && z == -v.z;
}

template <typename T>
inline void vector3<T>::opposite_this()
{
    x = -x; y = -y; z = -z;
}

template <typename T>
inline vector3<T> vector3<T>::opposite() const
{
    vector3<T> v;
    v.x = -x; v.y = -y; v.z = -z;
    return v;
}

template <typename T>
inline bool vector3<T>::is_collinear(const vector3<T>& v) const
{
    return x * v.y == y * v.x && z * v.x == x * v.z;
}

template <typename T>
inline void vector3<T>::collinear_this(T a)         // With a negative a you make it anticollinear
{
    (*this) *= a;
}

template <typename T>
inline vector3<T> vector3<T>::collinear(T a) const  // With a negative a you make it anticollinear
{
    return (*this) * a;
}

template <typename T>
inline bool vector3<T>::is_anticollinear(const vector3<T>& v) const
{
    return x * v.y == y * v.x && z * v.x == x * v.z && 
           std::signbit(x) != std::signbit(v.x) &&
           std::signbit(y) != std::signbit(v.y) &&
           std::signbit(z) != std::signbit(v.z);
}

template <typename T>
inline void vector3<T>::anticollinear_this(T a)         // With a negative a you make it collinear
{
    (*this) *= -a;
}

template <typename T>
inline vector3<T> vector3<T>::anticollinear(T a) const  // With a negative a you make it collinear
{
    return (*this) * -a;
}

#endif