[개발 목적]

다양한 센서를 이용해 출입 인증 시스템을 구현할 수 있다.

[개발 환경 및 장비]

Raspberry Pi 4, 초음파 센서, RGB LED, 부저, RFID

[기능 상세]

1. 접근시
  - 초음파센서 : 접근확인
  - LED : 초록불 ON (거리가 멀어지면 OFF)
  - 특정 거리 이내 접근시에만, RFID 사용 가능

2. 출입 인증 성공시
  - FND : 출입한 수 Counting
  - Buzzer : 출근 환영 음악

3. 출입 실패시
  - Buzzer : 간단한 경고음
  - LED : 빨간불 잠시 ON
  - 3회 기회 실패 시 더 강한 Buzzer 울림

[실행 결과]

---


https://github.com/junho1004/Mini_PJT/assets/109517019/f178fad8-9745-4d04-9411-fd1e86e972a8
