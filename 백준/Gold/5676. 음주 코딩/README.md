# [Gold I] 음주 코딩 - 5676 

[문제 링크](https://www.acmicpc.net/problem/5676) 

### 성능 요약

메모리: 4092 KB, 시간: 112 ms

### 분류

세그먼트 트리, 자료 구조

### 제출 일자

2025년 12월 27일 21:45:04

### 문제 설명

<p>It's normal to feel worried and tense the day before a programming contest. To relax, you went out for a drink with some friends in a nearby pub. To keep your mind sharp for the next day, you decided to play the following game. To start, your friends will give you a sequence of N integers X<sub>1</sub>, X<sub>2</sub>, ... , X<sub>N</sub>. Then, there will be K rounds; at each round, your friends will issue a command, which can be:</p>

<ul>
	<li>a change command, when your friends want to change one of the values in the sequence; or</li>
	<li>a product command, when your friends give you two values I, J and ask you if the product X<sub>I</sub> × X<sub>I+1</sub> × ... × X<sub>J-1</sub> × X<sub>J</sub> is positive, negative or zero.</li>
</ul>

<p>Since you are at a pub, it was decided that the penalty for a wrong answer is to drink a pint of beer. You are worried this could a ect you negatively at the next day's contest, and you don't want to check if Ballmer's peak theory is correct. Fortunately, your friends gave you the right to use your notebook. Since you trust more your coding skills than your math, you decided to write a program to help you in the game.</p>

### 입력 

 <p>Each test case is described using several lines. The rst line contains two integers N and K, indicating respectively the number of elements in the sequence and the number of rounds of the game (1 ≤ N, K ≤ 10<sup>5</sup>). The second line contains N integers X<sub>i</sub> that represent the initial values of the sequence (100 ≤ X<sub>i</sub> ≤ 100 for i = 1, 2, ... , N). Each of the next K lines describes a command and starts with an uppercase letter that is either "C" or "P". If the letter is "C", the line describes a change command, and the letter is followed by two integers I and V indicating that X<sub>I</sub> must receive the value V (1 ≤ I ≤ N and 100 ≤ V ≤ 100). If the letter is "P", the line describes a product command, and the letter is followed by two integers I and J indicating that the product from X<sub>I</sub> to X<sub>J</sub>, inclusive must be calculated (1 ≤ I ≤ J ≤ N). Within each test case there is at least one product command.</p>

### 출력 

 <p>For each test case output a line with a string representing the result of all the product commands in the test case. The i-th character of the string represents the result of the i-th product command. If the result of the command is positive the character must be "+" (plus); if the result is negative the character must be "-" (minus); if the result is zero the character must be "0" (zero)</p>

