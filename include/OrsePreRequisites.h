#define ORSE_NONCLIENT_BUILD

/*#if OGRE_COMPILER == OGRE_COMPILER_MSVC
#  if defined(ORSE_NONCLIENT_BUILD)
#    define _ORSE_Export __declspec(dllexport)
#  else
#    define _ORSE_Export __declspec(dllimport)
#  endif
#el*/
#if OGRE_COMPILER == OGRE_COMPILER_GNUC
# if defined(ORSE_NONCLIENT_BUILD)
#   define _ORSE_Export __attribute__ ((visibility("default")))
# endif
#endif