/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of fastutils.xs. Do not edit this file, edit fastutils.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "srcXS\\\\misc\\\\fastutils.xs"
/* Utility functions rewritten in C for speed */
#include <stdio.h>
#include <string.h>
#include <string>
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

typedef double (*NVtime_t) ();
static void *NVtime = NULL;

using namespace std;


#line 25 "srcXS\\misc\\fastutils.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)    S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage        S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 167 "srcXS\\misc\\fastutils.c"

XS_EUPXS(XS_Utils_binFind); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Utils_binFind)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "r_array, ID");
    {
	SV *	r_array = ST(0)
;
	SV *	ID = ST(1)
;
	SV *	RETVAL;
#line 24 "srcXS\\\\misc\\\\fastutils.xs"
	int ok;
	SV *ref;
	AV *array;
	I32 len;
#line 186 "srcXS\\misc\\fastutils.c"
#line 29 "srcXS\\\\misc\\\\fastutils.xs"
	/* Sanity check */
	ok = SvOK (r_array);
	if (ok) {
		ref = SvRV (r_array);
		ok = SvTYPE (ref) == SVt_PVAV;
	}
	if (ok) {
		array = (AV *) SvRV (r_array);
		len = av_len (array);
		if (len < 0)
			ok = 0;
	}

	if (ok) {
		I32 i;
		int found = 0;
		char *IDstr;
		STRLEN IDlen;

		/* Loop through the array and stop if one item matches */
		IDstr = SvPV (ID, IDlen);
		for (i = 0; i <= len; i++) {
			SV **currentSV;
			char *current;
			STRLEN currentlen;

			currentSV = av_fetch (array, i, 0);
			if (!currentSV)
				continue;
			current = SvPV (*currentSV, currentlen);

			if (currentlen == IDlen && memcmp (current, IDstr, currentlen) == 0) {
				found = 1;
				break;
			}
		}

		if (found)
			RETVAL = newSViv (i);
		else
			XSRETURN_UNDEF;

	} else
		XSRETURN_UNDEF;
#line 232 "srcXS\\misc\\fastutils.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Utils_timeOut); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Utils_timeOut)
{
    dVAR; dXSARGS;
    if (items < 1 || items > 2)
       croak_xs_usage(cv,  "r_time, compare_time = NULL");
    {
	SV *	r_time = ST(0)
;
	SV *	compare_time;
#line 82 "srcXS\\\\misc\\\\fastutils.xs"
		NV current_time, v_time, v_timeout;
#line 252 "srcXS\\misc\\fastutils.c"
	int	RETVAL;
	dXSTARG;

	if (items < 2)
	    compare_time = NULL;
	else {
	    compare_time = ST(1)
;
	}
#line 84 "srcXS\\\\misc\\\\fastutils.xs"
		if (compare_time) {
			/* r_time is a number */

			if (!(v_time = SvNV (r_time)))
				XSRETURN_YES;
			if (!(v_timeout = SvNV (compare_time)))
				XSRETURN_YES;

			if (!NVtime) {
				SV **svp = hv_fetch (PL_modglobal, "Time::NVtime", 12, 0);
				if (!svp)
					croak("Time::HiRes is required");
				if (!SvIOK (*svp))
					croak("Time::NVtime isn't a function pointer");
				NVtime = INT2PTR (void *, SvIV (*svp));
			}
			current_time = ((NVtime_t) NVtime) ();

		} else {
			/* r_time is a hash */
			HV *hash;
			SV **sv_time, **sv_timeout;

			if (!r_time || !SvOK (r_time) || !SvTYPE (r_time) == SVt_PV)
				XSRETURN_YES;
			if (!(hash = (HV *) SvRV (r_time)))
				XSRETURN_YES;
			if (!(sv_time = hv_fetch (hash, "time", 4, 0)) || !(v_time = SvNV (*sv_time)))
				XSRETURN_YES;
			if (!(sv_timeout = hv_fetch (hash, "timeout", 7, 0)) || !(v_timeout = SvNV (*sv_timeout)))
				XSRETURN_YES;

			if (!NVtime) {
				SV **svp = hv_fetch (PL_modglobal, "Time::NVtime", 12, 0);
				if (!svp)
					croak("Time::HiRes is required");
				if (!SvIOK (*svp))
					croak("Time::NVtime isn't a function pointer");
				NVtime = INT2PTR (void *, SvIV (*svp));
			}
			current_time = ((NVtime_t) NVtime) ();
		}

		RETVAL = (current_time - v_time > v_timeout);
#line 307 "srcXS\\misc\\fastutils.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Utils_xpmmake); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Utils_xpmmake)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "width, height, field_data");
    {
	int	width = (int)SvIV(ST(0))
;
	int	height = (int)SvIV(ST(1))
;
	char *	field_data = (char *)SvPV_nolen(ST(2))
;
	char *	RETVAL;
	dXSTARG;
#line 138 "srcXS\\\\misc\\\\fastutils.xs"
	// Create an XPM from raw field data.
	// Written in C++ for speed.
	string data;
	int y, x;
	char tmp[10], *buf, *line;

	data.reserve (width * height + 1024);
	data.append (
		"/* XPM */\n"
		"static char * my_xpm[] = {\n"
		"\"");
	snprintf (tmp, sizeof (tmp), "%d %d", width, height);
	data.append (tmp);
	data.append (" 8 1\",\n"
		"\"A\tc #F4F4F4\",\n"
		"\"B\tc #505050\",\n"
		"\"C\tc #6060B0\",\n"
		"\"D\tc #8080B0\",\n"
		"\"E\tc #7070B0\",\n"
		"\"F\tc #B0B0B0\",\n"
		"\"G\tc #808080\",\n"
		"\"H\tc #600000\",\n");

	line = (char *) malloc (width);
	for (y = height - 1; y >= 0; y--) {
		for (x = 0; x < width; x++) {
			switch (field_data[y * width + x]) {
			case '\0':
				line[x] = 'A';
				break;
			case '\1':
				line[x] = 'B';
				break;
			case '\2':
				line[x] = 'C';
				break;
			case '\3':
				line[x] = 'D';
				break;
			case '\4':
				line[x] = 'E';
				break;
			case '\5':
				line[x] = 'F';
				break;
			case '\6':
				line[x] = 'G';
				break;
			default:
				line[x] = 'H';
				break;
			}
		}
		data.append ("\"");
		data.append (line, width);
		data.append ("\",\n");
	}
	free (line);
	data.append ("};\n");

	// I hope sizeof(char) == 1...
	New (0, buf, data.size () + 1, char);
	Copy (data.c_str (), buf, data.size (), char);
	buf[data.size ()] = '\0';
	RETVAL = buf;
#line 395 "srcXS\\misc\\fastutils.c"
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Utils_makeDistMap); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Utils_makeDistMap)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "rawMap, width, height");
    {
	SV *	rawMap = ST(0)
;
	int	width = (int)SvIV(ST(1))
;
	int	height = (int)SvIV(ST(2))
;
	SV *	RETVAL;
#line 213 "srcXS\\\\misc\\\\fastutils.xs"
	STRLEN len;
	int i, x, y;
	int dist, val;
	unsigned char *c_rawMap, *data;
	bool done;
#line 422 "srcXS\\misc\\fastutils.c"
#line 219 "srcXS\\\\misc\\\\fastutils.xs"
	if (!SvOK (rawMap))
		XSRETURN_UNDEF;

	c_rawMap = (unsigned char *) SvPV (rawMap, len);
	if ((int) len != width * height)
		XSRETURN_UNDEF;

	/* Simplify the raw map data. Each byte in the raw map data
	   represents a block on the field, but only some bytes are
	   interesting to pathfinding. */
	New (0, data, len, unsigned char);
	Copy (c_rawMap, data, len, unsigned char);
	for (i = 0; i < (int) len; i++) {
		// 0 is open, 3 is walkable water
		switch (data[i]) {
		case 0:
		case 3:
			data[i] = 255;
			break;
		default:
			data[i] = 0;
			break;
		}
	}

	done = false;
	while (!done) {
		done = true;

		// 'push' wall distance right and up
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				i = y * width + x; // i: cell to examine
				dist = data[i]; // dist: initial dist of i from walkable/nonwalkable check above
				if (x != width - 1) { // ignore the width-1 because this is marked walkable in .gat but its not
					int ir = y * width + x + 1; // ir: cell to the right
					int distr = (int) data[ir]; // distr: initial dist of ir from walkable/nonwalkable check above
					int comp = dist - distr; // comp: 
					if (comp > 1) { // dist > distr: real dist is distr + 1
						val = distr + 1;
						if (val > 255)
							val = 255;
						data[i] = val;
						done = false;
					} else if (comp < -1) { // dist < distr: real distr is dist + 1
						val = dist + 1;
						if (val > 255)
							val = 255;
						data[ir] = val;
						done = false;
					}
				}

				if (y != height - 1) {
					int iu = (y + 1) * width + x;
					int distu = (int) data[iu];
					int comp = dist - distu;
					if (comp > 1) {
						int val = distu + 1;
						if (val > 255)
							val = 255;
						data[i] = (char) val;
						done = false;
					} else if (comp < -1) {
						int val = dist + 1;
						if (val > 255)
							val = 255;
						data[iu] = (char) val;
						done = true;
					}
				}
			}
		}

		// 'push' wall distance left and down
		for (y = height - 1; y >= 0; y--) {
			for (x = width - 1; x >= 0 ; x--) {
				i = y * width + x;
				dist = data[i];
				if (x != 0) {
					int il = y * width + x - 1;
					int distl = data[il];
					int comp = dist - distl;
					if (comp > 1) {
						val = distl + 1;
						if (val > 255)
							val = 255;
						data[i] = val;
						done = false;
					} else if (comp < -1) {
						val = dist + 1;
						if (val > 255)
							val = 255;
						data[il] = val;
						done = false;
					}
				}
				if (y != 0) {
					int id = (y - 1) * width + x;
					int distd = data[id];
					int comp = dist - distd;
					if (comp > 1) {
						val = distd + 1;
						if (val > 255)
							val = 255;
						data[i] = val;
						done = false;
					} else if (comp < -1) {
						val = dist + 1;
						if (val > 255)
							val = 255;
						data[id] = val;
						done = false;
					}
				}
			}
		}
	}

	RETVAL = newSVpv ((const char *) data, len);
#line 544 "srcXS\\misc\\fastutils.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_FastUtils); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_FastUtils)
{
    dVAR; dXSARGS;
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK;

        (void)newXSproto_portable("Utils::binFind", XS_Utils_binFind, file, "$$");
        (void)newXSproto_portable("Utils::timeOut", XS_Utils_timeOut, file, "$;$");
        (void)newXSproto_portable("Utils::xpmmake", XS_Utils_xpmmake, file, "$$$");
        (void)newXSproto_portable("Utils::makeDistMap", XS_Utils_makeDistMap, file, "$$$");
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

