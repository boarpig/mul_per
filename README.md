# Calculating multiplicative persistence

This is just for fun exploration based on [Numberphile video](https://www.youtube.com/watch?v=Wim9WJeDTHQ). In the end there is not much to do since 11 steps is all you're going to get ever on current home computers. This code is just code analogy of doodles on a notebook

## Some theory.

Following is a direct quote from Wikipedia:

For a radix of 10, there is thought to be no number with a multiplicative persistence > 11: this is known to be true for numbers up to 10^20000.

The smallest numbers with persistence 0, 1, ... are:

    0, 10, 25, 39, 77, 679, 6788, 68889, 2677889, 26888999, 3778888999, 277777788888899. 
    (sequence A003001 in the OEIS)
    
The search for these numbers can be sped up by using additional properties of the decimal digits of these record-breaking numbers. These digits must be sorted, and, except for the first two digits, all digits must be 7, 8, or 9.
