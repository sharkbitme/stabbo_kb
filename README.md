#stabbo_kb
is the codified version of one very famous disgruntled crustacean known for wielding a knife.

Essentially, this arduino sketch 'stabs' at numerous windows keyboard shortcuts, that you define, to help identify any shortcuts for kiosk-mode
breakouts on windows systems.

Ideal for use with an arduino due and leonardo (due is the better bet though, easier, and more program memory).

Current form is just running through winkey + single letter combos, will add additional modifier keys soon.

# usage

If using the IDE Serialmonitor, set the option to 'no line ending'.

Connect microusb data cable from the computer you are going to run the serial monitor/interface on to the usb programming port
on the Due (closest to power connector), start up the IDE and open serial monitor. Next, connect the native usb port on the Due to the target machine.

With Leonardo, you'll need a usb to serial cable or bridge (such as an FTDI TTL232R 3v3) and connect the TX and RX pins to the Leo appropriately. A power source to the Leo might be needed, depending on the situation. It should be noted that the Leo communicates over 'Serial1' instead of 'Serial' on the Due. For a Leo, use the 'stabbo_kb_leonardo' file in this repo.

Once connected via serial the current options are:




Select mode:


w - check defined combos, stopping for alt tab to check background stuff
r - rapid mode, no stopping to alt + tab

The W option will go through each winkey <a-z> combo, pausing after each and pressing alt + tab, then releasing tab,
  in order to bring up the task switcher. Some kiosk software may 'keep' the focus but sometimes things open in the
  background, so this helps check if something showed up or not. From there, it will prompt you if you want to continue
  through the combinations, or quit.
  
The R option is pretty much the same as above but, it doesn't stop to bring up the task switcher for you, it just
  runs through each combination with the delays that are in place.
  
# delays
Some systems aren't exactly the most responsive, so depending on the target, might need to increase delays in the function.
