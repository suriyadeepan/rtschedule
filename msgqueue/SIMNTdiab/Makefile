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
PRJ_ROOT_DIR := C:/Users/l4d/Documents/rtschedule/msgqueue
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
PROJECT_TARGETS = msgqueue/$(MODE_DIR)/msgqueue.out \
	 msgqueue_partialImage/$(MODE_DIR)/msgqueue_partialImage.o


#Rules

# msgqueue
ifeq ($(DEBUG_MODE),1)
msgqueue/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
msgqueue/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
msgqueue/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
msgqueue/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
msgqueue/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
msgqueue/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
msgqueue/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
msgqueue/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
msgqueue/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
msgqueue/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
msgqueue/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
msgqueue/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
msgqueue/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
msgqueue/$(MODE_DIR)/% : IDE_LIBRARIES = 
msgqueue/$(MODE_DIR)/% : PROJECT_TYPE = DKM
msgqueue/$(MODE_DIR)/% : DEFINES = 
msgqueue/$(MODE_DIR)/% : EXPAND_DBG = 0
msgqueue/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
msgqueue/$(MODE_DIR)/% : CPU = SIMNT
msgqueue/$(MODE_DIR)/% : TOOL_FAMILY = diab
msgqueue/$(MODE_DIR)/% : TOOL = diab
msgqueue/$(MODE_DIR)/% : TOOL_PATH = 
msgqueue/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
msgqueue/$(MODE_DIR)/% : LIBPATH = 
msgqueue/$(MODE_DIR)/% : LIBS = 
msgqueue/$(MODE_DIR)/% : OBJ_DIR := msgqueue/$(MODE_DIR)

OBJECTS_msgqueue = msgqueue_partialImage/$(MODE_DIR)/msgqueue_partialImage.o

msgqueue/$(MODE_DIR)/msgqueue.out : $(OBJECTS_msgqueue)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_msgqueue) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c pentium > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations  $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_msgqueue) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

msgqueue/$(MODE_DIR)/msgqueue_compile_file : $(FILE) ;

_clean :: msgqueue/$(MODE_DIR)/msgqueue_clean

msgqueue/$(MODE_DIR)/msgqueue_clean : 
	$(TRACE_FLAG)if [ -d "msgqueue" ]; then cd "msgqueue"; rm -rf $(MODE_DIR); fi


# msgqueue_partialImage
ifeq ($(DEBUG_MODE),1)
msgqueue_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
msgqueue_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
msgqueue_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
msgqueue_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
msgqueue_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
msgqueue_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
msgqueue_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
msgqueue_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
msgqueue_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
msgqueue_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
msgqueue_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
msgqueue_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
msgqueue_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
msgqueue_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
msgqueue_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
msgqueue_partialImage/$(MODE_DIR)/% : DEFINES = 
msgqueue_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
msgqueue_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
msgqueue_partialImage/$(MODE_DIR)/% : CPU = SIMNT
msgqueue_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
msgqueue_partialImage/$(MODE_DIR)/% : TOOL = diab
msgqueue_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
msgqueue_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
msgqueue_partialImage/$(MODE_DIR)/% : LIBPATH = 
msgqueue_partialImage/$(MODE_DIR)/% : LIBS = 
msgqueue_partialImage/$(MODE_DIR)/% : OBJ_DIR := msgqueue_partialImage/$(MODE_DIR)

msgqueue_partialImage/$(MODE_DIR)/Objects/msgqueue/msgq.o : C:/Users/l4d/Documents/rtschedule/msgqueue/msgq.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_msgqueue_partialImage = msgqueue_partialImage/$(MODE_DIR)/Objects/msgqueue/msgq.o

msgqueue_partialImage/$(MODE_DIR)/msgqueue_partialImage.o : $(OBJECTS_msgqueue_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1  -o "$@" $(OBJECTS_msgqueue_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

msgqueue_partialImage/$(MODE_DIR)/msgqueue_partialImage_compile_file : $(FILE) ;

_clean :: msgqueue_partialImage/$(MODE_DIR)/msgqueue_partialImage_clean

msgqueue_partialImage/$(MODE_DIR)/msgqueue_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "msgqueue_partialImage" ]; then cd "msgqueue_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := msgqueue_partialImage/$(MODE_DIR)/Objects/msgqueue/msgq.d
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
