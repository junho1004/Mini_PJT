from PySide2.QtWidgets import *
from light import Ui_MainWindow
from sense_hat import SenseHat
#from sense_emu import SenseHat
from time import sleep

class MyApp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        Ui_MainWindow.setupUi(self, self)
        self.main()

    def main(self):
        self.sense = SenseHat()
        self.R = 100
        self.G = 110
        self.B = 120
        self.Color = (self.R, self.G, self.B)
        
    def flash(self):
        self.Color = (self.R, self.G, self.B)
        self.sense.clear(self.Color)

    def clear(self):
        self.sense.clear()

    def click(self, x, y):
        self.Color = (self.R, self.G, self.B)
        self.sense.set_pixel(y, x, self.Color)
        print(y, x)

    def rslide(self, val):
        self.R = val

    def gslide(self, val):
        self.G = val

    def bslide(self, val):
        self.B = val

app = QApplication()
win = MyApp()
win.show()
app.exec_()