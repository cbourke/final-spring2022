

# ECEN 1940
## Final Exam
### Spring 2022

Wordle is a recent popular word game in which players have six attempts
to guess a five-letter word.  Partial feedback is given for each guess
in the form of colored tiles indicating when letters match or occupy
the correct position.  It won't be necessary to understand (or be good)
at the game itself, but you can try it here: https://wordleunlimited.org/

Instead, you will help develop an opening strategy for playing wordle by
processing a dictionary of words and producing a few reports to determine
the best 5 letter words to guess in order to maximize the number of correct
letters in the opening play.

## Files

We have provided several starter files.

* `dictionary.txt` - an (abridged) text file containing thousands of
standard English words, one per line.  All letters are lower case.
* `utils.h` and `utils.c` - a collection of utility functions that you may
find useful.  If you write any of your **own** functions, you should place
the prototypes in this header file (with proper documentation) and the
definitions in the source file.
* `wordle.c` - this contains the `main` function

## Outline

1. First, you will need to process the given dictionary file and, only
considering 5-letter words, read it into memory for processing.  You may
assume that the file is in the same directory as your program.

Hint: you may want to consider storing words in the given `WordleWord`
structure to make generating the reports below easier.  Whether you
choose to use this structure or redevelop your own, or not use a
structure at all is up to you.

The first output you'll report is simply the number of total words
in the given dictionary as well as the total number of 5 letter
words.  Do *not* print out the words (there are too many).
Your output should look something like:

```text
total words:          247406
total 5-letter words:  12236
```

2. Now that you have only 5 letter words, we want to know what the
most common letters are for *each* of the five places.  To do that,
you will procude a report of the *counts* of each letter: the number
of times each letter appears *in that place* for all 5 letter words.

Your output should look like the report below.  For example, `a`
appears as the first letter 838 times, as the second letter 2187
times, etc.  `b` appears as the first letter 822 times, the second
letter only 94 times etc.  Note that you should *store* these
counts (you'll need them later) instead of *just* printing them
out.

Hint: a trick you can use is to use a static integer array (careful
to initialize its values to zeros), `int count[5][26]` and use the
ASCII values of a character as an index, subtracting 97 (lowercase `a`).
For example:

```c
char foo = 'a';
count[0][foo-97] = {0};
```

Your output should look something like the following.

```text
Letter    1     2     3     4     5
a       838  2187  1096  1157  1066
b       822    94   359   215    66
c       846   164   346   463   160
d       617   107   409   406   758
e       366  1571   748  2090  1532
f       493    28   142   171    90
g       549    83   372   365   159
h       449   507   131   216   412
i       228  1236   992  1039   369
j       194    14    59    33     5
k       362    79   226   345   303
l       568   670   818   675   564
m       663   186   506   356   215
n       353   380   928   742   833
o       294  1773   877   791   512
p       761   211   353   307   163
q        74    18    11     3     6
r       568   911  1156   669   769
s      1373   142   545   534  1829
t       755   224   597   718   738
u       199  1064   579   448    94
v       231    62   251   154    15
w       349   141   229    96    66
x        30    59   144    12    91
y       146   284   224   106  1357
z       108    41   138   125    64
```

3. Now that we data on how frequent each letter is in each
position, we need to find the "best" words that will maximize
the likelihood of getting letters correct for our first guess.

To do that, we cannot simply take the most common letter
for each position because Wordle only allows you to guess valid
English words (the most common word would be `sares` which
is not a real word).  Instead, we will "score" each word by
computing the *total* count for each of its letters.

For example, `omaha` (not a word in the dictionary, just an
example) would have a score of

`294 + 186 + 1096 + 216 + 1066 = 2858`

Because `o` appears 294 times as the first letter, `m`
appears 186 times as the second letter, etc.

Compute the score for every 5 letter word and report the **20**
words with the top (highest) scores along with their score.
Hint: you may want to use the `Wordle` structure we provided and
sort by some criteria.

Your report should look something like the following.

```text
sanes (8407)
saree (8338)
bares (8084)
sates (8076)
pares (8023)
soree (7924)
sabes (7838)
lares (7830)
rares (7830)
seree (7722)
manes (7697)
carey (7636)
nares (7615)
soses (7610)
cates (7549)
laree (7533)
fanes (7527)
bates (7525)
samey (7513)
vares (7493)
```
