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
##  @file OperationConcepts.hpp

File Description:
##  Definition of the different operation concepts
\**************************************************************/

#ifndef OPERATIONCONCEPTS_H
    #define OPERATIONCONCEPTS_H

namespace utils::concepts { // namespace start
//----------------------------------------------------------------//
/* CONCEPTS */

// ------- Basic-Arithmetic ------- //
template<typename T>
concept Addable = requires(T a, T b) {
    {a + b} -> std::convertible_to<T>;
};

template<typename T>
concept Subtractable = requires(T a, T b) {
    {a - b} -> std::convertible_to<T>;
};

template<typename T>
concept Multipliable = requires(T a, T b) {
    {a * b} -> std::convertible_to<T>;
};

template<typename T>
concept Divisible = requires(T a, T b) {
    {a / b} -> std::convertible_to<T>;
};

template<typename T>
concept Arithmetic = Addable<T> && Subtractable<T> && Multipliable<T> && Divisible<T>;

template<typename T>
concept Incrementable = requires(T a) {++a; a++;};
template<typename T>
concept Decrementable = requires(T a) {--a; a--;};

// ----- Assignment-Operations ---- //
template<typename T>
concept AddAssignable = requires(T a, T b) {
    {a += b} -> std::same_as<T&>;
};

template<typename T>
concept SubtractAssignable = requires(T a, T b) {
    {a -= b} -> std::same_as<T&>;
};

template<typename T>
concept MultiplyAssignable = requires(T a, T b) {
    {a *= b} -> std::same_as<T&>;
};

template<typename T>
concept DivideAssignable = requires(T a, T b) {
    {a /= b} -> std::same_as<T&>;
};

// ---------- Comparison ---------- //
template<typename T>
concept EqualityComparable = requires(T a, T b) {
    {a == b} -> std::convertible_to<bool>;
    {a != b} -> std::convertible_to<bool>;
};

template<typename T>
concept Comparable = requires(T a, T b) {
    {a <  b}  -> std::convertible_to<bool>;
    {a <= b} -> std::convertible_to<bool>;
    {a >  b}  -> std::convertible_to<bool>;
    {a >= b} -> std::convertible_to<bool>;
};

// ------------- Unary ------------ //
template<typename T>
concept Negatable = requires(T a) {
    { -a } -> std::convertible_to<T>;
};

} // namespace end
#endif /* OPERATIONCONCEPTS_H */
