# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'light.ui'
##
## Created by: Qt User Interface Compiler version 6.4.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide2.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide2.QtWidgets import (QAbstractItemView, QApplication, QGridLayout, QHeaderView,
    QMainWindow, QMenuBar, QPushButton, QSizePolicy,
    QSlider, QStatusBar, QTableWidget, QTableWidgetItem,
    QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(642, 500)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.gridLayoutWidget = QWidget(self.centralwidget)
        self.gridLayoutWidget.setObjectName(u"gridLayoutWidget")
        self.gridLayoutWidget.setGeometry(QRect(150, 40, 301, 391))
        self.gridLayout = QGridLayout(self.gridLayoutWidget)
        self.gridLayout.setObjectName(u"gridLayout")
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.sliderR = QSlider(self.gridLayoutWidget)
        self.sliderR.setObjectName(u"sliderR")
        self.sliderR.setMaximum(255)
        self.sliderR.setValue(100)
        self.sliderR.setOrientation(Qt.Horizontal)

        self.gridLayout.addWidget(self.sliderR, 1, 0, 1, 1)

        self.sliderB = QSlider(self.gridLayoutWidget)
        self.sliderB.setObjectName(u"sliderB")
        self.sliderB.setMaximum(255)
        self.sliderB.setValue(120)
        self.sliderB.setOrientation(Qt.Horizontal)

        self.gridLayout.addWidget(self.sliderB, 5, 0, 1, 1)

        self.pushButton_2 = QPushButton(self.gridLayoutWidget)
        self.pushButton_2.setObjectName(u"pushButton_2")

        self.gridLayout.addWidget(self.pushButton_2, 12, 0, 1, 1)

        self.pushButton = QPushButton(self.gridLayoutWidget)
        self.pushButton.setObjectName(u"pushButton")

        self.gridLayout.addWidget(self.pushButton, 11, 0, 1, 1)

        self.sliderG = QSlider(self.gridLayoutWidget)
        self.sliderG.setObjectName(u"sliderG")
        self.sliderG.setMaximum(255)
        self.sliderG.setValue(110)
        self.sliderG.setOrientation(Qt.Horizontal)

        self.gridLayout.addWidget(self.sliderG, 3, 0, 1, 1)

        self.table = QTableWidget(self.gridLayoutWidget)
        if (self.table.columnCount() < 8):
            self.table.setColumnCount(8)
        if (self.table.rowCount() < 8):
            self.table.setRowCount(8)
        self.table.setObjectName(u"table")
        self.table.setEditTriggers(QAbstractItemView.NoEditTriggers)
        self.table.setAlternatingRowColors(False)
        self.table.setSelectionMode(QAbstractItemView.SingleSelection)
        self.table.setRowCount(8)
        self.table.setColumnCount(8)
        self.table.horizontalHeader().setVisible(False)
        self.table.horizontalHeader().setDefaultSectionSize(36)
        self.table.verticalHeader().setVisible(False)

        self.gridLayout.addWidget(self.table, 0, 0, 1, 1)

        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 642, 22))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        self.pushButton_2.clicked.connect(MainWindow.clear)
        self.pushButton.clicked.connect(MainWindow.flash)
        self.sliderR.valueChanged.connect(MainWindow.rslide)
        self.sliderG.valueChanged.connect(MainWindow.gslide)
        self.sliderB.valueChanged.connect(MainWindow.bslide)
        self.table.cellEntered.connect(MainWindow.click)
        self.table.cellPressed.connect(MainWindow.click)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.pushButton_2.setText(QCoreApplication.translate("MainWindow", u"Clear", None))
        self.pushButton.setText(QCoreApplication.translate("MainWindow", u"Flash", None))
    # retranslateUi

