#ifndef __JKIT__PLATFORM_HPP__
#define __JKIT__PLATFORM_HPP__

#include <stdint.h>

#if defined(__linux)
	#define JKIT_PLATFORM_LINUX
	#define JKIT_WINDOWING_X11
#elif defined(_WIN32) || defined(WIN32) || defined(_WINDOWS)
	#include <windows.h>
	#define JKIT_PLATFORM_WINDOWS
	#define JKIT_WINDOWING_WINDOWS
#endif


#if defined(_WINDOWS) || defined(_WIN32) || defined(__CYGWIN__)
	#ifdef engine_EXPORTS
		#ifdef __GNUC__
			#define JKIT_PUBLIC_API __attribute__ ((dllexport))
		#else
			#define JKIT_PUBLIC_API __declspec(dllexport)
		#endif
	#else
		#ifdef __GNUC__
			#define JKIT_PUBLIC_API __attribute__ ((dllimport))
		#else
			#define JKIT_PUBLIC_API __declspec(dllimport)
		#endif
	#endif
	#define JKIT_LOCAL_API
#else
	#if __GNUC__ >= 4
		#define JKIT_PUBLIC_API __attribute__ ((visibility ("default")))
		#define JKIT_LOCAL_API  __attribute__ ((visibility ("hidden")))
	#else
		#define JKIT_PUBLIC_API
		#define JKIT_LOCAL_API
	#endif
#endif


#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ > 4)
	#define JKIT_PRINTF(format_idx, arg_idx)	\
			__attribute__((__format__ (__printf__, format_idx, arg_idx)))
	#define JKIT_SCANF(format_idx, arg_idx)	\
			__attribute__((__format__ (__scanf__, format_idx, arg_idx)))
	#define JKIT_FORMAT(arg_idx)				\
			__attribute__((__format_arg__ (arg_idx)))
	#define JKIT_NORETURN					\
			__attribute__((__noreturn__))
	#define JKIT_CONST						\
			__attribute__((__const__))
	#define JKIT_UNUSED						\
			__attribute__((__unused__))
	#define JKIT_NO_INSTRUMENT				\
			__attribute__((__no_instrument_function__))
#else
	#define JKIT_PRINTF(format_idx, arg_idx)
	#define JKIT_SCANF(format_idx, arg_idx)
	#define JKIT_FORMAT(arg_idx)
	#define JKIT_NORETURN
	#define JKIT_CONST
	#define JKIT_UNUSED
	#define JKITD_NO_INSTRUMENT
#endif


#ifdef __GNUC__
	#define JKIT_NOEXCEPT noexcept
#else
	#define JKIT_NOEXCEPT throw()
#endif


#endif
