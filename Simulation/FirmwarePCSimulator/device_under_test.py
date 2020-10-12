from ctypes import *
from ctypes.wintypes import *
import os.path

class DeviceUnderTest:
    def __init__(self):
        pass

    def init(self):

        dll_name = "simulation.so"
        dllabspath = os.path.dirname(os.path.abspath(os.path.abspath(__file__))) + os.path.sep +"..\\..\\Software" + os.path.sep + "NUCLEO-F091RC" + os.path.sep + dll_name
        self.dut = ctypes.CDLL(dllabspath)
        self.dut.Lib_Simulation_Init()

    def generateGMPulse(self):
        self.dut.Lib_GMMeasurementCalculator_OnGMPulseObserved()
        self.dut.Lib_GMMeasurementCalculator_OnGMPulseObserved()
        self.dut.Lib_GMMeasurementCalculator_OnGMPulseObserved()

        self.dut.Lib_GMMeasurementCalculator_OnSamplingDone()

        self.dut.Lib_GMLoggerSIM_GetLoggedData.argtypes = [POINTER(POINTER(c_uint8)),  POINTER(c_uint8)]
        data = POINTER(c_uint8)()
        size = c_uint8()

        self.dut.Lib_GMLoggerSIM_GetLoggedData(byref(data), byref(size))

        logged_data = ""
        for i in range(size.value):
            logged_data += chr(data[i])

        return logged_data


