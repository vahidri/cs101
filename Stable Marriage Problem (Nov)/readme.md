# Stable Marriage Problem
on [Wikipedia](https://en.wikipedia.org/wiki/Stable_marriage_problem)

There are 3 cpp files. Listed in order of needed execution:
## 1st: Generate a Random list => list.txt
	if you want to give your own list to match, please enter it into "list.txt" in this format:
		in the first line, write n[size, men(=women) count)]
		in the lines [2,2+n] write men's preferences, seperated by space.
		[leave a blank line, to make the list clean, you may not but I recommand it]
		enter the women's preferences likewise
		[you may want to leave a last blank line as well]

## 2nd: Matches Men to Women. The SMP! => ans.txt
```
function stableMatching {
    Initialize all m ∈ M and w ∈ W to free
    while ∃ free man m who still has a woman w to propose to {
       w = highest ranked woman to whom m has not yet proposed
       if w is free
         (m, w) become engaged
       else some pair (m', w) already exists
         if w prefers m to m'
           (m, w) become engaged
           m' becomes free
         else
           (m', w) remain engaged
    }
}
```

## 3rd: Checks list.txt and ans.txt, for the possible objections.

