import spidev


spi = spidev.SpiDev()
spi.open(0, 0)

spi.max_speed_hz = 5000000
spi.mode = 0


def spi_loopback_test(data):
    try:
        print(f"MOSI: {data}")
        response = spi.xfer2(data)
        
        print(f"MISO: {response}")
    finally:
        spi.close()


if __name__ == "__main__":
    test_data = [0x01, 0x02, 0x03, 0x04, 0x05]
    spi_loopback_test(test_data)

