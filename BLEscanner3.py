#GPT-4 prompt : Give me window11 python code of BLE scanner with print device name and distance for endless loop
#               Please revise code to do not print out for the device name is None
#               Please add print out qty of founded device on every scan 
import asyncio
from bleak import BleakScanner

async def run():
    scanner = BleakScanner()
    while True:
        devices = await scanner.discover()
        print(f'Found {len(devices)} devices')
        for device in devices:
            if device.name is not None:
                print(f'Device: {device.name}, RSSI: {device.rssi}')

loop = asyncio.get_event_loop()
loop.run_until_complete(run())
