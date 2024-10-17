all: tokenizer

tokenizer.o: tokenizer.c tokenizer.h
	cc -c tokenizer.c

history.o: history.c history.h tokenizer.h
	cc -c history.c

uimain.o: uimain.c tokenizer.h history.h
	cc -c uimain.c

tokenizer: uimain.o tokenizer.o history.o
	cc -o tokenizer uimain.o tokenizer.c history.o

run:
	./tokenizer

clean:
	rm -f *.o tokenizer
