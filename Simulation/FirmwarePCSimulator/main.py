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

        
        """# TODO move it somewhere
        def invokeUpdate(dut):
            time.sleep(10)
            self.dut.generateEndOfSampleCollecting()
            self.onNewLoggedData()

        x = threading.Thread(target=invokeUpdate, args=(self,))
        x.start()"""


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
        for i in range(120):
            self.dut.generateGMPulse()
        
        self.dut.generateEndOfSampleCollecting()
        
        for i in range(101):
            self.dut.generateGMPulse()
        self.dut.generateEndOfSampleCollecting()

        for i in range(120):
            self.dut.generateGMPulse()
        
        self.dut.generateEndOfSampleCollecting()
        
        for i in range(110):
            self.dut.generateGMPulse()
        self.dut.generateEndOfSampleCollecting()


        display_data = self.dut.getDisplayData()
        display_length = self.dut.getDisplayLength()
        display_height = self.dut.getDisplayHeight()


        display_pixel_on_color = "#6df8fc"
        display_pixel_off_color ="#14182b"

        canvas = QtGui.QPixmap(display_length, display_height)
        # clean canvas, otherwise image is black
        # see https://stackoverflow.com/questions/63269098/qpixmap-qpainter-showing-black-window-background
        canvas.fill(QtGui.QColor(display_pixel_off_color))
        self.WidgetHWDisplay.setPixmap(canvas)



        painter = QtGui.QPainter(self.WidgetHWDisplay.pixmap())

        pen = QtGui.QPen()
        pen.setWidth(1)
        pen.setColor(QtGui.QColor(display_pixel_on_color))
        painter.setPen(pen)


        data_str=''

        for y in range(display_height):
            data_str +=("^\n")
            for x in range(display_length):
                # formula from SSD1306_DrawPixel()
                # SSD1306_Buffer[x + (y / 8) * SSD1306_WIDTH] |= 1 << (y % 8);
                cell = display_data[x + int(y / 8) * display_length]
                value = cell & (1 << (y %8))
                if(value == 0):
                    pen.setColor(QtGui.QColor(display_pixel_on_color))
                    painter.setPen(pen)
                    data_str += ('@')
                else:
                    pen.setColor(QtGui.QColor(display_pixel_off_color))
                    painter.setPen(pen)
                    data_str += ('_')
                painter.drawPoint(x, y)

        print (data_str)

        painter.end()


if __name__ == "__main__":
    app = QApplication([])
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
