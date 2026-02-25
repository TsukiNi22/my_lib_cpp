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

    /* optimisation */
    #define likely(c)   __builtin_expect(!!(c), 1)  // Signal a condition that has a bigger probability of appening
    #define unlikely(c) __builtin_expect(!!(c), 0)  // Signal a condition that has a smallest probability of appening

    /* binary */
    #define set_padding(n)  __attribute__((aligned(n))) // Set the memory padding in a struct

#endif /* MACRO_H */
