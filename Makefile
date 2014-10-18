SRC=test.c tiny_mm.c
BIN=test

$(BIN):$(SRC)
	gcc -g $^ -o $@

.PHONY:

clean:
	-rm -rf $(BIN) tags
