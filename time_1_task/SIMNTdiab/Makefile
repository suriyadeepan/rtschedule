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
PRJ_ROOT_DIR := C:/Users/l4d/Documents/rtschedule/time_1_task
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
PROJECT_TARGETS = time_1_task/$(MODE_DIR)/time_1_task.out \
	 time_1_task_partialImage/$(MODE_DIR)/time_1_task_partialImage.o


#Rules

# time_1_task
ifeq ($(DEBUG_MODE),1)
time_1_task/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
time_1_task/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
time_1_task/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
time_1_task/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
time_1_task/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
time_1_task/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
time_1_task/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
time_1_task/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
time_1_task/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
time_1_task/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
time_1_task/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
time_1_task/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
time_1_task/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
time_1_task/$(MODE_DIR)/% : IDE_LIBRARIES = 
time_1_task/$(MODE_DIR)/% : PROJECT_TYPE = DKM
time_1_task/$(MODE_DIR)/% : DEFINES = 
time_1_task/$(MODE_DIR)/% : EXPAND_DBG = 0
time_1_task/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
time_1_task/$(MODE_DIR)/% : CPU = SIMNT
time_1_task/$(MODE_DIR)/% : TOOL_FAMILY = diab
time_1_task/$(MODE_DIR)/% : TOOL = diab
time_1_task/$(MODE_DIR)/% : TOOL_PATH = 
time_1_task/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
time_1_task/$(MODE_DIR)/% : LIBPATH = 
time_1_task/$(MODE_DIR)/% : LIBS = 
time_1_task/$(MODE_DIR)/% : OBJ_DIR := time_1_task/$(MODE_DIR)

OBJECTS_time_1_task = time_1_task_partialImage/$(MODE_DIR)/time_1_task_partialImage.o

time_1_task/$(MODE_DIR)/time_1_task.out : $(OBJECTS_time_1_task)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_time_1_task) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c pentium > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations  $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_time_1_task) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

time_1_task/$(MODE_DIR)/time_1_task_compile_file : $(FILE) ;

_clean :: time_1_task/$(MODE_DIR)/time_1_task_clean

time_1_task/$(MODE_DIR)/time_1_task_clean : 
	$(TRACE_FLAG)if [ -d "time_1_task" ]; then cd "time_1_task"; rm -rf $(MODE_DIR); fi


# time_1_task_partialImage
ifeq ($(DEBUG_MODE),1)
time_1_task_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
time_1_task_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
time_1_task_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
time_1_task_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
time_1_task_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
time_1_task_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
time_1_task_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
time_1_task_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
time_1_task_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
time_1_task_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
time_1_task_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
time_1_task_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
time_1_task_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
time_1_task_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
time_1_task_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
time_1_task_partialImage/$(MODE_DIR)/% : DEFINES = 
time_1_task_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
time_1_task_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
time_1_task_partialImage/$(MODE_DIR)/% : CPU = SIMNT
time_1_task_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
time_1_task_partialImage/$(MODE_DIR)/% : TOOL = diab
time_1_task_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
time_1_task_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
time_1_task_partialImage/$(MODE_DIR)/% : LIBPATH = 
time_1_task_partialImage/$(MODE_DIR)/% : LIBS = 
time_1_task_partialImage/$(MODE_DIR)/% : OBJ_DIR := time_1_task_partialImage/$(MODE_DIR)

time_1_task_partialImage/$(MODE_DIR)/Objects/time_1_task/main.o : C:/Users/l4d/Documents/rtschedule/time_1_task/main.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_time_1_task_partialImage = time_1_task_partialImage/$(MODE_DIR)/Objects/time_1_task/main.o

time_1_task_partialImage/$(MODE_DIR)/time_1_task_partialImage.o : $(OBJECTS_time_1_task_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1  -o "$@" $(OBJECTS_time_1_task_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

time_1_task_partialImage/$(MODE_DIR)/time_1_task_partialImage_compile_file : $(FILE) ;

_clean :: time_1_task_partialImage/$(MODE_DIR)/time_1_task_partialImage_clean

time_1_task_partialImage/$(MODE_DIR)/time_1_task_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "time_1_task_partialImage" ]; then cd "time_1_task_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := time_1_task_partialImage/$(MODE_DIR)/Objects/time_1_task/main.d
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
