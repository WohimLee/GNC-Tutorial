

MAIN := src/main.cpp
cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))

so_objs := $(filter-out objs/main.o,$(cpp_objs))

include_dir := /Users/azen/Desktop/myAir/Work/Workspace/Tutorials/2.C++/GNC-Tutorial/Test/include


so_libs := ddd
so_dirs := /Users/azen/Desktop/myAir/Work/Workspace/Tutorials/2.C++/GNC-Tutorial/Test/lib

I_options := $(include_dir:%=-I%)
l_options := $(so_libs:%=-l%)
L_options := $(so_dirs:%=-L%)
r_options := $(so_dirs:%=-Wl,-rpath=%)

compile_options := -O3 -w -g $(I_options)
linking_options := $(l_options) $(L_options) $(r_options)

objs/%.o : src/%.cpp
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ $(compile_options)

compile : $(cpp_objs)



lib/libddd.so : $(so_objs)
	@mkdir -p $(dir $@)
	@g++ -shared $^ -o $@

dynamic : lib/libddd.so



workspace/exec : objs/main.o compile dynamic
	@mkdir -p $(dir $@)
	@g++ $< -o $@ $(linking_options)



run : workspace/exec
	@./$<


debug :
	@echo $(cpp_objs)



clean :
	@rm -rf workspace/exec objs lib

.PHONY : debug dynamic clean compile