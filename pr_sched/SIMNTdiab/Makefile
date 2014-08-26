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
PRJ_ROOT_DIR := C:/Users/l4d/Documents/rtschedule/pr_sched
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
PROJECT_TARGETS = pr_sched/$(MODE_DIR)/pr_sched.out \
	 pr_sched_partialImage/$(MODE_DIR)/pr_sched_partialImage.o


#Rules

# pr_sched
ifeq ($(DEBUG_MODE),1)
pr_sched/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
pr_sched/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
pr_sched/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
pr_sched/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
pr_sched/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
pr_sched/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
pr_sched/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
pr_sched/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
pr_sched/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
pr_sched/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
pr_sched/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
pr_sched/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
pr_sched/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
pr_sched/$(MODE_DIR)/% : IDE_LIBRARIES = 
pr_sched/$(MODE_DIR)/% : PROJECT_TYPE = DKM
pr_sched/$(MODE_DIR)/% : DEFINES = 
pr_sched/$(MODE_DIR)/% : EXPAND_DBG = 0
pr_sched/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
pr_sched/$(MODE_DIR)/% : CPU = SIMNT
pr_sched/$(MODE_DIR)/% : TOOL_FAMILY = diab
pr_sched/$(MODE_DIR)/% : TOOL = diab
pr_sched/$(MODE_DIR)/% : TOOL_PATH = 
pr_sched/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
pr_sched/$(MODE_DIR)/% : LIBPATH = 
pr_sched/$(MODE_DIR)/% : LIBS = 
pr_sched/$(MODE_DIR)/% : OBJ_DIR := pr_sched/$(MODE_DIR)

OBJECTS_pr_sched = pr_sched_partialImage/$(MODE_DIR)/pr_sched_partialImage.o

pr_sched/$(MODE_DIR)/pr_sched.out : $(OBJECTS_pr_sched)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_pr_sched) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c pentium > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations  $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_pr_sched) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

pr_sched/$(MODE_DIR)/pr_sched_compile_file : $(FILE) ;

_clean :: pr_sched/$(MODE_DIR)/pr_sched_clean

pr_sched/$(MODE_DIR)/pr_sched_clean : 
	$(TRACE_FLAG)if [ -d "pr_sched" ]; then cd "pr_sched"; rm -rf $(MODE_DIR); fi


# pr_sched_partialImage
ifeq ($(DEBUG_MODE),1)
pr_sched_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
pr_sched_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
pr_sched_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
pr_sched_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
pr_sched_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
pr_sched_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
pr_sched_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
pr_sched_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
pr_sched_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
pr_sched_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
pr_sched_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
pr_sched_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
pr_sched_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
pr_sched_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
pr_sched_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
pr_sched_partialImage/$(MODE_DIR)/% : DEFINES = 
pr_sched_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
pr_sched_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
pr_sched_partialImage/$(MODE_DIR)/% : CPU = SIMNT
pr_sched_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
pr_sched_partialImage/$(MODE_DIR)/% : TOOL = diab
pr_sched_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
pr_sched_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
pr_sched_partialImage/$(MODE_DIR)/% : LIBPATH = 
pr_sched_partialImage/$(MODE_DIR)/% : LIBS = 
pr_sched_partialImage/$(MODE_DIR)/% : OBJ_DIR := pr_sched_partialImage/$(MODE_DIR)

pr_sched_partialImage/$(MODE_DIR)/Objects/pr_sched/pr_sched.o : C:/Users/l4d/Documents/rtschedule/pr_sched/pr_sched.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_pr_sched_partialImage = pr_sched_partialImage/$(MODE_DIR)/Objects/pr_sched/pr_sched.o

pr_sched_partialImage/$(MODE_DIR)/pr_sched_partialImage.o : $(OBJECTS_pr_sched_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1  -o "$@" $(OBJECTS_pr_sched_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

pr_sched_partialImage/$(MODE_DIR)/pr_sched_partialImage_compile_file : $(FILE) ;

_clean :: pr_sched_partialImage/$(MODE_DIR)/pr_sched_partialImage_clean

pr_sched_partialImage/$(MODE_DIR)/pr_sched_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "pr_sched_partialImage" ]; then cd "pr_sched_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := pr_sched_partialImage/$(MODE_DIR)/Objects/pr_sched/pr_sched.d
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
