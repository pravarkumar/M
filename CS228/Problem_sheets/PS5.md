<img width="1074" height="152" alt="Screenshot 2026-09-09 at 11 04 29 AM" src="https://github.com/user-attachments/assets/0713ecc7-0711-44f7-828f-e3a012384c0d" />


Soln: The worst case time complexity is O(2^n) as we can use the formula :
    F = and over all not(mineterms) till the very last point the algo will try to find the soln but wotn be able to as the 
    solution odes not exist thus it ends up using all the n-1 vvariables with no unit propogation thus causing the high time complexity 
    

the best case time compelxity is O(n)
G = (p1) and ( p2) and ... (pn) where every literal is forced 



<img width="1052" height="100" alt="Screenshot 2026-09-09 at 11 14 02 AM" src="https://github.com/user-attachments/assets/7197578d-74c5-4600-b052-6f5b291d99f7" />



<img width="1064" height="209" alt="Screenshot 2026-09-09 at 11 19 11 AM" src="https://github.com/user-attachments/assets/266062b8-35e5-4b99-be6d-d1cbdbe9b15b" />


Here first of all we can work with the unit propogations first if we get a conflict in the process then the formula is 
UNSAT as there is no decision to be overturned and if not then the formula is SAT .

We can prove this as claim: Each clause contains at least one negative literal
this is because eahc clause contians at least 2 literlas otherwise it would had been covered in the unit propogation stp 
hence we get at leas tone negative literal. THis means that as long as we keep assignmeing the value 0 to all the 
varibles we end up with the (0,0,...,0) assignment which is true as each clause evalautes to true due to the negative literal
.Hence the algorithm never needs to backtrac as long as its assigning thevalue 0 to the varibles before assingning the vlaue 
1.

