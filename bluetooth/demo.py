#import evdev
from evdev import InputDevice, categorize, ecodes

#creates object 'gamepad' to store the data
#you can call it whatever you like
controller = InputDevice('/dev/input/event0')

#prints out device info at start
print(controller)
print(controller.capabilities(verbose=True))
#evdev takes care of polling the controller in a loop
for event in controller.read_loop():
    # if event.type == ecodes.EV_SYN or event.type == ecodes.EV_ABS:
    #     continue
    # print(categorize(event))
    print(event)