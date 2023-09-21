1. 개발 목적 : Raspberry Pi zero 를 사용하여 Google Glass 만들어보기
2. 개발 환경
   - OS : Raspberry Pi OS
   - HW : Raspberry Pi zero, OLED Display SSD1306 - SPI통신 사용
![image](https://github.com/junho1004/Mini_PJT/assets/109517019/0d2f1748-91ed-4b78-b1bd-a0140120c07a)
3. 개발 전 준비사항
   - SSD1306 모듈설치
      $pip3 install adafruit-circuitpython-ssd1306
      $git clone https://github.com/adafruit/Adafruit_CircuitPython_SSD1306

4. 화면구성
![image](https://github.com/junho1004/Mini_PJT/assets/109517019/7323090a-468d-4a66-8e4f-8cae32f817a7)

5. 사용 라이브러리
   - board, digitalio - board library와 함께 사용하여 Raspberry Pi zero에 설계한 회로와 연결
   - Image, ImageDraw, ImageFont - 이미지 영역에 할당할 이미지를 객체로 만들어 화면에 맞도록 프로세싱
   - adafruit_ssd1306 - SPI통신을 위한 라이브러리
6. 실행방법
	$python3 googleGlass.py

---
![glass](https://github.com/junho1004/Mini_PJT/assets/109517019/087227c4-7703-41e3-9989-058adba45e2a)
