# C02
This is my C02 from the 1337 / 42 Piscine.
It contains the solutions I submitted during the Piscine, along with explanations, resources, and tips!

## 📚 Concepts Covered
- String copying (`ft_strcpy`, `ft_strncpy`)
- String classification: alphabetic, lowercase, printable...
- String case manipulation.
- String length–aware copy (`ft_strlcpy`)
- Handling and displaying non-printable characters (`ft_putstr_non_printable`)
- Memory dump formatting (`ft_print_memory`)

## 🔗 Useful Resources

### String Functions & Basics
- [strcpy – man page](https://man7.org/linux/man-pages/man3/strcpy.3.html)
- [strncpy – man page](https://man7.org/linux/man-pages/man3/strncpy.3.html)
- [strlcpy – man page](https://man7.org/linux/man-pages/man3/strlcpy.3.html)

### Character Checks
- [ASCII Table](https://www.asciitable.com/)

### Advanced Output
- [write – man page](https://man7.org/linux/man-pages/man2/write.2.html)
- [Hexadecimal representation in C](https://www.includehelp.com/c/working-with-hexadecimal-values-in-c-programming-language.aspx)

## 💡 Tips
- Always pull up ascii table for string manipulation problems.
- For `ft_strcpy` and `ft_strncpy`, remember to copy the null terminator `'\0'`.
- In `ft_str_is_*` functions, return **1** if the string is empty.
- `ft_strupcase` / `ft_strlowcase` must modify the string *in place* and return the same pointer.
- In `ft_strlcpy`, always return the length of `src` regardless of truncation.
- For `ft_putstr_non_printable`, print non-printable characters as `\xx` (lowercase hex).
- In `ft_print_memory`, carefully match spacing and formatting from the example — the Moulinette will check exact output.
- Test with edge cases: empty strings, strings with only non-printables, maximum/minimum size buffers.
