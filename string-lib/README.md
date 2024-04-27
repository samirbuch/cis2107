# Hello Professor Ajaj, Nasif, Enguardo!

I've specifically omitted the `*.o` files because they were cluttering up
the workspace. If you would like to regenerate them, feel free to run:

> $ gcc -c **/*.c

Running `gcc -c *.c` will only generate an `.o` for the main file. Running the above
command will glob all the subdirectories.

Then running the standard:
> $ ar rcs libstrutils.a *.o

will produce the expected `libstrutils.a` file.

Running the following command will generate a binary that has the
strutils library linked against it:
$ gcc -o str_tester main.c -L. -lstrutils

Then, naturally, run `./str_tester` and see that the code runs as expected.

-----------------

There are a couple oddities about this lab that I'd like to point out:

1. I reimplemented a bunch of useful `string.h` features that I so dearly missed,
   `strlen` and `strcpy` chiefly among them. You'll see those two functions being used
   in pretty much every single function.
2. I also added a new `strequal` function (in lib/util/) to check if two strings are
   equal. Used in `find` and `ptr_to`.
3. I used CMake as my build system. Running the `gcc -c ...` command *may* produce
   an odd cmake*.o file, depending on if you loaded this project up in a Jetbrains IDE.
   If you did, simply delete the cmake*.o file before bundling the .o files into the
   library using `ar`.
4. You'll see that the `size_t` type is being used throughout this lab. How is that possible
   if I didn't include the string library at all?
   Well, if you check lib/reimpl/reimpl.h, you will find that I've only defined `size_t`
   if it isn't already defined, to prevent it from clashing with any other libraries.
5. `diff` made me want to pull my hair out. Please don't look at it for too long.
   If you're really curious, see this link: 
   https://en.wikipedia.org/wiki/Damerau%E2%80%93Levenshtein_distance#Optimal_string_alignment_distance

addendum: There were many points throughout this lab where I attempted to reimplement
          `strcat`. I was unsuccessful. I'm sure I could have with enough time, but I believe
          it has something to do with the way I handle finding the length of a string by
          checking to see if the final character is a null character. There are some points
          in this lab where doing this is impractical or impossible, particularly in
          `str_connect` or `replace`. Luckily, I was also able to just move the character
          pointers around with little difficulty. If I were to do this again with help 
          from the string.h library, I'm sure these functions would be much, MUCH easier 
          to write.