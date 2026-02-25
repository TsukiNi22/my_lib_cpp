/**************************************************************\
Edition:
##  @date 25/02/2026 by @author Tsukini

File Name:
##  @file Define.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef DEFINE_H
    #define DEFINE_H

    //----------------------------------------------------------------//
    /* DEFINE */

    /* attribute */
    #define unused          __attribute__((unused))                 // Signal an unused variable
    #define unused_return   __attribute__((warn_unused_result))     // Warn for unused return
    #define hidden          __attribute__((visibility("hidden")))   // Change the visibility on a shared lib
    #define ctor            __attribute__((constructor))            // Execute before the main
    #define dtor            __attribute__((destructor))             // Execute after the main

    /* optimisation */
    #define cold        __attribute__((cold))       // Signal a function that has a small number of use
    #define hot         __attribute__((hot))        // Signal a function that has a huge number of use
    #define likely      [[likely]]                  // Signal a condition that has a bigger probability of appening
    #define unlikely    [[unlikely]]                // Signal a condition that has a smallest probability of appening

    /* binary */
    #define remove_padding  __attribute__((packed))     // Remove the memory padding in a struct

#endif /* DEFINE_H */
