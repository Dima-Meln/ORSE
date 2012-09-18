#ifndef COMMON_H
#define COMMON_H

using namespace std;

#define BeginNamespace namespace Orse {
#define EndNamespace };

#   if OGRE_PLATFORM == OGRE_PLATFORM_WIN32

#	pragma once
#	pragma warning( disable : 4244 )

#	if OGRE_COMPILER == OGRE_COMPILER_MSVC
#		ifdef ORSE_EXPORT
#			define _ORSE_EXPORT __declspec(dllexport)
#		else
#			define _ORSE_EXPORT __declspec(dllimport)
#		endif
#	else
#		define _ORSE_EXPORT
#	endif
#elif OGRE_COMPILER == OGRE_COMPILER_GNUC
#	if defined(ORSE_EXPORT) && OGRE_COMP_VER >= 400
#		define _ORSE_EXPORT __attribute__ ((visibility("default")))
#	else
#		define _ORSE_EXPORT
#	endif
#else // Other Compilers
#	define _ORSE_EXPORT
#endif

#endif
