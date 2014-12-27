NAME= Bauernhof

TYPE= APP

SRCS=	App.cpp \
		MainWindow.cpp \
		GameView.cpp \
		SpielElement

LIBS= be root translation

#	specify the level of optimization that you desire
#	NONE, SOME, FULL
# OPTIMIZE= FULL

#	specify any preprocessor symbols to be defined.  The symbols
#	will be set to a value of 1.  For example specify DEBUG if you want
#	DEBUG=1 to be set when compiling.
DEFINES =   DEBUG

#	specify special warning levels
#	if unspecified default warnings will be used
#	NONE = supress all warnings
#	ALL = enable all warnings
WARNINGS = NONE

#	specify whether image symbols will be created
#	so that stack crawls in the debugger are meaningful
#	if TRUE symbols will be created
SYMBOLS = TRUE

#	specify debug settings
#	if TRUE will allow application to be run from
#	a source-level debugger
DEBUGGER = TRUE

#	specify additional compiler flags for all files
COMPILER_FLAGS =

#	specify additional linker flags
LINKER_FLAGS =

SVG_ICON = ../../Data/Icons/Logogross.svg

#EXTRA_DEPS = copy


APP_MENU	= Software

## include the makefile-engine
include $(BUILDHOME)/etc/makefile-engine
