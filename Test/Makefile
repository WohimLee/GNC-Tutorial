

cpp_srcs := $(shell find src -name *.cpp)
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))
lib_srcs := $(filter-out src/main.cpp,$(cpp_srcs))
lib_objs := $(filter-out objs/main.o,$(cpp_objs))


include_paths := /Users/azen/Desktop/myAir/Work/Workspace/Education/2.C++/GNC-Tutorial/Test/include
library_paths := /Users/azen/Desktop/myAir/Work/Workspace/Education/2.C++/GNC-Tutorial/Test/lib
linking_libs  := xxx

I_options := $(include_paths:%=-I%)
L_options := $(library_paths:%=-L%)
l_options := $(linking_libs:%=-l%)

compile_flags := -g -O3 -std=c++11 $(I_options)

objs/%.o : src/%.cpp
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ $(compile_flags)

lib/libxxx.a : $(lib_objs)
	@mkdir -p $(dir $@)
	@ar -r $@ $^

static_lib : lib/libxxx.a


objs/main.o : 

workspace/exec : objs/main.cpp
	@mkdir -p $(dir $@)
	@g++ $< -o $@ 

run : workspace/exec
	@./$<

debug :
	@echo $(cpp_srcs)
	@echo $(lib_objs)

clean :
	@rm -rf lib objs workspace/exec

.PHONY : debug static_lib clean