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
##  @file Vector2.hpp

File Description:
##  Vector hat contains 2 value respectivly x & y of undefined type
\**************************************************************/

#ifndef VECTOR2_H
    #define VECTOR2_H

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

    //----------------------------------------------------------------//
    /* DEFINE */

    /* limits */
    #define MAX_INDEX_VECTOR2 2

namespace utils::vector { // namespace start
//----------------------------------------------------------------//
/* CLASS */

template<typename T>
class Vector2: public utils::vector::IVector<T> {
    public:
        T x;
        T y;

        // ----------- Function ----------- //
        T get(std::size_t index) const final {
            if (index >= MAX_INDEX_VECTOR2)
                throw utils::exception::ErrorException(utils::exception::Code::VectorInvalidIndex);
            return (index == 0 ? this->x : this->y);
        }
        Vector2 clamp(const Vector2& min, const Vector2& max) const
        {return {std::clamp(x, min.x, max.x), std::clamp(y, min.y, max.y)};}

        // ------- Special-Function ------- //
        T dot(const Vector2& v) const
        requires utils::concepts::Multipliable<T> && utils::concepts::Addable<T> {return x * v.x + y * v.y;}
        T length() const
        requires utils::concepts::Multipliable<T> {return std::sqrt(x * x + y * y);}
        T lengthSquared() const
        requires utils::concepts::Multipliable<T> && utils::concepts::Addable<T> {return x * x + y * y;}
        Vector2 normalize() const
        requires utils::concepts::Divisible<T>
        {
            T len = length();
            return Vector2(x / len, y / len);
        }

        // ------------ Operator ---------- //
        Vector2& operator=(const Vector2& object) = default;
        Vector2& operator=(Vector2&& object) = default;
        T& operator[](std::size_t index) {
            if (index >= MAX_INDEX_VECTOR2)
                throw utils::exception::ErrorException(utils::exception::Code::VectorInvalidIndex);
            return (index == 0 ? x : y);
        }
        const T& operator[](std::size_t index) const {
            if (index >= MAX_INDEX_VECTOR2)
                throw utils::exception::ErrorException(utils::exception::Code::VectorInvalidIndex);
            return (index == 0 ? x : y);
        }

        // -------- Basic-Operator -------- //
        Vector2 operator+(const T& v) const
        requires utils::concepts::Addable<T> {return Vector2(x + v, y + v);}
        Vector2 operator+(const Vector2& v) const
        requires utils::concepts::Addable<T> {return Vector2(x + v.x, y + v.y);}
        Vector2 operator-(const T& v) const
        requires utils::concepts::Subtractable<T> {return Vector2(x - v, y - v);}
        Vector2 operator-(const Vector2& v) const
        requires utils::concepts::Subtractable<T> {return Vector2(x - v.x, y - v.y);}
        Vector2 operator*(const T& v) const
        requires utils::concepts::Multipliable<T> {return Vector2(x * v, y * v);}
        Vector2 operator*(const Vector2& v) const
        requires utils::concepts::Multipliable<T> {return Vector2(x * v.x, y * v.y);}
        Vector2 operator/(const T& v) const
        requires utils::concepts::Divisible<T> {return Vector2(x / v, y / v);}
        Vector2 operator/(const Vector2& v) const
        requires utils::concepts::Divisible<T> {return Vector2(x / v.x, y / v.y);}

        // ----- Assignment-Operator ----- //
        Vector2& operator+=(const T& v)
        requires utils::concepts::AddAssignable<T> {x += v; y += v; return *this;}
        Vector2& operator+=(const Vector2& v)
        requires utils::concepts::AddAssignable<T> {x += v.x; y += v.y; return *this;}
        Vector2& operator-=(const T& v)
        requires utils::concepts::SubtractAssignable<T> {x -= v; y -= v; return *this;}
        Vector2& operator-=(const Vector2& v)
        requires utils::concepts::SubtractAssignable<T> {x -= v.x; y -= v.y; return *this;}
        Vector2& operator*=(const T& v)
        requires utils::concepts::MultiplyAssignable<T> {x *= v; y *= v; return *this;}
        Vector2& operator*=(const Vector2& v)
        requires utils::concepts::MultiplyAssignable<T> {x *= v.x; y *= v.y; return *this;}
        Vector2& operator/=(const T& v)
        requires utils::concepts::DivideAssignable<T> {x /= v; y /= v; return *this;}
        Vector2& operator/=(const Vector2& v)
        requires utils::concepts::DivideAssignable<T> {x /= v.x; y /= v.y; return *this;}

        // ---------- Comparison ---------- //
        bool operator==(const T& v) const
        requires utils::concepts::EqualityComparable<T> {return (x == x && y == y);}
        bool operator==(const Vector2& v) const
        requires utils::concepts::EqualityComparable<T> {return (x == v.x && y == v.y);}
        bool operator!=(const T& v) const
        requires utils::concepts::EqualityComparable<T> {return (x != x || y != y);}
        bool operator!=(const Vector2& v) const
        requires utils::concepts::EqualityComparable<T> {return (x != v.x || y != v.y);}
        bool operator<(const T& v) const
        requires utils::concepts::Comparable<T> {return (x < x && y < y);}
        bool operator<(const Vector2& v) const
        requires utils::concepts::Comparable<T> {return (x < v.x && y < v.y);}
        bool operator<=(const T& v) const
        requires utils::concepts::Comparable<T> {return (x <= x && y <= y);}
        bool operator<=(const Vector2& v) const
        requires utils::concepts::Comparable<T> {return (x <= v.x && y <= v.y);}
        bool operator>(const T& v) const
        requires utils::concepts::Comparable<T> {return (x > x && y > y);}
        bool operator>(const Vector2& v) const
        requires utils::concepts::Comparable<T> {return (x > v.x && y > v.y);}
        bool operator>=(const T& v) const
        requires utils::concepts::Comparable<T> {return (x >= x && y >= y);}
        bool operator>=(const Vector2& v) const
        requires utils::concepts::Comparable<T> {return (x >= v.x && y >= v.y);}

        // ------------ Unary ------------- //
        Vector2 operator-() const
        requires utils::concepts::Negatable<T> {return Vector2(-x, -y);}

        // ---------- Constructor --------- //
        Vector2() = default;
        Vector2(T x, T y): x(x), y(y) {};
        Vector2(const Vector2& object) = default;
        Vector2(Vector2&& object) = default;

        // ----------- Destructor --------- //
        ~Vector2() = default;
};

// -------- Basic-Operator (reverse) -------- //
template<typename T>
utils::vector::Vector2<T> operator+(const T& lhs, const utils::vector::Vector2<T>& rhs)
requires utils::concepts::Addable<T>
{return utils::vector::Vector2<T>(lhs + rhs.x, lhs + rhs.y);}

template<typename T>
utils::vector::Vector2<T> operator-(const T& lhs, const utils::vector::Vector2<T>& rhs)
requires utils::concepts::Subtractable<T>
{return utils::vector::Vector2<T>(lhs - rhs.x, lhs - rhs.y);}

template<typename T>
utils::vector::Vector2<T> operator*(const T& lhs, const utils::vector::Vector2<T>& rhs)
requires utils::concepts::Multipliable<T>
{return utils::vector::Vector2<T>(lhs * rhs.x, lhs * rhs.y);}

template<typename T>
utils::vector::Vector2<T> operator/(const T& lhs, const utils::vector::Vector2<T>& rhs)
requires utils::concepts::Divisible<T>
{return utils::vector::Vector2<T>(lhs / rhs.x, lhs / rhs.y);}

// -------- Comparison (reverse) -------- //
template<typename T>
bool operator==(const T& lhs, const utils::vector::Vector2<T>& rhs)
requires utils::concepts::EqualityComparable<T>
{return (lhs == rhs.x && lhs == rhs.y);}

template<typename T>
bool operator!=(const T& lhs, const utils::vector::Vector2<T>& rhs)
requires utils::concepts::EqualityComparable<T>
{return (lhs != rhs.x || lhs != rhs.y);}

template<typename T>
bool operator<(const T& lhs, const utils::vector::Vector2<T>& rhs)
requires utils::concepts::Comparable<T>
{return (lhs < rhs.x && lhs < rhs.y);}

template<typename T>
bool operator<=(const T& lhs, const utils::vector::Vector2<T>& rhs)
requires utils::concepts::Comparable<T>
{return (lhs <= rhs.x && lhs <= rhs.y);}

template<typename T>
bool operator>(const T& lhs, const utils::vector::Vector2<T>& rhs)
requires utils::concepts::Comparable<T>
{return (lhs > rhs.x && lhs > rhs.y);}

template<typename T>
bool operator>=(const T& lhs, const utils::vector::Vector2<T>& rhs)
requires utils::concepts::Comparable<T>
{return (lhs >= rhs.x && lhs >= rhs.y);}

// -------- Comparison (reverse) -------- //
template<typename T>
std::ostream& operator<<(std::ostream& os, const utils::vector::Vector2<T>& v)
{return os << "(" << v.x << ", " << v.y << ")";}

} // namespace end
#endif /* VECTOR2_H */
