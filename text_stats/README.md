# Text Stats Tool (C) — README / Project Brief

A small C command-line program that reads a text file and prints basic statistics:
- **lines**
- **words**
- **chars** (bytes)

This project is designed to practice **file I/O**, **stream processing**, and **simple parsing state** in C.

---

## What you will build

A program called `textstats` that you run like this:

```bash
textstats <path-to-file>
```

It will output something like:
```bash
lines: 12
words: 234
chars: 1409
```

## Requirements

1. Input
* The program must accept one command-line argument: the file path.
* If no file path is provided:
    * print a usage message
    * exit with a non-zero status code

Example usage message:
```bash
Usage: textstats <path-to-file>
```

2. File Open error handling
* If the file cannot be opened:
    * print a helpful error message
    * exit with a non-zero status code

Example:
```bash
Error: could not open file: example.txt
```

## Output format

Print counts in a simple, readable format (one per line)

Example:
```
lines: 12
words: 234
chars: 1409
```

## Definitions
### Characters (chars)

* Count **every byte** read from the file
* Newlines ('\n') count as characters

Examples:
* "" -> chars = 0 
* "a" -> chars =  1
* "a\n" -> chars = 2

## Lines (lines)

* Count newline characters ('\n')
* **Also count the final line if the file does not end with a newline**

Examples:
* "" -> lines = 0
* "hello" -> lines = 1
* "hello\n" -> lines = 1 
* "a\nb\n" -> lines = 2
* "a\nb" -> lines = 2

## Words (words)

* A word is a **sequence of non-whitespace characters** separated by whitespace.
* Whitespace includes spaces, tabs, newlines, etc.

Examples:
* "hello world" -> words = 2
* "  hello   world   " -> words = 2
* "a\nb\tc" -> words = 3
* "" -> words = 0

## Constraints/Rules

* Do **not** load the entire file into memory
* Process the file as a **stream**:
    * Character-by-character (fgetc), OR
    * line-by-line (fgets)
* Keep scope simple: ASCII input is fine (ignore unicode complexities)

## Suggested build strategy (recommended order)

Implement in small steps so you don’t get stuck:

1. **Open the file** successfully.
2. Count chars **only**.
3. Add **line counting**.
4. Add **word counting** using a tiny state variable, e.g.:
    * “am I currently inside a word?”
5. Add clean CLI usage + error messages.


## Acceptance criteria (Definition of Done)

Your program is done when:

* textstats <file> prints correct lines, words, chars
* Handles:
    * empty file
    * file with no trailing newline
    * multiple spaces/tabs/newlines between words
* Gives useful errors for:
    * missing CLI arg
    * file not found / cannot open

## Example test files + expected outputs

Create these files and verify your program.

### Test 1: Empty file

**File contents:**
```bash
<empty>
```

**Expected:**
```bash
lines: 0
words: 0
chars: 0
```

### Test 2: Single word, no newline

**File contents:**
```bash
hello
```

**Expected:**
```bash
lines: 1
words: 1
chars: 5
```

### Test 3: Single word with trailing newline

**File contents:**
```bash
hello
```
(with a trailing newline)

**Expected:**
```bash
lines: 1
words: 1
chars: 6
```

### Test 4: Mixed whitespace

**File contents:**
```bash
a  b
c  d
```
(That second line contains a TAB between c and d.)

**Expected:**

* chars:
    * line1: "a  b\n" = 4
    * line2: "c\t d\n" depends on whether you include a space;
    use exactly:
        * c<TAB>d\n -> 4 chars total on the second line
* lines: 2
* words: 4 (a, b, c, d)

So if the file is exactly:
```bash
a  b\n
c<TAB>d\n
```

**Expected:**

```bash
lines: 2
words: 4
chars: 8
```

(If you add any extra spaces, your char count should change accordingly.)

## Suggested prohect layout

```bash
textstats/
  README.md
  textstats.c
  (optional) Makefile
```

## Optional stretch goals (pick 1-2 only)

* Support reading from **stdin** if no filename is provided (like Unix wc)
* Add flags:
    * -l lines only
    * -w words only
    * -c chars only
* Print output similar to Unix wc:
    * lines words chars filename
* Add a minimal test script that runs your program against the test files and checks output


## Notes

This project is intentially small. The real learning wins are:
* Correct file handling + error checking
* counting via streaming (no full file in memory)
* correct word counting with a simple "in_word" state
* handling the "no trailing newline" line-count edge case
