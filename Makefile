a.out: Game.cc Map.h
	g++ Game.cc -o a.out -lncurses
clean:
	rm -rf a.out
