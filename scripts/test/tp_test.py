import time
import smbus
import RPi.GPIO as GPIO

dev = smbus.SMBus(1)
dev_addr = 0x38

while True:
    x = ((dev.read_byte_data(dev_addr, 0x03) & 0x0F) << 8) + dev.read_byte_data(dev_addr, 0x04)
    y = ((dev.read_byte_data(dev_addr, 0x05) & 0x0F) << 8) + dev.read_byte_data(dev_addr, 0x06)
    print(x, y)
    time.sleep(0.05)


# i2cdetect -y -r -a 1
# i2cdump -y 1 0x38
# i2cget -y 1 0x38 0x9F