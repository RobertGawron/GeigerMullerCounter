import sys
from PyQt5.QtWidgets import *
from PyQt5 import QtWidgets, QtGui, QtCore, uic
from device_under_test import DeviceUnderTest
from datetime import datetime

import threading
import time

class MainWindow(QMainWindow):
    def __init__(self):
        QMainWindow.__init__(self)
        uic.loadUi("gui.ui", self)
        
        
        self.dut = DeviceUnderTest()

        self.WidgetGenerateGMPulse = self.findChild(QPushButton, "WidgetGenerateGMPulse")
        self.WidgetLogger = self.findChild(QTextBrowser, "WidgetLogger")
        self.WidgetHWDisplay= self.findChild(QLabel, "WidgetHWDisplay")
 
        self.WidgetGenerateGMPulse.clicked.connect(self.onGenerateGMPulse)
        
        
        # TODO remove it it's just to test the method
        self.onHWDisplayUpdate()

        
        # TODO move it somewhere
        
        def invokeUpdate(dut):
            time.sleep(10)
            self.dut.generateEndOfSampleCollecting()
            self.onNewLoggedData()

        x = threading.Thread(target=invokeUpdate, args=(self,))
        x.start()


        self.show()

    def onGenerateGMPulse(self):
        self.dut.generateGMPulse()

        # dummy way to show was was logged
        #self.dut.generateEndOfSampleCollecting()
        #self.onNewLoggedData()

    def onNewLoggedData(self):
        logged_data = self.dut.getLoggedData()
        local_timestamp = datetime.now()
        data_with_timestamp = "{}: {}".format(local_timestamp, logged_data)
        self.WidgetLogger.append (data_with_timestamp)

    def onHWDisplayUpdate(self):
        # this is a dummy implementation just to know how Qt + images works

        LCDHeightBlue = 48
        LCDHeightYellow = 16
        
        canvas = QtGui.QPixmap(128, LCDHeightBlue+LCDHeightYellow)
        # clean canvas, otherwise image is black
        # see https://stackoverflow.com/questions/63269098/qpixmap-qpainter-showing-black-window-background
        canvas.fill(QtGui.QColor("blue"))
        self.WidgetHWDisplay.setPixmap(canvas)

        painter = QtGui.QPainter(self.WidgetHWDisplay.pixmap())
        painter.drawLine(0, 0, 100, 100)
        painter.end()


if __name__ == "__main__":
    app = QApplication([])
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
