

cpp_srcs := $(shell find src -name *.cpp)
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))


objs/%.o : src/%.cpp
	@mkdir -p $(dir $@)
	@g++ -c $< -o $@

workspace/exec : $(cpp_objs)
	@mkdir -p $(dir $@)
	@g++ $^ -o $@

run : workspace/exec
	@./$<


debug :
	@echo $(cpp_objs)

clean :
	@rm -rf src/*.i src/*.s objs

.PHONY : debug objects
