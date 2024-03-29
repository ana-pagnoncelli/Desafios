# Shopping in FdI

The Nlogonian Aquatic Surf Championship is about to start! Next year, the big final will be hosted in the city of Foça do Iguachim (FdI)! That region is famous due to the shops in there. The shops in that region usually sell many products cheaper than other shops in the country. You want to take advantage of your trip to buy the new Aifôni (R)! (Actually, you wanted a Sãosunga (R), but this cellphone is literally a boom!)

There are N shops, numbered from 1 to N. Every shop sells the cellphone, although its price may be different in each shop. Since you do not want your trip to be tiring, you may consider not visiting all N shops, but only shops between two given shops i and j, inclusive. You are interested in the largest price difference of the cellphone in these shops. Such difference is equal to |M - m|, where M is the highest price in these shops, and m is the lowest price in them.

Also, shops can change their price as they want! Your task is to determine, for many queries, the largest price difference in shops between two given shops, considering the prices may eventually change.

## Input
The input contains several test cases. The first line of each test case contains the integer N (1 ≤ N ≤ 105). The second line contains N integers p1,p2,...,pN (1 ≤ pi ≤ 105). Integer pi indicates the initial price of the cellphone at shop i. The third line contains an integer Q (1 ≤ Q ≤ 105), the number of operations. Each of the next Q lines describes an operation. Each operation can be described in two ways:

1 i p (1 ≤ i ≤ N, 1 ≤ p ≤ 105), the price of the cellphone changed to p in store i.
2 i j (1 ≤ i ≤ j ≤ N), a query.
The input ends with end-of-file (EOF).

## Output
For each test case, print a line for each query containing the largest price difference in all shops between shops i and j, inclusive.