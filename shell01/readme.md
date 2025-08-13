# Shell01 – 1337 / 42 Piscine

This repository contains the solutions I submitted for **Shell01** during the Piscine, along with explanations, resources, and tips to help you understand each concept.

---

## 📚 Concepts Covered
- **Environment variables & groups**
  - Displaying user group memberships (`print_groups.sh`)
- **Finding files**
  - Searching recursively for `.sh` files and stripping extensions (`find_sh.sh`)
- **Counting**
  - Counting all files and directories (`count_files.sh`)
- **Networking basics**
  - Displaying machine MAC addresses (`MAC.sh`)
- **Special file names**
  - Creating files with unusual names and exact content
- **Listing & filtering**
  - Showing one line out of two from `ls -l` (`skip.sh`)
- **Text manipulation**
  - Parsing `/etc/passwd` with filters, reversals, sorting, and range selection (`r_dwssap.sh`)
- **Custom base arithmetic**
  - Converting numbers between unusual bases and adding them (`add_chelou.sh`)

---

## 🔗 Useful Resources

**Shell & File Management**  
- [GNU Coreutils Manual](https://www.gnu.org/software/coreutils/manual/)  
- [chmod – man page](https://man7.org/linux/man-pages/man1/chmod.1.html)  

**User & Group Management**  
- [id – man page](https://man7.org/linux/man-pages/man1/id.1.html)  

**Finding & Counting**  
- [find – man page](https://man7.org/linux/man-pages/man1/find.1.html)  
- [wc – man page](https://man7.org/linux/man-pages/man1/wc.1.html)  

**Networking**  
- [ifconfig – man page](https://man7.org/linux/man-pages/man8/ifconfig.8.html)  

**Text Processing**  
- [cat – man page](https://man7.org/linux/man-pages/man1/cat.1.html)  
- [rev – man page](https://man7.org/linux/man-pages/man1/rev.1.html)  
- [tr – man page](https://man7.org/linux/man-pages/man1/tr.1.html)  
- [sort – man page](https://man7.org/linux/man-pages/man1/sort.1.html)  
- [head – man page](https://man7.org/linux/man-pages/man1/head.1.html)  
- [tail – man page](https://man7.org/linux/man-pages/man1/tail.1.html)  

---

## 💡 Tips
- **Precision matters** — filenames, permissions, and output format must match exactly for Moulinette to pass.
- For exercises involving **environment variables** (`FT_USER`, `FT_LINE1`, `FT_LINE2`, `FT_NBR1`, `FT_NBR2`), test with:
  ```sh
  export FT_USER=nours
  ./print_groups.sh
