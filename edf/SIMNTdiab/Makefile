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
PRJ_ROOT_DIR := C:/Users/l4d/Documents/rtschedule/edf
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
PROJECT_TARGETS = edf/$(MODE_DIR)/edf.out \
	 edf_partialImage/$(MODE_DIR)/edf_partialImage.o


#Rules

# edf
ifeq ($(DEBUG_MODE),1)
edf/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
edf/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
edf/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
edf/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
edf/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
edf/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
edf/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
edf/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
edf/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
edf/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
edf/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
edf/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
edf/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
edf/$(MODE_DIR)/% : IDE_LIBRARIES = 
edf/$(MODE_DIR)/% : PROJECT_TYPE = DKM
edf/$(MODE_DIR)/% : DEFINES = 
edf/$(MODE_DIR)/% : EXPAND_DBG = 0
edf/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
edf/$(MODE_DIR)/% : CPU = SIMNT
edf/$(MODE_DIR)/% : TOOL_FAMILY = diab
edf/$(MODE_DIR)/% : TOOL = diab
edf/$(MODE_DIR)/% : TOOL_PATH = 
edf/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
edf/$(MODE_DIR)/% : LIBPATH = 
edf/$(MODE_DIR)/% : LIBS = 
edf/$(MODE_DIR)/% : OBJ_DIR := edf/$(MODE_DIR)

OBJECTS_edf = edf_partialImage/$(MODE_DIR)/edf_partialImage.o

edf/$(MODE_DIR)/edf.out : $(OBJECTS_edf)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_edf) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c pentium > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations  $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_edf) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

edf/$(MODE_DIR)/edf_compile_file : $(FILE) ;

_clean :: edf/$(MODE_DIR)/edf_clean

edf/$(MODE_DIR)/edf_clean : 
	$(TRACE_FLAG)if [ -d "edf" ]; then cd "edf"; rm -rf $(MODE_DIR); fi


# edf_partialImage
ifeq ($(DEBUG_MODE),1)
edf_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
edf_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
edf_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
edf_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
edf_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
edf_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
edf_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
edf_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
edf_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
edf_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
edf_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
edf_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
edf_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
edf_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
edf_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
edf_partialImage/$(MODE_DIR)/% : DEFINES = 
edf_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
edf_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
edf_partialImage/$(MODE_DIR)/% : CPU = SIMNT
edf_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
edf_partialImage/$(MODE_DIR)/% : TOOL = diab
edf_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
edf_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
edf_partialImage/$(MODE_DIR)/% : LIBPATH = 
edf_partialImage/$(MODE_DIR)/% : LIBS = 
edf_partialImage/$(MODE_DIR)/% : OBJ_DIR := edf_partialImage/$(MODE_DIR)

edf_partialImage/$(MODE_DIR)/Objects/edf/edf.o : C:/Users/l4d/Documents/rtschedule/edf/edf.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_edf_partialImage = edf_partialImage/$(MODE_DIR)/Objects/edf/edf.o

edf_partialImage/$(MODE_DIR)/edf_partialImage.o : $(OBJECTS_edf_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1  -o "$@" $(OBJECTS_edf_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

edf_partialImage/$(MODE_DIR)/edf_partialImage_compile_file : $(FILE) ;

_clean :: edf_partialImage/$(MODE_DIR)/edf_partialImage_clean

edf_partialImage/$(MODE_DIR)/edf_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "edf_partialImage" ]; then cd "edf_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := edf_partialImage/$(MODE_DIR)/Objects/edf/edf.d
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
