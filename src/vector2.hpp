#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>
#include <iostream>

// float specialization

template <typename> struct vector2;

template <>
struct vector2<float>
{
    float x;
    float y;

    /* ctors */
    vector2();
    vector2(float x_, float y_);
    vector2(float a);

    vector2<float>& operator=(const vector2<float>& v);

    /* Initialization */
    void init();        // Initialize to zero

    float* ptr() const;

    void zero();
    bool is_zero() const;
    bool is_almost_zero(const float tolerance = 0.01f) const;
    bool is_any_zero() const;

    /* Equality operators */

    bool operator==(const vector2<float>& v) const;
    bool operator!=(const vector2<float>& v) const;

    /* Compound arithmetic operators */

    vector2<float>& operator+=(const vector2<float>& v);
    vector2<float>& operator+=(const float a);
    vector2<float>& operator-=(const vector2<float>& v);
    vector2<float>& operator-=(const float a);
    vector2<float>& operator*=(const vector2<float>& v);
    vector2<float>& operator*=(const float a);
    vector2<float>& operator/=(const vector2<float>& v);
    vector2<float>& operator/=(const float a);

    /* Unary arithmetic operators */

    vector2<float> operator-(void) const;

    /* Binary arithmetic operators */

    vector2<float> operator+(const vector2<float>& v) const;
    vector2<float> operator-(const vector2<float>& v) const;
    vector2<float> operator*(const vector2<float>& v) const;    // Element wise multiplication
    vector2<float> operator*(float a) const;
    vector2<float> operator/(const vector2<float>& v) const;
    vector2<float> operator/(float a) const;                    // Division by scalar

    /* Other operations */

    float           lengthsqr() const;      // Squared Magnitude of a vector
    float           length() const;         // Magnitude of a vector
    void            normalize_this();       // Unit Vector
    vector2<float>  normalize() const;
    float           distance(const vector2<float>& v) const;    // Distance to another vector
    float           dot(const vector2<float>& v) const;         // Dot product

    bool            is_perpendicular(const vector2<float>& v) const;    // Check ortogonality between two vectors
    bool            is_opposite(const vector2<float>& v) const;
    void            opposite_this();
    vector2<float>  opposite() const;
    bool            is_collinear(const vector2<float>& v) const;
    void            collinear_this(float a);
    vector2<float>  collinear(float a) const;
    bool            is_anticollinear(const vector2<float>& v) const;
    void            anticollinear_this(float a);
    vector2<float>  anticollinear(float a) const;

};

/* Non-member functions */
vector2<float> operator*(float a, const vector2<float>& v);       // Symmetric multiplication by scalar

/* I/O operators */
std::ostream& operator<<(std::ostream& out, const vector2<float>& v);

std::istream& operator>>(std::istream& in, vector2<float>& v);

/* Canonical implementations */

float distance(const vector2<float>& lv, const vector2<float>& rv);

float dot(const vector2<float>& lv, const vector2<float>& rv);              // Dot product

/* ctors */

vector2<float>::vector2() {}

vector2<float>::vector2(float x_, float y_)
{
    x = x_;
    y = y_;
}

vector2<float>::vector2(float a)
{
    x = a;
    y = a;
}

/* Initialization */

inline void vector2<float>::init()
{
    x = 0.0f;
    y = 0.0f;
}

inline vector2<float>& vector2<float>::operator=(const vector2<float>& v)    // Assigment constructor
{
    x = v.x; y = v.y; return *this;
}

inline float* vector2<float>::ptr() const   // Base pointer to the vector
{
    return (float*)this;
}

/* I/O operators */
std::ostream& operator<<(std::ostream& out, const vector2<float>& v)
{
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}

std::istream& operator>>(std::istream& in, vector2<float>& v)
{
    std::cout << "x = ";
    in >> v.x;
    std::cout << "y = ";
    in >> v.y;

    return in;
}

/* Equality operators */
inline bool vector2<float>::operator==(const vector2<float>& v) const
{
    return (x == v.x) && (y == v.y);
}

inline bool vector2<float>::operator!=(const vector2<float>& v) const
{
    return !((*this) == v);
}

/* Compound arithmetic operators */
inline vector2<float>& vector2<float>::operator+=(const vector2<float>& v)
{
    x += v.x; y += v.y; return *this;
}

inline vector2<float>& vector2<float>::operator+=(float a)
{
    x += a; y += a; return *this;
}

inline vector2<float>& vector2<float>::operator-=(const vector2<float>& v)
{
    x -= v.x; y -= v.y; return *this;
}

inline vector2<float>& vector2<float>::operator-=(float a)
{
    x -= a; y -= a; return *this;
}

inline vector2<float>& vector2<float>::operator*=(const vector2<float>& v)
{
    x *= v.x; y *= v.y; return *this;
}

inline vector2<float>& vector2<float>::operator*=(float a)
{
    x *= a; y *= a; return *this;
}

inline vector2<float>& vector2<float>::operator/=(const vector2<float>& v)
{
    x /= v.x; y /= v.y; return *this;
}

inline vector2<float>& vector2<float>::operator/=(float a)
{
    x /= a; y /= a; return *this;
}

/* Unary arithmetic operators */
inline vector2<float> vector2<float>::operator-(void) const
{
    return vector2<float>(-x, -y);
}

/* Binary arithmetic operators */
inline vector2<float> vector2<float>::operator+(const vector2<float>& v) const
{
    return vector2<float>(x + v.x, y + v.y);
}

inline vector2<float> vector2<float>::operator-(const vector2<float>& v) const
{
    return vector2<float>(x - v.x, y - v.y);
}

inline vector2<float> vector2<float>::operator*(const vector2<float>& v) const   // Element wise multiplication
{
    return vector2<float>(x * v.x, y * v.y);
}

inline vector2<float> vector2<float>::operator*(float a) const
{
    return vector2<float>(x * a, y * a);
}

inline vector2<float> operator*(float a, const vector2<float>& v)
{
    return v * a;
}

inline vector2<float> vector2<float>::operator/(const vector2<float>& v) const   // Element wise division
{
    return vector2<float>(x / v.x, y / v.y);
}

inline vector2<float> vector2<float>::operator/(float a) const
{
    return vector2<float>(x / a, y / a);
}

/* Other operations */

inline void vector2<float>::zero()
{
    x = 0.0f; y = 0.0f;
}

inline bool vector2<float>::is_zero() const
{
    return (x == 0.0f) && (y == 0.0f);
}

inline bool vector2<float>::is_any_zero() const
{
    return (x == 0.0f) || (y == 0.0f);
}

inline bool vector2<float>::is_almost_zero(float tolerance) const
{
    return x > -tolerance && x < tolerance &&
           y > -tolerance && y < tolerance;
}

inline float vector2<float>::lengthsqr() const
{
    return x * x + y * y;
}

inline float vector2<float>::length() const
{
    return std::sqrt(lengthsqr());
}

inline void vector2<float>::normalize_this()
{
    (*this) /= length();
}

inline vector2<float> vector2<float>::normalize() const
{
    return (*this) / length();
}

inline float distance(const vector2<float>& lv, const vector2<float>& rv)	// Distance between two vectors
{
    vector2<float> v;
    v = lv - rv;
    return v.length();
}

inline float vector2<float>::distance(const vector2<float>& v) const        // Distance between two vectors
{
    return ::distance(*this, v);
}

inline float dot(const vector2<float>& lv, const vector2<float>& rv)        // Canonical Dot product
{
    return lv.x * rv.x + lv.y * rv.y;
}

inline float vector2<float>::dot(const vector2<float>& v) const             // Dot product
{
    return ::dot(*this, v);
}

inline bool vector2<float>::is_perpendicular(const vector2<float>& v) const     // Check orthogonality between two vectors
{
    return dot(v) == 0.0f;
}

inline bool vector2<float>::is_opposite(const vector2<float>& v) const
{
    return x == -v.x && y == -v.y;
}

inline void vector2<float>::opposite_this()
{
    x = -x; y = -y;
}

inline vector2<float> vector2<float>::opposite() const
{
    vector2<float> v;
    v.x = -x; v.y = -y;
    return v;
}

inline bool vector2<float>::is_collinear(const vector2<float>& v) const
{
    return x * v.y == y * v.x;
}

inline void vector2<float>::collinear_this(float a)         // With a negative a you make it anticollinear
{
    (*this) *= a;
}

inline vector2<float> vector2<float>::collinear(float a) const  // With a negative a you make it anticollinear
{
    return (*this) * a;
}

inline bool vector2<float>::is_anticollinear(const vector2<float>& v) const
{
    return x * v.y == y * v.x &&
           std::signbit(x) != std::signbit(v.x) &&
           std::signbit(y) != std::signbit(v.y);
}

inline void vector2<float>::anticollinear_this(float a)         // With a negative a you make it collinear
{
    (*this) *= -a;
}

inline vector2<float> vector2<float>::anticollinear(float a) const  // With a negative a you make it collinear
{
    return (*this) * -a;
}

// double template specialization

template <>
struct vector2<double>
{
    double x;
    double y;

    /* ctors */
    vector2();
    vector2(double x_, double y_);
    vector2(double a);

    vector2<double>& operator=(const vector2<double>& v);

    /* Initialization */
    void init();        // Initialize to zero

    double* ptr() const;

    void zero();
    bool is_zero() const;
    bool is_almost_zero(const double tolerance = 0.01f) const;
    bool is_any_zero() const;

    /* Equality operators */

    bool operator==(const vector2<double>& v) const;
    bool operator!=(const vector2<double>& v) const;

    /* Compound arithmetic operators */

    vector2<double>& operator+=(const vector2<double>& v);
    vector2<double>& operator+=(const double a);
    vector2<double>& operator-=(const vector2<double>& v);
    vector2<double>& operator-=(const double a);
    vector2<double>& operator*=(const vector2<double>& v);
    vector2<double>& operator*=(const double a);
    vector2<double>& operator/=(const vector2<double>& v);
    vector2<double>& operator/=(const double a);

    /* Unary arithmetic operators */

    vector2<double> operator-(void) const;

    /* Binary arithmetic operators */

    vector2<double> operator+(const vector2<double>& v) const;
    vector2<double> operator-(const vector2<double>& v) const;
    vector2<double> operator*(const vector2<double>& v) const;    // Element wise multiplication
    vector2<double> operator*(double a) const;
    vector2<double> operator/(const vector2<double>& v) const;
    vector2<double> operator/(double a) const;                    // Division by scalar

    /* Other operations */

    double          lengthsqr() const;      // Squared Magnitude of a vector
    double          length() const;         // Magnitude of a vector
    void            normalize_this();       // Unit Vector
    vector2<double> normalize() const;
    double          distance(const vector2<double>& v) const;    // Distance to another vector
    double          dot(const vector2<double>& v) const;         // Dot product

    bool            is_perpendicular(const vector2<double>& v) const;    // Check ortogonality between two vectors
    bool            is_opposite(const vector2<double>& v) const;
    void            opposite_this();
    vector2<double> opposite() const;
    bool            is_collinear(const vector2<double>& v) const;
    void            collinear_this(double a);
    vector2<double> collinear(double a) const;
    bool            is_anticollinear(const vector2<double>& v) const;
    void            anticollinear_this(double a);
    vector2<double> anticollinear(double a) const;

};

/* Non-member functions */
vector2<double> operator*(double a, const vector2<double>& v);       // Symmetric multiplication by scalar

/* I/O operators */
std::ostream& operator<<(std::ostream& out, const vector2<double>& v);

std::istream& operator>>(std::istream& in, vector2<double>& v);

/* Canonical implementations */

double distance(const vector2<double>& lv, const vector2<double>& rv);

double dot(const vector2<double>& lv, const vector2<double>& rv);              // Dot product

/* ctors */

vector2<double>::vector2() {}

vector2<double>::vector2(double x_, double y_)
{
    x = x_;
    y = y_;
}

vector2<double>::vector2(double a)
{
    x = a;
    y = a;
}

/* Initialization */

inline void vector2<double>::init()
{
    x = 0.0;
    y = 0.0;
}

inline vector2<double>& vector2<double>::operator=(const vector2<double>& v)    // Assigment constructor
{
    x = v.x; y = v.y; return *this;
}

inline double* vector2<double>::ptr() const   // Base pointer to the vector
{
    return (double*)this;
}

/* I/O operators */
std::ostream& operator<<(std::ostream& out, const vector2<double>& v)
{
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}

std::istream& operator>>(std::istream& in, vector2<double>& v)
{
    std::cout << "x = ";
    in >> v.x;
    std::cout << "y = ";
    in >> v.y;

    return in;
}

/* Equality operators */
inline bool vector2<double>::operator==(const vector2<double>& v) const
{
    return (x == v.x) && (y == v.y);
}

inline bool vector2<double>::operator!=(const vector2<double>& v) const
{
    return !((*this) == v);
}

/* Compound arithmetic operators */
inline vector2<double>& vector2<double>::operator+=(const vector2<double>& v)
{
    x += v.x; y += v.y; return *this;
}

inline vector2<double>& vector2<double>::operator+=(double a)
{
    x += a; y += a; return *this;
}

inline vector2<double>& vector2<double>::operator-=(const vector2<double>& v)
{
    x -= v.x; y -= v.y; return *this;
}

inline vector2<double>& vector2<double>::operator-=(double a)
{
    x -= a; y -= a; return *this;
}

inline vector2<double>& vector2<double>::operator*=(const vector2<double>& v)
{
    x *= v.x; y *= v.y; return *this;
}

inline vector2<double>& vector2<double>::operator*=(double a)
{
    x *= a; y *= a; return *this;
}

inline vector2<double>& vector2<double>::operator/=(const vector2<double>& v)
{
    x /= v.x; y /= v.y; return *this;
}

inline vector2<double>& vector2<double>::operator/=(double a)
{
    x /= a; y /= a; return *this;
}

/* Unary arithmetic operators */
inline vector2<double> vector2<double>::operator-(void) const
{
    return vector2<double>(-x, -y);
}

/* Binary arithmetic operators */
inline vector2<double> vector2<double>::operator+(const vector2<double>& v) const
{
    return vector2<double>(x + v.x, y + v.y);
}

inline vector2<double> vector2<double>::operator-(const vector2<double>& v) const
{
    return vector2<double>(x - v.x, y - v.y);
}

inline vector2<double> vector2<double>::operator*(const vector2<double>& v) const   // Element wise multiplication
{
    return vector2<double>(x * v.x, y * v.y);
}

inline vector2<double> vector2<double>::operator*(double a) const
{
    return vector2<double>(x * a, y * a);
}

inline vector2<double> operator*(double a, const vector2<double>& v)
{
    return v * a;
}

inline vector2<double> vector2<double>::operator/(const vector2<double>& v) const   // Element wise division
{
    return vector2<double>(x / v.x, y / v.y);
}

inline vector2<double> vector2<double>::operator/(double a) const
{
    return vector2<double>(x / a, y / a);
}

/* Other operations */

inline void vector2<double>::zero()
{
    x = 0.0; y = 0.0;
}

inline bool vector2<double>::is_zero() const
{
    return (x == 0.0) && (y == 0.0);
}

inline bool vector2<double>::is_any_zero() const
{
    return (x == 0.0) || (y == 0.0);
}

inline bool vector2<double>::is_almost_zero(double tolerance) const
{
    return x > -tolerance && x < tolerance&&
           y > -tolerance && y < tolerance;
}

inline double vector2<double>::lengthsqr() const
{
    return x * x + y * y;
}

inline double vector2<double>::length() const
{
    return std::sqrt(lengthsqr());
}

inline void vector2<double>::normalize_this()
{
    (*this) /= length();
}

inline vector2<double> vector2<double>::normalize() const
{
    return (*this) / length();
}

inline double distance(const vector2<double>& lv, const vector2<double>& rv)	// Distance between two vectors
{
    vector2<double> v;
    v = lv - rv;
    return v.length();
}

inline double vector2<double>::distance(const vector2<double>& v) const        // Distance between two vectors
{
    return ::distance(*this, v);
}

inline double dot(const vector2<double>& lv, const vector2<double>& rv)        // Canonical Dot product
{
    return lv.x * rv.x + lv.y * rv.y;
}

inline double vector2<double>::dot(const vector2<double>& v) const             // Dot product
{
    return ::dot(*this, v);
}

inline bool vector2<double>::is_perpendicular(const vector2<double>& v) const     // Check orthogonality between two vectors
{
    return dot(v) == 0.0;
}

inline bool vector2<double>::is_opposite(const vector2<double>& v) const
{
    return x == -v.x && y == -v.y;
}

inline void vector2<double>::opposite_this()
{
    x = -x; y = -y;
}

inline vector2<double> vector2<double>::opposite() const
{
    vector2<double> v;
    v.x = -x; v.y = -y;
    return v;
}

inline bool vector2<double>::is_collinear(const vector2<double>& v) const
{
    return x * v.y == y * v.x;
}

inline void vector2<double>::collinear_this(double a)         // With a negative a you make it anticollinear
{
    (*this) *= a;
}

inline vector2<double> vector2<double>::collinear(double a) const  // With a negative a you make it anticollinear
{
    return (*this) * a;
}

inline bool vector2<double>::is_anticollinear(const vector2<double>& v) const
{
    return x * v.y == y * v.x &&
           std::signbit(x) != std::signbit(v.x) &&
           std::signbit(y) != std::signbit(v.y);
}

inline void vector2<double>::anticollinear_this(double a)         // With a negative a you make it collinear
{
    (*this) *= -a;
}

inline vector2<double> vector2<double>::anticollinear(double a) const  // With a negative a you make it collinear
{
    return (*this) * -a;
}

#endif
