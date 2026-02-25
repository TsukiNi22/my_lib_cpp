/**************************************************************\
Edition:
##  @date 25/02/2026 by @author Tsukini

File Name:
##  @file Macro.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef MACRO_H
    #define MACRO_H

    //----------------------------------------------------------------//
    /* MACRO */

    /* attribute */
    #define write_only(i_ptr, i_size)   __attribute__((access(write_only, i_ptr, i_size)))  // Set the mode of a ptr in the argument so that it can only be writed in the limit of the size
    #define read_only(i_ptr, i_size)    __attribute__((access(read_only, i_ptr, i_size)))   // Set the mode of a ptr in the argument so that it can only be readed in the limit of the size
    #define nonnull(i_ptr)              __attribute__((nonnull(i_ptr)))                     // Warn for null on the given argument

    /* optimisation */
    #define alloc_size(i_size)          __attribute__((alloc_size(i_size)))         // Signal a malloc of the given size in the argument
    #define alloc_size(i_mul, i_size)   __attribute__((alloc_size(i_mul, i_size)))  // Signal a malloc of the given size in the argument multiply by another argument
    #define likely(c)                   __builtin_expect(!!(c), 1)                  // Signal a condition that has a bigger probability of appening
    #define unlikely(c)                 __builtin_expect(!!(c), 0)                  // Signal a condition that has a smallest probability of appening

    /* binary */
    #define set_padding(n)  __attribute__((aligned(n))) // Set the memory padding in a struct

#endif /* MACRO_H */
