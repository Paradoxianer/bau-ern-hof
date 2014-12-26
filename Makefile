NAME= Bauernhof

TYPE= APP

SRCS=	App.cpp \
		MainWindow.cpp \
		GameView.cpp \
		SpielElement

RSRCS=

LIBS= root be translation

LIBPATHS=

SYSTEM_INCLUDE_PATHS= 

LOCAL_INCLUDE_PATHS= 

OPTIMIZE=NONE
#	specify any preprocessor symbols to be defined.  The symbols will not
#	have their values set automatically; you must supply the value (if any)
#	to use.  For example, setting DEFINES to "DEBUG=1" will cause the
#	compiler option "-DDEBUG=1" to be used.  Setting DEFINES to "DEBUG"
#	would pass "-DDEBUG" on the compiler's command line.

DEFINES= DEBUG

#	specify special warning levels
#	if unspecified default warnings will be used
#	NONE = supress all warnings
#	ALL = enable all warnings
WARNINGS = ALL

# Build with debugging symbols if set to TRUE
SYMBOLS= TRUE

COMPILER_FLAGS=

LINKER_FLAGS=

## include the makefile-engine
include $(BUILDHOME)/etc/makefile-engine
