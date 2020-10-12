from ctypes import *
from ctypes.wintypes import *
libc = ctypes.CDLL("./main.so")

libc.Lib_Simulation_Init()

libc.Lib_GMMeasurementCalculator_OnGMPulseObserved()
libc.Lib_GMMeasurementCalculator_OnGMPulseObserved()
libc.Lib_GMMeasurementCalculator_OnGMPulseObserved()

libc.Lib_GMLoggerSIM_GetLoggedData.argtypes = [POINTER(POINTER(c_uint8)),  POINTER(c_uint8)]
data = POINTER(c_uint8)()
size = c_uint8()

libc.Lib_GMLoggerSIM_GetLoggedData(byref(data), byref(size))


for i in range(size.value):
    print(chr(data[i]))
