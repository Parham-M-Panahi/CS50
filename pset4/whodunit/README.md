# Questions

## What's `stdint.h`?

header file for different integer types

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

create variables if different size

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1, 4, 4, 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

0x4d42

## What's the difference between `bfSize` and `biSize`?

bfSize : size of file header (14 in case of 24bit-BMP)
biSzie : size of info header (40 in case of 24bit-BMP)

## What does it mean if `biHeight` is negative?

bitmap is top-down and its origin is top left corner

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

file doesn't exist, OS denies permisson

## Why is the third argument to `fread` always `1` in our code?

read that amount of bytes "ONCE"

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

(4 - (bi.biWidth * (sizeof(RGBTRIPLE)) % 4) % 4 = (4 - (3 * 3) % 4) % 4 = (4 - (9 % 4) % 4 = (4 - 1) % 4 = 3 % 4 = 3

## What does `fseek` do?

move the file cursor

## What is `SEEK_CUR`?

current position of file cursor

