SRCS = simpleloop.c matmul.c blocked.c sumprime.c
PROGS = simpleloop matmul blocked sumprime

all : $(PROGS)

$(PROGS) : % : %.c
	gcc -Wall -g -o $@ $<


traces: $(PROGS)
	./runit simpleloop
	./runit matmul 100
	./runit blocked 100 25
	./runit sumprime

.PHONY: clean
clean : 
	rm -f simpleloop matmul blocked sumprime tr-*.ref *.marker *~
