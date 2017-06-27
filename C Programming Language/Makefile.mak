CC ?= gcc
CFLAGS_common ?= -Wall -std=c99
CFLAGS_orig = -O0
CFLAGS_opt  = -O0

EXEC = Project
all: $(EXEC)

SRCS_common = LED.c
OUTPUT_file = Project

project:
	gcc -std=c99 -o Project ControlMapDemoBoard.c LED.c Socket.c RoutePlanning.c \
		-lpthread -lbcm2835  \


debug-project:
	gcc -std=c99 -g -o Project ControlMapDemoBoard.c LED.c Socket.c RoutePlanning.c \
		-lpthread -lbcm2835  \


perf-cache: $(EXEC)
	perf stat --repeat 100 \
		-e cache-misses,cache-references,instructions,cycles \
		./Project

output.txt: perf-cache calculate
	./calculate

plot: output.txt
	gnuplot scripts/runtime.gp

calculate: calculate.c
	$(CC) $(CFLAGS_common) $^ -o $@

.PHONY: clean
clean:
	$(RM) $(EXEC) *.o perf.* \
	      	calculate orig.txt opt.txt output.txt runtime.png
