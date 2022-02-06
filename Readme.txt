
2.	This problem is a variation on the theme of scrabble. You are given two files:

    * A dictionary that contains one word per line. (You can download
this test dictionary.)
    * A "value file" that specifies the values of letters and—here's
the catch—arbitrary strings. Each line of this file contains a letter
or string, some whitespace, and the corresponding point value. For
example:

      a 1
      q 9
      aa 57
      qu 12
      …

The value file need not list all letters of the alphabet. Letters that
are not listed are defined to have value 0. A word's point value is
the sum of the point values of matching strings in the value file. To
find the word's matching strings, we scan the word from left to right
and identify the longest string that matches the as-yet unmatched part
of the word. For example, given the following value file:

a 1
c 1
e 1
h 1
k 1
r 1
ha 5
ck 5
er 5
hac 15

the value of the word "hacker" is 15 ("hac") + 1 ("k") + 5 ("er") =
21. Similarly, given the value file:

ck 5
ker 15

the value of the word "hacker" is 0 ("h", "a") + 5 ("ck") + 0 ("e",
"r") = 5. Note that the high-value string "ker" does not match because
the "k" in "hacker" has already been matched by "ck" in the
left-to-right scan.

Write a program that takes the names of a dictionary and a value file
on the command line, and prints the highest-value word(s) and their
values, one per line, like this:

ck 5
ker 15


You can use any programming language, but avoid using any in-build data structure that language might provide.  Try to implement your own data structure for this problem.   Provide your own analysis of pros and cons of the data structure you use, time complexity, etc.

