import sys
from PyQt5.QtWidgets import *
from device_under_test import DeviceUnderTest


class MainWindow(QMainWindow):
    def __init__(self):
        QMainWindow.__init__(self)
        uic.loadUi("gui.ui", self)
        self.show()
        
        self.dut = DeviceUnderTest()
        self.dut.init()

        self.WidgetGenerateGMPulse = self.findChild(QPushButton, "WidgetGenerateGMPulse")
        self.WidgetLogger = self.findChild(QTextBrowser, "WidgetLogger")
        
        self.WidgetGenerateGMPulse.clicked.connect(self.onGenerateGMPulse)

    def onGenerateGMPulse(self):
        """alert = QMessageBox()
        alert.setText("self.dut.generateGMPulse()")
        alert.exec_()"""

        # dummy way to show was was logged
        v = self.dut.generateGMPulse()
        self.WidgetLogger.append (v)    


if __name__ == "__main__":
    app = QApplication([])
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
