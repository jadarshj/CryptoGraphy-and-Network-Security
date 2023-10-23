## Problem Statement : 
### To perform Round transformation process & Key Expansion process for AES-128version.
## Aim :
1. WAP to implement the ShiftRows Transformation
2. WAP to implement the MixColumns Transformation.
3. WAP to implement AddRoundKey Transformation.

I had taken the Logic from [How to Solve AES Mix Column Transformation by Chirag Bhalodia](https://www.youtube.com/watch?v=WPz4Kzz6vk4) , that is availabe on Youtube.

AES => Advanced Encryption Standard<br>
--- 
<img align="left" width="200" height="200" src="https://media.giphy.com/media/fRYV4ck2DRYpBmpG1f/giphy.gif">

<br> Introduction of AES :<br><br>
AES uses 128 bits of plain text. AES consists of multiple rounds of processing different key bits like,<br>
128 bits key – perform 10 rounds of encryption <br>
192 bits key – perform 12 rounds of  encryption.<br>
256 bits key – perform 14 rounds of encryption.<br>

<br><br>
For encryption, each round consists of the following four steps:<br>
1.Sub Bytes<br>
2.Shift Rows<br>
3.Mix Columns<br>
4.Add Round Key<br>

Above steps also called AES transformation function. 


---

CODE_RUN_01

1. ShiftRows Transformation.
2. MixColumns Transformation.
3. AddRoundKey Transformation.
0. Exit .
Enter Your Choice : 1

Enter the No.of rows : 4

Enter the No.of cols : 4

Enter the State Matrix : <br>
state[0][0] = 87<br>
state[0][1] = F2<br>
state[0][2] = 4D<br>
state[0][3] = 97<br>
state[1][0] = 6E<br>
state[1][1] = 4C<br>
state[1][2] = 90<br>
state[1][3] = EC<br>
state[2][0] = 46<br>
state[2][1] = E7<br>
state[2][2] = 4A<br>
state[2][3] = C3<br>
state[3][0] = A6<br>
state[3][1] = 8C<br>
state[3][2] = D8<br>
state[3][3] = 95<br>

State Matrix is :<br>
87 F2 4D 97<br>
6E 4C 90 EC<br>
46 E7 4A C3<br>
A6 8C D8 95<br>

Transformed : ShiftRows :<br>
87 F2 4D 97<br>
4C 90 EC 6E<br>
4A C3 46 E7<br>
95 A6 8C D8<br>

---

CODE_RUN_02


1. ShiftRows Transformation.  <br>
2. MixColumns Transformation. <br>
3. AddRoundKey Transformation.<br>
0. Exit .<br>
Enter Your Choice : 2

Enter the No.of rows : 4

Enter the No.of cols : 4

Enter the State Matrix :<br>
state[0][0] = 87<br>
state[0][1] = F2<br>
state[0][2] = 4D<br>
state[0][3] = 97<br>
state[1][0] = 6E<br>
state[1][1] = 4C<br>
state[1][2] = 90<br>
state[1][3] = EC<br>
state[2][0] = 46<br>
state[2][1] = E7<br>
state[2][2] = 4A<br>
state[2][3] = C3<br>
state[3][0] = A6<br>
state[3][1] = 8C<br>
state[3][2] = D8<br>
state[3][3] = 95<br>

State Matrix is :<br>
87 F2 4D 97<br>
6E 4C 90 EC<br>
46 E7 4A C3<br>
A6 8C D8 95<br>

Ans Matrix is :<br>
47 40 A3 4C<br>
37 D4 70 9F<br>
94 E4 3A 42<br>
ED A5 A6 BC<br>

---


CODE_RUN_03

1. ShiftRows Transformation.  <br>
2. MixColumns Transformation. <br>
3. AddRoundKey Transformation.<br>
0. Exit .<br>
Enter Your Choice : 3

For State Matrix :     <br>

Enter the No.of rows : 4

Enter the No.of cols : 4

Enter the State Matrix : <br>
state[0][0] = AC<br>
state[0][1] = 19<br>
state[0][2] = 28<br>
state[0][3] = 37<br>
state[1][0] = 77<br>
state[1][1] = FA<br>
state[1][2] = D1<br>
state[1][3] = 5C<br>
state[2][0] = 66<br>
state[2][1] = DC<br>
state[2][2] = 29<br>
state[2][3] = 00<br>
state[3][0] = F3<br>
state[3][1] = 21<br>
state[3][2] = 41<br>
state[3][3] = 6A<br>

State Matrix is :<br>
AC 19 28 37<br>
77 FA D1 5C<br>
66 DC 29 00<br>
F3 21 41 6A<br>

Enter the Key Matrix :<br>
Key[0][0] = 47<br>
Key[0][1] = 40<br>
Key[0][2] = A3<br>
Key[0][3] = 4C<br>
Key[1][0] = 37<br>
Key[1][1] = D4<br>
Key[1][2] = 70<br>
Key[1][3] = 9F<br>
Key[2][0] = 94<br>
Key[2][1] = EF<br>
Key[2][2] = 3A<br>
Key[2][3] = 42<br>
Key[3][0] = ED<br>
Key[3][1] = A5<br>
Key[3][2] = A6<br>
Key[3][3] = BC<br>

Key Matrix is : <br>
47 40 A3 4C<br>
37 D4 70 9F<br>
94 EF 3A 42<br>
ED A5 A6 BC<br>

Ans Matrix is :<br>
EB 59 8B 7B<br>
40 2E A1 C3<br>
F2 33 13 42<br>
1E 84 E7 D6<br>

