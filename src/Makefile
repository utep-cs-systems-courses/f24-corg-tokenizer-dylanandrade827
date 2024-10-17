CFLAGS=-g -O3

all: src

tokenizer.o: tokenizer.h
history.o: history.h

src: tokenizer.o history.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o src
