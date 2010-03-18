FIND_PATH(GENSOLVER_INCLUDE_DIR libgensolver.h /usr/include/gensolver /usr/local/include/gensolver)

FIND_LIBRARY(GENSOLVER_LIBRARY NAMES gensolver PATHS /usr/lib /usr/local/lib /usr/lib/gensolver /usr/local/lib/gensolver ) 

IF (GENSOLVER_INCLUDE_DIR AND GENSOLVER_LIBRARY)
   SET(GENSOLVER_FOUND TRUE)
ENDIF (GENSOLVER_INCLUDE_DIR AND GENSOLVER_LIBRARY)


IF (GENSOLVER_FOUND)
   IF (NOT Gensolver_FIND_QUIETLY)
      MESSAGE(STATUS "Found Gensolver: ${GENSOLVER_LIBRARY}")
   ENDIF (NOT Gensolver_FIND_QUIETLY)
ELSE (GENSOLVER_FOUND)
   IF (Gensolver_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find Gensolver")
   ENDIF (Gensolver_FIND_REQUIRED)
ENDIF (GENSOLVER_FOUND)
