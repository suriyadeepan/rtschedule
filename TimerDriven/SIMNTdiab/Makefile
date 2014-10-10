# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = SIMNTdiab
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
PRJ_ROOT_DIR := C:/Users/l4d/Documents/rtschedule/TimerDriven
WS_ROOT_DIR := C:/Users/l4d/Documents/rtschedule



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = simpc
CPU = SIMNT
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tX86LH:vxworks66
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
DEBUGFLAGS_Linker = -XO -Xsize-opt
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif


#Project Targets
PROJECT_TARGETS = TimerDriven/$(MODE_DIR)/TimerDriven.out \
	 TimerDriven_partialImage/$(MODE_DIR)/TimerDriven_partialImage.o


#Rules

# TimerDriven
ifeq ($(DEBUG_MODE),1)
TimerDriven/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
TimerDriven/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
TimerDriven/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
TimerDriven/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
TimerDriven/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TimerDriven/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
TimerDriven/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
TimerDriven/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
TimerDriven/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
TimerDriven/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
TimerDriven/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TimerDriven/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
TimerDriven/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
TimerDriven/$(MODE_DIR)/% : IDE_LIBRARIES = 
TimerDriven/$(MODE_DIR)/% : PROJECT_TYPE = DKM
TimerDriven/$(MODE_DIR)/% : DEFINES = 
TimerDriven/$(MODE_DIR)/% : EXPAND_DBG = 0
TimerDriven/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
TimerDriven/$(MODE_DIR)/% : CPU = SIMNT
TimerDriven/$(MODE_DIR)/% : TOOL_FAMILY = diab
TimerDriven/$(MODE_DIR)/% : TOOL = diab
TimerDriven/$(MODE_DIR)/% : TOOL_PATH = 
TimerDriven/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
TimerDriven/$(MODE_DIR)/% : LIBPATH = 
TimerDriven/$(MODE_DIR)/% : LIBS = 
TimerDriven/$(MODE_DIR)/% : OBJ_DIR := TimerDriven/$(MODE_DIR)

OBJECTS_TimerDriven = TimerDriven_partialImage/$(MODE_DIR)/TimerDriven_partialImage.o

TimerDriven/$(MODE_DIR)/TimerDriven.out : $(OBJECTS_TimerDriven)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_TimerDriven) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c pentium > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations  $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_TimerDriven) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

TimerDriven/$(MODE_DIR)/TimerDriven_compile_file : $(FILE) ;

_clean :: TimerDriven/$(MODE_DIR)/TimerDriven_clean

TimerDriven/$(MODE_DIR)/TimerDriven_clean : 
	$(TRACE_FLAG)if [ -d "TimerDriven" ]; then cd "TimerDriven"; rm -rf $(MODE_DIR); fi


# TimerDriven_partialImage
ifeq ($(DEBUG_MODE),1)
TimerDriven_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
TimerDriven_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
TimerDriven_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
TimerDriven_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
TimerDriven_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TimerDriven_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
TimerDriven_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
TimerDriven_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
TimerDriven_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
TimerDriven_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
TimerDriven_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TimerDriven_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
TimerDriven_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
TimerDriven_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
TimerDriven_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
TimerDriven_partialImage/$(MODE_DIR)/% : DEFINES = 
TimerDriven_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
TimerDriven_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
TimerDriven_partialImage/$(MODE_DIR)/% : CPU = SIMNT
TimerDriven_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
TimerDriven_partialImage/$(MODE_DIR)/% : TOOL = diab
TimerDriven_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
TimerDriven_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
TimerDriven_partialImage/$(MODE_DIR)/% : LIBPATH = 
TimerDriven_partialImage/$(MODE_DIR)/% : LIBS = 
TimerDriven_partialImage/$(MODE_DIR)/% : OBJ_DIR := TimerDriven_partialImage/$(MODE_DIR)

TimerDriven_partialImage/$(MODE_DIR)/Objects/TimerDriven/timer_driven.o : C:/Users/l4d/Documents/rtschedule/TimerDriven/timer_driven.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_TimerDriven_partialImage = TimerDriven_partialImage/$(MODE_DIR)/Objects/TimerDriven/timer_driven.o

TimerDriven_partialImage/$(MODE_DIR)/TimerDriven_partialImage.o : $(OBJECTS_TimerDriven_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1  -o "$@" $(OBJECTS_TimerDriven_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

TimerDriven_partialImage/$(MODE_DIR)/TimerDriven_partialImage_compile_file : $(FILE) ;

_clean :: TimerDriven_partialImage/$(MODE_DIR)/TimerDriven_partialImage_clean

TimerDriven_partialImage/$(MODE_DIR)/TimerDriven_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "TimerDriven_partialImage" ]; then cd "TimerDriven_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := TimerDriven_partialImage/$(MODE_DIR)/Objects/TimerDriven/timer_driven.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
