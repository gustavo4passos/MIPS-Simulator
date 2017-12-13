sim: shell.c sim.c instruction_decoder.c
	gcc -g -O2 $^ -o $@

.PHONY: clean
clean:
	rm -rf *.o *~ sim
