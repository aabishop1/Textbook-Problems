If you ever ever need to parse a string, instead of iterating through characters, litterally just create an isstream and read the stream into variables since the istream has members that parse spaces by default.
Additionally, remember that formatting flags can be passed to inoput or output streams.
