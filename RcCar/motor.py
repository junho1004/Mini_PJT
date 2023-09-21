from Raspi_MotorHAT import Raspi_MotorHAT, Raspi_DCMotor
from Raspi_PWM_Servo_Driver import PWM
from time import sleep

mh = Raspi_MotorHAT(addr=0x6f) 
myMotor = mh.getMotor(2) #핀번호

# 집게 팔 + 다이오드 + 버튼은 아두이노에서 따로 구현
from piservo import Servo
from gpiozero import LED

Left_Hand = Servo(18) #Release 70 angle // Grab 0 angle
Right_Hand = Servo(13) #Release 0 angle // Grab 70 angle
# 집게 오므리면 초록색 다이오드 on, 펼치면 off
Green = LED(19)         #put in Gpio Num
Green2 = LED(26)
d = 5
angleLeft = 235+d
angleMid = 330 +d
angleRight = 405+d
servo = PWM(0x6F)
servo.setPWMFreq(60)  # Set frequency to 60 Hz
myspeed = 100 # 정지 속도 = 100

def GO(speed):
    myMotor.setSpeed(speed)
    myMotor.run(Raspi_MotorHAT.BACKWARD)
    
def LEFT():
    servo.setPWM(0, 0, angleLeft)

def RIGHT():
    servo.setPWM(0, 0, angleRight)

def BACK(speed):
    myMotor.setSpeed(speed)
    myMotor.run(Raspi_MotorHAT.FORWARD)

def STOP():
    myMotor.run(Raspi_MotorHAT.RELEASE)
    servo.setPWM(0, 0, angleMid)

def UnGrab():
    sleep(0.5)
    for i in range(1):
        Left_Hand.write(70)
        Right_Hand.write(0)
        Green.off()
        Green2.off()

def Grab():
    sleep(0.5)
    for i in range(1):
        Left_Hand.write(0)
        Right_Hand.write(70)
        Green.on()
        Green2.on()

# subscriber.py
import paho.mqtt.client as mqtt

def on_connect(client, userdata, flags, rc):
    print(f"Connected with result code {rc}")
    # subscribe, which need to put into on_connect
    # if reconnect after losing the connection with the broker, it will continue to subscribe to the raspberry/topic topic
    client.subscribe("home/pi")


def on_message(client, userdata, msg):
    cmd = str(msg.payload.decode("utf-8"))

    if cmd == 'go':
        myspeed = 130
        GO(myspeed)

    if cmd == 'left':
        LEFT()

    if cmd == 'right':
        RIGHT()

    if cmd == 'back':
        myspeed = 130
        BACK(myspeed)

    if cmd == 'stop':
        STOP()

    if cmd == 'ungrab':
        UnGrab()
    if cmd == 'grab':
        Grab()




client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

# set the will message, when the Raspberry Pi is powered off, or the network is interrupted abnormally, it will send the will message to other clients
#client.will_set('raspberry/status', b'{"status": "Off"}')

# create connection, the three parameters are broker address, broker port number, and keep-alive time respectively
client.connect("192.168.110.192", 1883, 60)

# set the network loop blocking, it will not actively end the program before calling disconnect() or the program crash
client.loop_forever()
