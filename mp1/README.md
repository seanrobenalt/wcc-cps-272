[1] A stack can be used to recognize certain types of patterns. Consider the pattern STRING1#STRING2, where neither string contains "#". The STRING2 must be the reverse of STRING1. Write a program that reads strings until the user enters an empty string. The program should indicate whether each string matches the pattern.

Run:
```
Input a string: 1&A#A&1
1&A#A&1 matches the pattern

Input a string: 1&A#1&A
1&A#1&A does not match the pattern

Input a string: madamimadam#madamimadam
madamimadam#madamimadam matches the pattern

Input a string:
```
[2] Write a program that prompts the user to enter a non-negative decimal number and a base in the range 2 <= base <= 16. Write a function multibaseOutput() that displays the number in the specified base. The program terminates when the user enters a number of 0 and a base 0.

Run:
```
Enter a non-negative decimal number and base (2 <= B <= 16) or 0 0 to terminate: 155 16
    155 base 16 is 9B
Enter a non-negative decimal number and base (2 <= B <= 16) or 0 0 to terminate: 3553 8
    3553 base 8 is 6741
Enter a non-negative decimal number and base (2 <= B <= 16) or 0 0 to terminate: 0 0
```
[3] The program prompts for a filename and then reads the file to check for balanced curly braces, {}; parentheses, (); and square brackets, []. The program should ignore any character that is not a parenthesis, curly brace, or square bracket. Note that the proper nesting is required.

Assume File "balance1.txt" has
((a+b))[{{c}}](){([])} * c[i]
(welcome to C++)
{while (i = 5) ;}
[z]
Run 1:
```
Enter the file name: balance1.txt
The symbols in balance1.txt are balanced.

Assume File "balance2.txt" has [a(b]c)
Run 2:
Enter the file name: balance2.txt
The symbols in balance2.txt are not balanced.
```
