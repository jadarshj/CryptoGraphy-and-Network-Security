## Problem Statement : 
### To perform Round transformation process & Key Expansion process for AES-128version.
## Aim :
1. WAP to implement the ShiftRows Transformation
2. WAP to implement the MixColumns Transformation.
3. WAP to implement AddRoundKey Transformation.

I had taken the Logic from [How to Solve AES Mix Column Transformation by Chirag Bhalodia](https://www.youtube.com/watch?v=WPz4Kzz6vk4) , that is availabe on Youtube.

AES => Advanced Encryption Standard
---
<img align="left" width="200" height="200" src="https://media.giphy.com/media/fRYV4ck2DRYpBmpG1f/giphy.gif">

Introduction of AES :
AES uses 128 bits of plain text. AES consists of multiple rounds of processing different key bits like,
128 bits key – perform 10 rounds of encryption 
192 bits key – perform 12 rounds of  encryption.
256 bits key – perform 14 rounds of encryption.

For encryption, each round consists of the following four steps: Sub Bytes, 
Shift Rows, Mix Columns, Add Round Key.
Above steps also called AES transformation function. 


https://media.giphy.com/media/fRYV4ck2DRYpBmpG1f/giphy.gif
