sim: shell.c sim.c instruction_decoder.c instructions.c
	gcc -g -O2 $^ -o $@

.PHONY: clean
clean:
	rm -rf *.o *~ sim
