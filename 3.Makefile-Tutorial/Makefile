

cpp_srcs := $(shell find src -name *.cpp)
# cpp_objs := $(subst src/,objs/,$(cpp_srcs))
# cpp_objs := $(subst .cpp,.o,$(cpp_objs))
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))


include_paths := /datav/shared/100_du/03.08/lean/protobuf-3.11.4/lib \
                 /usr/local/cuda-10.1/lib64 \
				 ./include

# I_flags := $(foreach item,$(include_paths),-I$(item))
I_flags := $(include_paths:%=-I%)



debug :
	@echo $(include_paths)
	@echo $(I_flags)




.PHONY : debug