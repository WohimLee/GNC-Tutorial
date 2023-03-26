

cpp_srcs := $(shell find src -name *.cpp)
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))


include_paths := /Users/azen/Desktop/myAir/Work/Workspace/Education/2.C++/GNC-Tutorial/Test/include \
				 

I_flags := $(include_paths:%=-I%)

compile_options := -g -O3 -w $(I_flags)


objs/%.o : src/%.cpp
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ $(compile_options)

workspace/exec : $(cpp_objs)
	@mkdir -p $(dir $@)
	@g++ $^ -o $@

run : workspace/exec
	@./$<

debug :
	@echo $(compile_options)


clean :
	@rm -rf objs workspace/exec

.PHOHY : run debug