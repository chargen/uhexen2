/*
	common.h
	misc utilities used in client and server

	$Id: common.h,v 1.3 2007-09-22 15:27:32 sezero Exp $
*/

#ifndef __HX2_COMMON_H
#define __HX2_COMMON_H

/* snprintf and vsnprintf : */
#undef	SNPRINTF_RETURNS_NEGATIVE
#undef	SNPRINTF_DOESNT_TERMINATE

/* platforms where (v)snprintf implementations return
   a negative value upon error: DOS (DJGPP v2.0.4) and
   Windows does that. Add more here. */
#if defined(PLATFORM_WINDOWS) || defined(PLATFORM_DOS)
#define	SNPRINTF_RETURNS_NEGATIVE	1
#endif

/* platform where (v)snprintf implementations may not
   null-terminate the given buffer upon truncation :
   Windows does that. Add more here. */
#if defined(PLATFORM_WINDOWS)
#define	SNPRINTF_DOESNT_TERMINATE	1
#endif

/* platform dependant (v)snprintf function names: */
#if defined(PLATFORM_WINDOWS)
#define	snprintf_func		_snprintf
#define	vsnprintf_func		_vsnprintf
#else
#define	snprintf_func		snprintf
#define	vsnprintf_func		vsnprintf
#endif

#if defined(SNPRINTF_RETURNS_NEGATIVE) || defined(SNPRINTF_DOESNT_TERMINATE)
extern int q_snprintf (char *str, size_t size, const char *format, ...) __attribute__((format(printf,3,4)));
extern int q_vsnprintf(char *str, size_t size, const char *format, va_list args);
#else
#define	q_snprintf		snprintf_func
#define	q_vsnprintf		vsnprintf_func
#endif


extern	char		com_token[1024];

char *COM_Parse (char *data);

extern	int		com_argc;
extern	char		**com_argv;

int COM_CheckParm (const char *parm);

#endif	/* __HX2_COMMON_H */

