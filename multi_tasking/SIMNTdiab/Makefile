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
PRJ_ROOT_DIR := C:/Users/l4d/Documents/rtschedule/multi_tasking
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
PROJECT_TARGETS = multi_tasking/$(MODE_DIR)/multi_tasking.out \
	 multi_tasking_partialImage/$(MODE_DIR)/multi_tasking_partialImage.o


#Rules

# multi_tasking
ifeq ($(DEBUG_MODE),1)
multi_tasking/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
multi_tasking/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
multi_tasking/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
multi_tasking/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
multi_tasking/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
multi_tasking/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
multi_tasking/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
multi_tasking/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
multi_tasking/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
multi_tasking/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
multi_tasking/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
multi_tasking/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
multi_tasking/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
multi_tasking/$(MODE_DIR)/% : IDE_LIBRARIES = 
multi_tasking/$(MODE_DIR)/% : PROJECT_TYPE = DKM
multi_tasking/$(MODE_DIR)/% : DEFINES = 
multi_tasking/$(MODE_DIR)/% : EXPAND_DBG = 0
multi_tasking/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
multi_tasking/$(MODE_DIR)/% : CPU = SIMNT
multi_tasking/$(MODE_DIR)/% : TOOL_FAMILY = diab
multi_tasking/$(MODE_DIR)/% : TOOL = diab
multi_tasking/$(MODE_DIR)/% : TOOL_PATH = 
multi_tasking/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
multi_tasking/$(MODE_DIR)/% : LIBPATH = 
multi_tasking/$(MODE_DIR)/% : LIBS = 
multi_tasking/$(MODE_DIR)/% : OBJ_DIR := multi_tasking/$(MODE_DIR)

OBJECTS_multi_tasking = multi_tasking_partialImage/$(MODE_DIR)/multi_tasking_partialImage.o

multi_tasking/$(MODE_DIR)/multi_tasking.out : $(OBJECTS_multi_tasking)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_multi_tasking) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c pentium > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations  $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_multi_tasking) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

multi_tasking/$(MODE_DIR)/multi_tasking_compile_file : $(FILE) ;

_clean :: multi_tasking/$(MODE_DIR)/multi_tasking_clean

multi_tasking/$(MODE_DIR)/multi_tasking_clean : 
	$(TRACE_FLAG)if [ -d "multi_tasking" ]; then cd "multi_tasking"; rm -rf $(MODE_DIR); fi


# multi_tasking_partialImage
ifeq ($(DEBUG_MODE),1)
multi_tasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
multi_tasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
multi_tasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
multi_tasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
multi_tasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
multi_tasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
multi_tasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
multi_tasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
multi_tasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
multi_tasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
multi_tasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
multi_tasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
multi_tasking_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
multi_tasking_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
multi_tasking_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
multi_tasking_partialImage/$(MODE_DIR)/% : DEFINES = 
multi_tasking_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
multi_tasking_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
multi_tasking_partialImage/$(MODE_DIR)/% : CPU = SIMNT
multi_tasking_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
multi_tasking_partialImage/$(MODE_DIR)/% : TOOL = diab
multi_tasking_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
multi_tasking_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
multi_tasking_partialImage/$(MODE_DIR)/% : LIBPATH = 
multi_tasking_partialImage/$(MODE_DIR)/% : LIBS = 
multi_tasking_partialImage/$(MODE_DIR)/% : OBJ_DIR := multi_tasking_partialImage/$(MODE_DIR)

multi_tasking_partialImage/$(MODE_DIR)/Objects/multi_tasking/multi_task.o : C:/Users/l4d/Documents/rtschedule/multi_tasking/multi_task.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_multi_tasking_partialImage = multi_tasking_partialImage/$(MODE_DIR)/Objects/multi_tasking/multi_task.o

multi_tasking_partialImage/$(MODE_DIR)/multi_tasking_partialImage.o : $(OBJECTS_multi_tasking_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1  -o "$@" $(OBJECTS_multi_tasking_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

multi_tasking_partialImage/$(MODE_DIR)/multi_tasking_partialImage_compile_file : $(FILE) ;

_clean :: multi_tasking_partialImage/$(MODE_DIR)/multi_tasking_partialImage_clean

multi_tasking_partialImage/$(MODE_DIR)/multi_tasking_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "multi_tasking_partialImage" ]; then cd "multi_tasking_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := multi_tasking_partialImage/$(MODE_DIR)/Objects/multi_tasking/multi_task.d
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
