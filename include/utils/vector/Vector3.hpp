/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 08/04/2026 by @author Tsukini

File Name:
##  @file Vector3.hpp

File Description:
##  Vector hat contains 3 value respectivly x, y & z of undefined type
\**************************************************************/

#ifndef VECTOR3_H
    #define VECTOR3_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "../concepts/OperationConcepts.hpp"        // Operation Concepts
    #include "../exception/ExceptionDefine.hpp"         // utils::exception::Code
    #include "../exception/basic/ErrorException.hpp"    // utils::exception::ErrorException
    #include "IVector.hpp"                              // utils::vector::IVector
    #include <ostream>                                  // std::ostream
    #include <cstddef>                                  // std::size_t
    #include <cmath>                                    // std::sqrt
    #include <algorithm>                                // std::clamp

    //----------------------------------------------------------------//
    /* DEFINE */

    /* limits */
    #define MAX_INDEX_VECTOR3 3

namespace utils::vector { // namespace start
//----------------------------------------------------------------//
/* CLASS */

template<typename T>
class Vector3: public utils::vector::IVector<T> {
    public:
        T x;
        T y;
        T z;

        // ----------- Function ----------- //
        T get(std::size_t index) const final {
            if (index >= MAX_INDEX_VECTOR3)
                throw utils::exception::ErrorException(utils::exception::Code::VectorInvalidIndex);
            return (index == 0 ? x : (index == 1 ? y : z));
        }
        Vector3 clamp(const Vector3& min, const Vector3& max) const
        {return {std::clamp(x, min.x, max.x), std::clamp(y, min.y, max.y), std::clamp(z, min.z, max.z)};}

        // ------- Special-Function ------- //
        T dot(const Vector3& v) const
        requires utils::concepts::Multipliable<T> && utils::concepts::Addable<T>
        {return x * v.x + y * v.y + z * v.z;}
        T length() const
        requires utils::concepts::Multipliable<T> {return std::sqrt(x * x + y * y + z * z);}
        T lengthSquared() const
        requires utils::concepts::Multipliable<T> && utils::concepts::Addable<T> {return x * x + y * y + z * z;}
        Vector3 normalize() const
        requires utils::concepts::Divisible<T>
        {
            T len = length();
            return Vector3(x / len, y / len, z / len);
        }

        // ------------ Operator ---------- //
        Vector3& operator=(const Vector3& object) = default;
        Vector3& operator=(Vector3&& object) = default;
        T& operator[](std::size_t index) {
            if (index >= MAX_INDEX_VECTOR3)
                throw utils::exception::ErrorException(utils::exception::Code::VectorInvalidIndex);
            return (index == 0 ? x : (index == 1 ? y : z));
        }
        const T& operator[](std::size_t index) const {
            if (index >= MAX_INDEX_VECTOR3)
                throw utils::exception::ErrorException(utils::exception::Code::VectorInvalidIndex);
            return (index == 0 ? x : (index == 1 ? y : z));
        }

        // -------- Basic-Operator -------- //
        Vector3 operator+(const T& v) const
        requires utils::concepts::Addable<T> {return Vector3(x + v, y + v, z + v);}
        Vector3 operator+(const Vector3& v) const
        requires utils::concepts::Addable<T> {return Vector3(x + v.x, y + v.y, z + v.z);}
        Vector3 operator-(const T& v) const
        requires utils::concepts::Subtractable<T> {return Vector3(x - v, y - v, z - v);}
        Vector3 operator-(const Vector3& v) const
        requires utils::concepts::Subtractable<T> {return Vector3(x - v.x, y - v.y, z - v.z);}
        Vector3 operator*(const T& v) const
        requires utils::concepts::Multipliable<T> {return Vector3(x * v, y * v, z * v);}
        Vector3 operator*(const Vector3& v) const
        requires utils::concepts::Multipliable<T> {return Vector3(x * v.x, y * v.y, z * v.z);}
        Vector3 operator/(const T& v) const
        requires utils::concepts::Divisible<T> {return Vector3(x / v, y / v, z / v);}
        Vector3 operator/(const Vector3& v) const
        requires utils::concepts::Divisible<T> {return Vector3(x / v.x, y / v.y, z / v.z);}

        // ----- Assignment-Operator ----- //
        Vector3& operator+=(const T& v)
        requires utils::concepts::AddAssignable<T> {x += v; y += v; z += v; return *this;}
        Vector3& operator+=(const Vector3& v)
        requires utils::concepts::AddAssignable<T> {x += v.x; y += v.y; z += v.z; return *this;}
        Vector3& operator-=(const T& v)
        requires utils::concepts::SubtractAssignable<T> {x -= v; y -= v; z -= v; return *this;}
        Vector3& operator-=(const Vector3& v)
        requires utils::concepts::SubtractAssignable<T> {x -= v.x; y -= v.y; z -= v.z; return *this;}
        Vector3& operator*=(const T& v)
        requires utils::concepts::MultiplyAssignable<T> {x *= v; y *= v; z *= v; return *this;}
        Vector3& operator*=(const Vector3& v)
        requires utils::concepts::MultiplyAssignable<T> {x *= v.x; y *= v.y; z *= v.z; return *this;}
        Vector3& operator/=(const T& v)
        requires utils::concepts::DivideAssignable<T> {x /= v; y /= v; z /= v; return *this;}
        Vector3& operator/=(const Vector3& v)
        requires utils::concepts::DivideAssignable<T> {x /= v.x; y /= v.y; z /= v.z; return *this;}

        // ---------- Comparison ---------- //
        bool operator==(const T& v) const
        requires utils::concepts::EqualityComparable<T> {return (x == v && y == v && z == v);}
        bool operator==(const Vector3& v) const
        requires utils::concepts::EqualityComparable<T> {return (x == v.x && y == v.y && z == v.z);}
        bool operator!=(const T& v) const
        requires utils::concepts::EqualityComparable<T> {return (x != v || y != v || z != v);}
        bool operator!=(const Vector3& v) const
        requires utils::concepts::EqualityComparable<T> {return (x != v.x || y != v.y || z != v.z);}
        bool operator<(const T& v) const
        requires utils::concepts::Comparable<T> {return (x < v && y < v && z < v);}
        bool operator<(const Vector3& v) const
        requires utils::concepts::Comparable<T> {return (x < v.x && y < v.y && z < v.z);}
        bool operator<=(const T& v) const
        requires utils::concepts::Comparable<T> {return (x <= v && y <= v && z <= v);}
        bool operator<=(const Vector3& v) const
        requires utils::concepts::Comparable<T> {return (x <= v.x && y <= v.y && z <= v.z);}
        bool operator>(const T& v) const
        requires utils::concepts::Comparable<T> {return (x > v && y > v && z > v);}
        bool operator>(const Vector3& v) const
        requires utils::concepts::Comparable<T> {return (x > v.x && y > v.y && z > v.z);}
        bool operator>=(const T& v) const
        requires utils::concepts::Comparable<T> {return (x >= v && y >= v && z >= v);}
        bool operator>=(const Vector3& v) const
        requires utils::concepts::Comparable<T> {return (x >= v.x && y >= v.y && z >= v.z);}

        // ------------ Unary ------------- //
        Vector3 operator-() const
        requires utils::concepts::Negatable<T> {return Vector3(-x, -y, -z);}

        // ---------- Constructor --------- //
        Vector3() = default;
        Vector3(T x, T y, T z): x(x), y(y), z(z) {};
        Vector3(const Vector3& object) = default;
        Vector3(Vector3&& object) = default;

        // ----------- Destructor --------- //
        ~Vector3() = default;
};

// -------- Basic-Operator (reverse) -------- //
template<typename T>
utils::vector::Vector3<T> operator+(const T& lhs, const utils::vector::Vector3<T>& rhs)
requires utils::concepts::Addable<T>
{return utils::vector::Vector3<T>(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z);}

template<typename T>
utils::vector::Vector3<T> operator-(const T& lhs, const utils::vector::Vector3<T>& rhs)
requires utils::concepts::Subtractable<T>
{return utils::vector::Vector3<T>(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z);}

template<typename T>
utils::vector::Vector3<T> operator*(const T& lhs, const utils::vector::Vector3<T>& rhs)
requires utils::concepts::Multipliable<T>
{return utils::vector::Vector3<T>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);}

template<typename T>
utils::vector::Vector3<T> operator/(const T& lhs, const utils::vector::Vector3<T>& rhs)
requires utils::concepts::Divisible<T>
{return utils::vector::Vector3<T>(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z);}

// -------- Comparison (reverse) -------- //
template<typename T>
bool operator==(const T& lhs, const utils::vector::Vector3<T>& rhs)
requires utils::concepts::EqualityComparable<T>
{return (lhs == rhs.x && lhs == rhs.y && lhs == rhs.z);}

template<typename T>
bool operator!=(const T& lhs, const utils::vector::Vector3<T>& rhs)
requires utils::concepts::EqualityComparable<T>
{return (lhs != rhs.x || lhs != rhs.y || lhs != rhs.z);}

template<typename T>
bool operator<(const T& lhs, const utils::vector::Vector3<T>& rhs)
requires utils::concepts::Comparable<T>
{return (lhs < rhs.x && lhs < rhs.y && lhs < rhs.z);}

template<typename T>
bool operator<=(const T& lhs, const utils::vector::Vector3<T>& rhs)
requires utils::concepts::Comparable<T>
{return (lhs <= rhs.x && lhs <= rhs.y && lhs <= rhs.z);}

template<typename T>
bool operator>(const T& lhs, const utils::vector::Vector3<T>& rhs)
requires utils::concepts::Comparable<T>
{return (lhs > rhs.x && lhs > rhs.y && lhs > rhs.z);}

template<typename T>
bool operator>=(const T& lhs, const utils::vector::Vector3<T>& rhs)
requires utils::concepts::Comparable<T>
{return (lhs >= rhs.x && lhs >= rhs.y && lhs >= rhs.z);}

// -------- Output -------- //
template<typename T>
std::ostream& operator<<(std::ostream& os, const utils::vector::Vector3<T>& v)
{return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";}

} // namespace end
#endif /* VECTOR3_H */
