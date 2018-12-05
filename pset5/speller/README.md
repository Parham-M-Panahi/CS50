# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

example of largest possible word in text

## According to its man page, what does `getrusage` do?

returns the statistics of resources used during a call

## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

takes less time and memory to copy the structs

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

after loading the dict into memory and opening file, read each character at a time until EOF, decide whether the character is part of a word or is to be ignored, when get
to the end of a word, spell check the word and time it.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

you can't check to see wether the word is alphabetical or is there a digit in there.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

they are to be read and not to be modified
