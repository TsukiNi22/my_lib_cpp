/**************************************************************\
Edition:
##  @date 26/02/2026 by @author Tsukini

File Name:
##  @file Attribute-fallback.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef ATTRIBUTE_FALLBACK_H
    #define ATTRIBUTE_FALLBACK_H

    //----------------------------------------------------------------//
    /* DEFINE */

    /* attributes */
    #define nodiscard
    #define unused
    #define hidden
    #define ctor
    #define dtor

    /* branch prediction */
    #define likely
    #define unlikely
    #define likely_c(c)     (c)
    #define unlikely_c(c)   (c)

    /* optimisation */
    #define cold
    #define hot

    /* binary layout */
    #define remove_padding
    #define set_padding(n)

    /* allocation hints */
    #define alloc_size(i_size)
    #define alloc_size_mul(i_mul, i_size)
    #define write_only(i_ptr, i_size)
    #define read_only(i_ptr, i_size)
    #define nonnull(i_ptr)

#endif /* ATTRIBUTE_FALLBACK_H */
