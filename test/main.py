from pynput.mouse import Controller
import time

mouse = Controller()

while True:
    x, y = mouse.position
    mouse.position = (x + 1, y + 1)
    time.sleep(120)