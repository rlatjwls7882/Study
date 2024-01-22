# [Bronze II] Wheel Rotation - 6060 

[문제 링크](https://www.acmicpc.net/problem/6060) 

### 성능 요약

메모리: 14648 KB, 시간: 140 ms

### 분류

구현, 수학

### 제출 일자

2024년 1월 22일 21:37:42

### 문제 설명

<p>Farmer John has an old-time thresher (wheat harvester) that requires belts to be installed on various gears to turn the parts. The engine drives pulley 1 in a clockwise direction which attaches via a belt to pulley 2. Pulley 2 attaches via a belt to pulley 3 and so on through a total of N (2 <= N <= 1,000) pulleys (and N-1 belts).</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/452fea32-a8bf-49c3-a639-afdf2c1619e6/-/preview/" style="width: 142px; height: 137px;"></p>

<p>The diagram above depicts the two ways a belt can be installed between two gears. In this illustration, pulley 1's belt directly drives pulley 2 (a 'straight' connection) and thus they will rotate in the same direction. Pulley 3 drives pulley 4 via a 'crossed belt' that reverses the direction of the rotation.</p>

<p>Given a list of the belt types that connect the pulleys along with the fact that pulley 1 is driven in a clockwise direction by the engine, determine the drive direction of pulley N. Each belt is described by three integers:</p>

<ul>
	<li>S_i -- the driving (source) pulley</li>
	<li>D_i -- the driven (destination) pulley</li>
	<li>C_i -- the connection type (0=straight, 1=crossed)</li>
</ul>

<p>Unfortunately, FJ lists the belts in random order.</p>

<p>By way of example, consider the illustration below. N = 4, and pulley 1 is driven clockwise by the thresher engine. Straight belts drive pulley 2 and then pulley 3, so they rotate clockwise. The crosswise belt reverses the rotation direction so pulley 4 (pulley N) rotates counterclockwise.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/95e3e1c5-4fcf-46df-96a0-0b12e2382b23/-/preview/" style="width: 317px; height: 136px;"></p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N: Each line describes a belt with three integers: S_i, D_i, and C_i</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the rotation direction for pulley N (0=clockwise, 1=counterclockwise)</li>
</ul>

