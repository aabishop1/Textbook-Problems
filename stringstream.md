If you ever ever need to parse a string, instead of iterating through characters, litterally just create an isstream and read the stream into variables since the istream has members that parse spaces by default.
Additionally, remember that formatting flags can be passed to inoput or output streams.


Additionally, lets talk about argv**

it is a pointer to pointers of c-style strings.
c-style strings are a pointer to a char sequence which ends in a literal 0

so the value of argv if directly printed would be a pointer to another register, which contains all of the pointers to the c-style strings
if we used & to get the address/pointer of argv it would print the literal location of argv instead of its value.

when we pass argv[0] it goes to the register dictated by argv and goes to the 0th value, which is a pointer to a c style string
if we did &argv[0] it would be the address of the 0th c style string.
