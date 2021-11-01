test_header_parser : test_header_parser.o
	gcc -Werror -o test_header_parser test_header_parser.o \
	../src/header_parser.c
test_header_parser.o : test_header_parser.c
	gcc -Werror -c test_header_parser.c
.PHONY clean:
clean:
	rm test_header_parser.o test_header_parser
