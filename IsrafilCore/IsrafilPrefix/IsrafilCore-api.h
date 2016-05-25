
#ifndef ISRAFILCORE_API_H
#define ISRAFILCORE_API_H

#ifdef ISRAFILCORE_STATIC_DEFINE
#  define ISRAFILCORE_API
#  define ISRAFILCORE_NO_EXPORT
#else
#  ifndef ISRAFILCORE_API
#    ifdef IsrafilCore_EXPORTS
        /* We are building this library */
#      define ISRAFILCORE_API __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define ISRAFILCORE_API __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ISRAFILCORE_NO_EXPORT
#    define ISRAFILCORE_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ISRAFILCORE_DEPRECATED
#  define ISRAFILCORE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ISRAFILCORE_DEPRECATED_EXPORT
#  define ISRAFILCORE_DEPRECATED_EXPORT ISRAFILCORE_API ISRAFILCORE_DEPRECATED
#endif

#ifndef ISRAFILCORE_DEPRECATED_NO_EXPORT
#  define ISRAFILCORE_DEPRECATED_NO_EXPORT ISRAFILCORE_NO_EXPORT ISRAFILCORE_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define ISRAFILCORE_NO_DEPRECATED
#endif

#endif
 

#ifndef ISRAFILCORE_API_H
#define ISRAFILCORE_API_H

#ifdef ISRAFILCORE_STATIC_DEFINE
#  define ISRAFILCORE_API
#  define ISRAFILCORE_NO_EXPORT
#else
#  ifndef ISRAFILCORE_API
#    ifdef IsrafilCore_EXPORTS
        /* We are building this library */
#      define ISRAFILCORE_API __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define ISRAFILCORE_API __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ISRAFILCORE_NO_EXPORT
#    define ISRAFILCORE_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ISRAFILCORE_DEPRECATED
#  define ISRAFILCORE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ISRAFILCORE_DEPRECATED_EXPORT
#  define ISRAFILCORE_DEPRECATED_EXPORT ISRAFILCORE_API ISRAFILCORE_DEPRECATED
#endif

#ifndef ISRAFILCORE_DEPRECATED_NO_EXPORT
#  define ISRAFILCORE_DEPRECATED_NO_EXPORT ISRAFILCORE_NO_EXPORT ISRAFILCORE_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define ISRAFILCORE_NO_DEPRECATED
#endif

#endif
