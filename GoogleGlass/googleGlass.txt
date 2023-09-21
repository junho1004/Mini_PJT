import board
import digitalio
from PIL import Image, ImageDraw, ImageFont
import adafruit_ssd1306

#OLED setting
oled_reset = digitalio.DigitalInOut(board.D24)

WIDTH = 128
HEIGHT = 64
BORDER = 5

# Use for I2C
spi = board.SPI()
oled_cs = digitalio.DigitalInOut(board.D8)
oled_dc = digitalio.DigitalInOut(board.D25)
oled = adafruit_ssd1306.SSD1306_SPI(WIDTH, HEIGHT, spi, oled_dc, oled_reset, oled_cs)

# Clear display
oled.fill(0)
oled.show()