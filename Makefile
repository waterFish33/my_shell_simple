my_shell:my_shell.c
	gcc -o $@ $^
.PHONY:clean
clean:
	rm -rf my_shell
