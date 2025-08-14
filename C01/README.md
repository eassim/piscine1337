# C01
This is my C01 from the 1337 / 42 Piscine.
It contains the solutions I submitted during the Piscine, along with explanations, resources and tips!

## 📚 Concepts Covered
- Pointers and pointer manipulation
- Passing and returning results via function parameters
- String output with `write`
- Counting string length manually
- Reversing arrays in place
- Sorting arrays in ascending order

## 🔗 Useful Resources

### Pointers & Memory
- [Pointers in C – GeeksforGeeks](https://www.geeksforgeeks.org/c-pointers/)

### Functions & Parameters
- [C Functions – Programiz](https://www.programiz.com/c-programming/c-functions)

### Strings & Arrays
- [`write` manual page](https://man7.org/linux/man-pages/man2/write.2.html)
- [Array reversal in C](https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/)
- [Sorting in C](https://www.geeksforgeeks.org/c/c-program-to-sort-an-array-in-ascending-order/)

## 💡 Tips
- Understand how pointers work before diving into multi-level pointer exercises — draw diagrams if necessary.
- For `ft_swap`, remember you are swapping *values*, not addresses.
- When implementing `ft_div_mod` and `ft_ultimate_div_mod`, watch out for division by zero.
- In `ft_putstr`, loop until you reach the null terminator `'\0'`.
- For `ft_strlen`, don’t count the null terminator.
- In `ft_rev_int_tab` and `ft_sort_int_tab`, test with arrays of size 0, 1, and already sorted arrays to catch edge cases.
