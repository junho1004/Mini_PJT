[ 개요 ]

임베디드 분야에서 직접 접근해야하는 메모리에 대한 이해는 필수적이다.
우리가 사용하는 SSD의 동작을 분석해서 SSD에 대한 이해를 높인다.
이를 SW적으로 구현해보고, 검증하는 셸 프로그래밍을 통해 SSD에 대한 이해와 개발역량을 쌓는다.

[ 기간 ]

22.09.30 ~ 22.10.04

[ 인원 ]

2명

[ 프로젝트 구성 ] 

1. 가상 SSD 제작
    - HW 를 Software 로 구현한다
2. Test Shell Application 만들기
    - 테스트 프로그램
3. Test Script 작성하기
    - 테스트 프로그램 內 Test Code

[ Detail ]

1. SSD는 물리적인 저장장치이지만, SW적으로 구현하는 프로젝트로 설계할 예정.
2. SSD 는 파일 입출력을 통해서 간단하게 구현
3. Read/Write 기능 구현을 통해 SSD 테스트 가능

[ 필요 지식 ]

SSD 

- 저장할 수 있는 최소 공간의 사이즈는 4KB
( 한 글자 = 약 1 Byte 으로 간주했을 때 , 4,096 글자 저장 가능 공간
- 각 공간마다 LBA (Logical Block Address) 라는 주소를 가짐
- SSD 는 OS 로부터 Read / Write / Unmap 등 다양한 명령어를
전달받는다

[ 가상 SSD 스펙 ]

- Read 명령어와 Write 명령어만 존재
- LBA 단위는 4 Byte
- ( 실제로는 4KB 이지만 , 우리가 만들 최소 저장공간 사이즈는 4 Byte)
- LBA 0 ~ 99 까지 100 칸을 저장할 수 있다
- 총 400 Byte 를 저장 할 수 있는 가상 SSD 를 구현

[ 세부 규정 ]

데이터 범위

- LBA : 0 ~ 99, 10 진수
- 값 : 항상 0x 가 붙으며 10 글자로 표기한다. ( 0x00000000 ~ 0xFFFFFFFF)

Read 명령어

- ssd R [LBA]
- result.txt 에 읽은 값이 적힌다. 기존 데이터는 사라진다.
- 한번도 안적은 곳은 0x00000000 으로 읽힌다.

Write 명령어

- ssd W [LBA] [ 값]
- nand.txt 에 저장한 값이 기록된다.

[ 사용자 입력 예시 ]

- write 3 0xAAAABBBB
    - 3번 LBA에 0xAAAABBBB를 기록한다.
    - ssd에 명령어를 전달한다.

 
- read 3
    - 3번 LBA를 읽는다.
    - ssd에 명령어를 전달한다.
    - result.txt에 적힌 결과를 화면에 출력한다.

- exit
    - Shell이 종료된다.


- help
    - 각 명령어당 사용 방법을 출력한다.
 

- fullwrite 0xABCDFFFF
    - LBA 0번부터 99번까지 write를 수행한다.
    - 모든 LBA에 값 0xABCDFFFF가 적힌다.

- fullread
    - LBA 0번부터 99번까지 read를 수행한다.
    - 모든 LBA의 값들이 화면에 출력된다.
 
[ 유의사항 ]

- 입력받은 매개변수가 유효성 검사 수행
    - 파라미터의 Format이 정확해야 함
    - LBA의 범위는 0~99
    - A ~ F, 0 ~ 9 까지 범위만 허용

- 없는 명령어를 수행하는 경우 "INVALID COMMAND"를 출력
    - 어떠한 명령어를 입력하더라도 segment falut가 나오면 안된다.

---
[read & write]
<img width="268" alt="01readwrite" src="https://github.com/junho1004/Mini_PJT/assets/109517019/314ecd72-f654-4d8a-b251-9a84ebc25ab8">

[fullwrite]
<img width="201" alt="02fullwrite" src="https://github.com/junho1004/Mini_PJT/assets/109517019/e3170ed8-deeb-4a8d-ad51-cc35c6642f25">

[fullread]
<img width="137" alt="03fullread" src="https://github.com/junho1004/Mini_PJT/assets/109517019/2d1e7dd9-a1be-454e-93a5-b151b133092b">

[nand.txt]
<img width="122" alt="04nand_txt" src="https://github.com/junho1004/Mini_PJT/assets/109517019/e8b89c82-0045-4dfb-b8c1-3333ddc4f5f5">

[result.txt]
<img width="280" alt="05result_txt" src="https://github.com/junho1004/Mini_PJT/assets/109517019/5368ba87-c5da-4435-a1a9-7a43e73c0a4c">
