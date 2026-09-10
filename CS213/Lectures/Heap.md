<img width="1136" height="103" alt="Screenshot 2026-09-10 at 8 34 51 PM" src="https://github.com/user-attachments/assets/d07f2470-e216-4e2e-8e0c-ca85e58f7e6c" />


Recall: the number of internal nodes a binary tree of height h can have is
n ≤ nmax = 20 + 21 + ... + 2h = 2^(h+1)

<img width="950" height="108" alt="Screenshot 2026-09-10 at 8 35 52 PM" src="https://github.com/user-attachments/assets/aecf6a97-918a-48a7-b6e1-b2afb751ae6d" />
 - 1


<img width="624" height="227" alt="Screenshot 2026-09-10 at 8 36 03 PM" src="https://github.com/user-attachments/assets/094b1414-0d45-4cdc-80bb-3533d7fe31b9" />


<img width="178" height="56" alt="Screenshot 2026-09-10 at 8 36 31 PM" src="https://github.com/user-attachments/assets/e2ac0cba-215a-4a39-85fb-a15472f9ced7" />

in a nearly complete binary tree 


<img width="332" height="145" alt="Screenshot 2026-09-10 at 8 37 48 PM" src="https://github.com/user-attachments/assets/84727b4b-bfb6-4664-9841-7f71a37ade89" />


this property is now very easy to maintain 

To delete another node, first copy the bottom-right element to that
node, and then remove the bottom-right node


Heap as an array:


A[0] is root. Children of A[i] are A[2i+1] and A[2i+2] (right/both possibly leaves)

<img width="1206" height="660" alt="Screenshot 2026-09-10 at 9 24 38 PM" src="https://github.com/user-attachments/assets/9204dff3-621a-4b47-b7b7-ce8675ca449d" />




