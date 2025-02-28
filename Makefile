SRCS := $(wildcard src/*.cpp)
INCS := -I./include

main : $(SRCS)
	g++ $(INCS) $(SRCS) -o main