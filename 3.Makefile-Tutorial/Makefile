
cpp_srcs := $(shell find src -name *.cpp)
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))


objs/%.o : src/%.cpp
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@

workspace/exec : $(cpp_objs)
	@mkdir workspace/exec
	@g++ $^ -o $@

run : workspace
	@./$<

clean :
	@rm -rf objs workspace/exec

debug :
	@echo $(as_files)

.PHONY : debug run clean

