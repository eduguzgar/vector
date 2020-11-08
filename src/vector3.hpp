#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <iostream>

template <typename> struct vector3;

// float template specialization

template <>
struct vector3<float>
{
    float x;
    float y;
    float z;

    /* ctors */
    vector3();
    vector3(float x_, float y_, float z_);
    vector3(float a);

    vector3<float>& operator=(const vector3<float>& v);

    /* Initialization */
    void init();        // Initialize to zero

    float* ptr() const;

    void zero();
    bool is_zero() const;
    bool is_almost_zero(const float tolerance = 0.01f) const;
    bool is_any_zero() const;

    /* Equality operators */

    bool operator==(const vector3<float>& v) const;
    bool operator!=(const vector3<float>& v) const;

    /* Compound arithmetic operators */

    vector3<float>& operator+=(const vector3<float>& v);
    vector3<float>& operator+=(const float a);
    vector3<float>& operator-=(const vector3<float>& v);
    vector3<float>& operator-=(const float a);
    vector3<float>& operator*=(const vector3<float>& v);
    vector3<float>& operator*=(const float a);
    vector3<float>& operator/=(const vector3<float>& v);
    vector3<float>& operator/=(const float a);

    /* Unary arithmetic operators */

    vector3<float> operator-(void) const;

    /* Binary arithmetic operators */

    vector3<float> operator+(const vector3<float>& v) const;
    vector3<float> operator-(const vector3<float>& v) const;
    vector3<float> operator*(const vector3<float>& v) const;    // Element wise multiplication
    vector3<float> operator*(float a) const;
    vector3<float> operator/(const vector3<float>& v) const;
    vector3<float> operator/(float a) const;                    // Division by scalar

    /* Other operations */

    float           lengthsqr() const;      // Squared Magnitude of a vector
    float           length() const;         // Magnitude of a vector
    float           lengthsqr_xy() const;
    float           lengthsqr_xz() const;
    float           lengthsqr_yz() const;
    float           length_xy() const;
    float           length_xz() const;
    float           length_yz() const;
    void            normalize_this();       // Unit Vector
    vector3<float>  normalize() const;
    float           distance(const vector3<float>& v) const;    // Distance to another vector
    float           dot(const vector3<float>& v) const;         // Dot product
    vector3<float>  cross(const vector3<float>& v) const;       // Cross product

    bool            is_perpendicular(const vector3<float>& v) const;    // Check ortogonality between two vectors
    void            perpendicular_this(const vector3<float>& v);
    vector3<float>  perpendicular(const vector3<float>& v);
    bool            is_opposite(const vector3<float>& v) const;
    void            opposite_this();
    vector3<float>  opposite() const;
    bool            is_collinear(const vector3<float>& v) const;
    void            collinear_this(float a);
    vector3<float>  collinear(float a) const;
    bool            is_anticollinear(const vector3<float>& v) const;
    void            anticollinear_this(float a);
    vector3<float>  anticollinear(float a) const;

};

/* Non-member functions */
vector3<float> operator*(float a, const vector3<float>& v);       // Symmetric multiplication by scalar

/* I/O operators */
std::ostream& operator<<(std::ostream& out, const vector3<float>& v);

std::istream& operator>>(std::istream& in, vector3<float>& v);

/* Canonical implementations */

float distance(const vector3<float>& lv, const vector3<float>& rv);

float dot(const vector3<float>& lv, const vector3<float>& rv);              // Dot product

vector3<float> cross(const vector3<float>& lv, const vector3<float>& rv);   // Cross product

/* ctors */

vector3<float>::vector3() {}

vector3<float>::vector3(float x_, float y_, float z_)
{
    x = x_;
    y = y_;
    z = z_;
}

vector3<float>::vector3(float a)
{
    x = a;
    y = a;
    z = a;
}

/* Initialization */
inline void vector3<float>::init()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

inline vector3<float>& vector3<float>::operator=(const vector3<float>& v)    // Assigment constructor
{
    x = v.x; y = v.y; z = v.z; return *this;
}

inline float* vector3<float>::ptr() const   // Base pointer to the vector
{
    return (float*)this;
}

/* I/O operators */
std::ostream& operator<<(std::ostream& out, const vector3<float>& v)
{
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

std::istream& operator>>(std::istream& in, vector3<float>& v)
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
inline bool vector3<float>::operator==(const vector3<float>& v) const
{
    return (x == v.x) && (y == v.y) && (z == v.z);
}

inline bool vector3<float>::operator!=(const vector3<float>& v) const
{
    return !((*this) == v);
}

/* Compound arithmetic operators */
inline vector3<float>& vector3<float>::operator+=(const vector3<float>& v)
{
    x += v.x; y += v.y; z += v.z; return *this;
}

inline vector3<float>& vector3<float>::operator+=(float a)
{
    x += a; y += a; z += a; return *this;
}

inline vector3<float>& vector3<float>::operator-=(const vector3<float>& v)
{
    x -= v.x; y -= v.y; z -= v.z; return *this;
}

inline vector3<float>& vector3<float>::operator-=(float a)
{
    x -= a; y -= a; z -= a; return *this;
}

inline vector3<float>& vector3<float>::operator*=(const vector3<float>& v)
{
    x *= v.x; y *= v.y; z *= v.z; return *this;
}

inline vector3<float>& vector3<float>::operator*=(float a)
{
    x *= a; y *= a; z *= a; return *this;
}

inline vector3<float>& vector3<float>::operator/=(const vector3<float>& v)
{
    x /= v.x; y /= v.y; z /= v.z; return *this;
}

inline vector3<float>& vector3<float>::operator/=(float a)
{
    x /= a; y /= a; z /= a; return *this;
}

/* Unary arithmetic operators */
inline vector3<float> vector3<float>::operator-(void) const
{
    return vector3<float>(-x, -y, -z);
}

/* Binary arithmetic operators */
inline vector3<float> vector3<float>::operator+(const vector3<float>& v) const
{
    return vector3<float>(x + v.x, y + v.y, z + v.z);
}

inline vector3<float> vector3<float>::operator-(const vector3<float>& v) const
{
    return vector3<float>(x - v.x, y - v.y, z - v.z);
}

inline vector3<float> vector3<float>::operator*(const vector3<float>& v) const   // Element wise multiplication
{
    return vector3<float>(x * v.x, y * v.y, z * v.z);
}

inline vector3<float> vector3<float>::operator*(float a) const
{
    return vector3<float>(x * a, y * a, z * a);
}

inline vector3<float> operator*(float a, const vector3<float>& v)
{
    return v * a;
}

inline vector3<float> vector3<float>::operator/(const vector3<float>& v) const   // Element wise division
{
    return vector3<float>(x / v.x, y / v.y, z / v.z);
}

inline vector3<float> vector3<float>::operator/(float a) const
{
    return vector3<float>(x / a, y / a, z / a);
}

/* Other operations */
inline void vector3<float>::zero()
{
    x = 0.0f; y = 0.0f; z = 0.0f;
}

inline bool vector3<float>::is_zero() const
{
    return (x == 0.0f) && (y == 0.0f) && (z == 0.0f);
}

inline bool vector3<float>::is_any_zero() const
{
    return (x == 0.0f) || (y == 0.0f) || (z == 0.0f);
}

inline bool vector3<float>::is_almost_zero(float tolerance) const
{
    return x > -tolerance && x < tolerance&&
           y > -tolerance && y < tolerance&&
           z > -tolerance && z < tolerance;
}

inline float vector3<float>::lengthsqr() const
{
    return x * x + y * y + z * z;
}

inline float vector3<float>::length() const
{
    return std::sqrt(lengthsqr());
}

inline float vector3<float>::lengthsqr_xy() const
{
    return x * x + y * y;
}

inline float vector3<float>::lengthsqr_xz() const
{
    return x * x + z * z;
}

inline float vector3<float>::lengthsqr_yz() const
{
    return y * y + z * z;
}

inline float vector3<float>::length_xy() const
{
    return std::sqrt(lengthsqr_xy());
}

inline float vector3<float>::length_xz() const
{
    return std::sqrt(lengthsqr_xz());
}

inline float vector3<float>::length_yz() const
{
    return std::sqrt(lengthsqr_yz());
}

inline void vector3<float>::normalize_this()
{
    (*this) /= length();
}

inline vector3<float> vector3<float>::normalize() const
{
    return (*this) / length();
}

inline float distance(const vector3<float>& lv, const vector3<float>& rv)	// Distance between two vectors
{
    vector3<float> v;
    v = lv - rv;
    return v.length();
}

inline float vector3<float>::distance(const vector3<float>& v) const        // Distance between two vectors
{
    return ::distance(*this, v);
}

inline float dot(const vector3<float>& lv, const vector3<float>& rv)        // Canonical Dot product
{
    return lv.x * rv.x + lv.y * rv.y + lv.z * rv.z;
}

inline float vector3<float>::dot(const vector3<float>& v) const             // Dot product
{
    return ::dot(*this, v);
}

inline vector3<float> cross(const vector3<float>& lv, const vector3<float>& rv)  	// Canonical Cross product
{
    vector3<float> v;
    v.x = lv.y * rv.z - lv.z * rv.y;
    v.y = lv.z * rv.x - lv.x * rv.z;
    v.z = lv.x * rv.y - lv.y * rv.x;
    return v;
}

inline vector3<float> vector3<float>::cross(const vector3<float>& v) const           // Cross product
{
    return ::cross(*this, v);
}

inline bool vector3<float>::is_perpendicular(const vector3<float>& v) const     // Check orthogonality between two vectors
{
    return dot(v) == 0.0f;
}

inline void vector3<float>::perpendicular_this(const vector3<float>& v)		// Make this vector perpendicular to another vector
{
    (*this) = ::cross(*this, v);
}

inline vector3<float> vector3<float>::perpendicular(const vector3<float>& v)	// Perpendicular vector
{
    vector3<float> v_aux;
    v_aux = ::cross(*this, v);
    return v_aux;
}

inline bool vector3<float>::is_opposite(const vector3<float>& v) const
{
    return x == -v.x && y == -v.y && z == -v.z;
}

inline void vector3<float>::opposite_this()
{
    x = -x; y = -y; z = -z;
}

inline vector3<float> vector3<float>::opposite() const
{
    vector3<float> v;
    v.x = -x; v.y = -y; v.z = -z;
    return v;
}

inline bool vector3<float>::is_collinear(const vector3<float>& v) const
{
    return x * v.y == y * v.x && z * v.x == x * v.z;
}

inline void vector3<float>::collinear_this(float a)         // With a negative a you make it anticollinear
{
    (*this) *= a;
}

inline vector3<float> vector3<float>::collinear(float a) const  // With a negative a you make it anticollinear
{
    return (*this) * a;
}

inline bool vector3<float>::is_anticollinear(const vector3<float>& v) const
{
    return x * v.y == y * v.x && z * v.x == x * v.z &&
           std::signbit(x) != std::signbit(v.x) &&
           std::signbit(y) != std::signbit(v.y) &&
           std::signbit(z) != std::signbit(v.z);
}

inline void vector3<float>::anticollinear_this(float a)         // With a negative a you make it collinear
{
    (*this) *= -a;
}

inline vector3<float> vector3<float>::anticollinear(float a) const  // With a negative a you make it collinear
{
    return (*this) * -a;
}

// double template specialization

template <>
struct vector3<double>
{
    double x;
    double y;
    double z;

    /* ctors */
    vector3();
    vector3(double x_, double y_, double z_);
    vector3(double a);

    vector3<double>& operator=(const vector3<double>& v);

    /* Initialization */
    void init();        // Initialize to zero

    double* ptr() const;

    void zero();
    bool is_zero() const;
    bool is_almost_zero(const double tolerance = 0.01f) const;
    bool is_any_zero() const;

    /* Equality operators */

    bool operator==(const vector3<double>& v) const;
    bool operator!=(const vector3<double>& v) const;

    /* Compound arithmetic operators */

    vector3<double>& operator+=(const vector3<double>& v);
    vector3<double>& operator+=(const double a);
    vector3<double>& operator-=(const vector3<double>& v);
    vector3<double>& operator-=(const double a);
    vector3<double>& operator*=(const vector3<double>& v);
    vector3<double>& operator*=(const double a);
    vector3<double>& operator/=(const vector3<double>& v);
    vector3<double>& operator/=(const double a);

    /* Unary arithmetic operators */

    vector3<double> operator-(void) const;

    /* Binary arithmetic operators */

    vector3<double> operator+(const vector3<double>& v) const;
    vector3<double> operator-(const vector3<double>& v) const;
    vector3<double> operator*(const vector3<double>& v) const;    // Element wise multiplication
    vector3<double> operator*(double a) const;
    vector3<double> operator/(const vector3<double>& v) const;
    vector3<double> operator/(double a) const;                    // Division by scalar

    /* Other operations */

    double          lengthsqr() const;      // Squared Magnitude of a vector
    double          length() const;         // Magnitude of a vector
    double          lengthsqr_xy() const;
    double          lengthsqr_xz() const;
    double          lengthsqr_yz() const;
    double          length_xy() const;
    double          length_xz() const;
    double          length_yz() const;
    void            normalize_this();       // Unit Vector
    vector3<double> normalize() const;
    double          distance(const vector3<double>& v) const;    // Distance to another vector
    double          dot(const vector3<double>& v) const;         // Dot product
    vector3<double> cross(const vector3<double>& v) const;       // Cross product

    bool            is_perpendicular(const vector3<double>& v) const;    // Check ortogonality between two vectors
    void            perpendicular_this(const vector3<double>& v);
    vector3<double> perpendicular(const vector3<double>& v);
    bool            is_opposite(const vector3<double>& v) const;
    void            opposite_this();
    vector3<double> opposite() const;
    bool            is_collinear(const vector3<double>& v) const;
    void            collinear_this(double a);
    vector3<double> collinear(double a) const;
    bool            is_anticollinear(const vector3<double>& v) const;
    void            anticollinear_this(double a);
    vector3<double> anticollinear(double a) const;

};

/* Non-member functions */
vector3<double> operator*(double a, const vector3<double>& v);       // Symmetric multiplication by scalar

/* I/O operators */
std::ostream& operator<<(std::ostream& out, const vector3<double>& v);

std::istream& operator>>(std::istream& in, vector3<double>& v);

/* Canonical implementations */

double distance(const vector3<double>& lv, const vector3<double>& rv);

double dot(const vector3<double>& lv, const vector3<double>& rv);               // Dot product

vector3<double> cross(const vector3<double>& lv, const vector3<double>& rv);    // Cross product

/* ctors */

vector3<double>::vector3() {}

vector3<double>::vector3(double x_, double y_, double z_)
{
    x = x_;
    y = y_;
    z = z_;
}

vector3<double>::vector3(double a)
{
    x = a;
    y = a;
    z = a;
}

/* Initialization */
inline void vector3<double>::init()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

inline vector3<double>& vector3<double>::operator=(const vector3<double>& v)    // Assigment constructor
{
    x = v.x; y = v.y; z = v.z; return *this;
}

inline double* vector3<double>::ptr() const   // Base pointer to the vector
{
    return (double*)this;
}

/* I/O operators */
std::ostream& operator<<(std::ostream& out, const vector3<double>& v)
{
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

std::istream& operator>>(std::istream& in, vector3<double>& v)
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
inline bool vector3<double>::operator==(const vector3<double>& v) const
{
    return (x == v.x) && (y == v.y) && (z == v.z);
}

inline bool vector3<double>::operator!=(const vector3<double>& v) const
{
    return !((*this) == v);
}

/* Compound arithmetic operators */
inline vector3<double>& vector3<double>::operator+=(const vector3<double>& v)
{
    x += v.x; y += v.y; z += v.z; return *this;
}

inline vector3<double>& vector3<double>::operator+=(double a)
{
    x += a; y += a; z += a; return *this;
}

inline vector3<double>& vector3<double>::operator-=(const vector3<double>& v)
{
    x -= v.x; y -= v.y; z -= v.z; return *this;
}

inline vector3<double>& vector3<double>::operator-=(double a)
{
    x -= a; y -= a; z -= a; return *this;
}

inline vector3<double>& vector3<double>::operator*=(const vector3<double>& v)
{
    x *= v.x; y *= v.y; z *= v.z; return *this;
}

inline vector3<double>& vector3<double>::operator*=(double a)
{
    x *= a; y *= a; z *= a; return *this;
}

inline vector3<double>& vector3<double>::operator/=(const vector3<double>& v)
{
    x /= v.x; y /= v.y; z /= v.z; return *this;
}

inline vector3<double>& vector3<double>::operator/=(double a)
{
    x /= a; y /= a; z /= a; return *this;
}

/* Unary arithmetic operators */
inline vector3<double> vector3<double>::operator-(void) const
{
    return vector3<double>(-x, -y, -z);
}

/* Binary arithmetic operators */
inline vector3<double> vector3<double>::operator+(const vector3<double>& v) const
{
    return vector3<double>(x + v.x, y + v.y, z + v.z);
}

inline vector3<double> vector3<double>::operator-(const vector3<double>& v) const
{
    return vector3<double>(x - v.x, y - v.y, z - v.z);
}

inline vector3<double> vector3<double>::operator*(const vector3<double>& v) const   // Element wise multiplication
{
    return vector3<double>(x * v.x, y * v.y, z * v.z);
}

inline vector3<double> vector3<double>::operator*(double a) const
{
    return vector3<double>(x * a, y * a, z * a);
}

inline vector3<double> operator*(double a, const vector3<double>& v)
{
    return v * a;
}

inline vector3<double> vector3<double>::operator/(const vector3<double>& v) const   // Element wise division
{
    return vector3<double>(x / v.x, y / v.y, z / v.z);
}

inline vector3<double> vector3<double>::operator/(double a) const
{
    return vector3<double>(x / a, y / a, z / a);
}

/* Other operations */
inline void vector3<double>::zero()
{
    x = 0.0; y = 0.0; z = 0.0;
}

inline bool vector3<double>::is_zero() const
{
    return (x == 0.0) && (y == 0.0) && (z == 0.0);
}

inline bool vector3<double>::is_any_zero() const
{
    return (x == 0.0) || (y == 0.0) || (z == 0.0);
}

inline bool vector3<double>::is_almost_zero(double tolerance) const
{
    return x > -tolerance && x < tolerance&&
        y > -tolerance && y < tolerance&&
        z > -tolerance && z < tolerance;
}

inline double vector3<double>::lengthsqr() const
{
    return x * x + y * y + z * z;
}

inline double vector3<double>::length() const
{
    return std::sqrt(lengthsqr());
}

inline double vector3<double>::lengthsqr_xy() const
{
    return x * x + y * y;
}

inline double vector3<double>::lengthsqr_xz() const
{
    return x * x + z * z;
}

inline double vector3<double>::lengthsqr_yz() const
{
    return y * y + z * z;
}

inline double vector3<double>::length_xy() const
{
    return std::sqrt(lengthsqr_xy());
}

inline double vector3<double>::length_xz() const
{
    return std::sqrt(lengthsqr_xz());
}

inline double vector3<double>::length_yz() const
{
    return std::sqrt(lengthsqr_yz());
}

inline void vector3<double>::normalize_this()
{
    (*this) /= length();
}

inline vector3<double> vector3<double>::normalize() const
{
    return (*this) / length();
}

inline double distance(const vector3<double>& lv, const vector3<double>& rv)	// Distance between two vectors
{
    vector3<double> v;
    v = lv - rv;
    return v.length();
}

inline double vector3<double>::distance(const vector3<double>& v) const        // Distance between two vectors
{
    return ::distance(*this, v);
}

inline double dot(const vector3<double>& lv, const vector3<double>& rv)        // Canonical Dot product
{
    return lv.x * rv.x + lv.y * rv.y + lv.z * rv.z;
}

inline double vector3<double>::dot(const vector3<double>& v) const             // Dot product
{
    return ::dot(*this, v);
}

inline vector3<double> cross(const vector3<double>& lv, const vector3<double>& rv)  	// Canonical Cross product
{
    vector3<double> v;
    v.x = lv.y * rv.z - lv.z * rv.y;
    v.y = lv.z * rv.x - lv.x * rv.z;
    v.z = lv.x * rv.y - lv.y * rv.x;
    return v;
}

inline vector3<double> vector3<double>::cross(const vector3<double>& v) const           // Cross product
{
    return ::cross(*this, v);
}

inline bool vector3<double>::is_perpendicular(const vector3<double>& v) const     // Check orthogonality between two vectors
{
    return dot(v) == 0.0;
}

inline void vector3<double>::perpendicular_this(const vector3<double>& v)		// Make this vector perpendicular to another vector
{
    (*this) = ::cross(*this, v);
}

inline vector3<double> vector3<double>::perpendicular(const vector3<double>& v)	// Perpendicular vector
{
    vector3<double> v_aux;
    v_aux = ::cross(*this, v);
    return v_aux;
}

inline bool vector3<double>::is_opposite(const vector3<double>& v) const
{
    return x == -v.x && y == -v.y && z == -v.z;
}

inline void vector3<double>::opposite_this()
{
    x = -x; y = -y; z = -z;
}

inline vector3<double> vector3<double>::opposite() const
{
    vector3<double> v;
    v.x = -x; v.y = -y; v.z = -z;
    return v;
}

inline bool vector3<double>::is_collinear(const vector3<double>& v) const
{
    return x * v.y == y * v.x && z * v.x == x * v.z;
}

inline void vector3<double>::collinear_this(double a)         // With a negative a you make it anticollinear
{
    (*this) *= a;
}

inline vector3<double> vector3<double>::collinear(double a) const  // With a negative a you make it anticollinear
{
    return (*this) * a;
}

inline bool vector3<double>::is_anticollinear(const vector3<double>& v) const
{
    return x * v.y == y * v.x && z * v.x == x * v.z &&
        std::signbit(x) != std::signbit(v.x) &&
        std::signbit(y) != std::signbit(v.y) &&
        std::signbit(z) != std::signbit(v.z);
}

inline void vector3<double>::anticollinear_this(double a)         // With a negative a you make it collinear
{
    (*this) *= -a;
}

inline vector3<double> vector3<double>::anticollinear(double a) const  // With a negative a you make it collinear
{
    return (*this) * -a;
}

#endif
