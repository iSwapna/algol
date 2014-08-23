WHATAMI?
-------

A DYNAMIC ALGORITHM TO COMPUTE THE POWER SET.

Power set:
----------
Power set is all possible 0 to n combinations of characters in a sequence.

eg: seq = "abcd"
    power set = {"","a","b","c","d","ab","ac","ad","bc","bd","cd","abc","abd","acd","bcd","abcd"} 
    There are 2^n combinations in the power set of an n length sequence. 	

Big-oh efficiency:
------------------
Compare time efficiency with Brute Force method with bitset.

Two algorithms to solve the power set compute problem. 
1. Brute force (BF) uses big-oh = O(n*(2^n)) time complexity.

	For n = 20, big-oh = 20971520 = ~.2G
	For n = 24, big-oh = 402653184 = ~4G
	For n = 26, big-oh = 1744830464= ~17G
	For n = 30, big-oh = 32212254720 = ~32G
 
2. Dynamic version (DY) has good savings in time, since we use lookup for already created sub sequences. 
     
	Each iteration looks up it's previous binomial coefficient number of sub sequences calcluated in the last iteration. It generates a binomial coefficient number of sequences. The maximum number of lookups is for the middle+1 th iteration. This looks up n!/( (n/2)!*(n/2)! ). Stringler's approx ofr this is 4^k/ sqrt(pi*k). Calling this bcMax and taking this as the upper limit for all iterations, big-oh is upper bounded by n*bcMax. 

        For n = 20, big-oh = 1183363 = ~.1G
	For n = 24, big-oh = 18933799 = ~4G
	For n = 26, big-oh = 75735200= ~7G
	For n = 30, big-oh = 1211763200= ~12G


TBD:
----

1. Use more efficient DS in stack memory. Vector is allocated on the heap and slow with resize on every pass of the n calls. 

2. Complexity measurement is currently emperical and varies with every run. Find out how to constraint and gaurantee available memory for the process. How to factor out I/O time. 

3. Write Map Reduce for parallel compute


OUTPUT: 
------

$ ./a.out

Usage: ./a.out [print | BF | DY | all | BF26 <sequence> | DY26 <sequence> ]

 [ print: canned test: Brute Force- print to console]
 [ BF: canned test: Brute Force- save to file]
 [ DY: canned test: Dynamic- save to file]
 [ all:  run 1, 2, 3]
 [ DY26: Dynamic on user provided sequence ]
 [ BF26: Brute Force on user provided sequence ]

$ ./a.out print

Test 1. Brute Force Method 

SEQ: a
len: 1 numOfVariants: 2
variant: 0 : 
variant: 1 : a

SEQ: ab
len: 2 numOfVariants: 4
variant: 0 : 
variant: 1 : a
variant: 2 : b
variant: 3 : ab

SEQ: abc
len: 3 numOfVariants: 8
variant: 0 : 
variant: 1 : a
variant: 2 : b
variant: 3 : ab
variant: 4 : c
variant: 5 : ac
variant: 6 : bc
variant: 7 : abc ........
.......................
......


$ ./a.out BF  ==> saves power set to file BF.txt (~500MB)

Test 2. Brute Force Method 
Result in file: BF.txt

 N: 6 Parent Seq: abdwde
 RUN TIME: 0.325 ms

 N: 7 Parent Seq: abcdefg
 RUN TIME: 0.682 ms

 N: 8 Parent Seq: abcdefgi
 RUN TIME: 1.439 ms

 N: 9 Parent Seq: 123456789
 RUN TIME: 1.886 ms

 N: 10 Parent Seq: 0123456789
 RUN TIME: 3.573 ms

 N: 20 Parent Seq: abcdefghijklmnopqrst
 RUN TIME: 3833.85 ms

 N: 22 Parent Seq: 12abcdefghijklmnopqrst
 RUN TIME: 15579 ms

 N: 24 Parent Seq: 1234abcdefghijklmnopqrst
 RUN TIME: 62902.4 ms

$ ./a.out DY  ==> saves power set to file DY.txt (~500MB)

Test 3. Dynamic Method 
Result in file: DY.txt

 N: 6 Parent Seq: abdwde
 RUN TIME: 0.288 ms

 N: 7 Parent Seq: abcdefg
 RUN TIME: 0.695 ms

 N: 8 Parent Seq: abcdefgi
 RUN TIME: 1.381 ms

 N: 9 Parent Seq: 123456789
 RUN TIME: 2.735 ms

 N: 10 Parent Seq: 0123456789
 RUN TIME: 4.849 ms

 N: 20 Parent Seq: abcdefghijklmnopqrst
 RUN TIME: 3823.39 ms

 N: 22 Parent Seq: 12abcdefghijklmnopqrst
 RUN TIME: 15360.5 ms

 N: 24 Parent Seq: 1234abcdefghijklmnopqrst
 RUN TIME: 61600 ms


$ ./a.out DY26 gdstew6732hew

3

Test 5. Dynamic Method 
Result in file: DY.txt

 N: 13 Parent Seq: gdstew6732hew
 RUN TIME: 29.49 ms

