/* How would you test the word count program? What kinds of input are
   most likely to uncover bugs if there are any? */
/* 1. test with unprintable input, it should not be counted,
   2. test with non-ascii characters, which means unicode or other
   multi-bytes code, it should not be handled like ascii code
   3. test with no blank, no newline or even no character, this is to
   test the bound of output
   4. test with huge characters, which may cause overflow if you
   choose a type which is not big enough */
