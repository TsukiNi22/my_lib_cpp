/**************************************************************\
Edition:
##  @date 26/02/2026 by @author Tsukini

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
    #define unused          [[maybe_unused]]                // Signal an unused variable
    #define nodiscard       [[nodiscard]]                   // Warn for unused return
    #define hidden          [[gnu::visibility("hidden")]]   // Change the visibility on a shared lib
    #define ctor            [[gnu::constructor]]            // Execute before the main
    #define dtor            [[gnu::destructor]]             // Execute after the main

    /* optimisation */
    #define cold        [[gnu::cold]]   // Signal a function that has a small number of use
    #define hot         [[gnu::hot]]    // Signal a function that has a huge number of use
    #define likely      [[likely]]      // Signal a condition that has a bigger probability of appening
    #define unlikely    [[unlikely]]    // Signal a condition that has a smallest probability of appening

    /* binary */
    #define remove_padding  [[gnu::packed]] // Remove the memory padding in a struct

#endif /* DEFINE_H */
